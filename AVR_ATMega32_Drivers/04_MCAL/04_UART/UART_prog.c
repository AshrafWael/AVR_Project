/*
 * UART_prog.h
 *
 *  Created on: May 5, 2023
 *      Author: Ashraf
 */
 
#include "../../01_LIB/01_stdTypes/stdTypes.h"
#include "../../01_LIB/03_errotSTATE/errotSTATE.h"
 
#include "UART_config.h"
#include "UART_priv.h"
 
 ES_t UART_enuInit(void)
 {
	 ES_t Local_enuErrorState =ES_NOK;
	 
	 
	 
	 return Local_enuErrorState;
 }

ES_t UART_enuSendChar(u8 Copy_u8Data)
{
		 ES_t Local_enuErrorState =ES_NOK;
	 
	 return Local_enuErrorState;
	
}

ES_t UART_enuReciveChar(u8 *Copy_pu8Data)
{
		 ES_t Local_enuErrorState =ES_NOK;
	 
	 return Local_enuErrorState;
	
}

ES_t UART_enuSendString( const char *Copy_pu8Data)
{
	
		 ES_t Local_enuErrorState =ES_NOK;
	 
	 return Local_enuErrorState;
}

ES_t UART_enuReciveString(char *Copy_pu8Data)
{
	
		 ES_t Local_enuErrorState =ES_NOK;
	 
	 return Local_enuErrorState;
	
}