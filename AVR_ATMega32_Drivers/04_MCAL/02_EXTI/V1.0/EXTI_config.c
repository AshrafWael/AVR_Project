/*
 * EXTI_config.c
 *
 *  Created on: Sep 4, 2023
 *      Author: User
 */
#include "stdTypes.h"
#include "erorSTATE.h"
#include <avr/interrupt.h>
#include "EXTI_priv.h"
#include "EXTI_config.h"

EXTI_t EXTI_AstrEXTIConfig[3]=
					 {
							{ACTIVE,FALLING_EDGE},// INT0
							{DEACTIVE},//INT1
							{DEACTIVE} //INT2
						};


