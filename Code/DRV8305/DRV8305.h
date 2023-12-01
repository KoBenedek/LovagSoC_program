/**
 *  Copyright (C) 2022 Benedek Kocsis
 *
 *  File name:      DRV8305.h
 *  Company:        University of Miskolc
 *  Department:     Department of Automation and Infocommunication
 *  Author:         Benedek Kocsis
 *  
 *  Description:    Code containing function prototypes and definitions
 *                  for the DRV8305 FET driver IC.
 */

#ifndef DRV8305_H_
#define DRV8305_H_

#include <stdint.h>
#include <stdbool.h>
#include "DRV8305Registers.h"
#include "SPI.h"

#define DRV8305_RW_BIT_Pos      15
#define DRV8305_ADDRESS_Pos     11

#define DRV8305		((DRV8305_Typedef *)(&DRV8305_Device))

typedef enum
{
    DRV_CSA1 = 0,
    DRV_CSA2 = 1,
    DRV_CSA3 = 2
} DRV8305_CSA_t;

typedef enum
{
    Gain_10VV = 0,
    Gain_20VV = 1,
    Gain_40VV = 2,
    Gain_80VV = 3
} DRV8305_CSA_Gain_t;

static volatile DRV8305_Typedef DRV8305_Device;

void DRV8305_Init(void);
void DRV8305_Enable(void);
void DRV8305_Disable(void);
bool DRV8305_Enabled(void);
bool DRV8305_IsError(void);
void DRV8305_ErrorClear(void);

uint16_t DRV8305_Read(DRV8305_Address_t Address);
uint16_t DRV8305_Write(DRV8305_Address_t Address, uint16_t Data);

void DRV8305_SetCSAGain(DRV8305_CSA_t CSA, DRV8305_CSA_Gain_t Gain);
void DRV8305_Update(DRV8305_Address_t Address);

#endif /* DRV8305_H_ */
