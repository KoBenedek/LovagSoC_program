#	Copyright (C) 2023 Benedek Kocsis
#
#   File name:      Makefile
#   Company:        University of Miskolc
#   Department:     Department of Automation and Infocommunication
#   Author:         Benedek Kocsis
#
#   Description:    Makefile for the compilation and other tasks
#					involving IcarusVerilog

.PHONY: build directory remove-temp
#Assembly compiler command
ASMC = riscv32-unknown-elf-as
#C compiler command
CC = riscv32-unknown-elf-gcc
#Linker command
LD = riscv32-unknown-elf-ld
#Generate outputs command
OBJCOPY = riscv32-unknown-elf-objcopy
#Data dump command
OBJDUMP = riscv32-unknown-elf-objdump
#Tool to convert .elf to .hex
ELF2HEX = elf2hex
#Name of the linker script
ASM_LINKER = linker
#Memory map
MAP = $(OUTPUT).map

ASMCFLAGS = -march=rv32i -mabi=ilp32
CCFLAGS = -march=rv32i -mabi=ilp32 $(INCS)
LDFLAGS = -m elf32lriscv -Map=$(PATH_TO_BUILD)/$(MAP) --print-memory-usage
E2HFLAGS= --bit-width 32
# -mno-relax
# -no-relax
# -nostdlib

PROJECT_ROOT = .
PATH_TO_E2H = $(PROJECT_ROOT)/Device/Utility
PATH_TO_STARTUP = $(PROJECT_ROOT)/Device
PATH_TO_SRCS = $(PROJECT_ROOT)/Code
PATH_TO_LD = $(PROJECT_ROOT)/Device
PATH_TO_BUILD = $(PROJECT_ROOT)/build
PATH_TO_OBJS = $(PROJECT_ROOT)/Device

STARTUP = LovagSoC_startup.S
INCS = -I ./Device
SRCS = main.c

OUTPUT = LovagSoC_program

ASM_OBJ = $(addprefix $(PATH_TO_STARTUP)/, $(subst .S,.o, $(STARTUP)))

OBJS = $(addprefix $(PATH_TO_SRCS)/, $(subst .c,.o, $(SRCS)))

build: directory $(OUTPUT).elf remove-temp $(OUTPUT).bin $(OUTPUT)_ihex.hex $(OUTPUT).v $(OUTPUT).hex
	@echo Build complete.

directory:
	@mkdir -p $(PATH_TO_BUILD)

$(OBJS):
	@$(CC) $(CCFLAGS) $(subst .o,.c,$@) -r -o $(PATH_TO_OBJS)/$(notdir $@)

$(ASM_OBJ):
	@$(ASMC) $(ASMCFLAGS) $(subst .o,.S,$@) -o $(PATH_TO_OBJS)/$(notdir $@)

$(OUTPUT).elf: $(ASM_OBJ) $(OBJS) directory
	@$(LD) $(PATH_TO_OBJS)/$(notdir $(ASM_OBJ)) $(PATH_TO_OBJS)/$(notdir $(OBJS)) -o $(PATH_TO_BUILD)/$@ -T $(PATH_TO_LD)/$(ASM_LINKER).ld $(LDFLAGS)

$(OUTPUT).bin: $(OUTPUT).elf
	@$(OBJCOPY) $(PATH_TO_BUILD)/$(OUTPUT).elf $(PATH_TO_BUILD)/$@ -O binary

$(OUTPUT)_ihex.hex: $(OUTPUT).elf
	@$(OBJCOPY) $(PATH_TO_BUILD)/$(OUTPUT).elf $(PATH_TO_BUILD)/$@ -O ihex

$(OUTPUT).v: $(OUTPUT).elf
	@$(OBJCOPY) $(PATH_TO_BUILD)/$(OUTPUT).elf $(PATH_TO_BUILD)/$@ -O verilog

$(OUTPUT).hex: $(OUTPUT).elf
	@$(PATH_TO_E2H)/$(ELF2HEX) $(E2HFLAGS) --input $(PATH_TO_BUILD)/$(OUTPUT).elf --output $(PATH_TO_BUILD)/$@

program:
	@python3 upload_prog.py

view-o: $(OUTPUT).elf
	@$(OBJDUMP) -d $(PATH_TO_OBJS)/$(notdir $(ASM_OBJ)) $(PATH_TO_OBJS)/$(notdir $(OBJS))
	@-rm $(PATH_TO_OBJS)/$(notdir $(OBJS))
	@-rm $(PATH_TO_OBJS)/$(notdir $(ASM_OBJ))

view-elf: $(OUTPUT).elf
	@$(OBJDUMP) -D $(PATH_TO_BUILD)/$(OUTPUT).elf
	@-rm $(PATH_TO_OBJS)/$(notdir $(OBJS))
	@-rm $(PATH_TO_OBJS)/$(notdir $(ASM_OBJ))

remove-temp:
	@-rm $(PATH_TO_OBJS)/$(notdir $(OBJS))
	@-rm $(PATH_TO_OBJS)/$(notdir $(ASM_OBJ))

clean:
	@-rm -rf $(PATH_TO_BUILD)
