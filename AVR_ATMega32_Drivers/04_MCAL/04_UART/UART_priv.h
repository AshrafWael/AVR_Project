/*
 * UART_priv.h
 *
 *  Created on: May 5, 2023
 *      Author: Ashraf
 */

#ifndef UART_PRIV_H_
#define UART_PRIV_H_

#define UDR       *((volatile uint8 *) 0x2C)
#define UCSRA     *((volatile uint8 *) 0x2B)
#define UCSRB     *((volatile uint8 *) 0x2A)
#define UBRRL     *((volatile uint8 *) 0x29)
#define UCSRC     *((volatile uint8 *) 0x40)
#define UBRRH     *((volatile uint8 *) 0x40)








#endif