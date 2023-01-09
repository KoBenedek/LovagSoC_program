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

int main(void)
{
    SPI_Init();
    SPI_SetConfig(Config_ADC120);

    while(1)
    {
        SPI_ChipSelect(SPI_CS1);
        SPI_Tx_16bit(3 << 11);
        GPIO->PORT0.reg16 = SPI_Tx_16bit(0);
        SPI_ChipDeselect(SPI_CS1);
    }

    return 0;
}
