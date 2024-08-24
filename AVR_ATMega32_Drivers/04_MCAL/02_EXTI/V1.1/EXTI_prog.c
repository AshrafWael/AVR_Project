/*
 * EXTI_prog.c
 *
 *  Created on: Sep 3, 2023
 *      Author: User
 */

#include "stdTypes.h"
#include "erorSTATE.h"

#include "EXTI_priv.h"
#include "EXTI_config.h"
#include "EXTI_int.h"
#include "interrupt.h"
/*Global void (pointer to function) and global void (pointer to  parameter)*/
static void (*EXTI_ApfunINTfun[3])(void)={NULL,NULL,NULL};
ES_t EXTI_enuInit(void)
{
	ES_t Local_enuerrorState= ES_NOK;
#ifdef   EXTI_INT
	/*CHECK FOR EXTI*/
   #if EXTI_INT==EXTI_INT0
	                         GICR |=(1<<6); //Enable intrupt ot INT0
	                          MCUCR &=~(3<<0);//Mask Bit 0 1  at Sence level reg
	                          /*Chech for Sense mode */
                     #if EXTI_SENSE_MODE==EXTI_FALLING_EDGE
	                            MCUCR |=(2<<3);
                     #elif  EXTI_SENSE_MODE==EXTI_RISING_EDGE
	                          MCUCR |=(3<<2);
                     #elif  EXTI_SENSE_MODE==EXTI_ON_CHANGE
                               MCUCR |=(1<<0);
                     #elif  EXTI_SENSE_MODE==EXTI_LOW_LEVEL

     #endif
     #elif EXTI_INT==EXTI_INT1
             	           GICR |=(1<<7); //Enable intrupt ot INT0
             	            MCUCR &=~(3<<2);//Mask Bit 2  3  at Sence level reg
                    #if EXTI_SENSE_MODE==EXTI_FALLING_EDGE
             	              MCUCR |=(3<<2);
                    #elif  EXTI_SENSE_MODE==EXTI_RISING_EDGE
             	            MCUCR |=(1<<3);
                    #elif  EXTI_SENSE_MODE==EXTI_ON_CHANGE
                              MCUCR |=(1<<2);
                    #elif  EXTI_SENSE_MODE==EXTI_LOW_LEVEL

       #endif
                 #elif EXTI_INT==EXTI_INT2
                 	           GICR |=(1<<5); //Enable intrupt ot INT0
                 	         MCUCSR &=~(1<<6);//Mask Bit 6  at Sence level reg
                     #if EXTI_SENSE_MODE==EXTI_FALLING_EDGE
                 	        MCUCSR |=(1<<6);
                     #elif  EXTI_SENSE_MODE==EXTI_RISING_EDGE

        #endif
        #else
                 	  #error "Wrong INT0_SENSE configuration option"
    #endif
 #endif
       Local_enuerrorState= ES_OK;
	return Local_enuerrorState;
}

ES_t EXTI_enuSetSenceMode(u8 Copy_u8SenseMode , u8 Copy_u8INT)
{
	ES_t Local_enuerrorState= ES_NOK;
#if  Copy_u8INT>MAX_NUM_OF_EXTI
 #if Copy_u8INT==EXTI_INT0
          	            MCUCR &=~(3<<2);//Mask Bit 2  3  at Sence level reg
                 #if Copy_u8SenseMode==EXTI_FALLING_EDGE
          	              MCUCR |=(3<<2);
                 #elif  Copy_u8SenseMode==EXTI_RISING_EDGE
          	            MCUCR |=(1<<3);
                 #elif  Copy_u8SenseMode==EXTI_ON_CHANGE
                           MCUCR |=(1<<2);
                 #elif  Copy_u8SenseMode==EXTI_LOW_LEVEL
 #endif
 #elif Copy_u8INT==EXTI_INT1
            	            MCUCR &=~(3<<2);//Mask Bit 2  3  at Sence level reg
                   #if EXTI_SENSE_MODE==EXTI_FALLING_EDGE
            	              MCUCR |=(3<<2);
                   #elif  EXTI_SENSE_MODE==EXTI_RISING_EDGE
            	            MCUCR |=(1<<3);
                   #elif  EXTI_SENSE_MODE==EXTI_ON_CHANGE
                             MCUCR |=(1<<2);
                   #elif  EXTI_SENSE_MODE==EXTI_LOW_LEVEL
 #endif
 #elif EXTI_INT==EXTI_INT2
	                       MCUCSR &=~(1<<6);//Mask Bit 6  at Sence level reg
                  #if EXTI_SENSE_MODE==EXTI_FALLING_EDGE
	                      MCUCSR |=(1<<6);
                  #elif  EXTI_SENSE_MODE==EXTI_RISING_EDGE
 #endif

 #endif
	                      Local_enuerrorState=ES_OK;
#endif
	                      return Local_enuerrorState;
}

ES_t EXTI_enuEnableINT( u8 Copy_u8INT)
{
	ES_t Local_enuerrorState= ES_OK;
#if   Copy_u8INT>MAX_NUM_OF_EXTI
  #if Copy_u8INT==EXTI_INT0
	             GICR |=(1<<6);
  #elif Copy_u8INT==EXTI_INT1
           	     GICR |=(1<<7);
  #elif Copy_u8INT==EXTI_INT2
               	 GICR |=(1<<5);
  #endif
#else
               	Local_enuerrorState=ES_NOK;
#endif
		return Local_enuerrorState;
}

ES_t EXTI_enuDisableINT( u8 Copy_u8INT)
{
	ES_t Local_enuerrorState= ES_OK;
#if   Copy_u8INT>MAX_NUM_OF_EXTI
  #if Copy_u8INT==EXTI_INT0
	             GICR &= ~(1<<6);
  #elif Copy_u8INT==EXTI_INT1
           	     GICR &= ~(1<<7);
  #elif Copy_u8INT==EXTI_INT2
               	 GICR &= ~(1<<5);
  #endif
#else
               	Local_enuerrorState=ES_NOK;
#endif
		return Local_enuerrorState;
}

ES_t EXTI_enuClearFlag( u8 Copy_u8INT)
{
	ES_t Local_enuerrorState= ES_OK;
#if   Copy_u8INT>MAX_NUM_OF_EXTI
  #if Copy_u8INT==EXTI_INT0
	             GIFR &= ~(1<<6);
  #elif Copy_u8INT==EXTI_INT1
           	     GIFR &= ~(1<<7);
  #elif Copy_u8INT==EXTI_INT2
               	 GIFR &= ~(1<<5);
  #endif
#else
               	Local_enuerrorState=ES_NOK;
#endif
		return Local_enuerrorState;
}

ES_t EXTI_enuCallBack(void (*Copy_pfunAppFun)(void),u8 Copy_u8INT)
{
	ES_t Local_enuerrorState= ES_NOK;
	if(Copy_pfunAppFun !=NULL &&   Copy_u8INT<MAX_NUM_OF_EXTI)
	{
		EXTI_ApfunINTfun[Copy_u8INT]=Copy_pfunAppFun;
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
		EXTI_ApfunINTfun[0]();
		//EXTI_enuClearFlag( EXTI_INT0 );
	}
	else{}
}
ISR(VECT_INT1)
{
//	tog();

	if(EXTI_ApfunINTfun[1]!=NULL)
	{
		EXTI_ApfunINTfun[1]();
		//EXTI_enuClearFlag( EXTI_INT0 );
	}
	else{}

}
ISR(VECT_INT2)
{
	EXTI_ApfunINTfun[2]();
}


