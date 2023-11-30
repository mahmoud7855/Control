#include <avr/delay.h>

#include "../LIB/BIT_MATH.h"
#include "../LIB/Std_Types.h"

#include "../MCAL/UART/UART_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GIE/GIE_interface.h"



#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/KPD/KPD_interface.h"
#include "../HAL/LM35/LM35_interface.h"

void Door (void);
void ReceiveUser (void);
void Wrong (void);
void Admin (void);
void User (void);
void Start (void);

u8 Temp;
u8 U8TempValue = 0;
u8 Speed;
u8 Switchfan;
u8 UserPassword[5] = {1,2,3,4};
u8 AdminPassword[5] = {5, 6 ,7 ,8};
u8 Size = sizeof(UserPassword)-1;
u8 UPass[sizeof(UserPassword)-1] = {0};
u8 CheckCounter = 0;
u8 Counter = 0;
u8 LoopCounter = 0;
u8 PressedKey = 0;
u8 Control = 0;
u8 SelectMode = 0;
u8 Flag = 0;
u8 Trys = 0;
u8 DownCount = 10;
u8 LightValue = 0;
u8 Mapping_Light = 0;
void main (void)
{
	//u8 TempValue = 0;
	UART_voidInit();
	KPD_voidInit();
	LCD_voidInitPins();
	LCD_voidInit();
	ADC_voidInit();
	LM35_voidInit();
	EXTI_voidInit();
	GIE_voidEnableGlobalInterrupt();
	EXTI_voidInterruptContal(EXTI_INT0, EXTI_ENABLE);
	DIO_voidSetPinDirection(PORTD, PIN0, INPUT);
	DIO_voidSetPinDirection(PORTD, PIN1, OUTPUT);
	DIO_voidSetPinDirection(PORTA, PIN1, INPUT);
	DIO_voidSetPinDirection(PORTD, PIN2, INPUT);
	LCD_voidGotoXY(0, 3);
	LCD_voidSendSrting("WELCOME :)");
	_delay_ms(200);
	LCD_voidClearDisplay();
	LCD_voidClearDisplay();
	LCD_voidGotoXY(0, 3);
	LCD_voidSendSrting("SELECT MODE ");
	_delay_ms(200);
	LCD_voidClearDisplay();
	LCD_voidGotoXY(0, 0);
	LCD_voidSendSrting("ADMIN -> 1");
	LCD_voidGotoXY(1, 0);
	LCD_voidSendSrting("USER -> 2");
	Start();
	EXTI_voidSetCallBack(&Door);
	do
	{
		SelectMode = KPD_u8GetPressKey();
	}while(SelectMode == 255);

	if(SelectMode == 1)
	{
		Start();
		LCD_voidClearDisplay();
		LCD_voidSendSrting("ADMIN MODE");
		do
		{
			PressedKey = KPD_u8GetPressKey();
		}while(PressedKey == 255);
		if(PressedKey == 'O')
		{
			LCD_voidClearDisplay();
			LCD_voidGotoXY(0, 0);
			LCD_voidSendSrting("Enter Password");
			LCD_voidGotoXY(1, 0);
		}

	}
	else if(SelectMode == 2)
	{
		Start();
		LCD_voidClearDisplay();
		LCD_voidSendSrting("USER MODE");
		do
		{
			PressedKey = KPD_u8GetPressKey();
		}while(PressedKey == 255);
		if(PressedKey == 'O')
		{
			LCD_voidClearDisplay();
			LCD_voidGotoXY(0, 0);
			LCD_voidSendSrting("Enter Password");
			LCD_voidGotoXY(1, 0);
		}
	}
	while(1)
	{

		EXTI_voidSetCallBack(&Door);
		if(SelectMode == 1)
		{
			Admin();
		}
	    else if(SelectMode == 2)
		{

			User();
		}

	}
}

void Door (void)
{

		u8 Local_u8Pir = 0;
		LCD_voidClearDisplay();
		Temp = 'O';
		UART_TransmitData(Temp);
		Local_u8Pir = DIO_u8GetPinValue(PORTD, PIN2);
		UART_TransmitData(Local_u8Pir);
		LCD_voidSendSrting("Door is Open");
		_delay_ms(500);
		LCD_voidClearDisplay();
		LCD_voidGotoXY(0, 0);
		LCD_voidSendSrting("TEMP -> 1");
		LCD_voidGotoXY(1, 0);
		LCD_voidSendSrting("LIGHT -> 2");
}

