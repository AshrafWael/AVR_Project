/*
 * EXTI_prog.c
 *
 *  Created on: Sep 4, 2023
 *      Author: User
 */
#include "stdTypes.h"
#include "erorSTATE.h"

#include "EXTI_priv.h"
#include "EXTI_config.h"
#include "interrupt.h"
/*Global void (pointer to function) and global void (pointer to  parameter)*/
static volatile void (*EXTI_ApfunINTfun[3]) (void*)={NULL,NULL,NULL}; //Array of pointer to function take void pointer contain 3 pointers

void * EXTI_ApvidGenericParameter[3]={NULL,NULL,NULL};//Array of pointer to void parameter of 3 parameter

ES_t EXTI_enuInit(EXTI_t *Copy_PstrEXTIConfig)
{
	ES_t Local_enuerrorState= ES_NOK;
	if(Copy_PstrEXTIConfig!=NULL)
	{
		u8 Local_u8Iterator;
		for(Local_u8Iterator=0;Local_u8Iterator<MAX_NUM_OF_EXTI;Local_u8Iterator++)
		{
			if(Copy_PstrEXTIConfig[Local_u8Iterator].EXTI_u8state==ACTIVE)
			{

				switch(Local_u8Iterator)
				{
			case INT0 :
					GICR |=(1<<6); //Enable intrupt ot INT0
					MCUCR &=~(3<<0);//Mask Bit 0 1  at Sence level reg
					switch(Copy_PstrEXTIConfig[Local_u8Iterator].EXTI_u8senceLevel)
					{
					case  RISING_EDGE:
						MCUCR |=(3<<0);
						break;
					case FALLING_EDGE :
						MCUCR |=(1<<1);  //hINT
						break;
					case NO_CHANGE :
						MCUCR |=(1<<0);
						break;
					case LOW_LEVEL:
						break;
					default:
						Local_enuerrorState= ES_OUT_OF_RANGE;
					}

					break;
			case INT1 :
					GICR |=(1<<7);
					MCUCR &=~(3<<2);//Mask Bit 2 3
					switch(Copy_PstrEXTIConfig[Local_u8Iterator].EXTI_u8senceLevel)
					{
					case  RISING_EDGE:
						MCUCR |=(3<<2);
						break;
					case FALLING_EDGE :
						MCUCR |=(1<<3);
						break;
					case NO_CHANGE :
						MCUCR |=(1<<2);
						break;
					case LOW_LEVEL:
						break;
					default:
						Local_enuerrorState= ES_OUT_OF_RANGE;
					}
					break;
			case INT2 :
					GICR |=(1<<5);
					MCUCSR &=~(1<<6); //Mask Bit 6
					switch(Copy_PstrEXTIConfig[Local_u8Iterator].EXTI_u8senceLevel)
										{
						case  RISING_EDGE:
							MCUCSR |=(1<<6);
							break;
						case FALLING_EDGE :
							break;
						default:
							Local_enuerrorState= ES_OUT_OF_RANGE;
						}
					break;
				}

			}

		}
		Local_enuerrorState= ES_OK;
	}
	else
	{
		Local_enuerrorState= ES_NULL_POINTER;
	}
	return Local_enuerrorState;
}
ES_t EXTI_enuSetSenceMode(u8 Copy_PstrEXTI_ID,u8 Copy_u8SenceLevel)
{
	ES_t Local_enuerrorState= ES_NOK;
     if(Copy_PstrEXTI_ID<MAX_NUM_OF_EXTI)
     {
    	 if(Copy_PstrEXTI_ID == INT0)
    	 {
    		    MCUCR &=~(3<<0);
				switch(Copy_u8SenceLevel)
				{
				case  RISING_EDGE:
					MCUCR |=(3<<0);
					break;
				case FALLING_EDGE :
					MCUCR |=(1<<1);
					break;
				case NO_CHANGE :
					MCUCR |=(1<<0);
					break;
				case LOW_LEVEL:
					break;
				default:
					Local_enuerrorState= ES_OUT_OF_RANGE;
				}
    	 }
    	 else if(Copy_PstrEXTI_ID == INT1)
    	 {
				MCUCR &=~(3<<2);//Mask Bit 2 3
				switch(Copy_u8SenceLevel)
				{
				case  RISING_EDGE:
					MCUCR |=(3<<2);
					break;
				case FALLING_EDGE :
					MCUCR |=(1<<3);
					break;
				case NO_CHANGE :
					MCUCR |=(1<<2);
					break;
				case LOW_LEVEL:
					break;
				default:
					Local_enuerrorState= ES_OUT_OF_RANGE;
				}
    	 }
    	 else if(Copy_PstrEXTI_ID == INT2)
    	 {
				MCUCSR &=~(1<<6); //Mask Bit 6
				switch(Copy_u8SenceLevel)
									{
					case  RISING_EDGE:
						MCUCSR |=(1<<6);
						break;
					case FALLING_EDGE :
						break;
					default:
						Local_enuerrorState= ES_OUT_OF_RANGE;
					}
    	 }
     }
	return Local_enuerrorState;
}

