/*
 * LCD_prog.c
 *
 *  Created on: May 12, 2023
 *      Author: User
 */
#include "stdTypes.h"
#include "erorSTATE.h"

#include "DIO_init.h"

#include "LCD_priv.h"
#include "LCD_config.h"


#include "util/delay.h"


ES_t LCD_enuInt(void)
{

	ES_t Local_enuErrorState=ES_NOK;
    DIO_enuSetPinDirection(RS_PORT,RS_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(RW_PORT,RW_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(EN_PORT,EN_PIN,DIO_u8OUTPUT);

	DIO_enuSetPinDirection(D7_PORT,D7_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D6_PORT,D6_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D5_PORT,D5_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D4_PORT,D4_PIN,DIO_u8OUTPUT);
	_delay_ms(30);
#if LCD_MODE == EGHT_BIT
	DIO_enuSetPinDirection(D3_PORT,D3_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D2_PORT,D2_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D1_PORT,D1_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D0_PORT,D0_PIN,DIO_u8OUTPUT);
	/* FUNCTION SET*/
  LCD_invidSendCommand(0x38);
#elif LCD_MODE == FOUR_BIT
	LCD_invidSendCommand(0x28);
#endif

     _delay_ms(1);
     /*Display on off control */
     LCD_invidSendCommand(0x0f);
     _delay_ms(1);
            /*    Display Clear*/
     LCD_invidSendCommand(0x01);
     _delay_ms(2);
     /*   Entry Mode set*/
     LCD_invidSendCommand(0x06);
	 return Local_enuErrorState=ES_OK;
}

static void LCD_vidLatch(u8 Copy_u8Data)
{
    /*  RW PIN*/
DIO_enuSetPinValue(RW_PORT,RW_PIN,DIO_u8LOW);
		/* EN PIN*/
DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8LOW);

DIO_enuSetPinValue(D7_PORT,D7_PIN,((Copy_u8Data>>7)&LCD_ONE));
DIO_enuSetPinValue(D6_PORT,D6_PIN,((Copy_u8Data>>6)&LCD_ONE));
DIO_enuSetPinValue(D5_PORT,D5_PIN,((Copy_u8Data>>5)&LCD_ONE));
DIO_enuSetPinValue(D4_PORT,D4_PIN,((Copy_u8Data>>4)&LCD_ONE));
#if LCD_MODE ==EGHT_BIT
DIO_enuSetPinValue(D3_PORT,D3_PIN,((Copy_u8Data>>3)&LCD_ONE));
DIO_enuSetPinValue(D2_PORT,D2_PIN,((Copy_u8Data>>2)&LCD_ONE));
DIO_enuSetPinValue(D1_PORT,D1_PIN,((Copy_u8Data>>1)&LCD_ONE));
DIO_enuSetPinValue(D0_PORT,D0_PIN,((Copy_u8Data>>0)&LCD_ONE));
#elif LCD_MODE == FOUR_BIT

#endif
DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8HIGH);
 _delay_ms(10);
DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8LOW);
}

static inline void LCD_invidSendCommand( u8 Copy_u8Command)
{
    /*  RS 0   COMMAND*/
DIO_enuSetPinValue(RS_PORT,RS_PIN,DIO_u8LOW);
        /*  RW PIN*/
DIO_enuSetPinValue(RW_PORT,RW_PIN,DIO_u8LOW);

DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8LOW);

DIO_enuSetPinValue(D7_PORT,D7_PIN,((Copy_u8Command>>7)&LCD_ONE));
DIO_enuSetPinValue(D6_PORT,D6_PIN,((Copy_u8Command>>6)&LCD_ONE));
DIO_enuSetPinValue(D5_PORT,D5_PIN,((Copy_u8Command>>5)&LCD_ONE));
DIO_enuSetPinValue(D4_PORT,D4_PIN,((Copy_u8Command>>4)&LCD_ONE));
DIO_enuSetPinValue(D3_PORT,D3_PIN,((Copy_u8Command>>3)&LCD_ONE));
DIO_enuSetPinValue(D2_PORT,D2_PIN,((Copy_u8Command>>2)&LCD_ONE));
DIO_enuSetPinValue(D1_PORT,D1_PIN,((Copy_u8Command>>1)&LCD_ONE));
DIO_enuSetPinValue(D0_PORT,D0_PIN,((Copy_u8Command>>0)&LCD_ONE));

DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8HIGH);
     _delay_ms(10);
DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8LOW);

}
ES_t LCD_enuSendCommand(u8 Copy_u8Command)
{
	ES_t Local_enuErrorState=ES_NOK;
	DIO_enuSetPinValue(RS_PORT,RS_PIN,DIO_u8LOW);
	LCD_vidLatch(Copy_u8Command);
	return	Local_enuErrorState=ES_OK;

}
ES_t LCD_enuDisplayChar(u8 Copy_u8Data)
{
	ES_t Local_enuErrorState=ES_NOK;
	DIO_enuSetPinValue(RS_PORT,RS_PIN,DIO_u8HIGH);
		LCD_vidLatch( Copy_u8Data );
		 return Local_enuErrorState=ES_OK;

}
ES_t LCD_enuDisplayString(u8 *Copy_pu8Data)
{
	ES_t Local_enuErrorState=ES_NOK;

	u8 Local_u8Count;
	for(Local_u8Count=0;Copy_pu8Data[Local_u8Count];Local_u8Count++)
	{
		LCD_enuDisplayChar(Copy_pu8Data[Local_u8Count]);

	}
	return	Local_enuErrorState=ES_OK;
}
void LCD_enuDisplayNumber(u32 Copy_u32Number)
{
  u32 Loca_u32ReserveNumber=1;
  while(Copy_u32Number!=0)
  {
	  Loca_u32ReserveNumber=(Loca_u32ReserveNumber*10)+(Copy_u32Number%10);
	  Copy_u32Number=Copy_u32Number/10;
  }
	  while(Loca_u32ReserveNumber!=1)
	  {
		  LCD_enuDisplayChar((Loca_u32ReserveNumber%10)+'0');
		  Loca_u32ReserveNumber=Loca_u32ReserveNumber/10;
	  }

}
ES_t  LCD_enuSetPosition(u8 Copy_u8Row ,u8 Copy_u8Colom)
{
	ES_t Local_enuErrorState=ES_NOK;

	u8 Local_u8RowLocation [] = {0x80,0xC0};
	LCD_enuSendCommand(Local_u8RowLocation [Copy_u8Row-LCD_ONE]+(Copy_u8Colom-LCD_ONE));
    Local_enuErrorState=ES_OK;
	return	Local_enuErrorState;
}


