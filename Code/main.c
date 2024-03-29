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

#include <stdio.h>

#include "LovagSoC.h"
#include "SPI.h"
#include "UART.h"
#include "Motor.h"
#include "DRV8305.h"
#include "ADC120IPT.h"

#define LOVAGSOC_LOGO                                           \
"\x1b[36m""\n\r  _                            _____        _____ \n\r"    \
" | |                          / ____|      / ____|\n\r"        \
" | |     _____   ____ _  __ _| (___   ___ | |     \n\r"        \
" | |    / _ \\ \\ / / _` |/ _` |\\___ \\ / _ \\| |     \n\r"   \
" | |___| (_) \\ V / (_| | (_| |____) | (_) | |____ \n\r"       \
" |______\\___/ \\_/ \\__,_|\\__, |_____/ \\___/ \\_____|\n\r"  \
"                         __/ |                    \n\r"        \
"                        |___/                     \n\r""\x1b[0m"

uint32_t milis_count = 0;
uint32_t successful_startups = 0;
uint32_t startup_attempts = 0;
float    success_rate = 0;
uint32_t uart_tx_cnt = 0;
uint32_t spi_tx_cnt = 0;
uint8_t  tim_triggered = 0;

/**
 * @brief The main function.
 * 
 * @return int 
 */
int main(void)
{
    UART_Init();
    Motor_Init();
    SPI_Init();
    DRV8305_Init();
    ADC120_Init();

    UART_SendString(LOVAGSOC_LOGO);
    printf("Version: v%d.%d%d.\n\n\r", 
            (int)((CPU_READ_CSR(CSR_mImpID) >> 16) & 0xFF), 
            (int)((CPU_READ_CSR(CSR_mImpID) >> 8) & 0xFF), 
            (int)(CPU_READ_CSR(CSR_mImpID) & 0xFF));

    GPIO->DIR.reg16 = 0xFFFFu;

    PLIC->IPR5.reg = 1u;
    PLIC->IE.bit.IE5 = 1u;
    GPT->IR.bit.OVFIE = 1u;
    GPT->ARR.reg = 10000u;
    GPT->PSC.reg = 10000u;

    DRV8305_ErrorClear();

    while(DRV8305_Read(DRV8305_WNWR) != 0);

    GPT->CTRL.bit.EN = 1u;

    Motor_DutyCycleSetter(50u);

    DRV8305_Enable();
    Motor_Start();
    startup_attempts++;

    while(1)
    {
        if(DRV8305_Read(DRV8305_WNWR) != 0)
        {
            UART_SendString("Undervoltage!");
            DRV8305_Disable();
            Motor_Stop();
        }
        else
        {
            DRV8305_Enable();
            if(Motor_Running() & !Motor_Stalled())
            {
                Motor_Stop();
                successful_startups++;
            }
            else if(Motor_Stalled())
            {
                Motor_ClearError();
                startup_attempts++;
            }
            else 
            {
                Motor_Start();
                startup_attempts++;
            }
        }
        
        success_rate = (float)(100 * successful_startups) / (float)startup_attempts;
        if(Motor_Running())
        {
            printf("\x1b[A");
            printf("\33[2K");
            printf("\rStartup success rate is %d,%d percent.\n", (int)success_rate, (int)((success_rate - (int)success_rate) * 1000));
            printf("\33[2K");
            printf("\rNumber of TX frames: UART: %d, SPI: %d.\n", (int)uart_tx_cnt, (int)spi_tx_cnt);
            printf("\x1b[A");
        }

        while(!tim_triggered)
        {
            GPIO->STATE.reg16 = CPU_Time();
        }
        tim_triggered = 0;
        
        GPIO->STATE.reg16 = ADC120_Read(ADC120_Channel3);
    }

    return 0;
}

__attribute__ ((interrupt ("machine"))) void UART_IRQHandler(void)
{
    UART->IR.bit.TXIP = 1u;
    uart_tx_cnt++;
}

__attribute__ ((interrupt ("machine"))) void SPI_IRQHandler(void)
{
    SPI->IR.bit.TXIP = 1u;
    spi_tx_cnt++;
}

__attribute__ ((interrupt ("machine"))) void MotVez_IRQHandler(void)
{
    MOTVEZ->IR.bit.STALLIP = 1u;
    printf("\x1B[31m""\tSTALL""\x1b[0m");
}

__attribute__ ((interrupt ("machine"))) void GPT_IRQHandler(void)
{
    GPT->IR.bit.OVFIP = 1u;
    tim_triggered = 1;
}
