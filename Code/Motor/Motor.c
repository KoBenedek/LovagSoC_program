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

/*
 *    PIN20   -   n FPGA Pmod inverter enable pin
 */

#include "Motor.h"
#include "LovagSoC.h"

/**
 * @brief Initialises the motor module and MotVez peripheral with set parameters.
 * 
 */
void Motor_Init(void)
{
    GPIO->DIR.bit.PIN20 = 1u;

    //Disable the inverter circuit.
    GPIO->STATE.bit.PIN20 = 1u;

    MOTVEZ->CCONR1.bit.MOT_EN = 0u;

    MOTVEZ->CCONR1.bit.COAST_LOCK_CNT = 2u;
    MOTVEZ->CCONR2.bit.COMM_TIM_PSC = 20u;
    MOTVEZ->CCONR2.bit.DEMAG_PERIOD = 4u;
    MOTVEZ->OLRR1.bit.OL_RAMP_CONST = 4u;
    MOTVEZ->OLRR1.bit.OL_RAMP_FINAL = 4000u;
    MOTVEZ->OLRR2.bit.OL_RAMP_START = 20000u;
    MOTVEZ->OLRR3.bit.COAST_LOCK_PR = 15000u;
    MOTVEZ->PDR.bit.BEMF_FILT_CYCLES = 10u;
    MOTVEZ->PDR.bit.BEMF_FILT_EN = 1u;
    MOTVEZ->PDR.bit.DEMAG_EN = 0u;
    MOTVEZ->PDR.bit.PWM_SYNC = 2u;
    MOTVEZ->PWMCR.bit.PWM_DC = 40u;
    MOTVEZ->PWMCR.bit.PWM_INT_GEN = 1u;
    MOTVEZ->PWMCR.bit.PWM_TIM_PSC = 5u;

    MOTVEZ->SDR1.bit.STOP_ON_STALL = 1u;
    MOTVEZ->SDR1.bit.STALL_DET_EN = 3u;
    MOTVEZ->SDR1.bit.MIN_COMM_PR = 146u;
    MOTVEZ->SDR2.bit.MAX_COMM_PR = 0xFFFEu;

    MOTVEZ->OCR.bit.HS_O_POL = 1u;
    MOTVEZ->OCR.bit.LS_O_POL = 1u;
    MOTVEZ->OCR.bit.HIGH_Z_O = 0u;

    //Enable the inverter circuit.
    GPIO->STATE.bit.PIN20 = 0u;
}

/**
 * @brief Prompts the MotVez peripheral to execute motor startup.
 * 
 */
void Motor_Start(void) { MOTVEZ->CCONR1.bit.MOT_EN = 1u; }

/**
 * @brief Prompts the MotVez peripheral to stop the motor.
 * 
 */
void Motor_Stop(void) { MOTVEZ->CCONR1.bit.MOT_EN = 0u;}

/**
 * @brief Checks whether or not the motor is running.
 * 
 * @return true 
 * @return false 
 */
bool Motor_Running(void)
{ 
    return (MOTVEZ->CCONR1.bit.MOT_EN && !MOTVEZ->SDR1.bit.MOT_STALLED);
}

/**
 * @brief Clears the motor stalled status.
 * 
 */
void Motor_ClearError(void)
{
    bool StatusSave = MOTVEZ->CCONR1.bit.MOT_EN;
    MOTVEZ->CCONR1.bit.MOT_EN = 0u;
    MOTVEZ->CCONR1.bit.MOT_EN = StatusSave;
}

/**
 * @brief Returns the motor stall status.
 * 
 * @return true 
 * @return false 
 */
bool Motor_Stalled(void) { return MOTVEZ->SDR1.bit.MOT_STALLED; }

/**
 * @brief Sets the duty cycle of the inverter power stage.
 * 
 * @param duty_cycle 
 */
void Motor_DutyCycleSetter(uint16_t duty_cycle)
{
    if(0x1FF < duty_cycle) duty_cycle = 0x1FF;
    MOTVEZ->PWMCR.bit.PWM_DC = duty_cycle;
}

/**
 * @brief Reads the commutational sector time of the motor.
 * 
 * @return uint16_t 
 */
uint16_t Motor_PeriodGetter(void)
{
    if(Motor_Running()) return MOTVEZ->ZC_PR.bit.ZC_PD;
    else return 0xFFFF;
}
