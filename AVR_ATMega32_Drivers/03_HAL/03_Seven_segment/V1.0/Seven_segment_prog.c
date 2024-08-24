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

ES_t Seven_Segment_enuInt(void)
{
  ES_t Local_enuErrorState=ES_NOK;
   u32 Local_u32ErrorCheck=0;
   Local_u32ErrorCheck=(DIO_enuSetPinDirection(SEG_APORT,SEG_APIN,DIO_u8OUTPUT));
   Local_u32ErrorCheck|=(DIO_enuSetPinDirection(SEG_BPORT,SEG_BPIN,DIO_u8OUTPUT)<<3);
   Local_u32ErrorCheck|=(DIO_enuSetPinDirection(SEG_CPORT,SEG_CPIN,DIO_u8OUTPUT)<<6);
   Local_u32ErrorCheck|=(DIO_enuSetPinDirection(SEG_DPORT,SEG_DPIN,DIO_u8OUTPUT)<<9);
   Local_u32ErrorCheck|=(DIO_enuSetPinDirection(SEG_EPORT,SEG_EPIN,DIO_u8OUTPUT)<<12);
   Local_u32ErrorCheck|=(DIO_enuSetPinDirection(SEG_FPORT,SEG_FPIN,DIO_u8OUTPUT)<<15);
   Local_u32ErrorCheck|=(DIO_enuSetPinDirection(SEG_GPORT,SEG_GPIN,DIO_u8OUTPUT)<<18);

#if    SEG_CMN<= DIO_u8PIN7 && SEG_CMN_PORT<= DIO_u8PORTD
           DIO_enuSetPinDirection(SEG_CMN_PORT ,SEG_CMN ,DIO_u8OUTPUT);
#elif   SEG_CMN== NOT_CONECTED || SEG_CMN_PORT== NOT_CONECTED

#else
#error"Your Common Pin has Wrong Selection"
#endif

#if    SEG_DOT<= DIO_u8PIN7 && SEG_DOT_PORT<= DIO_u8PORTD
           DIO_enuSetPinDirection(SEG_DOT_PORT ,SEG_DOT ,DIO_u8OUTPUT);
#elif   SEG_DOT== NOT_CONECTED || SEG_DOT_PORT== NOT_CONECTED

#else
#error"Your DOT Pin has Wrong Selection"
#endif
       u8 Local_u8Eterator;
        for(Local_u8Eterator=0;Local_u8Eterator<sizeof(Local_u32ErrorCheck)*8;Local_u8Eterator+=3)
        {
      	   if(((Local_u32ErrorCheck>>Local_u8Eterator)&7)!=ES_OK)
      	   {
      		 return  Local_enuErrorState;
      	   }
        }
        Local_enuErrorState =ES_OK;
	return  Local_enuErrorState;
}

