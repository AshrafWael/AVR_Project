/*
 * KPD_prog.c
 *
 *  Created on: May 19, 2023
 *      Author: Ashraf
 */
#include "stdTypes.h"
#include "erorSTATE.h"

#include "DIO_init.h"

#include "KPD_int.h"
#include "KPD_priv.h"
#include "KPD_config.h"

ES_t KPD_enuInt(void)
{
	u8 Local_ErrorState =ES_NOK;

	DIO_enuSetPinDirection(KPD_COLOM0_PORT,KPD_COLOM0_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(KPD_COLOM1_PORT,KPD_COLOM1_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(KPD_COLOM2_PORT,KPD_COLOM2_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(KPD_COLOM3_PORT,KPD_COLOM3_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinValue(KPD_COLOM0_PORT,KPD_COLOM0_PIN,DIO_u8HIGH);
	DIO_enuSetPinValue(KPD_COLOM1_PORT,KPD_COLOM1_PIN,DIO_u8HIGH);
	DIO_enuSetPinValue(KPD_COLOM2_PORT,KPD_COLOM2_PIN,DIO_u8HIGH);
	DIO_enuSetPinValue(KPD_COLOM3_PORT,KPD_COLOM3_PIN,DIO_u8HIGH);

	DIO_enuSetPinDirection(KPD_ROW0_PORT,KPD_ROW0_PIN,DIO_u8INPUT);
	DIO_enuSetPinDirection(KPD_ROW1_PORT,KPD_ROW1_PIN,DIO_u8INPUT);
	DIO_enuSetPinDirection(KPD_ROW2_PORT,KPD_ROW2_PIN,DIO_u8INPUT);
	DIO_enuSetPinDirection(KPD_ROW3_PORT,KPD_ROW3_PIN,DIO_u8INPUT);
	DIO_enuSetPinValue(KPD_ROW0_PORT,KPD_ROW0_PIN,DIO_u8PULL_UP);
	DIO_enuSetPinValue(KPD_ROW1_PORT,KPD_ROW1_PIN,DIO_u8PULL_UP);
	DIO_enuSetPinValue(KPD_ROW2_PORT,KPD_ROW2_PIN,DIO_u8PULL_UP);
	DIO_enuSetPinValue(KPD_ROW3_PORT,KPD_ROW3_PIN,DIO_u8PULL_UP);

	return Local_ErrorState;
}

ES_t KPD_enuGetPressedKey(u8 *Copy_u8PinValue)
{

	u8 Local_ErrorState =ES_NOK;

	*Copy_u8PinValue=0;

	u8 Local_u8EteratorRowIdx,Local_u8EteratorColomIdx,Local_u8PressedKey, Local_u8PinState;

	 static u8 Local_KPD_Au8SwitchNum[KPD_ROW_NUM][KPD_COLOM_NUM]=KPD_Au8SwitchNum;

	 static u8 Local_KPDColomPortArr[KPD_COLOM_NUM]={KPD_COLOM0_PORT,KPD_COLOM1_PORT,KPD_COLOM2_PORT,KPD_COLOM3_PORT};

	 static u8 Local_KPDRowPortArr[KPD_ROW_NUM]={KPD_ROW0_PORT,KPD_ROW1_PORT,KPD_ROW2_PORT,KPD_ROW3_PORT};

	 static u8 Local_KPDColomPinArr[KPD_COLOM_NUM]={KPD_COLOM0_PIN,KPD_COLOM1_PIN,KPD_COLOM2_PIN,KPD_COLOM3_PIN};

	 static u8 Local_KPDRowPinArr[KPD_ROW_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};

	for(Local_u8EteratorColomIdx=0;Local_u8EteratorColomIdx<KPD_COLOM_NUM;Local_u8EteratorColomIdx++)
	{
		Local_ErrorState =DIO_enuSetPinValue(Local_KPDColomPortArr[Local_u8EteratorColomIdx],Local_KPDColomPinArr[Local_u8EteratorColomIdx],DIO_u8LOW);

	for(Local_u8EteratorRowIdx=0;Local_u8EteratorRowIdx<KPD_ROW_NUM;Local_u8EteratorRowIdx++)
	{
		Local_ErrorState =DIO_enuGetPintValue(Local_KPDRowPortArr[Local_u8EteratorRowIdx],Local_KPDRowPinArr[Local_u8EteratorRowIdx],& Local_u8PinState);

		if(DIO_u8LOW == Local_u8PinState)
		{
			*Copy_u8PinValue=Local_KPD_Au8SwitchNum[Local_u8EteratorRowIdx][Local_u8EteratorColomIdx];
			while(DIO_u8LOW == Local_u8PinState)
			{
				Local_ErrorState =DIO_enuGetPintValue(Local_KPDRowPortArr[Local_u8EteratorRowIdx],Local_KPDRowPinArr[Local_u8EteratorRowIdx],&Local_u8PinState);
			}
			*Copy_u8PinValue=Local_KPD_Au8SwitchNum[Local_u8EteratorRowIdx][Local_u8EteratorColomIdx];
		}

	}
	    DIO_enuSetPinValue(Local_KPDColomPortArr[Local_u8EteratorColomIdx],Local_KPDColomPinArr[Local_u8EteratorColomIdx],DIO_u8HIGH);
	}

	return Local_ErrorState;
}
