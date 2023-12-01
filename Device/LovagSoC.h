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
			__IOM uint16_t MASK_EN			: 1;
            __IM  uint16_t POS_PTRN         : 3;
            __IOM uint16_t HALL_EN          : 1;
		} bit;
	} PDR;

	union
	{
		__IOM uint16_t reg;

		struct
		{
				  uint16_t					: 6;
			__IOM uint16_t STALLIP			: 1;
			__IOM uint16_t CLOCKIP			: 1;
			__IOM uint16_t OLRIP			: 1;
			__IOM uint16_t COMMIP			: 1;
			__IOM uint16_t POSIP			: 1;
			__IOM uint16_t STALLIE			: 1;
			__IOM uint16_t CLOCKIE			: 1;
			__IOM uint16_t OLRIE			: 1;
			__IOM uint16_t COMMIE			: 1;
			__IOM uint16_t POSIE			: 1;
		} bit;
    } IR;

	__IM uint16_t RESERVED_1[6];

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
            __IOM uint16_t EN_CTRL_MOT_EN   : 1;
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
			      uint16_t					: 1;
			__IOM uint16_t MIN_COMM_PR		: 11;
			__IOM uint16_t STALL_DET_EN		: 2;
			__IM  uint16_t MOT_STALLED		: 1;
			__IOM uint16_t STOP_ON_STALL	: 1;
		} bit;
	} SDR1;

	union
	{
		__IOM uint16_t reg;

		struct
		{
			__IOM uint16_t MAX_COMM_PR		: 16;
		} bit;
	} SDR2;

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

	__IM uint16_t RESERVED_2[7];

	union
	{
		__IOM uint16_t reg;

		struct
		{
				  uint16_t					: 5;
			__IOM uint16_t HIGH_Z_O			: 1;
			__IOM uint16_t LS_O_POL			: 1;
			__IOM uint16_t HS_O_POL			: 1;
				  uint16_t					: 1;
			__IOM uint16_t FET_STATES		: 6;
			__IOM uint16_t FET_ATOMIC_SET	: 1;
		} bit;
	} OCR;

	__IM uint16_t RESERVED_3[7];

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
    } REIE;

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
    } FEIE;

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
    } IRP;
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
        __IOM uint16_t reg;

        struct
        {
                  uint16_t              : 14;
            __IOM uint16_t TXIP         : 1;
            __IOM uint16_t TXIE         : 1;
        } bit;
    } IR;

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

	__IM uint16_t RESERVED_4[1];

    union
    {
        __IOM uint16_t reg;

        struct
        {
                  uint16_t              : 12;
            __IOM uint16_t TXIP         : 1;
            __IOM uint16_t RXIP         : 1;
            __IOM uint16_t TXIE         : 1;
            __IOM uint16_t RXIE         : 1;
        } bit;
    } IR;
} UART_Typedef;

typedef struct
{
	__IM uint32_t RESERVED_5[1];

    union
    {
        __IOM uint32_t reg;

        struct
        {
            __IOM uint32_t IPR1         : 4;
                  uint32_t              : 28;
        } bit;
    } IPR1;

    union
    {
        __IOM uint32_t reg;

        struct
        {
            __IOM uint32_t IPR2         : 4;
                  uint32_t              : 28;
        } bit;
    } IPR2;
    
    union
    {
        __IOM uint32_t reg;

        struct
        {
            __IOM uint32_t IPR3         : 4;
                  uint32_t              : 28;
        } bit;
    } IPR3;
    
    union
    {
        __IOM uint32_t reg;

        struct
        {
            __IOM uint32_t IPR4         : 4;
                  uint32_t              : 28;
        } bit;
    } IPR4;
    
    union
    {
        __IOM uint32_t reg;

        struct
        {
            __IOM uint32_t IPR5         : 4;
                  uint32_t              : 28;
        } bit;
    } IPR5;

    union
    {
        __IM  uint32_t reg;

        struct
        {
                  uint32_t              : 1;
            __IM  uint32_t IP1          : 1;
            __IM  uint32_t IP2          : 1;
            __IM  uint32_t IP3          : 1;
            __IM  uint32_t IP4          : 1;
            __IM  uint32_t IP5          : 1;
                  uint32_t              : 26;
        } bit;
    } IPB;

    union
    {
        __IOM uint32_t reg;

        struct
        {
                  uint32_t              : 1;
            __IOM uint32_t IE1          : 1;
            __IOM uint32_t IE2          : 1;
            __IOM uint32_t IE3          : 1;
            __IOM uint32_t IE4          : 1;
            __IOM uint32_t IE5          : 1;
                  uint32_t              : 26;
        } bit;
    } IE;
    
    union
    {
        __IOM uint32_t reg;

        struct
        {
            __IOM uint32_t ITH         : 32;
        } bit;
    } ITH;

	__IM uint32_t RESERVED_6[1];
} PLIC_Typedef;

typedef struct
{
    union
    {
        __IOM uint16_t reg;

        struct
        {
                  uint16_t              : 14;
            __IOM uint16_t RST          : 1;
            __IOM uint16_t EN           : 1;
        } bit;
    } CTRL;

    union
    {
        __IOM uint16_t reg;

        struct
        {
            __IOM uint16_t PSC          : 16;
        } bit;
    } PSC;

    union
    {
        __IOM uint16_t reg;

        struct
        {
            __IOM uint16_t ARR          : 16;
        } bit;
    } ARR;

    union
    {
        __IOM uint16_t reg;

        struct
        {
            __IOM uint16_t CNT          : 16;
        } bit;
    } CNT;

    union
    {
        __IOM uint16_t reg;

        struct
        {
            __IOM uint16_t CMP          : 16;
        } bit;
    } CMP;

    union
    {
        __IOM uint16_t reg;

        struct
        {
                  uint16_t              : 12;
            __IOM uint16_t OVFIP        : 1;
            __IOM uint16_t CMIP         : 1;
            __IOM uint16_t OVFIE        : 1;
            __IOM uint16_t CMIE         : 1;
        } bit;
    } IR;
} GPT_Typedef;

#define MOTVEZ_BASE 0x10000U
#define GPIO_BASE   0x10400U
#define SPI_BASE    0x10800U
#define UART_BASE   0x10C00U
#define PLIC_BASE   0x11000U
#define GPT_BASE    0x11400U

#define MOTVEZ      ((MotVez_Typedef*)MOTVEZ_BASE)
#define GPIO        ((GPIO_Typedef*)GPIO_BASE)
#define SPI         ((SPI_Typedef*)SPI_BASE)
#define UART        ((UART_Typedef*)UART_BASE)
#define PLIC        ((PLIC_Typedef*)PLIC_BASE)
#define GPT         ((GPT_Typedef*)GPT_BASE)

#define CPU_READ_CSR(address)     ({uint32_t data; __asm__ volatile ("csrr    %0, %1" : "=r" (data) : "n" (address) : ); data;})

typedef enum
{
    CSR_Cycle = 0xC00,
    CSR_Time = 0xC01,
    CSR_InstRet = 0xC02,
    CSR_mImpID = 0xF13
} CSR_t;

uint32_t CPU_ReadCSR(CSR_t address);
uint32_t CPU_Time(void);
uint32_t CPU_Cycle(void);
uint32_t CPU_InstRet(void);

#endif /* LovagSoC_H_ */
