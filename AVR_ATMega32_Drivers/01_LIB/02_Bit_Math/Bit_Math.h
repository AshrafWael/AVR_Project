/*****************************************************************************/
/* Title        	: 	BIT_MATH File									     */
/* File Name    	: 	Bit_Math.h  		                                 */
/* Author       	: 	Ashraf Wael                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	11/08/2022                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: None                              	 	 		  *
******************************************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H
/*Set bit*/
#define SET_BIT(var,bit) var=var|(1<<bit) 
/*Clear bit*/
#define CLEAR_BIT(var,bit) var=var&(~(1<<bit))
/*Get bit*/
#define GET_BIT(var,bit) ((var>>bit)&1)
/*Toggle bit*/
#define TOGGLE_BIT(var,bit) var=var^(1<<bit) 

#endif