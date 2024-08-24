/*
 * UART_int.h
 *
 *  Created on: May 5, 2023
 *      Author: Ashraf
 */

#ifndef INT_PRIV_H_
#define UART_PRIV_H_


ES_t UART_enuInit(void);

ES_t UART_enuSendChar(u8 Copy_u8Data);

ES_t UART_enuReciveChar(u8 *Copy_pu8Data);

ES_t UART_enuSendString( const char *Copy_pu8Data);

ES_t UART_enuReciveString(char *Copy_pu8Data);

#endif