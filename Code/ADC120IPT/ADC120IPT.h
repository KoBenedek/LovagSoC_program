/**
 *  Copyright (C) 2022 Benedek Kocsis
 *
 *  File name:      ADC120IPT.h
 *  Company:        University of Miskolc
 *  Department:     Department of Automation and Infocommunication
 *  Author:         Benedek Kocsis
 *  
 *  Description:    Code for specifically ADC120IPT AD converter
 *                  chip related definitions and function prototypes.
 */

#ifndef ADC120IPT_H_
#define ADC120IPT_H_

#include <stdint.h>
#include <stdbool.h>
#include "ADC120IPTRegisters.h"
#include "SPI.h"

#define ADC120_ADDRESS_Pos  11

void ADC120_Init(void);

uint16_t ADC120_Read(ADC120_Address_t Address);
void ADC120_ReadAll(uint16_t *DataArray);
void ADC120_ReadSequence(uint16_t *DataArray, ADC120_Address_t *SequenceArray, uint8_t SequenceLength);

#endif /* ADC120IPT_H_ */
