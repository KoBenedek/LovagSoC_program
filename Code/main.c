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
#include "UART.h"
#include "Motor.h"
#include "DRV8305.h"
#include "ADC120IPT.h"

void ElsoFuggveny(uint16_t count);

/**
 * @brief The main function.
 * 
 * @return int 
 */
int main(void)
{
    GPIO->DIR.reg16 = 0xFFFFu;

    Motor_Init();
    SPI_Init();
    DRV8305_Init();

    DRV8305_ErrorClear();

    while(DRV8305_Read(DRV8305_WNWR) != 0);

    Motor_DutyCycleSetter(30u);

    DRV8305_Enable();
    Motor_Start();

    while(1)
    {
        if(DRV8305_Read(DRV8305_WNWR) != 0)
        {
            UART_SendString("Error!\n\r");
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
            else 
            {
                Motor_Start();
                UART_SendString("Started.\n\r");
            }
        }
        for (uint8_t i = 0; i < 2; i++)
        {
            ElsoFuggveny(65535);
        }
        GPIO->STATE.reg16 = ADC120_Read(ADC120_Channel3);
    }

    return 0;
}

void ElsoFuggveny(uint16_t count)
{
    for (volatile uint32_t i = 0; i < 16; i++)
    {
        volatile uint16_t delay_cnt = 0;
        for (volatile uint16_t j = 0; j < count; j++)
        {
            delay_cnt++;
        }
    }
}