ES_t EXTI_enuEnableINT(u8 Copy_PstrEXTI_ID)
{
	ES_t Local_enuerrorState= ES_NOK;

    if(Copy_PstrEXTI_ID<MAX_NUM_OF_EXTI)
    {
   	 if(Copy_PstrEXTI_ID == INT0)
            {
   		GICR |=(1<<6);
			}
   	 else if(Copy_PstrEXTI_ID == INT1)
   	        {
   		GICR |=(1<<7);
			}
   	 else if(Copy_PstrEXTI_ID == INT2)
   	        {
   		GICR |=(1<<5);
            }
    }
	return Local_enuerrorState;
}

ES_t EXTI_enuDisableINT(u8 Copy_PstrEXTI_ID)
{
	ES_t Local_enuerrorState= ES_NOK;

    if(Copy_PstrEXTI_ID<MAX_NUM_OF_EXTI)
    {
   	 if(Copy_PstrEXTI_ID == INT0)
            {
   		GICR &= ~(1<<6);
			}
   	 else if(Copy_PstrEXTI_ID == INT1)
   	        {
   		GICR &= ~(1<<7);
			}
   	 else if(Copy_PstrEXTI_ID == INT2)
   	        {
   		GICR &= ~(1<<5);
            }
    }
	return Local_enuerrorState;
}

ES_t EXTI_enuCallBack(void (*Copy_pfunAppFun) (void*),void *Copy_pvidParameter,u8 Copy_PstrEXTI_ID)
{
	ES_t Local_enuerrorState= ES_NOK;
	if(Copy_pfunAppFun!=NULL &&  Copy_PstrEXTI_ID<MAX_NUM_OF_EXTI)
	{
		EXTI_ApfunINTfun[Copy_PstrEXTI_ID]=Copy_pfunAppFun;
		EXTI_ApvidGenericParameter[Copy_PstrEXTI_ID]=Copy_pvidParameter;
	}
	else
	{
		Local_enuerrorState= ES_NULL_POINTER;
	}
	return Local_enuerrorState;
}
ISR(VECT_INT0)
{
	if(EXTI_ApfunINTfun[0]!=NULL)
	{
		EXTI_ApfunINTfun[0](EXTI_ApvidGenericParameter[0]);
	}
	else
	{}
}
ISR(VECT_INT1)
{
	if(EXTI_ApfunINTfun[INT1]!=NULL)
	{
		EXTI_ApfunINTfun[INT1](EXTI_ApvidGenericParameter[1]);
	}
	else
	{}
}
ISR(VECT_INT2)
{
	if(EXTI_ApfunINTfun[INT2]!=NULL)
	{
		EXTI_ApfunINTfun[INT2](EXTI_ApvidGenericParameter[2]);
	}
	else
	{}
}