ES_t Seven_Segment_enuDisplayNum(u8 Copy_u8Num)
{
	ES_t Local_enuErrorState=ES_NOK;
	u32 Local_u32Check=0;
	if(Copy_u8Num<10)
	{
#if SEG_TYPE == COMMON_CATHOD
	Local_u32Check=DIO_enuSetPinValue(SEG_APORT,SEG_APIN,   ((SEG_Au8NumDisplay[Copy_u8Num]>>0)&1));
	Local_u32Check|=(DIO_enuSetPinValue(SEG_BPORT,SEG_BPIN, ((SEG_Au8NumDisplay[Copy_u8Num]>>1)&1))<<3);
	Local_u32Check|=(DIO_enuSetPinValue(SEG_CPORT,SEG_CPIN, ((SEG_Au8NumDisplay[Copy_u8Num]>>2)&1))<<6);
	Local_u32Check|=(DIO_enuSetPinValue(SEG_DPORT,SEG_DPIN, ((SEG_Au8NumDisplay[Copy_u8Num]>>3)&1))<<9);
	Local_u32Check|=(DIO_enuSetPinValue(SEG_EPORT,SEG_EPIN, ((SEG_Au8NumDisplay[Copy_u8Num]>>4)&1))<<12);
	Local_u32Check|=(DIO_enuSetPinValue(SEG_FPORT,SEG_FPIN, ((SEG_Au8NumDisplay[Copy_u8Num]>>5)&1))<<15);
	Local_u32Check|=(DIO_enuSetPinValue(SEG_GPORT,SEG_GPIN, ((SEG_Au8NumDisplay[Copy_u8Num]>>6)&1))<<18);
#elif SEG_TYPE == COMMON_ANOD
	Local_u32Check=DIO_enuSetPinValue(SEG_APORT,SEG_APIN,   !((SEG_Au8NumDisplay[Copy_u8Num]>>0)&1));
	Local_u32Check|=(DIO_enuSetPinValue(SEG_BPORT,SEG_BPIN, !((SEG_Au8NumDisplay[Copy_u8Num]>>1)&1))<<3);
	Local_u32Check|=(DIO_enuSetPinValue(SEG_CPORT,SEG_CPIN, !((SEG_Au8NumDisplay[Copy_u8Num]>>2)&1))<<6);
	Local_u32Check|=(DIO_enuSetPinValue(SEG_DPORT,SEG_DPIN, !((SEG_Au8NumDisplay[Copy_u8Num]>>3)&1))<<9);
	Local_u32Check|=(DIO_enuSetPinValue(SEG_EPORT,SEG_EPIN, !((SEG_Au8NumDisplay[Copy_u8Num]>>4)&1))<<12);
	Local_u32Check|=(DIO_enuSetPinValue(SEG_FPORT,SEG_FPIN, !((SEG_Au8NumDisplay[Copy_u8Num]>>5)&1))<<15);
	Local_u32Check|=(DIO_enuSetPinValue(SEG_GPORT,SEG_GPIN, !((SEG_Au8NumDisplay[Copy_u8Num]>>6)&1))<<18);
#else
#error"Your Common Pin has Wrong Selection"
#endif

	       u8 Local_u8Eterator;
	        for(Local_u8Eterator=0;Local_u8Eterator<sizeof(Local_u32Check)*8;Local_u8Eterator+=3)
	        {
	      	   if(((Local_u32Check>>Local_u8Eterator)&7)!=ES_OK)
	      	   {
	      		 return  Local_enuErrorState;
	      	   }
	        }
	        Local_enuErrorState =ES_OK;
	}
	else
	{
		 Local_enuErrorState =ES_OUT_OF_RANGE;
	}
	return  Local_enuErrorState;
}

ES_t Seven_Segment_enuEnable_Common(void)
{
	ES_t Local_enuErrorState=ES_NOK;
#if    SEG_CMN<= DIO_u8PIN7 && SEG_CMN_PORT<= DIO_u8PORTD
	#if SEG_TYPE==COMMON_CATHOD
	Local_enuErrorState=DIO_enuSetPinValue(SEG_CMN_PORT ,SEG_CMN ,DIO_u8LOW);
	#elif SEG_TYPE==COMMON_ANOD
	Local_enuErrorState=DIO_enuSetPinValue(SEG_CMN_PORT ,SEG_CMN ,DIO_u8HIGH);
	#else
	#error"WRONG TYPE"
	#endif
#elif   SEG_CMN== NOT_CONECTED || SEG_CMN_PORT== NOT_CONECTED

#else
#error"Your Common Pin has Wrong Selection"
#endif

	return  Local_enuErrorState;
}

ES_t Seven_Segment_enuDisableCommon(void)
{
	ES_t Local_enuErrorState=ES_NOK;
#if SEG_CMN<= DIO_u8PIN7 && SEG_CMN_PORT<= DIO_u8PORTD
	#if SEG_TYPE==COMMON_CATHOD
	Local_enuErrorState=DIO_enuSetPinValue(SEG_CMN_PORT ,SEG_CMN ,DIO_u8HIGH);
	#elif SEG_TYPE==COMMON_ANOD
	Local_enuErrorState=DIO_enuSetPinValue(SEG_CMN_PORT ,SEG_CMN ,DIO_u8LOW);
	#else
	#error"Wrong type"
	#endif
#elif   SEG_CMN== NOT_CONECTED || SEG_CMN_PORT== NOT_CONECTED

#else
#error"Your Common Pin has Wrong Selection"
#endif
	return  Local_enuErrorState;
}

