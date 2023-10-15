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
 *  Known issues (TODO):
 *  
 */

//TODO: Future implementation!
//#include <stdio.h>

#include "LovagSoC.h"
#include "SPI.h"
#include "UART.h"
#include "Motor.h"
#include "DRV8305.h"
#include "ADC120IPT.h"

volatile uint32_t milis_count = 0;

/**
 * @brief The main function.
 * 
 * @return int 
 */
int main(void)
{
    milis_count = CPU_Time();
    GPIO->DIR.reg16 = 0xFFFFu;

    Motor_Init();
    SPI_Init();
    DRV8305_Init();

    DRV8305_ErrorClear();

    while(DRV8305_Read(DRV8305_WNWR) != 0);

    Motor_DutyCycleSetter(50u);

    DRV8305_Enable();
    Motor_Start();

    while(1)
    {
        if(DRV8305_Read(DRV8305_WNWR) != 0)
        {
            UART_SendString("Undervoltage!\n\r");
            DRV8305_Disable();
            Motor_Stop();
        }
        else
        {
            DRV8305_Enable();
            if(Motor_Running())
            {
                Motor_Stop();
                UART_SendString("Stopped.\n\r");
            }
            else if(Motor_Stalled())
            {
                Motor_ClearError();
                //TODO: Future implementation!
                //printf("Printf works!\n\r");
                UART_SendString("Stalled. Restarting. \n\r");
            }
            else 
            {
                Motor_Start();
                UART_SendString("Started.\n\r");
            }
        }

        while((milis_count + 3000) != CPU_Time())
        {
            GPIO->STATE.reg16 = CPU_Time();
        }
        milis_count = CPU_Time();
        
        GPIO->STATE.reg16 = ADC120_Read(ADC120_Channel3);
    }

    return 0;
}
