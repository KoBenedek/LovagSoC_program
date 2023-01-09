/**
 *  Copyright (C) 2022 Benedek Kocsis
 *
 *  File name:      ADC120IPTRegisters.h
 *  Company:        University of Miskolc
 *  Department:     Department of Automation and Infocommunication
 *  Author:         Benedek Kocsis
 *  
 *  Description:    Code for specifically ADC120IPT AD converter
 *                  chip related channel addressing definitions.
 */

#ifndef ADC120IPTRegisters_H_
#define ADC120IPTRegisters_H_

#include "stdint.h"

/**
 * ADC120IPT register addresses
 */
typedef enum
{
    ADC120_Channel1 = 0,
    ADC120_Channel2 = 1,
    ADC120_Channel3 = 2,
    ADC120_Channel4 = 3,
    ADC120_Channel5 = 4,
    ADC120_Channel6 = 5,
    ADC120_Channel7 = 6,
    ADC120_Channel8 = 7,
} ADC120_Address_t;

#endif /* ADC120IPTRegisters_H_ */
