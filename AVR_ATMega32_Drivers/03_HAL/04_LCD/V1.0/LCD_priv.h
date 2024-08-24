/*
 * LCD_priv.h
 *
 *  Created on: May 12, 2023
 *      Author: User
 */

#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_


#define  EGHT_BIT   5
#define  FOUR_BIT   10

static inline void LCD_invidSendCommand( u8 Copy_u8Command);

static void LCD_vidLatch(u8 Copy_u8Data);



#define 	LCD_ZERO		0
#define 	LCD_ONE			1
#define 	LCD_TWO			2
#define 	LCD_THREE		3
#define 	LCD_FOUR		4
#define 	LCD_FIVE		5
#define 	LCD_SIX			6
#define 	LCD_SEVEN		7
#define 	LCD_EIGHT		8
#define 	LCD_TEN			10
#define		LCD_MAX_CGRAM	64
#endif /* LCD_PRIV_H_ */
