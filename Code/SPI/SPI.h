/**
 *  Copyright (C) 2023 Benedek Kocsis
 *
 *  File name:      SPI.h
 *  Company:        University of Miskolc
 *  Department:     Department of Automation and Infocommunication
 *  Author:         Benedek Kocsis
 *
 *  Title:          SPI header
 *  
 *  Description:    Header containing definitions for SPI.c.
 */

#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    SPI_CS1 = 1,
    SPI_CS2 = 2
} SPIChipSel_t;

typedef enum
{
    Config_ADC120 = 0,
    Config_DRV8305 = 1
} SPIConfig_t;

void        SPI_Init(void);
void        SPI_SetConfig(SPIConfig_t NewConfig);

uint8_t     SPI_Tx_8bit(uint8_t TxData);
uint16_t    SPI_Tx_16bit(uint16_t TxData);
uint32_t    SPI_Tx_32bit(uint32_t TxData);

void        SPI_ChipSelect(SPIChipSel_t CSLine);
void        SPI_ChipDeselect(SPIChipSel_t CSLine);

#endif /* SPI_H_ */
