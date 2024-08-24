/*
 * DIO_init.h
 *
 *  Created on: May 5, 2023
 *      Author: User
 */

#ifndef DIO_INIT_H_
#define DIO_INIT_H_
//APIS for module

#include "erorSTATE.h"
#include "stdTypes.h"
//PORTS ID
#define DIO_u8PORTA   0
#define DIO_u8PORTB   1
#define DIO_u8PORTC   2
#define DIO_u8PORTD   3

//PINES ID
#define DIO_u8PIN0    0
#define DIO_u8PIN1    1
#define DIO_u8PIN2    2
#define DIO_u8PIN3    3
#define DIO_u8PIN4    4
#define DIO_u8PIN5    5
#define DIO_u8PIN6    6
#define DIO_u8PIN7    7

#define DIO_u8INPUT       0
#define DIO_u8OUTPUT      1

#define DIO_u8FLOAT       0
#define DIO_u8PULL_UP     1

#define DIO_u8LOW         0
#define DIO_u8HIGH        1

ES_t DIO_enuinit(void);

ES_t DIO_enuSetPortDirection(u8 Copy_u8PortID,u8 Copy_u8PortValue);

ES_t DIO_enuSetPortValue(u8 Copy_u8PortID,u8 Copy_u8PortValue);

ES_t DIO_enuGetPortValue(u8 Copy_u8PortID,u8 *Copy_pu8PortValue);

ES_t DIO_enuToglePortValue(u8 Copy_u8PortID);

ES_t DIO_enuSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8pinID,u8 Copy_u8PinValue);

ES_t DIO_enuSetPinValue(u8 Copy_u8PortID,u8 Copy_u8pinID,u8 Copy_u8PinValue);

ES_t DIO_enuGetPinValue(u8 Copy_u8PortID,u8 Copy_u8pinID,u8 *Copy_pu8PinValue);

ES_t DIO_enuToglePinValue(u8 Copy_u8PortID,u8 Copy_u8pinID);




#endif /* DIO_INIT_H_ */
