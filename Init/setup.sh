#!/bin/bash
#
#  Copyright (C) 2023 Benedek Kocsis
#
#  File name:      setup.sh
#  Company:        University of Miskolc
#  Department:     Department of Automation and Infocommunication
#  Author:         Benedek Kocsis
#
#  Title:          Setup script
#  
#  Description:    Shell script to setup the elf2hex file and the necessary 
#                  libfemto library.
#

cd ..
git clone https://github.com/michaeljclark/riscv-probe.git

retval=$(($?))

if [ $retval -eq 0 ]
then
    cd LovagSoC_program
    cp -a ../riscv-probe/libfemto ./Code/libfemto
    rm ./Code/libfemto/std/putchar.c
    cp ./Init/putchar.c ./Code/libfemto/std/putchar.c
    cd ..
    rm -r -f riscv-probe
else
    exit 1
fi

git clone https://github.com/sifive/elf2hex.git

retval=$(($?))

if [ $retval -eq 0 ]
then
    cp ./elf2hex/freedom-elf2hex.sh ./LovagSoC_program/Device/Utility/elf2hex
    chmod +x ./LovagSoC_program/Device/Utility/elf2hex
    oldstuff="@OBJCOPY@"
    newstuff="/opt/riscv/bin/riscv64-unknown-elf-objcopy"
    sed -i "s|$oldstuff|$newstuff|g" LovagSoC_program/Device/Utility/elf2hex
    oldstuff="@BIN2HEX@"
    newstuff="/usr/local/bin/riscv64-unknown-elf-bin2hex"
    sed -i "s|$oldstuff|$newstuff|g" LovagSoC_program/Device/Utility/elf2hex
    rm -r -f elf2hex
    exit 0
else
    exit 1
fi

exit 0