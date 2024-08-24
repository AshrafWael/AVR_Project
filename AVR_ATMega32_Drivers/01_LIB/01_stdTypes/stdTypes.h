/*****************************************************************************/
/* Title        	: 	STD TYPES File									     */
/* File Name    	: 	STD_TYPES.h  		                                 */
/* Author       	: 	Ashraf Wael                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	11/08/2022                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/
#ifndef STDTYPES_H_
#define STDTYPES_H_


/* Boolean data type */
typedef unsigned char bool_t;
#define TRUE    ((bool_t) 1)
#define FALSE   ((bool_t) 0)

#define NULL (void*)0
/* Standard unsigned integer data types */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

/* Standard signed integer data types */
typedef signed char int8_t;
//typedef signed short int16_t;
typedef signed long int32_t;
typedef signed long long int64_t;

/* Standard floating-point data types */
typedef float float32_t;
typedef double float64_t;

/* Standard pointer data types */
typedef void* void_ptr;
typedef const void* const_void_ptr;

#endif /* STDTYPES_H_ */
