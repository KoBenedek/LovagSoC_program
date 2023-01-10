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
#include "Motor.h"
#include "DRV8305.h"
#include "ADC120IPT.h"

void ElsoFuggveny(void);

int main(void)
{
    Motor_Init();
    SPI_Init();
    DRV8305_Init();

    DRV8305_ErrorClear();

    while(DRV8305_Read(DRV8305_WNWR)->WNWR.bit.FAULT == true);

    Motor_DutyCycleSetter(30u);

    DRV8305_Enable();
    Motor_Start();

    while(1)
    {
        if(DRV8305_Read(DRV8305_WNWR)->WNWR.bit.PVDD_UVFL == true)
        {
            DRV8305_Disable();
            Motor_Stop();
        }
        else
        {
            DRV8305_Enable();
            if(Motor_Running()) Motor_Stop();
            else Motor_Start();
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
