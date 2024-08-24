/*
 * EXTI_int.h
 *
 *  Created on: Sep 3, 2023
 *      Author: User
 */

#ifndef EXTI_INT_H_
#define EXTI_INT_H_

#define MAX_NUM_OF_EXTI   3

#define EXTI_INT0   0
#define EXTI_INT1   1
#define EXTI_INT2   2

#define EXTI_FALLING_EDGE  4
#define EXTI_RISING_EDGE   5
#define EXTI_LOW_LEVEL     6
#define EXTI_ON_CHANGE     7

ES_t EXTI_enuInit(void);

ES_t EXTI_enuSetSenceMode(u8 Copy_u8SenseMode , u8 Copy_u8INT);

ES_t EXTI_enuEnableINT( u8 Copy_u8INT);

ES_t EXTI_enuDisableINT( u8 Copy_u8INT);

ES_t EXTI_enuClearFlag( u8 Copy_u8INT);

ES_t EXTI_enuCallBack(void (*Copy_pfunAppFun)(void),u8 Copy_u8INT);

#endif /* EXTI_INT_H_ */
