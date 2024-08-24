/*
 * EXTI_priv.h
 *
 *  Created on: Sep 3, 2023
 *      Author: User
 */

#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_

/*====EXTI Register====*/
#define MCUCR    *((volatile u8*)0x55)  //Control Register

#define MCUCSR   *((volatile u8*)0x54)  //Control and Status Register

#define GICR     *((volatile u8*)0x5B)  //Genral Intrupt Control Register(PIE)

#define GIFR     *((volatile u8*)0x5A)  //Genral Intrupt Flag Register  (PIF)

#define SREG       *(( volatile u8*)0x5F)

#endif /* EXTI_PRIV_H_ */
