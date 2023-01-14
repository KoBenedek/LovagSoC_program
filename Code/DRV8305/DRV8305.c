/**
 *  Copyright (C) 2022 Benedek Kocsis
 *
 *  File name:      DRV8305.c
 *  Company:        University of Miskolc
 *  Department:     Department of Automation and Infocommunication
 *  Author:         Benedek Kocsis
 *  
 *  Description:    Code containing functions interfacing the
 *                  DRV8305 FET driver IC.
 */

/*
 *    PIN18   -   DRV8305 Enable pin
 *    PIN21   -   DRV8305 nFault pin
 */

#include "DRV8305.h"
#include "LovagSoC.h"

/**
 * @brief Initialises the DRV8305 internal device image and the necessary IO.
 * 
 */
void DRV8305_Init(void)
{
    GPIO->DIR.bit.PIN18 = 1u;
    GPIO->DIR.bit.PIN21 = 0u;

    DRV8305_Disable();

    DRV8305_Read(DRV8305_WNWR);
    DRV8305_Read(DRV8305_VDSF);
    DRV8305_Read(DRV8305_ICFR);
    DRV8305_Read(DRV8305_VGSF);
    DRV8305_Read(DRV8305_HGDC);
    DRV8305_Read(DRV8305_LGDC);
    DRV8305_Read(DRV8305_GDCR);
    DRV8305_Read(DRV8305_ICOR);
    DRV8305_Read(DRV8305_SACR);
    DRV8305_Read(DRV8305_VRCR);
    DRV8305_Read(DRV8305_VDSS);
}

/**
 * @brief Enables the DRV8305.
 * 
 */
void DRV8305_Enable(void) { GPIO->STATE.bit.PIN18 = 1u; }

/**
 * @brief Disables the DRV8305.
 * 
 */
void DRV8305_Disable(void) { GPIO->STATE.bit.PIN18 = 0u; }

/**
 * @brief Gets whether the DRV8305 is enabled.
 * 
 * @return true 
 * @return false 
 */
bool DRV8305_Enabled(void) { return GPIO->STATE.bit.PIN18; }

/**
 * @brief Gets whether the DRV8305 is signalling an error.
 * 
 * @return true 
 * @return false 
 */
bool DRV8305_IsError(void) { return !GPIO->STATE.bit.PIN21; }

/**
 * @brief Attempts to clear the error signal of the DRV8305.
 * 
 */
void DRV8305_ErrorClear(void)
{
    bool prev_state = DRV8305_Enabled();
    DRV8305_Disable();
    DRV8305_Enable();
    if(false == prev_state)  DRV8305_Disable();
}

/**
 * @brief Read the register values on a given device register address.
 * 
 * @param Address 
 * @return DRV8305_Typedef* 
 */
uint16_t DRV8305_Read(DRV8305_Address_t Address)
{
    uint16_t RetVal = 0;
    uint16_t TxData = 0;

    TxData |= (1 << DRV8305_RW_BIT_Pos) | (((uint16_t)Address) << DRV8305_ADDRESS_Pos);

    SPI_SetConfig(Config_DRV8305);

    SPI_ChipSelect(SPI_CS1);

    RetVal = SPI_tx_16bit(TxData);
    *(&(DRV8305->WNWR.reg) + Address - 1) = RetVal;

    SPI_ChipDeselect(SPI_CS1);

    return RetVal;
}

/**
 * @brief Write values to a given device register address.
 * 
 * @param Address 
 * @param Data 
 * @return uint16_t 
 */
uint16_t DRV8305_Write(DRV8305_Address_t Address, uint16_t Data)
{
    uint16_t RetVal = 0;
    uint16_t TxData = Data;

    TxData |= (0 << DRV8305_RW_BIT_Pos) | (((uint16_t)Address) << DRV8305_ADDRESS_Pos);

    SPI_SetConfig(Config_DRV8305);

    SPI_ChipSelect(SPI_CS1);

    RetVal = SPI_tx_16bit(TxData);

    SPI_ChipDeselect(SPI_CS1);

    return RetVal;
}

/**
 * @brief Set the gain of one of the three current shunt amplifiers of DRV8305.
 * 
 * @param CSA 
 * @param Gain 
 */
void DRV8305_SetCSAGain(DRV8305_CSA_t CSA, DRV8305_CSA_Gain_t Gain)
{
    uint16_t RegData = DRV8305_Read(DRV8305_SACR);

    RegData &= ~(3 << (SACR_GAIN_CS1_Pos + CSA * 2));
    RegData |= Gain << (SACR_GAIN_CS1_Pos + CSA * 2);

    DRV8305_Write(DRV8305_SACR, RegData);
}

/**
 * @brief Writes the struct content of the given register to the device and
 *        updates the struct values based on the data read back.
 * 
 * @param Address 
 */
void DRV8305_Update(DRV8305_Address_t Address)
{
    DRV8305_Write(Address, *(&(DRV8305->WNWR.reg) + Address - 1));
    DRV8305_Read(Address);
}
