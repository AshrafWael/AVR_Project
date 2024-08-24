/*
 * LED_int.h
 *
 *  Created on: May 7, 2023
 *      Author: User
 */

#ifndef LED_INT_H_
#define LED_INT_H_


#include "stdTypes.h"
#include "erorSTATE.h"

#include "LED_config.h"
#include "LED_priv.h"

ES_t LED_enuInit(LED_t *Copy_pstrLedConfig);

ES_t LED_enuTurnON(LED_t *Copy_pstrLedID);

ES_t LED_enuTurnOFF(LED_t *Copy_pstrLedID);


#endif /* LED_INT_H_ */
