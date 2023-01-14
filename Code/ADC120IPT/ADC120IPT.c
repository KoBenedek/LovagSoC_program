/**
 *  Copyright (C) 2022 Benedek Kocsis
 *
 *  File name:      ADC120IPT.c
 *  Company:        University of Miskolc
 *  Department:     Department of Automation and Infocommunication
 *  Author:         Benedek Kocsis
 *  
 *  Description:    Code for specifically ADC120IPT AD converter
 *                  chip related functions.
 */

#include "ADC120IPT.h"

/**
 * @brief Executes the initialisation of the ADC120 chip.
 * 
 */
void ADC120_Init(void)
{
    
}

/**
 * @brief Read the specified ADC channel by sending the corresponding address.
 * 
 * @param Address 
 * @return uint16_t 
 */
uint16_t ADC120_Read(ADC120_Address_t Address)
{
    uint16_t RetVal = 0;
    uint16_t TxData = 0;

    SPI_SetConfig(Config_ADC120);

    TxData |= ((uint16_t)Address) << ADC120_ADDRESS_Pos;

    SPI_ChipSelect(SPI_CS2);

    SPI_tx_16bit(TxData);
    RetVal = SPI_tx_16bit(0);

    SPI_ChipDeselect(SPI_CS2);

    return RetVal;
}

/**
 * @brief Read all of the ADC channels.
 * 
 * @param DataArray 
 */
void ADC120_ReadAll(uint16_t *DataArray)
{
    uint16_t TxData = 0;

    SPI_SetConfig(Config_ADC120);

    SPI_ChipSelect(SPI_CS2);

    for (ADC120_Address_t Address = ADC120_Channel2; Address < (ADC120_Channel8 + 2); Address++)
    {
        TxData = ((uint16_t)Address) << ADC120_ADDRESS_Pos;
        *DataArray++ = SPI_tx_16bit(TxData);
    }

    SPI_ChipDeselect(SPI_CS2);
}

/**
 * @brief Read a given number of channels in a given sequence.
 * 
 * @param DataArray 
 * @param SequenceArray 
 * @param SequenceLength 
 */
void ADC120_ReadSequence(uint16_t *DataArray, ADC120_Address_t *SequenceArray, uint8_t SequenceLength)
{
    uint16_t TxData = 0;
    uint8_t Index = 0;

    SPI_SetConfig(Config_ADC120);

    SPI_ChipSelect(SPI_CS2);

    TxData = ((uint16_t)(*SequenceArray++)) << ADC120_ADDRESS_Pos;

    if(ADC120_Channel1 == *SequenceArray--)
    {
        *DataArray++ = SPI_tx_16bit(TxData);
        Index++;
    }
    else
    {
        SPI_tx_16bit(TxData);
    }

    while (Index < SequenceLength)
    {
        TxData = ((uint16_t)(*SequenceArray++)) << ADC120_ADDRESS_Pos;
        *DataArray++ = SPI_tx_16bit(TxData);;
        Index++;
    }

    SPI_ChipDeselect(SPI_CS2);
}
