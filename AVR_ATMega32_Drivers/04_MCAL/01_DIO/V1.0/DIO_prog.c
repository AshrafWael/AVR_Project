/*
 * DIO_prog.c
 *
 *  Created on: May 5, 2023
 *      Author: User
 */

#ifndef DIO_PROG_C_
#define DIO_PROG_C_

#include "stdTypes.h"
#include "erorSTATE.h"

#include "DIO_priv.h"
#include "DIO_config.h"


ES_t DIO_enuinit(void)
{
	ES_t Local_enuerrorState= ES_NOK;

     DDRA=CONC(PA_PIN0_DIR,PA_PIN1_DIR,PA_PIN2_DIR,PA_PIN3_DIR,PA_PIN4_DIR,PA_PIN5_DIR,PA_PIN6_DIR);
     DDRB=CONC(PB_PIN0_DIR,PB_PIN1_DIR,PB_PIN2_DIR,PB_PIN3_DIR,PB_PIN4_DIR,PB_PIN5_DIR,PB_PIN6_DIR);
     DDRC=CONC(PC_PIN0_DIR,PC_PIN1_DIR,PC_PIN2_DIR,PC_PIN3_DIR,PC_PIN4_DIR,PC_PIN5_DIR,PC_PIN6_DIR);
     DDRD=CONC(PD_PIN0_DIR,PD_PIN1_DIR,PD_PIN2_DIR,PD_PIN3_DIR,PD_PIN4_DIR,PD_PIN5_DIR,PD_PIN6_DIR);

     PORTA=CONC(PA_PIN0_VALUE,PA_PIN1_VALUE,PA_PIN2_VALUE,PA_PIN3_VALUE,PA_PIN4_VALUE,PA_PIN5_VALUE,PA_PIN6_VALUE);
     PORTB=CONC(PB_PIN0_VALUE,PB_PIN1_VALUE,PB_PIN2_VALUE,PB_PIN3_VALUE,PB_PIN4_VALUE,PB_PIN5_VALUE,PB_PIN6_VALUE);
     PORTC=CONC(PC_PIN0_VALUE,PC_PIN1_VALUE,PC_PIN2_VALUE,PC_PIN3_VALUE,PC_PIN4_VALUE,PC_PIN5_VALUE,PC_PIN6_VALUE);
     PORTD=CONC(PD_PIN0_VALUE,PD_PIN1_VALUE,PD_PIN2_VALUE,PD_PIN3_VALUE,PD_PIN4_VALUE,PD_PIN5_VALUE,PD_PIN6_VALUE);

     Local_enuerrorState= ES_OK;

	return  Local_enuerrorState;
}

