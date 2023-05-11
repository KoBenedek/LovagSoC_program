/**
 *  Copyright (C) 2023 Benedek Kocsis
 *
 *  File name:      Motor.h
 *  Company:        University of Miskolc
 *  Department:     Department of Automation and Infocommunication
 *  Author:         Benedek Kocsis
 *
 *  Title:          Motor module header
 *  
 *  Description:    Header containing declaration of motor related functions.
 */

#ifndef Motor_H_
#define Motor_H_

#include <stdbool.h>
#include <stdint.h>

void Motor_Init(void);
void Motor_Start(void);
void Motor_Stop(void);
bool Motor_Running(void);
bool Motor_Stalled(void);
void Motor_ClearError(void);
void Motor_DutyCycleSetter(uint16_t duty_cycle);
uint16_t Motor_PeriodGetter(void);

#endif /* Motor_H_ */
