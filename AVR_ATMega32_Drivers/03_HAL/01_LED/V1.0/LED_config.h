/*
 * LED_config.h
 *
 *  Created on: May 7, 2023
 *      Author: User
 */

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

#define LED_NUM  3

typedef struct {
	u8 LED_u8PortID;
	u8 LED_u8PinID;
	u8 LED_u8Conection;
	u8 LED_u8IntialStatus;
}LED_t;


#endif /* LED_CONFIG_H_ */
