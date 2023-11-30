#include <util/delay.h>

#include "../../LIB/Std_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

static void voidSendCommand(u8 Copy_u8Command)
{
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_Rw, LOW);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_RS, LOW);

    DIO_voidSetPortSpecificValue(LCD_DATA_PORT, Copy_u8Command);

    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_EN, LOW);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_EN, HIGH);
    _delay_ms(2);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_EN, LOW);
}

void LCD_voidSendData(u8 Copy_u8Data)
{

    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_RS, HIGH);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_Rw, LOW);
    

    DIO_voidSetPortSpecificValue(LCD_DATA_PORT, Copy_u8Data);

    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_EN, LOW);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_EN, HIGH);
    _delay_ms(2);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_EN, LOW);
}

void LCD_voidSendNumber(u32 Copy_u32Number)
{
	if(Copy_u32Number == 0)
	{
		LCD_voidSendData('0');
	}
    u8 Local_u8SpllitedNumber[10];
    s8 Local_s8LoopCounter = 0;
    while (Copy_u32Number != 0)
    {
        Local_u8SpllitedNumber[Local_s8LoopCounter] = Copy_u32Number % 10;
        Copy_u32Number /= 10;
        Local_s8LoopCounter++;
    }
    Local_s8LoopCounter--;
    while (Local_s8LoopCounter >= 0)
    {
        LCD_voidSendData(Local_u8SpllitedNumber[Local_s8LoopCounter] + '0');
        Local_s8LoopCounter--;
    }
    
}

void LCD_voidGotoXY(u8 Copy_u8X, u8 Copy_u8Y)
{
    u8 Local_u8Address = 0;
    if(Copy_u8X == 0)
    {
        Local_u8Address = Copy_u8Y;
    }
    else if(Copy_u8X == 1)
    {
        Local_u8Address = Copy_u8Y + 0x40;
    }
    else
    {

    }
    SET_BIT(Local_u8Address, 7);
    voidSendCommand(Local_u8Address);
}

void LCD_voidSendSrting(const u8 * Ref_pu8String)
{
	u8 Local_u8LoopCounter = 0;
	while(Ref_pu8String[Local_u8LoopCounter] != NULL_TERMINATOR)
    {
		LCD_voidSendData(Ref_pu8String[Local_u8LoopCounter]);
		Local_u8LoopCounter++;
	}
}

void LCD_voidSendCustomCharacter(u8 * Ref_pu8CharacterArray, u8 Copy_u8PatternNumber, u8 Copy_u8XPosition, u8 Copy_u8YPosition)
{
    u8 Local_u8LoopCounter = 0;
    /*CALCULATE THE CGRAM ADDRESS OF THE PATTERN = PatternNumber * 8 (The Frist Location)*/
    u8 Local_u8CGRAMAddress = Copy_u8PatternNumber * 8; 
    /*SET THE 6th OF THE SET CGRAM ADDRESS*/
    SET_BIT(Local_u8CGRAMAddress, 6);
    /*SEND THE CGRAM ADDRESS COMMAND TO LCD*/
    voidSendCommand(Local_u8CGRAMAddress);
    /*LOOP ON THE ARRAY AND SEND EASH ELEMENT TO THE LCD TO BE STORED*/
    for(Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++)
    {
        LCD_voidSendData(Ref_pu8CharacterArray[Local_u8LoopCounter]);
    }
    /*Send Command To DDRAM To Store The Data*/
    LCD_voidGotoXY(Copy_u8XPosition, Copy_u8YPosition);
    /*Send The Pattern Number To Display*/
    LCD_voidSendData(Copy_u8PatternNumber);
}
void LCD_voidInit(void)
{
    
    _delay_ms(40);
    /*FUNCTION SET COMMAND*/
    voidSendCommand(LCD_FUNCTION_SET_CMD);
    /*DISPLAY ON/OFF CONTROL*/
    voidSendCommand(LCD_ON_OFF_CONTROL);
    /*DISPLAY CLEAR*/
    voidSendCommand(LCD_DISPLAY_CLEAR);

}

void LCD_voidClearDisplay(void)
{
    voidSendCommand(LCD_DISPLAY_CLEAR);
}

void LCD_voidInitPins (void)
{

    /*Set Data Port To Be OutPut*/
    DIO_voidSetPortDirection(LCD_DATA_PORT, OUTPUT);
    /*Set Contol pin To Be OutPut*/
    DIO_voidSetPortSpecificDirection(LCD_CONTROL_PORT, LCD_SET_CONTROL_PINS);
}
