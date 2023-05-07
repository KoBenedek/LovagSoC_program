/**
 *  Copyright (C) 2023 Benedek Kocsis
 *
 *  File name:      SPI.c
 *  Company:        University of Miskolc
 *  Department:     Department of Automation and Infocommunication
 *  Author:         Benedek Kocsis
 *
 *  Title:          SPI module
 *  
 *  Description:    Code containing SPI related functions.
 */

#include "SPI.h"
#include "LovagSoC.h"

/**
 * @brief Initialises SPI peripheral parameters and IO.
 * 
 */
void SPI_Init(void)
{
	GPIO->DIR.bit.PIN16 = 1u;
	GPIO->DIR.bit.PIN17 = 1u;

    SPI_ChipDeselect(SPI_CS1);
    SPI_ChipDeselect(SPI_CS2);

	//Set the config for ADC120.
	SPI->CTRL.bit.ALT_CFG = 0u;
	SPI->CTRL.bit.PHA = 0u;
	SPI->CTRL.bit.POL = 0u;
	SPI->CTRL.bit.CLK_PSC = 4u;

	//Set the config for DRV8305.
	SPI->CTRL.bit.ALT_CFG = 1u;
	SPI->CTRL.bit.PHA = 1u;
	SPI->CTRL.bit.POL = 0u;
	SPI->CTRL.bit.CLK_PSC = 50u;

	SPI->CTRL.bit.ALT_CFG = 0u;
}

/**
 * @brief Sets the selected SPI configuration.
 * 
 * @param NewConfig 
 */
void SPI_SetConfig(SPIConfig_t NewConfig)
{
	SPI->CTRL.bit.ALT_CFG = (uint8_t)NewConfig;
}

/**
 * @brief Transmits a data packet of 8 bits.
 * 
 * @param TxData 
 * @return uint8_t 
 */
uint8_t SPI_tx_8bit(uint8_t TxData)
{
	SPI->DAT.reg8 = TxData;
	while(SPI->CTRL.bit.BUSY);
	return SPI->DAT.reg8;
}

/**
 * @brief Transmits a data packet of 16 bits.
 * 
 * @param TxData 
 * @return uint16_t 
 */
uint16_t SPI_tx_16bit(uint16_t TxData)
{
	SPI->DAT.reg16 = TxData;
	while(SPI->CTRL.bit.BUSY);
	return SPI->DAT.reg16;
}

/**
 * @brief Transmits a data packet of 32 bits.
 * 
 * @param TxData 
 * @return uint32_t 
 */
uint32_t SPI_tx_32bit(uint32_t TxData)
{
	SPI->DAT.reg32 = TxData;
	while(SPI->CTRL.bit.BUSY);
	return SPI->DAT.reg32;
}

/**
 * @brief Activates the selected chip-select IO.
 * 
 * @param CSLine 
 */
void SPI_ChipSelect(SPIChipSel_t CSLine)
{
	switch (CSLine)
	{
	case SPI_CS1:
		GPIO->STATE.bit.PIN16 = 0u;
	break;

	case SPI_CS2:
		GPIO->STATE.bit.PIN17 = 0u;
	break;
	
	default:
		break;
	}
}

/**
 * @brief Deactivates the selected chip-select IO.
 * 
 * @param CSLine 
 */
void SPI_ChipDeselect(SPIChipSel_t CSLine)
{
    switch (CSLine)
	{

	case SPI_CS1:
		GPIO->STATE.bit.PIN16 = 1u;
	break;

	case SPI_CS2:
		GPIO->STATE.bit.PIN17 = 1u;
	break;
	
	default:
		break;
	}
}
