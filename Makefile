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
ASMC = riscv64-unknown-elf-as
#C compiler command
CC = riscv64-unknown-elf-gcc
#Linker command
LD = riscv64-unknown-elf-ld
#Generate outputs command
OBJCOPY = riscv64-unknown-elf-objcopy
#Data dump command
OBJDUMP = riscv64-unknown-elf-objdump
#Tool to convert .elf to .hex
ELF2HEX = elf2hex
#Name of the linker script
ASM_LINKER = linker
#Memory map
MAP = $(OUTPUT).map

ASMCFLAGS = -march=rv32i -mabi=ilp32 
CCFLAGS = -march=rv32i -mabi=ilp32 $(INCS) -g -O0 -no-pie -Wall -funsigned-char
LDFLAGS = -lgcc -m elf32lriscv -Map=$(PATH_TO_BUILD)/$(MAP) --print-memory-usage
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

INCS += 								\
	-I ./Device							\
	-I ./Code/SPI						\
	-I ./Code/UART						\
	-I ./Code/DRV8305					\
	-I ./Code/ADC120IPT					\
	-I ./Code/Motor						\
	-I ./Code/libfemto/include			\
	-I ./Code/libfemto/std

SRCS +=									\
	main.c								\
	SPI/SPI.c							\
	UART/UART.c							\
	DRV8305/DRV8305.c					\
	ADC120IPT/ADC120IPT.c				\
	Motor/Motor.c						\
	libfemto/std/printf.c				\
	libfemto/std/vprintf.c				\
	libfemto/std/vsnprintf.c			\
	libfemto/std/putchar.c

OUTPUT = LovagSoC_program

ASM_OBJ = $(addprefix $(PATH_TO_STARTUP)/, $(subst .S,.o, $(STARTUP)))

OBJS = $(addprefix $(PATH_TO_SRCS)/, $(subst .c,.o, $(SRCS)))

OBJS += $(PATH_TO_STARTUP)/LovagSoC.o

build: directory $(OUTPUT).elf $(OUTPUT)_objview.txt  remove-temp $(OUTPUT).bin $(OUTPUT)_ihex.hex $(OUTPUT).v $(OUTPUT).hex $(OUTPUT)_elfview.txt
	@echo Build complete.

directory:
	@mkdir -p $(PATH_TO_BUILD)

$(OBJS):
	@$(CC) $(CCFLAGS) $(subst .o,.c,$@) -r -o $(PATH_TO_OBJS)/$(notdir $@)

$(ASM_OBJ):
	@$(ASMC) $(ASMCFLAGS) $(subst .o,.S,$@) -o $(PATH_TO_OBJS)/$(notdir $@)

OBJS_PATH = $(addprefix $(PATH_TO_OBJS)/, $(notdir $(OBJS)))
ASM_OBJ_PATH = $(addprefix $(PATH_TO_OBJS)/, $(notdir $(ASM_OBJ)))

$(OUTPUT).elf: $(ASM_OBJ) $(OBJS) directory
	@$(LD) -L/opt/riscv/lib/gcc/riscv64-unknown-elf/12.2.0/rv32i/ilp32 $(ASM_OBJ_PATH) $(OBJS_PATH) -o $(PATH_TO_BUILD)/$@ -T $(PATH_TO_LD)/$(ASM_LINKER).ld $(LDFLAGS)

$(OUTPUT).bin: $(OUTPUT).elf
	@$(OBJCOPY) $(PATH_TO_BUILD)/$(OUTPUT).elf $(PATH_TO_BUILD)/$@ -O binary

$(OUTPUT)_ihex.hex: $(OUTPUT).elf
	@$(OBJCOPY) $(PATH_TO_BUILD)/$(OUTPUT).elf $(PATH_TO_BUILD)/$@ -O ihex

$(OUTPUT).v: $(OUTPUT).elf
	@$(OBJCOPY) $(PATH_TO_BUILD)/$(OUTPUT).elf $(PATH_TO_BUILD)/$@ -O verilog

$(OUTPUT).hex: $(OUTPUT).elf
	@$(PATH_TO_E2H)/$(ELF2HEX) $(E2HFLAGS) --input $(PATH_TO_BUILD)/$(OUTPUT).elf --output $(PATH_TO_BUILD)/$@

$(OUTPUT)_objview.txt: $(ASM_OBJ) $(OBJS)
	@$(OBJDUMP) -S $(ASM_OBJ_PATH) $(OBJS_PATH) > $(PATH_TO_BUILD)/$@

$(OUTPUT)_elfview.txt: $(OUTPUT).elf
	@$(OBJDUMP) -S $(PATH_TO_BUILD)/$(OUTPUT).elf > $(PATH_TO_BUILD)/$@

program: erase
	@python3 upload_prog.py program

read:
	@python3 upload_prog.py read 4096 read_code.txt

erase:
	@python3 upload_prog.py erase 4096

remove-temp:
	@-rm $(OBJS_PATH)
	@-rm $(ASM_OBJ_PATH)

clean:
	@-rm -rf $(PATH_TO_BUILD)
