/**
 *  Copyright (C) 2023 Benedek Kocsis
 *
 *  File name:      LovagSoC.h
 *  Company:        University of Miskolc
 *  Department:     Department of Automation and Infocommunication
 *  Author:         Benedek Kocsis
 *
 *  Title:          LovagSoC device header file
 *  
 *  Description:    Header file containing the device register definitions for the LovagSoC.
 */

#ifndef LovagSoC_H_
#define LovagSoC_H_

#include <stdint.h>

/* following defines should be used for structure members */
#ifndef __IM
 #define __IM     volatile const      /*! Defines 'read only' structure member permissions */
#endif

#ifndef __OM
 #define __OM     volatile            /*! Defines 'write only' structure member permissions */
#endif

#ifndef __IOM
 #define __IOM    volatile            /*! Defines 'read / write' structure member permissions */
#endif

typedef struct
{
	union
	{
		__IOM uint16_t reg;

		struct
		{
			__IOM uint16_t BEMF_FILT_CYCLES	: 7;
			__IOM uint16_t BEMF_FILT_EN		: 1;
            __IOM uint16_t PWM_SYNC         : 2;
            __IOM uint16_t DEMAG_EN         : 1;
            __IOM uint16_t MASK_EN          : 1;
            __IM  uint16_t POS_PTRN         : 3;
            __IOM uint16_t HALL_EN          : 1;
		} bit;
	} PDR;

	union
	{
		__IM uint16_t reg;

		struct 
		{
			__IM uint16_t ZC_PD			 	: 16;
		} bit;
	} ZC_PR;

	union
	{
		__IOM uint16_t reg;

		struct
		{
				  uint16_t					: 6;
			__IOM uint16_t COAST_LOCK_CNT	: 5;
                  uint16_t                  : 1;
            __IOM uint16_t SYNC_MOT_MODE    : 1;
            __IOM uint16_t MOT_BREAK        : 1;
            __IOM uint16_t MOT_DIR          : 1;
            __IOM uint16_t MOT_EN           : 1;
		} bit;
	} CCONR1;

	union
	{
		__IOM uint16_t reg;

		struct
		{
			__IOM uint16_t BREAK_LENGTH		: 5;
            __IOM uint16_t COMM_TIM_PSC    	: 8;
            __IOM uint16_t DEMAG_PERIOD     : 3;
		} bit;
	} CCONR2;

    union
	{
		__IOM uint16_t reg;

		struct
		{
            __IOM uint16_t OL_RAMP_FINAL    : 13;
            __IOM uint16_t OL_RAMP_CONST    : 3;
		} bit;
	} OLRR1;

    union
	{
		__IOM uint16_t reg;

		struct
		{
            __IOM uint16_t OL_RAMP_START    : 16;
		} bit;
	} OLRR2;

	union
	{
		__IOM uint16_t reg;

		struct
		{
            __IOM uint16_t COAST_LOCK_PR    : 16;
		} bit;
	} OLRR3;

	union
	{
		__IOM uint16_t reg;

		struct
		{
			__IOM uint16_t PWM_DC			: 9;
			__IOM uint16_t PWM_TIM_PSC		: 6;
			__IOM uint16_t PWM_INT_GEN		: 1;
		} bit;
	} PWMCR;

	union
	{
		__IOM uint16_t reg;

		struct
		{
				  uint16_t					: 9;
			__IOM uint16_t FET_STATES		: 6;
			__IOM uint16_t FET_ATOMIC_SET	: 1;
		} bit;
	} OCR;

} MotVez_Typedef;

