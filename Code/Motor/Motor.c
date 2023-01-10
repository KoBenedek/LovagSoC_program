/**
 *  Copyright (C) 2023 Benedek Kocsis
 *
 *  File name:      Motor.c
 *  Company:        University of Miskolc
 *  Department:     Department of Automation and Infocommunication
 *  Author:         Benedek Kocsis
 *
 *  Title:          Motor module
 *  
 *  Description:    Source file containing the motor related functions.
 */

#include "Motor.h"
#include "LovagSoC.h"

/**
 * @brief 
 * 
 */
void Motor_Init(void)
{
    //Disable the inverter circuit.
    GPIO->PORT0.bit.PIN20 = 1u;

    //Needs to be set to 0 otherwise the motor spins immediately op power-up.
    MOTVEZ->CCONR1.bit.EN_CTRL_MOT_EN = 0u; 
    MOTVEZ->CCONR1.bit.MOT_EN = 0u;

    MOTVEZ->CCONR1.bit.COAST_LOCK_CNT = 10u;
    MOTVEZ->CCONR2.bit.COMM_TIM_PSC = 20u;
    MOTVEZ->CCONR2.bit.DEMAG_PERIOD = 3u;
    MOTVEZ->OLRR1.bit.OL_RAMP_CONST = 4u;
    MOTVEZ->OLRR1.bit.OL_RAMP_FINAL = 3000u;
    MOTVEZ->OLRR2.bit.OL_RAMP_START = 60000u;
    MOTVEZ->OLRR3.bit.COAST_LOCK_PR = 4000u;
    MOTVEZ->PDR.bit.BEMF_FILT_CYCLES = 10u;
    MOTVEZ->PDR.bit.BEMF_FILT_EN = 1u;
    MOTVEZ->PDR.bit.DEMAG_EN = 0u;
    MOTVEZ->PDR.bit.PWM_SYNC = 0u;
    MOTVEZ->PWMCR.bit.PWM_DC = 40u;
    MOTVEZ->PWMCR.bit.PWM_INT_GEN = 1u;
    MOTVEZ->PWMCR.bit.PWM_TIM_PSC = 5u;

    //Enable the inverter circuit.
    GPIO->PORT0.bit.PIN20 = 0u;
}

/**
 * @brief 
 * 
 */
void Motor_Start(void) { MOTVEZ->CCONR1.bit.MOT_EN = 1u; }

/**
 * @brief 
 * 
 */
void Motor_Stop(void) { MOTVEZ->CCONR1.bit.MOT_EN = 0u;}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Motor_Running(void) { return MOTVEZ->CCONR1.bit.MOT_EN; } //Not sufficient if motor stalls!

/**
 * @brief 
 * 
 * @param duty_cycle 
 */
void Motor_DutyCycleSetter(uint16_t duty_cycle)
{
    if(0x1FF < duty_cycle) duty_cycle = 0x1FF;
    MOTVEZ->PWMCR.bit.PWM_DC = duty_cycle;
}

/**
 * @brief 
 * 
 * @return uint16_t 
 */
uint16_t Motor_PeriodGetter(void)
{
    if(Motor_Running()) return MOTVEZ->ZC_PR.bit.ZC_PD;
    else return 0xFFFF;
}
