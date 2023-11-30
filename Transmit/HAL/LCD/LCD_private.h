#ifndef _LCD_PRIVATE_H
#define _LCD_PRIVATE_H

#define NULL_TERMINATOR			   '\0'
#define LCD_FUNCTION_SET_CMD       0b00111000
#define LCD_ON_OFF_CONTROL         0b00001100
#define LCD_DISPLAY_CLEAR          0b00000001

static void voidSendCommand(u8 Copy_u8Command);

#endif
