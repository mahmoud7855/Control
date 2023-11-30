#include "../LIB/BIT_MATH.h"
#include "../LIB/Std_Types.h"

#include <avr/delay.h>

#include "../MCAL/UART/UART_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"
#include "../MCAL/GIE/GIE_interface.h"

void main (void)
{
	UART_voidInit();
	LCD_voidInitPins();
	LCD_voidInit();
	TIMER_voidTimer0Init();
	TIMER_voidTimer1Init();
	TIMER_voidTimer1SetTopValue(20000);
	DIO_voidSetPinDirection(PORTD, PIN0, INPUT);
	DIO_voidSetPinDirection(PORTD, PIN1, OUTPUT);
	DIO_voidSetPinDirection(PORTB, PIN3, OUTPUT);
	DIO_voidSetPinDirection(PORTB, PIN4, OUTPUT);
	DIO_voidSetPinDirection(PORTB, PIN5, OUTPUT);

	DIO_voidSetPinDirection(PORTC, PIN0, OUTPUT);
	DIO_voidSetPinDirection(PORTC, PIN1, OUTPUT);
	DIO_voidSetPinDirection(PORTC, PIN2, OUTPUT);
	DIO_voidSetPinDirection(PORTC, PIN3, OUTPUT);
	DIO_voidSetPinDirection(PORTC, PIN4, OUTPUT);
	DIO_voidSetPinDirection(PORTC, PIN5, OUTPUT);
	DIO_voidSetPinDirection(PORTC, PIN6, OUTPUT);
	DIO_voidSetPinDirection(PORTC, PIN7, OUTPUT);
	DIO_voidSetPortSpecificValue(PORTC, 0b00000000);

	DIO_voidSetPinValue(PORTB, PIN4, HIGH);
	DIO_voidSetPinValue(PORTB, PIN5, LOW);

	DIO_voidSetPinDirection(PORTD, PIN5, OUTPUT);

	u8 Signal = 0;
	u8 Speed = 0;
	u8 TempValue = 0;
	u8 Light = 0;
	u8 LightValue = 0;
	u8 PirState = 0;
	while(1)
	{

		u8 Local_u8StoreTemp = 0;
		u8 Local_u8StoreLight = 0;
		UART_voidReceiveDataSynchronous(&Signal);

		if(Signal == 'T')
		{
			UART_voidReceiveDataSynchronous(&TempValue);
			Local_u8StoreTemp = TempValue;
			LCD_voidSendNumber(Local_u8StoreTemp);
			UART_voidReceiveDataSynchronous(&Speed);
			if(Local_u8StoreTemp < 25)
			{
				TIMER_voidTimer0SetCOMatchValue(20);
			}
			else if(Local_u8StoreTemp >= 25 &&  Local_u8StoreTemp < 30)
			{
				TIMER_voidTimer0SetCOMatchValue(Speed);
			}
			else if(Local_u8StoreTemp >= 30 && Local_u8StoreTemp < 35)
			{
				TIMER_voidTimer0SetCOMatchValue(Speed);
			}
			else if(Local_u8StoreTemp >= 35)
			{
				TIMER_voidTimer0SetCOMatchValue(Speed);
			}
		}
		if(Signal == 'L')
		{
			UART_voidReceiveDataSynchronous(&LightValue);
			Local_u8StoreLight = LightValue;
			//LCD_voidGotoXY(0, 0);
			//_delay_ms(100);
			//LCD_voidClearDisplay();
			//LCD_voidSendNumber(Local_u8StoreLight);
			if(Local_u8StoreLight < 20)
			{
				DIO_voidSetPortSpecificValue(PORTC, 0b11111111);

			}
			else if(Local_u8StoreLight >= 20 && Local_u8StoreLight < 70)
			{
				DIO_voidSetPortSpecificValue(PORTC, 0b00111111);
			}

			else if(Local_u8StoreLight >= 70 && Local_u8StoreLight < 120)
			{
				DIO_voidSetPortSpecificValue(PORTC, 0b00011111);
			}

			else if(Local_u8StoreLight >= 120 && Local_u8StoreLight < 170)
			{
				DIO_voidSetPortSpecificValue(PORTC, 0b00001111);

			}
			else if(Local_u8StoreLight >= 170 && Local_u8StoreLight < 210)
			{
				DIO_voidSetPortSpecificValue(PORTC, 0b00000111);
			}
			else if(Local_u8StoreLight >= 210 && Local_u8StoreLight < 230)
			{
				DIO_voidSetPortSpecificValue(PORTC, 0b00000011);
			}

			else if(Local_u8StoreLight >= 230 && Local_u8StoreLight < 255)
			{
				DIO_voidSetPortSpecificValue(PORTC, 0b00000000);
			}

		}
		if(Signal == 'F')
		{
			UART_voidReceiveDataSynchronous(&Speed);
			if(Speed == 255)
			{
				TIMER_voidTimer0SetCOMatchValue(Speed);
			}
			else if(Speed == 150)
			{
				TIMER_voidTimer0SetCOMatchValue(Speed);
			}
			else if(Speed == 70)
			{
				TIMER_voidTimer0SetCOMatchValue(Speed);
			}
		}
		if(Signal == 'O')
		{
			UART_voidReceiveDataSynchronous(&PirState);
			if(PirState == HIGH)
			{
				TIMER_voidTimer1SetCompareMatchTime(1500);
			}
		}

	}

}


