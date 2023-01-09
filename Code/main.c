/**
 *  Copyright (C) 2023 Benedek Kocsis
 *
 *  File name:      main.c
 *  Company:        University of Miskolc
 *  Department:     Department of Automation and Infocommunication
 *  Author:         Benedek Kocsis
 *
 *  Title:          Main
 *  
 */

#include "LovagSoC.h"
#include "SPI.h"
#include "DRV8305.h"
#include "ADC120IPT.h"

int main(void)
{
    SPI_Init();
    DRV8305_Init();

    while(1)
    {
        GPIO->PORT0.reg16 = ADC120_Read(ADC120_Channel4);
        DRV8305->SACR.bit.GAIN_CS1 = 1u;
        DRV8305_Update(DRV8305_SACR);
    }

    return 0;
}