ES_t DIO_enuSetPortDirection(u8 Copy_u8PortID,u8 Copy_u8PortValue)
{
	ES_t Local_enuerrorState= ES_NOK;

	if(Copy_u8PortID<=DIO_PORTD)
				{
			switch(Copy_u8PortID)
					{
					case DIO_PORTA :
						DDRA= Copy_u8PortValue;
						break;
					case DIO_PORTB :
						DDRB= Copy_u8PortValue;
						break;
					case DIO_PORTC :
						DDRC= Copy_u8PortValue;
						break;
					case DIO_PORTD :
						DDRD= Copy_u8PortValue;
						break;
					}
					Local_enuerrorState= ES_OK;
				}
				else
				{
					Local_enuerrorState= ES_OUT_OF_RANGE;
				}
		return  Local_enuerrorState;
}
ES_t DIO_enuSetPortValue(u8 Copy_u8PortID,u8 Copy_u8PortValue)
{
	ES_t Local_enuerrorState= ES_NOK;
	if(Copy_u8PortID<=DIO_PORTD)
		{
			switch(Copy_u8PortID)
			{
			case DIO_PORTA :
				PORTA= Copy_u8PortValue;
				break;
			case DIO_PORTB :
				PORTB= Copy_u8PortValue;
				break;
			case DIO_PORTC :
				PORTC= Copy_u8PortValue;
				break;
			case DIO_PORTD :
				PORTD= Copy_u8PortValue;
				break;
			}
			Local_enuerrorState= ES_OK;
		}
		else
		{
			Local_enuerrorState= ES_OUT_OF_RANGE;
		}

		return  Local_enuerrorState;
}
ES_t DIO_enuGetPortValue(u8 Copy_u8PortID,u8 *Copy_pu8PortValue)
{
	ES_t Local_enuerrorState= ES_NOK;
        if(Copy_pu8PortValue !=NULL)
        {
        	if(Copy_u8PortID<=DIO_PORTD)
        	{
        		switch(Copy_u8PortID)
        		{
        		case DIO_PORTA:
        			*Copy_pu8PortValue=PINA;
        			break;
        		case DIO_PORTB:
        		     *Copy_pu8PortValue=PINB;
        		      break;
        		case DIO_PORTC:
        		      *Copy_pu8PortValue=PINC;
        		      break;
        		case DIO_PORTD:
        		       *Copy_pu8PortValue=PIND;
        		        break;
        		}
        		Local_enuerrorState= ES_OK;
        	}
        	else
        	{
        		Local_enuerrorState= ES_OUT_OF_RANGE;
        	}
        }
        else
        {
        	   Local_enuerrorState= ES_NULL_POINTER;
        }
		return  Local_enuerrorState;
}

ES_t DIO_enuToglePortValue(u8 Copy_u8PortID)
{
	ES_t Local_enuerrorState= ES_NOK;
	if(Copy_u8PortID<=DIO_PORTD)
			{
				switch(Copy_u8PortID)
				{
				case DIO_PORTA :
					PORTA=~PORTA;
					break;
				case DIO_PORTB :
					PORTB=~PORTB;
					break;
				case DIO_PORTC :
					PORTC=~PORTC;
					break;
				case DIO_PORTD :
					PORTD=~PORTD;
					break;
				}
				Local_enuerrorState= ES_OK;
			}
			else
			{
				Local_enuerrorState= ES_OUT_OF_RANGE;
			}

		return  Local_enuerrorState;
}

ES_t DIO_enuSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8pinID,u8 Copy_u8PinValue)
{
	ES_t Local_enuerrorState= ES_NOK;
			if(Copy_u8PortID <=DIO_PORTD &&
					Copy_u8pinID<=DIO_PIN7 &&
					Copy_u8PinValue<= OUTPUT)
			{
				switch(Copy_u8PortID)
				{
				case DIO_PORTA :
					DDRA &=~(DIO_MASK_BIT<<Copy_u8pinID);
					DDRA |= (Copy_u8pinID <<Copy_u8PinValue);
					break;
				case DIO_PORTB :
					DDRB &=~(DIO_MASK_BIT<<Copy_u8pinID);
					DDRB |= (Copy_u8pinID<< Copy_u8PinValue);
					 break;
				case DIO_PORTC :
				   DDRC &=~(DIO_MASK_BIT<<Copy_u8pinID);
				   DDRC |= (Copy_u8pinID<< Copy_u8PinValue);
				 		break;
				case DIO_PORTD :
				   DDRD &=~(DIO_MASK_BIT<<Copy_u8pinID);
				   DDRD |= (Copy_u8pinID<< Copy_u8PinValue);
						 break;
				}
				Local_enuerrorState= ES_OK;
			}
			else
			{
				 Local_enuerrorState = ES_OUT_OF_RANGE;
			}
		return  Local_enuerrorState;
}

