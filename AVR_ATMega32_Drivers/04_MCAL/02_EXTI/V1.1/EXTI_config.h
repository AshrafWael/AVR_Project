/*
 * EXTI_config.h
 *
 *  Created on: Sep 3, 2023
 *      Author: User
 */

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_


/*
 Options :-
 	 1-EXTI_INT0
 	 2-EXTI_INT1
 	 3-EXTI_INT2
 */
#define EXTI_INT   EXTI_INT1
/* Sense Mode
 Options :-
 	 1-EXTI_FALLING_EDGE
 	 2-EXTI_RISING_EDGE
 	 3-EXTI_LOW_LEVEL
 	 4-EXTI_ON_CHANGE
 */

#define EXTI_SENSE_MODE  EXTI_FALLING_EDGE


#endif /* EXTI_CONFIG_H_ */
