/*
 * LED_config.c
 *
 *  Created on: May 7, 2023
 *      Author: User
 */

#include "stdTypes.h"
#include "erorSTATE.h"

#include "DIO_init.h"

#include "LED_config.h"
#include "LED_priv.h"
LED_t LED_AstrLedConfig[LED_NUM]={
		{DIO_u8PORTA,DIO_u8PIN5,LED_SINK,LED_OFF},
		{DIO_u8PORTB,DIO_u8PIN4,LED_SOURCE,LED_ON},
		{DIO_u8PORTC,DIO_u8PIN2,LED_SOURCE,LED_OFF}
};
