/*****************************************************************************/
/* Title        	: 	ERORSTATE File									     */
/* File Name    	: 	errorSTATE.h  		                                 */
/* Author       	: 	Ashraf Wael                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	11/08/2022                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: None                              	 	 		  *
******************************************************************************/
#ifndef ERORSTATE_H_
#define ERORSTATE_H_

typedef enum
{
 ES_NOK,          //0
 ES_OK,           //1
 ES_NULL_POINTER, //2
 ES_OUT_OF_RANGE //3
}ES_t;

#endif /* ERORSTATE_H_ */