ES_t DIO_enuSetPinValue(u8 Copy_u8PortID,u8 Copy_u8pinID,u8 Copy_u8PinValue)
{
	ES_t Local_enuerrorState= ES_NOK;
	if(Copy_u8PortID <=DIO_PORTD &&
				Copy_u8pinID<=DIO_PIN7 &&
				Copy_u8PinValue<= OUTPUT)
		{
			switch(Copy_u8PortID)
			{
			case DIO_PORTA :
				PORTA &=~(DIO_MASK_BIT<<Copy_u8pinID);
				PORTA |= (Copy_u8pinID <<Copy_u8PinValue);
				break;
			case DIO_PORTB :
				PORTB &=~(DIO_MASK_BIT<<Copy_u8pinID);
				PORTB |= (Copy_u8pinID<< Copy_u8PinValue);
				 break;
			case DIO_PORTC :
			   PORTC &=~(DIO_MASK_BIT<<Copy_u8pinID);
			   PORTC |= (Copy_u8pinID<< Copy_u8PinValue);
			 		break;
			case DIO_PORTD :
			   PORTD &=~(DIO_MASK_BIT<<Copy_u8pinID);
			   PORTD |= (Copy_u8pinID<< Copy_u8PinValue);
					 break;
			}
			Local_enuerrorState= ES_OK;
		}
		else
		{
			 Local_enuerrorState = ES_OUT_OF_RANGE;
		}
		return  Local_enuerrorState;
}
ES_t DIO_enuGetPinValue(u8 Copy_u8PortID,u8 Copy_u8pinID,u8 *Copy_pu8PinValue)
{
	ES_t Local_enuerrorState= ES_NOK;
	   if(Copy_pu8PinValue !=NULL)
	        {
	        	if(Copy_u8PortID<=DIO_PORTD &&
	        			Copy_u8pinID<=DIO_PIN7)
	        	{
	        		switch(Copy_u8PortID)
	        		{
	        		case DIO_PORTA:
	        			*Copy_pu8PinValue=((PINA>>Copy_u8pinID)&DIO_MASK_BIT);
	        			break;
	        		case DIO_PORTB:
	        			*Copy_pu8PinValue=((PINB>>Copy_u8pinID)&DIO_MASK_BIT);
	        		      break;
	        		case DIO_PORTC:
	        			*Copy_pu8PinValue=((PINC>>Copy_u8pinID)&DIO_MASK_BIT);
	        		      break;
	        		case DIO_PORTD:
	        			*Copy_pu8PinValue=((PIND>>Copy_u8pinID)&DIO_MASK_BIT);
	        		        break;
	        		}
	        		Local_enuerrorState= ES_OK;
	        	}
	        	else
	        	{
	        		Local_enuerrorState= ES_OUT_OF_RANGE;
	        	}
	        }
	        else
	        {
	        	   Local_enuerrorState= ES_NULL_POINTER;
	        }

		return  Local_enuerrorState;
}

ES_t DIO_enuToglePinValue(u8 Copy_u8PortID,u8 Copy_u8pinID)
{
	ES_t Local_enuerrorState= ES_NOK;

 	          if(Copy_u8PortID<=DIO_PORTD &&
	        			Copy_u8pinID<=DIO_PIN7)
	        	{
	        		switch(Copy_u8PortID)
	        		{
	        		case DIO_PORTA:
	        			 PORTA^=(DIO_MASK_BIT << Copy_u8pinID);
	        			break;
	        		case DIO_PORTB:
	        			PORTB^=(DIO_MASK_BIT << Copy_u8pinID);
	        		      break;
	        		case DIO_PORTC:
	        			PORTC^=(DIO_MASK_BIT << Copy_u8pinID);
	        		      break;
	        		case DIO_PORTD:
	        			PORTD^=(DIO_MASK_BIT << Copy_u8pinID);
	        		        break;
	        		}
	        		Local_enuerrorState= ES_OK;
	        	}
	        	else
	        	{
	        		Local_enuerrorState= ES_OUT_OF_RANGE;
	        	}


		return  Local_enuerrorState;
}


#endif /* DIO_PROG_C_ */
