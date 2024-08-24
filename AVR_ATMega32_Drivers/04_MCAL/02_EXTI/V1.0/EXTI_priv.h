/*
 * EXTI_priv.h
 *
 *  Created on: Sep 4, 2023
 *      Author: User
 */

#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_

/*=======state of intrupt=====*/
#define ACTIVE       6
#define DEACTIVE    10
/*======sence Level to triger intrupt======*/
#define RISING_EDGE  5
#define FALLING_EDGE  6
#define NO_CHANGE    7
#define  LOW_LEVEL   10
/*===Number of EXTI====*/
#define MAX_NUM_OF_EXTI   3

#define INT0   0
#define INT1   1
#define INT2   2
/*====EXTI Register====*/
#define MCUCR    *((u8*)0x55)  //Control Register

#define MCUCSR   *((u8*)0x54)  //Control and Status Register

#define GICR     *((u8*)0x5B)  //Genral Intrupt Control Register(PIE)

#define GIFR     *((u8*)0x5A)  //Genral Intrupt Flag Register  (PIF)

#define SREG    *((u8*)0x5F)







#endif /* EXTI_PRIV_H_ */
