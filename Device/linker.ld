/**
 *  Copyright (C) 2023 Benedek Kocsis
 *
 *  File name:      linker.ld
 *  Company:        University of Miskolc
 *  Department:     Department of Automation and Infocommunication
 *  Author:         Benedek Kocsis
 *
 *  Title:          Linker script
 *  
 *  Description:    Linker script for the memory assignment if the test code.
 */

MEMORY
{
   ROM(rx) : ORIGIN = 0x0000, LENGTH = 15360 /* 15kB ROM */
   BRAM(rwx) : ORIGIN = 15360, LENGTH = 1024 /* 1kB RAM */
}
SECTIONS
{
    /* Text section contains the code and read-only data. */
    .text :
    {
        . = ALIGN(4);
        ./Device/LovagSoC_startup.o (.text.VectorTable)
        ./Device/LovagSoC_startup.o (.text.Reset_Handler)
        ./Device/LovagSoC_startup.o (.text.Default_Handler)
        *(.text)
        *(.rodata)
        *(.srodata)
        . = ALIGN(4);
        _etext = .;
    } >ROM

    /* Data section contains variables and runtime generated data. */
    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data)
        *(.sdata)
        . = ALIGN(4);
        _edata = .;
    } >BRAM

    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss)
        *(.sbss)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
    } >BRAM
}
