/*
 * Seven_segment_prog.c
 *
 *  Created on: May 10, 2023
 *      Author: User
 */

#include "stdTypes.h"
#include "erorSTATE.h"

#include "DIO_init.h"

#include "Seven_segment_int.h"
#include "Seven_segment_priv.h"
#include "Seven_segment_config.h"

extern SEG_t SEG_AstrSevenSegmentConfig [SEG_NUM];

ES_t  Seven_Segment_enuInt(SEG_t *Copy_u8pstrSegConfig)
{
  ES_t Local_enuErrorState=ES_NOK;
  if(Copy_u8pstrSegConfig !=NULL)
  {
	  u32 Local_u32Check=0;
    u8 Local_u8Eterator;
    for(Local_u8Eterator=0;Local_u8Eterator<=SEG_NUM;Local_u8Eterator++)
    {
    	Local_u32Check|=(DIO_enuSetPinDirection(Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8APORT,Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8APIN,DIO_u8OUTPUT)<<0);
    	Local_u32Check|=(DIO_enuSetPinDirection(Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8BPORT,Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8BPIN,DIO_u8OUTPUT)<<3);
    	Local_u32Check|=(DIO_enuSetPinDirection(Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8CPORT,Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8CPIN,DIO_u8OUTPUT)<<6);
    	Local_u32Check|=(DIO_enuSetPinDirection(Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8DPORT,Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8DPIN,DIO_u8OUTPUT)<<9);
    	Local_u32Check|=(DIO_enuSetPinDirection(Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8EPORT,Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8EPIN,DIO_u8OUTPUT)<<12);
    	Local_u32Check|=(DIO_enuSetPinDirection(Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8FPORT,Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8FPIN,DIO_u8OUTPUT)<<15);
    	Local_u32Check|=(DIO_enuSetPinDirection(Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8GPORT,Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8GPIN,DIO_u8OUTPUT)<<18);

    	if(Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8CMNPORT != NOT_CONECTED  &&
    		Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8CMNPIN != NOT_CONECTED	)
    	{
    		 Local_enuErrorState=DIO_enuSetPinDirection(Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8CMNPORT,Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8CMNPIN,DIO_u8OUTPUT);
    	}
    	if(Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8DOTPORT != NOT_CONECTED  &&
    		Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8DOTPIN != NOT_CONECTED	)
    	{
    		 Local_enuErrorState=DIO_enuSetPinDirection(Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8DOTPORT,Copy_u8pstrSegConfig[Local_u8Eterator].SEG_u8DOTPIN,DIO_u8OUTPUT);
    	}
    }
    	u8 Local_u8Ete;
    	for(Local_u8Ete=0;Local_u8Ete<sizeof(Local_u32Check)*8;Local_u8Ete+=3)
    	{
    		if(((Local_u32Check>>Local_u8Ete)&7)!=ES_OK)
    		{
    			return  Local_enuErrorState;
    		}
    	}
    	Local_enuErrorState =ES_OK;
  }
  else
  {
	  Local_enuErrorState =ES_NULL_POINTER;
  }
	return  Local_enuErrorState;
}

ES_t Seven_Segment_enuDisplayNum(u8 Copy_u8SegID,u8 Copy_u8NUM)
{
	ES_t Local_enuErrorState=ES_NOK;
	u32 Local_u32Check=0;
	if(Copy_u8SegID <=SEG_NUM && Copy_u8NUM <=MAX_SEG_NUM)
	{
		if(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8TYPE== COMMON_CATHOD)
		{
			Local_u32Check|=(DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8APORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8APIN,(((SEG_Au8NumDisplay [Copy_u8NUM])>>0))&1)<<0);
			Local_u32Check|=(DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8BPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8BPIN,(((SEG_Au8NumDisplay [Copy_u8NUM])>>1))&1)<<3);
			Local_u32Check|=(DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CPIN,(((SEG_Au8NumDisplay [Copy_u8NUM])>>2))&1)<<6);
			Local_u32Check|=(DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8DPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8DPIN,(((SEG_Au8NumDisplay [Copy_u8NUM])>>3))&1)<<9);
			Local_u32Check|=(DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8EPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8EPIN,(((SEG_Au8NumDisplay [Copy_u8NUM])>>4))&1)<<12);
			Local_u32Check|=(DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8FPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8FPIN,(((SEG_Au8NumDisplay [Copy_u8NUM])>>5))&1)<<15);
			Local_u32Check|=(DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8GPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8GPIN,(((SEG_Au8NumDisplay [Copy_u8NUM])>>6))&1)<<18);

		}
		else if(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8TYPE== COMMON_CATHOD)
		{
			Local_u32Check|=(DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8APORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8APIN,!(((SEG_Au8NumDisplay [Copy_u8NUM])>>0))&1)<<0);
			Local_u32Check|=(DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8BPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8BPIN,!(((SEG_Au8NumDisplay [Copy_u8NUM])>>1))&1)<<3);
			Local_u32Check|=(DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CPIN,!(((SEG_Au8NumDisplay [Copy_u8NUM])>>2))&1)<<6);
			Local_u32Check|=(DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8DPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8DPIN,!(((SEG_Au8NumDisplay [Copy_u8NUM])>>3))&1)<<9);
			Local_u32Check|=(DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8EPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8EPIN,!(((SEG_Au8NumDisplay [Copy_u8NUM])>>4))&1)<<12);
        	Local_u32Check|=(DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8FPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8FPIN,!(((SEG_Au8NumDisplay [Copy_u8NUM])>>5))&1)<<15);
	     	Local_u32Check|=(DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8GPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8GPIN,!(((SEG_Au8NumDisplay [Copy_u8NUM])>>6))&1)<<18);
		}
		u8 Local_u8Ete;
		    	for(Local_u8Ete=0;Local_u8Ete<sizeof(Local_u32Check)*8;Local_u8Ete+=3)
		    	{
		    		if(((Local_u32Check>>Local_u8Ete)&7)!=ES_OK)
		    		{
		    			return  Local_enuErrorState;
		    		}
		    	}
		    	Local_enuErrorState =ES_OK;
        }
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}
	return  Local_enuErrorState;
}

