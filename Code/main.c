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

void ElsoFuggveny(void);

int main(void)
{
    MOTVEZ->CCONR1.bit.MOT_EN = 0u;
    GPIO->PORT0.bit.PIN20 = false;
    GPIO->PORT0.bit.PIN18 = false;
    GPIO->PORT0.bit.PIN18 = true;
    GPIO->PORT0.bit.PIN18 = false;
    SPI_Init();
    DRV8305_Init();
    while(DRV8305->WNWR.bit.FAULT == true)
    {
        DRV8305_Read(DRV8305_WNWR);
    }
    GPIO->PORT0.bit.PIN18 = true;
    MOTVEZ->CCONR1.bit.MOT_EN = 1u;

    while(1)
    {
        GPIO->PORT0.bit.PIN0 = MOTVEZ->CCONR1.bit.MOT_EN;
        if(DRV8305_Read(DRV8305_WNWR)->WNWR.bit.PVDD_UVFL == true)
        {
            GPIO->PORT0.bit.PIN18 = false;
            MOTVEZ->CCONR1.bit.MOT_EN = 0u;
        }
        else
        {
            GPIO->PORT0.bit.PIN18 = true;
            MOTVEZ->CCONR1.bit.MOT_EN = ~MOTVEZ->CCONR1.bit.MOT_EN;
            
        }
        for (uint8_t i = 0; i < 2; i++)
        {
            ElsoFuggveny();
        }
    }

    return 0;
}

void ElsoFuggveny(void)
{
    for (volatile uint32_t i = 0; i < 16; i++)
    {
        volatile uint16_t delay_cnt = 0;
        for (volatile uint16_t j = 0; j < 65535; j++)
        {
            delay_cnt++;
        }
        
        GPIO->PORT0.reg16 = 1 << i;
    }
}