void Wrong (void)
{
	LCD_voidClearDisplay();
	LCD_voidGotoXY(0, 0);
	LCD_voidSendSrting("WRONG PASS");
	LCD_voidGotoXY(1, 4);
	LCD_voidSendSrting("TRY AGAIN");
	_delay_ms(500);
	LCD_voidClearDisplay();
	Counter = 0;
	CheckCounter = 0;
	Trys++;
	if(Trys != 2)
	{
		LCD_voidClearDisplay();
		LCD_voidGotoXY(0, 0);
		LCD_voidSendSrting("Enter Password");
		LCD_voidGotoXY(1, 0);
	}
}

void SendAdmin (void)
{

	u8 LightValue = 0;
	u8 Local_u8Key = 0;
	u8 Key = 0;
	u8 Mapping_Light = 0;
	u8 TempValue = 0;
	LCD_voidGotoXY(0, 0);
	LCD_voidSendSrting("1-> TEMP");
	LCD_voidGotoXY(1, 0);
	LCD_voidSendSrting("3-> LIGHT ");
	LCD_voidGotoXY(0, 9);
	LCD_voidSendSrting("2-> FAN");
	do
	{
		Local_u8Key = KPD_u8GetPressKey();
	}while(Local_u8Key == 255);
	while(Local_u8Key == 1)
	{
		LCD_voidClearDisplay();
		Temp = 'T';
		UART_TransmitData(Temp);
		U8TempValue = LM35_u8GetTempratureSynchronous();
		LCD_voidGotoXY(0, 0);
		LCD_voidSendSrting("TEMP: ");
		LCD_voidGotoXY(0, 5);
		LCD_voidSendNumber(U8TempValue);
		UART_TransmitData(U8TempValue);
		if(U8TempValue < 25)
		{
			Speed = 20;
			UART_TransmitData(Speed);
		}
		else if(U8TempValue >= 25 &&  U8TempValue < 30)
		{
			Speed = 70;
			UART_TransmitData(Speed);
		}
		else if(U8TempValue >= 30 && U8TempValue < 35)
		{
			Speed = 150;
			UART_TransmitData(Speed);
		}
		else if(U8TempValue >= 35)
		{
			Speed = 255;
			UART_TransmitData(Speed);
		}

		LCD_voidGotoXY(1, 0);
		LCD_voidSendSrting("1-> TO SET ");
		_delay_ms(100);
		do
		{
			Key = KPD_u8GetPressKey();
		}while(Key == 255);
		if(Key == 'O')
		{
			LCD_voidClearDisplay();
			break;
		}
	}
	while(Local_u8Key == 2)
	{
		LCD_voidClearDisplay();
		Temp = 'F';
		UART_TransmitData(Temp);
		LCD_voidGotoXY(0, 0);
		LCD_voidSendSrting("1-> HIGH");
		LCD_voidGotoXY(0, 9);
		LCD_voidSendSrting("2-> MID");
		LCD_voidGotoXY(1, 0);
		LCD_voidSendSrting("3-> LOW");

		do
		{

			Switchfan = KPD_u8GetPressKey();
		}while(Switchfan == 255);
		if(Switchfan == 1)
		{
			LCD_voidClearDisplay();
			LCD_voidGotoXY(0, 0);
			LCD_voidSendSrting("HIGH SPEED");
			Speed = 255;
			UART_TransmitData(Speed);
		}
		else if(Switchfan == 2)
		{
			LCD_voidClearDisplay();
			LCD_voidGotoXY(0, 0);
			LCD_voidSendSrting("MID SPEED");
			Speed = 150;
			UART_TransmitData(Speed);
		}
		else if(Switchfan == 3)
		{
			LCD_voidClearDisplay();
			LCD_voidGotoXY(0, 0);
			LCD_voidSendSrting("LOW SPEED");
			Speed = 70;
			_delay_ms(100);
			UART_TransmitData(Speed);
		}
		_delay_ms(100);
		do
		{
			Key = KPD_u8GetPressKey();
		}while(Key == 255);
		if(Key == 'O')
		{
			LCD_voidClearDisplay();
			LCD_voidGotoXY(0, 0);
			LCD_voidSendSrting("1-> HIGH");
			LCD_voidGotoXY(0, 9);
			LCD_voidSendSrting("2-> MID");
			LCD_voidGotoXY(1, 0);
			LCD_voidSendSrting("3-> LOW");
			do
			{
				Key = KPD_u8GetPressKey();
			}while(Key == 255);
			if(Key == 'O')
			{
				LCD_voidClearDisplay();
				break;
			}

		}
	}
	while(Local_u8Key == 3)
	{
		LCD_voidClearDisplay();
		Temp = 'L';
		UART_TransmitData(Temp);
		Mapping_Light = ACD_voidStartConversionSynchronous(ADC_Channel_1);
		LightValue = ADC_voidMapping(255, 0, 243, 2, Mapping_Light);
		LCD_voidGotoXY(0, 0);
		LCD_voidSendSrting("LIGHT: ");
		LCD_voidGotoXY(0, 7);
		LCD_voidSendNumber(LightValue + 2);
		UART_TransmitData(LightValue + 2);
		LCD_voidGotoXY(1, 0);
		LCD_voidSendSrting("TO SET -> 3");
		_delay_ms(100);
		do
		{
			Key = KPD_u8GetPressKey();
		}while(Key == 255);
		if(Key == 'O')
		{
			LCD_voidClearDisplay();
			break;
		}
	}

}

