/*
 * KPD_LT_prog.c
 *
 *  Created on: May 28, 2023
 *      Author: User
 */


#include "stdTypes.h"
#include "erorSTATE.h"
#include <util/delay.h>

#include "KPAD_int.h"

#include "KPAD_config.h"

#include  "KPAD_priv.h"

#include "DIO_init.h"

extern u8 KPAD_Au8PadKeys[KPD_ROW_NUM][KPD_COLOM_NUM];
extern KPAD_t KPAD_AstrKeyPadConfig[NUM_OF_KEPAD];

ES_t KPAD_enuInit(KPAD_t* Copy_pstrKeyPadConfig)
{
	ES_t Local_enuErorState =ES_NOK;
	if(Copy_pstrKeyPadConfig!=NULL)
	{
		ES_t Local_enuErorState =ES_OK;
		 u8 Local_u8Etrator1;
		 u8 Local_u8Etrator2;
		 for(Local_u8Etrator2=0;Local_u8Etrator2<NUM_OF_KEPAD;Local_u8Etrator2++)
		 {
			for(Local_u8Etrator1=0;Local_u8Etrator1<KPD_ROW_NUM;Local_u8Etrator1++)
			{
				Local_enuErorState =DIO_enuSetPinDirection(KPAD_AstrKeyPadConfig[Local_u8Etrator2].KPAD_strRows[Local_u8Etrator1].Row_u8Port,KPAD_AstrKeyPadConfig[Local_u8Etrator2].KPAD_strRows[Local_u8Etrator1].Row_u8Pin,DIO_u8INPUT);
				Local_enuErorState =DIO_enuSetPinValue(KPAD_AstrKeyPadConfig[Local_u8Etrator2].KPAD_strRows[Local_u8Etrator1].Row_u8Port,KPAD_AstrKeyPadConfig[Local_u8Etrator2].KPAD_strRows[Local_u8Etrator1].Row_u8Pin,DIO_u8PULL_UP);
			}
			for(Local_u8Etrator1=0;Local_u8Etrator1<KPD_COLOM_NUM;Local_u8Etrator1++)
			{
				Local_enuErorState =DIO_enuSetPinDirection(KPAD_AstrKeyPadConfig[Local_u8Etrator2].KPAD_strCol[Local_u8Etrator1].Col_u8Port,KPAD_AstrKeyPadConfig[Local_u8Etrator2].KPAD_strCol[Local_u8Etrator1].Col_u8Pin,DIO_u8OUTPUT);
				Local_enuErorState =DIO_enuSetPinValue(KPAD_AstrKeyPadConfig[Local_u8Etrator2].KPAD_strCol[Local_u8Etrator1].Col_u8Port,KPAD_AstrKeyPadConfig[Local_u8Etrator2].KPAD_strCol[Local_u8Etrator1].Col_u8Pin,DIO_u8HIGH);
			}

		 }

	}
	else
	{
		Local_enuErorState =ES_NULL_POINTER;
	}
	   return Local_enuErorState;
}
ES_t KPAD_enuGetPressedKey(KPAD_t* Copy_pstrKeyPadConfig, u8* Copy_pu8Value)
{
	ES_t Local_enuErorState =ES_NOK;

	if(Copy_pstrKeyPadConfig!=NULL ||
			Copy_pu8Value!=NULL	)
	{

		ES_t Local_enuErorState =ES_OK;
		*Copy_pu8Value = 0;
		u8 Local_u8RowsIterator, Local_u8ColsIterator, Local_u8GetKey;
		for(Local_u8ColsIterator=0;Local_u8ColsIterator<KPD_COLOM_NUM;Local_u8ColsIterator++)
{
			Local_enuErorState=DIO_enuSetPinValue(Copy_pstrKeyPadConfig->KPAD_strCol[Local_u8ColsIterator].Col_u8Port,Copy_pstrKeyPadConfig->KPAD_strCol[Local_u8ColsIterator].Col_u8Pin,DIO_u8LOW);
		for(Local_u8RowsIterator=0;Local_u8RowsIterator<KPD_ROW_NUM;Local_u8RowsIterator++)
		{
			Local_enuErorState=DIO_enuGetPinValue(Copy_pstrKeyPadConfig->KPAD_strRows[Local_u8RowsIterator].Row_u8Port,Copy_pstrKeyPadConfig->KPAD_strRows[Local_u8RowsIterator].Row_u8Pin,&Local_u8GetKey);
			if(!Local_u8GetKey)
			{
					_delay_ms(50);
					while(!Local_u8GetKey){
						Local_enuErorState=DIO_enuGetPinValue(Copy_pstrKeyPadConfig->KPAD_strRows[Local_u8RowsIterator].Row_u8Port,Copy_pstrKeyPadConfig->KPAD_strRows[Local_u8RowsIterator].Row_u8Pin,&Local_u8GetKey);
			}
			*Copy_pu8Value=KPAD_Au8PadKeys[KPD_ROW_NUM][KPD_COLOM_NUM];
			break;

		}
		}
		Local_enuErorState=DIO_enuSetPinValue(Copy_pstrKeyPadConfig->KPAD_strCol[Local_u8ColsIterator].Col_u8Port,Copy_pstrKeyPadConfig->KPAD_strCol[Local_u8ColsIterator].Col_u8Pin,DIO_u8LOW);
}

	}
	else
	{
		Local_enuErorState =ES_NULL_POINTER;
	}
	 return Local_enuErorState;
}
