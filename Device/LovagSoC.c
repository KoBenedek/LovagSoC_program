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
   return CPU_READ_CSR(CSR_Time);
}

uint32_t CPU_Cycle(void)
{
   return CPU_READ_CSR(CSR_Cycle);
}

uint32_t CPU_InstRet(void)
{
   return CPU_READ_CSR(CSR_InstRet);
}
