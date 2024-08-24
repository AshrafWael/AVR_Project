/*
 * Seven_segment_int.h
 *
 *  Created on: May 10, 2023
 *      Author: User
 */

#ifndef SEVEN_SEGMENT_INT_H_
#define SEVEN_SEGMENT_INT_H_

#include "stdTypes.h"
#include "erorSTATE.h"

#include "Seven_segment_config.h"

ES_t Seven_Segment_enuInt(SEG_t *Copy_u8pstrSegConfig);

ES_t Seven_Segment_enuDisplayNum(u8 Copy_u8SegID,u8 Copy_u8NUM);

ES_t Seven_Segment_enuEnable_Common(u8 Copy_u8SegID);

ES_t Seven_Segment_enuDisableCommon(u8 Copy_u8SegID);

ES_t Seven_Segment_enuEnableDot(u8 Copy_u8SegID);

ES_t Seven_Segment_enuDisableDot(u8 Copy_u8SegID);

ES_t Seven_Segment_enuClearDisplay(u8 Copy_u8SegID);



#endif /* SEVEN_SEGMENT_INT_H_ */
