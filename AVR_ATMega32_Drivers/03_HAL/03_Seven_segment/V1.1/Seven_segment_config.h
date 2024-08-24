/*
 * Seven_segment_config.h
 *
 *  Created on: May 10, 2023
 *      Author: User
 */

#ifndef SEVEN_SEGMENT_CONFIG_H_
#define SEVEN_SEGMENT_CONFIG_H_

#include "DIO_init.h"

#define SEG_NUM  2

typedef struct
{
	 u8 SEG_u8APORT;
	 u8 SEG_u8APIN;

	 u8 SEG_u8BPORT;
	 u8 SEG_u8BPIN;

	 u8 SEG_u8CPORT;
	 u8 SEG_u8CPIN;

	 u8 SEG_u8DPORT;
	 u8 SEG_u8DPIN;

	 u8 SEG_u8EPORT;
	 u8 SEG_u8EPIN;

	 u8 SEG_u8FPORT;
	 u8 SEG_u8FPIN;

	 u8 SEG_u8GPORT;
	 u8 SEG_u8GPIN;

	 u8 SEG_u8CMNPORT;
	 u8 SEG_u8CMNPIN;

	 u8 SEG_u8DOTPORT;
	 u8 SEG_u8DOTPIN;

	 u8 SEG_u8TYPE ;



}SEG_t;

#endif /* SEVEN_SEGMENT_CONFIG_H_ */
