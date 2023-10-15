/**
 *  Copyright (C) 2023 Benedek Kocsis
 *
 *  File name:      LovagSoC.c
 *  Company:        University of Miskolc
 *  Department:     Department of Automation and Infocommunication
 *  Author:         Benedek Kocsis
 *
 *  Title:          LovagSoC
 *  
 *  Description:    Source file for LovagSoC CPU functions.
 */

#include "LovagSoC.h"

uint32_t CPU_Time(void)
{
   uint32_t time;
   __asm__ volatile ("csrr    %0, time" : "=r" (time) : : );
   return time;
}

uint32_t CPU_Cycle(void)
{
   uint32_t cycle;
   __asm__ volatile ("csrr    %0, cycle" : "=r" (cycle) : : );
   return cycle;
}

uint32_t CPU_InstRet(void)
{
   uint32_t instret;
   __asm__ volatile ("csrr    %0, instret" : "=r" (instret) : : );
   return instret;
}
