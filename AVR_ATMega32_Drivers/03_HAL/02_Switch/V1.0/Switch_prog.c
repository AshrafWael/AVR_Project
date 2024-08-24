/*
 * Switch_prog.c
 *
 *  Created on: May 6, 2023
 *      Author: User
 */
#include "stdTypes.h"
#include "erorSTATE.h"

#include "Switch_priv.h"
#include "Switch_config.h"

#include "DIO_init.h"

ES_t Switch_enuinit(SW_t * Copy_AstrSwitches)
{
	ES_t Local_enuErrorState=ES_NOK;
		if(Copy_AstrSwitches !=NULL)
		{
			u8 Local_u8etretor =0;
			for(Local_u8etretor=0;Local_u8etretor<SW_NUM;Local_u8etretor++)
			{
				Local_enuErrorState=DIO_enuSetPinDirection(Copy_AstrSwitches[Local_u8etretor].SW_PortID,Copy_AstrSwitches[Local_u8etretor].SW_PinID,DIO_u8INPUT);
				Local_enuErrorState=DIO_enuSetPinValue(Copy_AstrSwitches[Local_u8etretor].SW_PortID,Copy_AstrSwitches[Local_u8etretor].SW_PinID,Copy_AstrSwitches[Local_u8etretor].SW_Status);

			}
		}
		else
		{
			Local_enuErrorState=ES_NULL_POINTER;
		}
	return Local_enuErrorState;
}

ES_t Switch_enuGetState(SW_t * Copy_AstrSwitches, u8 *Copy_pu8SwitchState)
{
	ES_t Local_enuErrorState=ES_NOK;
		if(Copy_AstrSwitches !=NULL &&
				Copy_pu8SwitchState!=NULL)
		{
			Local_enuErrorState=DIO_enuGetPinValue(Copy_AstrSwitches->SW_PortID,Copy_AstrSwitches->SW_PinID,Copy_pu8SwitchState);

		}
		else
		{
			Local_enuErrorState=ES_NULL_POINTER;
		}

		return Local_enuErrorState;

}