ES_t Seven_Segment_enuEnable_Common(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_u8SegID<= SEG_NUM)
	{
		if(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CMNPORT != NOT_CONECTED &&
			SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CMNPIN != NOT_CONECTED)
		{
			if(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8TYPE== COMMON_CATHOD)
			{
				DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CMNPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CMNPIN,DIO_u8LOW);
			}
			if(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8TYPE== COMMON_ANOD)
				{
					DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CMNPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CMNPIN,DIO_u8HIGH);
				}
		}
	}
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}
	return  Local_enuErrorState;
}

ES_t Seven_Segment_enuDisableCommon(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState=ES_NOK;

	if(Copy_u8SegID<= SEG_NUM)
		{
			if(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CMNPORT != NOT_CONECTED &&
				SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CMNPIN != NOT_CONECTED)
			{
				if(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8TYPE== COMMON_CATHOD)
				{
					DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CMNPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CMNPIN,DIO_u8HIGH);
				}
				if(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8TYPE== COMMON_ANOD)
					{
						DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CMNPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CMNPIN,DIO_u8LOW);
					}
			}
		}
		else
		{
			Local_enuErrorState=ES_OUT_OF_RANGE;
		}
	return  Local_enuErrorState;
}

ES_t Seven_Segment_enuEnableDot(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState=ES_NOK;

	if(Copy_u8SegID<= SEG_NUM)
		{
			if(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8DOTPORT != NOT_CONECTED &&
				SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8DOTPIN != NOT_CONECTED)
			{
				if(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8TYPE== COMMON_CATHOD)
				{
					DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8DOTPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CMNPIN,DIO_u8HIGH);
				}
				if(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8TYPE== COMMON_ANOD)
					{
						DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8DOTPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CMNPIN,DIO_u8LOW);
					}
			}
		}
		else
		{
			Local_enuErrorState=ES_OUT_OF_RANGE;
		}
	return  Local_enuErrorState;
}
ES_t Seven_Segment_enuDisableDot(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState=ES_NOK;

	if(Copy_u8SegID<= SEG_NUM)
		{
			if(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8DOTPORT != NOT_CONECTED &&
				SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8DOTPIN != NOT_CONECTED)
			{
				if(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8TYPE== COMMON_CATHOD)
				{
					DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8DOTPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CMNPIN,DIO_u8LOW);
				}
				if(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8TYPE== COMMON_ANOD)
					{
						DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8DOTPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CMNPIN,DIO_u8HIGH);
					}
			}
		}
		else
		{
			Local_enuErrorState=ES_OUT_OF_RANGE;
		}

	return  Local_enuErrorState;
}

ES_t Seven_Segment_enuClearDisplay(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState=ES_NOK;
 u32 Local_u32Check=0;
if(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8TYPE== COMMON_CATHOD)
{
	DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8APORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8APIN,DIO_u8LOW);
	DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8BPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8BPIN,DIO_u8LOW);
	DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CPIN,DIO_u8LOW);
	DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8DPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8DPIN,DIO_u8LOW);
	DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8EPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8EPIN,DIO_u8LOW);
	DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8FPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8FPIN,DIO_u8LOW);
	DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8GPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8GPIN,DIO_u8LOW);

}
else if(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8TYPE== COMMON_CATHOD)
{
	DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8APORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8APIN,DIO_u8HIGH);
	DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8BPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8BPIN,DIO_u8HIGH);
	DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8CPIN,DIO_u8HIGH);
	DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8DPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8DPIN,DIO_u8HIGH);
	DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8EPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8EPIN,DIO_u8HIGH);
	DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8FPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8FPIN,DIO_u8HIGH);
 	DIO_enuSetPinValue(SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8GPORT,SEG_AstrSevenSegmentConfig[Copy_u8SegID].SEG_u8GPIN,DIO_u8HIGH);
}





	return  Local_enuErrorState;
}


