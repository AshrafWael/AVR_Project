/*
 * Switch_init.h
 *
 *  Created on: May 6, 2023
 *      Author: User
 */

#ifndef SWITCH_INIT_H_
#define SWITCH_INIT_H_

#include "erorSTATE.h"
#include "Switch_priv.h"

ES_t Switch_enuinit(SW_t * Copy_AstrSwitches);

ES_t Switch_enuGetState(SW_t *Copy_AstrSwitches, u8 *Copy_pu8SwitchState);


#endif /* SWITCH_INIT_H_ */
