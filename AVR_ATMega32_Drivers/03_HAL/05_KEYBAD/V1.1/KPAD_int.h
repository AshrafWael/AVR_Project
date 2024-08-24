/*
 * KPAD_int.h
 *
 *  Created on: Jul 8, 2023
 *      Author: User
 */

#ifndef KPAD_INT_H_
#define KPAD_INT_H_


#include "KPAD_config.h"

ES_t KPAD_enuInit(KPAD_t* Copy_pstrKeyPadConfig);

ES_t KPAD_enuGetPressedKey(KPAD_t* Copy_pstrKeyPadConfig, u8* Copy_puin8Value);

#endif /* KPAD_INT_H_ */