typedef struct
{
    union
    {
		__IOM uint32_t reg32;
        __IOM uint16_t reg16;

        struct
        {
            __IOM uint32_t PIN0			: 1;
            __IOM uint32_t PIN1			: 1;
            __IOM uint32_t PIN2			: 1;
            __IOM uint32_t PIN3			: 1;
            __IOM uint32_t PIN4			: 1;
            __IOM uint32_t PIN5			: 1;
            __IOM uint32_t PIN6			: 1;
            __IOM uint32_t PIN7			: 1;
            __IOM uint32_t PIN8			: 1;
            __IOM uint32_t PIN9			: 1;
            __IOM uint32_t PIN10		: 1;
            __IOM uint32_t PIN11		: 1;
            __IOM uint32_t PIN12		: 1;
            __IOM uint32_t PIN13		: 1;
            __IOM uint32_t PIN14		: 1;
            __IOM uint32_t PIN15		: 1;
            __IOM uint32_t PIN16		: 1;
            __IOM uint32_t PIN17		: 1;
            __IOM uint32_t PIN18		: 1;
            __IOM uint32_t PIN19		: 1;
            __IOM uint32_t PIN20		: 1;
            __IOM uint32_t PIN21		: 1;
            __IOM uint32_t PIN22		: 1;
            __IOM uint32_t PIN23		: 1;
            __IOM uint32_t PIN24		: 1;
            __IOM uint32_t PIN25		: 1;
            __IOM uint32_t PIN26		: 1;
            __IOM uint32_t PIN27		: 1;
            __IOM uint32_t PIN28		: 1;
            __IOM uint32_t PIN29		: 1;
            __IOM uint32_t PIN30		: 1;
            __IOM uint32_t PIN31		: 1;
        } bit;
    } STATE;

    union
    {
		__IOM uint32_t reg32;
        __IOM uint16_t reg16;

        struct
        {
            __IOM uint32_t PIN0			: 1;
            __IOM uint32_t PIN1			: 1;
            __IOM uint32_t PIN2			: 1;
            __IOM uint32_t PIN3			: 1;
            __IOM uint32_t PIN4			: 1;
            __IOM uint32_t PIN5			: 1;
            __IOM uint32_t PIN6			: 1;
            __IOM uint32_t PIN7			: 1;
            __IOM uint32_t PIN8			: 1;
            __IOM uint32_t PIN9			: 1;
            __IOM uint32_t PIN10		: 1;
            __IOM uint32_t PIN11		: 1;
            __IOM uint32_t PIN12		: 1;
            __IOM uint32_t PIN13		: 1;
            __IOM uint32_t PIN14		: 1;
            __IOM uint32_t PIN15		: 1;
            __IOM uint32_t PIN16		: 1;
            __IOM uint32_t PIN17		: 1;
            __IOM uint32_t PIN18		: 1;
            __IOM uint32_t PIN19		: 1;
            __IOM uint32_t PIN20		: 1;
            __IOM uint32_t PIN21		: 1;
            __IOM uint32_t PIN22		: 1;
            __IOM uint32_t PIN23		: 1;
            __IOM uint32_t PIN24		: 1;
            __IOM uint32_t PIN25		: 1;
            __IOM uint32_t PIN26		: 1;
            __IOM uint32_t PIN27		: 1;
            __IOM uint32_t PIN28		: 1;
            __IOM uint32_t PIN29		: 1;
            __IOM uint32_t PIN30		: 1;
            __IOM uint32_t PIN31		: 1;
        } bit;
    } DIR;
} GPIO_Typedef;

typedef struct
{
    union
    {
        __IOM uint16_t reg;

        struct
        {
                  uint16_t			    : 5;
            __IOM uint16_t ALT_CFG      : 1;
            __IM  uint16_t BUSY 		: 1;
            __IOM uint16_t CLK_PSC      : 7;
            __IOM uint16_t POL          : 1;
            __IOM uint16_t PHA          : 1;
        } bit;
    } CTRL;

    union
    {
        __IOM uint32_t reg32;
        __IOM uint16_t reg16;
        __IOM uint8_t  reg8;
    } DAT;
} SPI_Typedef;

typedef struct
{
    union
    {
        __IOM uint16_t reg;

        struct
        {
                  uint16_t              : 8;
            __IOM uint16_t STOPB        : 1;
            __IOM uint16_t PAR          : 2;
            __IOM uint16_t DAT_BITS     : 3;
            __IM  uint16_t BUSY         : 1;
            __IM  uint16_t DAT_RDY      : 1;
        } bit;
    } CTRL;

    union
    {
        __IOM uint16_t reg;

        struct
        {
            __IOM uint16_t CLK_PSC      : 16;
        } bit;
    } PSCR;

    union
    {
        __IOM uint16_t reg;

        struct
        {
            __IOM uint16_t DAT          : 16;
        } bit;
    } DAT;
} UART_Typedef;

#define MOTVEZ_BASE 0x2002U
#define GPIO_BASE   0x2080U
#define SPI_BASE    0x2088U
#define UART_BASE   0x2090U

#define MOTVEZ      ((MotVez_Typedef*)MOTVEZ_BASE)
#define GPIO        ((GPIO_Typedef*)GPIO_BASE)
#define SPI         ((SPI_Typedef*)SPI_BASE)
#define UART        ((UART_Typedef*)UART_BASE)

#endif /* LovagSoC_H_ */
