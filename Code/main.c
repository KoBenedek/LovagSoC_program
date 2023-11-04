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
    printf("Version: development v%d.%d%d.\n\r", 
            (int)((CPU_READ_CSR(CSR_mImpID) >> 16) & 0xFF), 
            (int)((CPU_READ_CSR(CSR_mImpID) >> 8) & 0xFF), 
            (int)(CPU_READ_CSR(CSR_mImpID) & 0xFF));

    milis_count = CPU_Time();
    GPIO->DIR.reg16 = 0xFFFFu;

    DRV8305_ErrorClear();

    while(DRV8305_Read(DRV8305_WNWR) != 0);

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
            printf("\33[2K");
            printf("\rStartup success rate is %d,%d percent.", (int)success_rate, (int)((success_rate - (int)success_rate) * 1000));
        }

        while((milis_count + 1000) != CPU_Time())
        {
            GPIO->STATE.reg16 = CPU_Time();
        }
        milis_count = CPU_Time();
        
        GPIO->STATE.reg16 = ADC120_Read(ADC120_Channel3);
    }

    return 0;
}
