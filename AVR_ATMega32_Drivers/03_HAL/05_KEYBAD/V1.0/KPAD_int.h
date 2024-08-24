/*
 * KPD_LT_int.h
 *
 *  Created on: May 28, 2023
 *      Author: User
 */

#ifndef KPD_LT_INT_H_
#define KPD_LT_INT_H_

#include "KPAD_config.h"

ES_t KPAD_enuInit(KPAD_t* Copy_pstrKeyPadConfig);

ES_t KPAD_enuGetPressedKey(KPAD_t* Copy_pstrKeyPadConfig, u8* Copy_puint8Value);

#endif /* KPD_LT_INT_H_ */
