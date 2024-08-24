/*
 * KPAD_config.c
 *
 *  Created on: Jul 8, 2023
 *      Author: User
 */

#include "stdTypes.h"
#include "erorSTATE.h"

#include "DIO_init.h"

#include "KPAD_config.h"

KPAD_t KPAD_AstrKeyPadConfig[NUM_OF_KEPAD]=
{
		{
		{
		      {DIO_u8PORTC,DIO_u8PIN0},
			  {DIO_u8PORTC,DIO_u8PIN1},
			  {DIO_u8PORTC,DIO_u8PIN2},
			  {DIO_u8PORTC,DIO_u8PIN3}
		},
		{
			  {DIO_u8PORTC,DIO_u8PIN4},
			  {DIO_u8PORTC,DIO_u8PIN5},
			  {DIO_u8PORTC,DIO_u8PIN6},
			  {DIO_u8PORTC,DIO_u8PIN7}

		}
		}
};
