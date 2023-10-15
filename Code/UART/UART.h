/**
 *  Copyright (C) 2023 Benedek Kocsis
 *
 *  File name:      UART.h
 *  Company:        University of Miskolc
 *  Department:     Department of Automation and Infocommunication
 *  Author:         Benedek Kocsis
 *
 *  Title:          UART module
 *  
 *  Description:    Header containing declarations and definitions for the UART module.
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

void UART_Init(void);
void UART_tx(uint8_t data);
uint8_t UART_rx_blocking(void);
uint8_t UART_rx_nonblocking(void);
bool UART_busy(void);
bool UART_data_ready(void);
void UART_SendString(char* data);

#endif /* UART_H_ */