void Admin (void)
{
	while(Trys < 2)
	{
		Start();
		do
		{
			PressedKey = KPD_u8GetPressKey();
		}while(PressedKey == 255);
		if(PressedKey >= 0 && PressedKey != 'C')
		{
			LCD_voidSendData('*');
			UPass[Counter] = PressedKey;
			Counter++;
		}
		else if(PressedKey == 'C')
		{
			if(Counter == Size)
			{
				for(LoopCounter = 0; LoopCounter < Size; LoopCounter++)
				{
					if(UPass[LoopCounter] == AdminPassword[LoopCounter])
					{
						CheckCounter++;
					}
				}
				if(CheckCounter == Size)
				{
					LCD_voidClearDisplay();
					LCD_voidGotoXY(0, 0);
					LCD_voidSendSrting("CORRECT PASS");
					_delay_ms(500);
					LCD_voidClearDisplay();
					Flag = 1;
					while(Flag == 1)
					{
						SendAdmin();
					}
				}
				else
				{
					Wrong();
				}
			}
			else
			{
				Wrong();
			}
		}
	}
	while(Flag == 0)
	{
		LCD_voidClearDisplay();
		LCD_voidGotoXY(0, 0);
		LCD_voidSendSrting("MAX TRYS");
		LCD_voidGotoXY(1, 0);
		LCD_voidSendNumber(DownCount);
		_delay_ms(100);
		DownCount--;
		if(DownCount == 0)
		{
			Trys = 0;
			DownCount = 10;
			DownCount += 10;
			break;
		}
	}
	LCD_voidClearDisplay();
	LCD_voidGotoXY(0, 0);
	LCD_voidSendSrting("Enter Password");
	LCD_voidGotoXY(1, 0);
}


void User (void)
{
	while(Trys < 2)
	{
		Start();
		do
		{
			PressedKey = KPD_u8GetPressKey();
		}while(PressedKey == 255);
		if(PressedKey >= 0 && PressedKey != 'C')
		{
			LCD_voidSendData('*');
			UPass[Counter] = PressedKey;
			Counter++;
		}
		else if(PressedKey == 'C')
		{
			if(Counter == Size)
			{
				for(LoopCounter = 0; LoopCounter < Size; LoopCounter++)
				{
					if(UPass[LoopCounter] == UserPassword[LoopCounter])
					{
						CheckCounter++;
					}
				}
				if(CheckCounter == Size)
				{
					LCD_voidClearDisplay();
					LCD_voidGotoXY(0, 0);
					LCD_voidSendSrting("CORRECT PASS");
					_delay_ms(500);
					LCD_voidClearDisplay();
					Flag = 1;
					while(Flag == 1)
					{

						ReceiveUser();
					}
				}
				else
				{
					Wrong();
				}
			}
			else
			{
				Wrong();
			}
		}
	}
	while(Flag == 0)
	{
		LCD_voidClearDisplay();
		LCD_voidGotoXY(0, 0);
		LCD_voidSendSrting("MAX TRYS");
		LCD_voidGotoXY(1, 0);
		LCD_voidSendNumber(DownCount);
		_delay_ms(100);
		DownCount--;
		if(DownCount == 0)
		{
			Trys = 0;
			DownCount = 10;
			DownCount += 10;
			break;
		}
	}
	LCD_voidClearDisplay();
	LCD_voidGotoXY(0, 0);
	LCD_voidSendSrting("Enter Password");
	LCD_voidGotoXY(1, 0);
}


