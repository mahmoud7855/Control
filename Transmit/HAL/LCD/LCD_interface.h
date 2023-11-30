#ifndef _LCD_INTERFACE_H
#define _LCD_INTERFACE_H

void LCD_voidGotoXY(u8 Copy_u8X, u8 Copy_u8Y);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidGotoXY(u8 Copy_u8X, u8 Copy_u8Y);
void LCD_voidSendNumber(u32 Copy_u32Number);
void LCD_voidSendCustomCharacter(u8 * Ref_pu8CharacterArray, u8 Copy_u8PatternNumber, u8 Copy_u8XPosition, u8 Copy_u8YPosition);
void LCD_voidClearDisplay(void);
void LCD_voidSendSrting(const u8 * Ref_pu8String);
void LCD_voidInit(void);
void LCD_voidInitPins (void);

#endif