ES_t Seven_Segment_enuEnableDot(void)
{
	ES_t Local_enuErrorState=ES_NOK;
#if    SEG_DOT<= DIO_u8PIN7 && SEG_DOT_PORT<= DIO_u8PORTD
	#if SEG_TYPE==COMMON_CATHOD
	 Local_enuErrorState=DIO_enuSetPinValue(SEG_DOT_PORT ,SEG_DOT ,DIO_u8HIGH);
	#elif SEG_TYPE==COMMON_ANOD
	 Local_enuErrorState=DIO_enuSetPinValue(SEG_DOT_PORT ,SEG_DOT ,DIO_u8LOW);
	#else
	#error"Wrong type"
	#endif
#elif   SEG_DOT== NOT_CONECTED || SEG_DOT_PORT== NOT_CONECTED

#else
#error"Your Common Pin has Wrong Selection"
#endif

	return  Local_enuErrorState;
}
ES_t Seven_Segment_enuDisableDot(void)
{
	ES_t Local_enuErrorState=ES_NOK;
#if    SEG_DOT<= DIO_u8PIN7 && SEG_DOT_PORT<= DIO_u8PORTD
	#if SEG_TYPE==COMMON_CATHOD
	DIO_enuSetPinValue(SEG_DOT_PORT ,SEG_DOT ,DIO_u8LOW);
	#elif SEG_TYPE==COMMON_ANOD
	DIO_enuSetPinValue(SEG_DOT_PORT ,SEG_DOT ,DIO_u8HIGH);
	#else
	#error"Wrong type"
	#endif
#elif   SEG_DOT== DOT_CONECTED || SEG_DOT_PORT== NOT_CONECTED

#else
#error"Your Common Pin has Wrong Selection"
#endif
	return  Local_enuErrorState;
}

ES_t Seven_Segment_enuClearDisplay(void)
{
	ES_t Local_enuErrorState=ES_NOK;
	u32 Local_u32Check=0;
#if SEG_TYPE == COMMON_CATHOD
	Local_u32Check=DIO_enuSetPinValue(SEG_APORT,SEG_APIN,  DIO_u8LOW);
	Local_u32Check|=DIO_enuSetPinValue(SEG_BPORT,SEG_BPIN, DIO_u8LOW);
	Local_u32Check|=DIO_enuSetPinValue(SEG_CPORT,SEG_CPIN, DIO_u8LOW);
	Local_u32Check|=DIO_enuSetPinValue(SEG_DPORT,SEG_DPIN, DIO_u8LOW);
	Local_u32Check|=DIO_enuSetPinValue(SEG_EPORT,SEG_EPIN, DIO_u8LOW);
	Local_u32Check|=DIO_enuSetPinValue(SEG_FPORT,SEG_FPIN, DIO_u8LOW);
	Local_u32Check|=DIO_enuSetPinValue(SEG_GPORT,SEG_GPIN, DIO_u8LOW);
#elif SEG_TYPE == COMMON_ANOD
	Local_u32Check= DIO_enuSetPinValue(SEG_APORT,SEG_APIN, DIO_u8HIGH);
	Local_u32Check|=DIO_enuSetPinValue(SEG_BPORT,SEG_BPIN, DIO_u8HIGH);
	Local_u32Check|=DIO_enuSetPinValue(SEG_CPORT,SEG_CPIN, DIO_u8HIGH);
	Local_u32Check|=DIO_enuSetPinValue(SEG_DPORT,SEG_DPIN, DIO_u8HIGH);
	Local_u32Check|=DIO_enuSetPinValue(SEG_EPORT,SEG_EPIN, DIO_u8HIGH);
	Local_u32Check|=DIO_enuSetPinValue(SEG_FPORT,SEG_FPIN, DIO_u8HIGH);
	Local_u32Check|=DIO_enuSetPinValue(SEG_GPORT,SEG_GPIN, DIO_u8HIGH);
#else
#error"Your Common Pin has Wrong Selection"
#endif
	return  Local_enuErrorState;
}


