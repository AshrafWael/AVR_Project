/*
 * Seven_segment_config.c
 *
 *  Created on: May 11, 2023
 *      Author: User
 */
#include "stdTypes.h"
#include "erorSTATE.h"

#include "DIO_init.h"

#include "Seven_segment_config.h"
#include "Seven_segment_priv.h"



SEG_t SEG_AstrSevenSegmentConfig [SEG_NUM]={
		{   DIO_u8PORTA,DIO_u8PIN3,//pin a
			DIO_u8PORTB,DIO_u8PIN4,//pin d
			DIO_u8PORTB,DIO_u8PIN0,//pin c
			DIO_u8PORTC,DIO_u8PIN5,//pin d
			DIO_u8PORTD,DIO_u8PIN2,//pin e
			DIO_u8PORTD,DIO_u8PIN1,//pin f
			DIO_u8PORTA,DIO_u8PIN6,//pin g
			NOT_CONECTED,NOT_CONECTED,
			NOT_CONECTED,NOT_CONECTED,
			COMMON_CATHOD,
		},//seg 0

	 	 {       DIO_u8PORTA , DIO_u8PIN1 , //pin a
				 DIO_u8PORTB , DIO_u8PIN6 , //pin b
				 DIO_u8PORTC , DIO_u8PIN4 , //pin c
				 DIO_u8PORTA , DIO_u8PIN5 , //pin d
				 DIO_u8PORTC , DIO_u8PIN7 , //pin e
				 DIO_u8PORTD , DIO_u8PIN5 , //pin f
				 DIO_u8PORTA , DIO_u8PIN4 , //pin g
				 NOT_CONECTED , NOT_CONECTED , //pin cmn
				 NOT_CONECTED , NOT_CONECTED , //pin dot
				 COMMON_ANOD //type
				} // seg 1

};

