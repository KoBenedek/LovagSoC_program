#	Copyright (C) 2023 Benedek Kocsis
#
#   File name:      LovagSoC_startup.S
#   Company:        University of Miskolc
#   Department:     Department of Automation and Infocommunication
#   Author:         Benedek Kocsis
#
#   Description:    LovagSoC startup file.

.text
.global _start
.type _start, @function

_start:

     li   sp,0x2000

# zero-init bss section:
     la a0, _sbss
     la a1, _ebss
     bge a0, a1, end_init_bss
loop_init_bss:
     sw zero, 0(a0)
     addi a0, a0, 4
     blt a0, a1, loop_init_bss
end_init_bss:

     call main
     ebreak
