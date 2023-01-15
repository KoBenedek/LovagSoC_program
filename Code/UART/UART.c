/**
 *  Copyright (C) 2023 Benedek Kocsis
 *
 *  File name:      UART.c
 *  Company:        University of Miskolc
 *  Department:     Department of Automation and Infocommunication
 *  Author:         Benedek Kocsis
 *
 *  Title:          UART
 *  
 *  Description:    Source file for UART functions.
 */

/*
 *  clk_psc     |   baud rate
 *      54      |   115207
 *      648     |   9641
 */

#include "UART.h"
#include "LovagSoC.h"

void UART_Init(void)
{
    UART->CTRL.bit.PAR = 0u;
    UART->CTRL.bit.STOPB = 0u;
    UART->CTRL.bit.DAT_BITS = 3u;
    UART->PSCR.bit.CLK_PSC = 54u; /** TODO: hardware bug probably... */

    /** TODO: This doesnt work??? hardware bug... */
    //UART->CTRL.bit.DAT_BITS = 3u;
    //UART->CTRL.bit.PAR = 0u;
    //UART->CTRL.bit.STOPB = 0u;
    //UART->PSCR.reg = 648u;
}

void UART_tx(uint8_t data)
{
    while(UART->CTRL.bit.BUSY);
    UART->DAT.bit.DAT = data;
    while(UART->CTRL.bit.BUSY);
}

uint8_t UART_rx_blocking(void)
{
    while(!UART->CTRL.bit.DAT_RDY);
    return UART->DAT.bit.DAT;
}

uint8_t UART_rx_nonblocking(void)
{
    if(UART->CTRL.bit.DAT_RDY) { return UART->DAT.bit.DAT; }
    else { return 0; }
}

void UART_SendString(char* data)
{
    while(*data) {UART_tx((uint8_t)(*data++));}
}

bool UART_busy(void) { return UART->CTRL.bit.BUSY; }

bool UART_data_ready(void) { return UART->CTRL.bit.DAT_RDY; }