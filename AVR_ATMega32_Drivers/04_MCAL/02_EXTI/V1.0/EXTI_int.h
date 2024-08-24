/*
 * EXTI_int.h
 *
 *  Created on: Sep 4, 2023
 *      Author: User
 */

#ifndef EXTI_INT_H_
#define EXTI_INT_H_

ES_t EXTI_enuInit(EXTI_t *Copy_PstrEXTIConfig);

ES_t EXTI_enuSetSenceMode(u8 Copy_PstrEXTI_ID,u8 Copy_u8SenceLevel);

ES_t EXTI_enuEnableINT(u8 Copy_PstrEXTI_ID);

ES_t EXTI_enuDisableINT(u8 Copy_PstrEXTI_ID);

ES_t EXTI_enuCallBack(void (*Copy_pfunAppFun) (void*),void * Copy_pvidParameter,u8 Copy_PstrEXTI_ID);






#endif /* EXTI_INT_H_ */
