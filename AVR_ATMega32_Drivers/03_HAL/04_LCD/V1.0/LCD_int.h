/*
 * LCD_int.h
 *
 *  Created on: May 12, 2023
 *      Author: User
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_


ES_t LCD_enuInt(void);

ES_t LCD_enuSendCommand(u8 Copy_u8Command);

ES_t LCD_enuDisplayChar(u8 Copy_u8Data);

void LCD_enuDisplayNumber(u32 Copy_u32Number);

ES_t LCD_enuDisplayString(u8 *Copy_pu8Data);

ES_t  LCD_enuSetPosition(u8 Copy_u8Row ,u8 Copy_u8Colom);


#endif /* LCD_INT_H_ */
