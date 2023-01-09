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
    } PORT0;
} GPIO_Typedef;

typedef struct
{
    union
    {
        __IOM uint16_t reg;

        struct
        {
                  uint16_t			    : 6;
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

#define GPIO_BASE   0x1080U
#define SPI_BASE    0x1084U

#define GPIO        ((GPIO_Typedef*)GPIO_BASE)
#define SPI         ((SPI_Typedef*)SPI_BASE)

#endif /* LovagSoC_H_ */