void ReceiveUser (void)
{
	u8 LightValue = 0;
	u8 Local_u8Key = 0;
	u8 Key = 0;
	u8 Mapping_Light = 0;
	LCD_voidGotoXY(1, 0);
	LCD_voidSendSrting("2-> LIGHT");
	LCD_voidGotoXY(0, 9);
	LCD_voidSendSrting("1-> FAN");
	EXTI_voidSetCallBack(&Door);
	LCD_voidGotoXY(0, 0);
	UART_TransmitData('T');
	UART_TransmitData(U8TempValue);
	U8TempValue = 30;
	LCD_voidSendSrting("TEMP: ");
	UART_TransmitData(Speed);
	LCD_voidGotoXY(0, 5);
	LCD_voidSendNumber(U8TempValue);

	do
	{
		Key = KPD_u8GetPressKey();
	}while(Key == 255);
	while(Key == 1)
	{
		LCD_voidClearDisplay();
		Temp = 'F';
		UART_TransmitData(Temp);
		LCD_voidGotoXY(0, 0);
		LCD_voidSendSrting("1-> HIGH");
		LCD_voidGotoXY(0, 9);
		LCD_voidSendSrting("2-> MID");
		LCD_voidGotoXY(1, 0);
		LCD_voidSendSrting("3-> LOW");

		do
		{

			Switchfan = KPD_u8GetPressKey();
		}while(Switchfan == 255);
		if(Switchfan == 1)
		{
			LCD_voidClearDisplay();
			LCD_voidGotoXY(0, 0);
			LCD_voidSendSrting("HIGH SPEED");
			Speed = 255;
			UART_TransmitData(Speed);
		}
		else if(Switchfan == 2)
		{
			LCD_voidClearDisplay();
			LCD_voidGotoXY(0, 0);
			LCD_voidSendSrting("MID SPEED");
			Speed = 150;
			UART_TransmitData(Speed);
		}
		else if(Switchfan == 3)
		{
			LCD_voidClearDisplay();
			LCD_voidGotoXY(0, 0);
			LCD_voidSendSrting("LOW SPEED");
			Speed = 70;
			_delay_ms(100);
			UART_TransmitData(Speed);
		}
		_delay_ms(100);
		do
		{
			Key = KPD_u8GetPressKey();
		}while(Key == 255);
		if(Key == 'O')
		{
			LCD_voidClearDisplay();
			LCD_voidGotoXY(0, 0);
			LCD_voidSendSrting("1-> HIGH");
			LCD_voidGotoXY(0, 9);
			LCD_voidSendSrting("2-> MID");
			LCD_voidGotoXY(1, 0);
			LCD_voidSendSrting("3-> LOW");
		}
	}
	while(Key == 2)
	{
		LCD_voidClearDisplay();
		Temp = 'L';
		UART_TransmitData(Temp);
		Mapping_Light = ACD_voidStartConversionSynchronous(ADC_Channel_1);
		LightValue = ADC_voidMapping(255, 0, 243, 2, Mapping_Light);
		LCD_voidGotoXY(0, 0);
		LCD_voidSendSrting("LIGHT: ");
		LCD_voidGotoXY(0, 7);
		LCD_voidSendNumber(LightValue + 2);
		UART_TransmitData(LightValue + 2);
		LCD_voidGotoXY(1, 0);
		LCD_voidSendSrting("TO SET -> 2");
		_delay_ms(100);
		do
		{
			Key = KPD_u8GetPressKey();
		}while(Key == 255);
		if(Key == 'O')
		{
			LCD_voidClearDisplay();
			break;
		}
	}
}

void Start (void)
{
	Temp = 'T';
	UART_TransmitData(Temp);
	U8TempValue = LM35_u8GetTempratureSynchronous();
	UART_TransmitData(U8TempValue);
	if(U8TempValue < 25)
	{
		Speed = 20;
		UART_TransmitData(Speed);
	}
	else if(U8TempValue >= 25 &&  U8TempValue < 30)
	{
		Speed = 70;
		UART_TransmitData(Speed);
	}
	else if(U8TempValue >= 30 && U8TempValue < 35)
	{
		Speed = 150;
		UART_TransmitData(Speed);
	}
	else if(U8TempValue >= 35)
	{
		Speed = 255;
		UART_TransmitData(Speed);
	}
	_delay_ms(10);
	Temp = 'L';
	UART_TransmitData(Temp);
	Mapping_Light = ACD_voidStartConversionSynchronous(ADC_Channel_1);
	LightValue = ADC_voidMapping(255, 0, 243, 2, Mapping_Light);
	UART_TransmitData(LightValue);
	_delay_ms(10);
}





