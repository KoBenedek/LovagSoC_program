#	Copyright (C) 2023 Benedek Kocsis
#
#   File name:      LovagSoC_startup.S
#   Company:        University of Miskolc
#   Department:     Department of Automation and Infocommunication
#   Author:         Benedek Kocsis
#
#   Description:    LovagSoC startup file.

.section .text

.globl LovagSoC_startup

startup:
    li sp, 1024
    call main
    ebreak
