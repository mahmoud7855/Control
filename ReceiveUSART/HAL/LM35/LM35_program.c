#include"../../LIB/Std_Types.h"
#include"../../LIB/BIT_MATH.h"

#include"../../MCAL/DIO/DIO_interface.h"
#include"../../MCAL/ADC/ADC_interface.h"


#include "LM35_interface.h"
#include "LM35_private.h"
#include "LM35_config.h"


void LM35_voidInit(void)
{
	DIO_voidSetPinDirection(LM35_PORT, LM35_CHANNEL, INPUT);
	ADC_voidInit();
}

static u8 StepSize = (u8)(5000UL / 256UL);
u8 LM35_u8GetTempratureSynchronous (void)
{
	u8 Local_u8DigitalValue  = 0;
	u16 Local_u8AnalogValue  = 0;
	u8 Local_u8TempValue     = 0;
	
	Local_u8DigitalValue = ACD_voidStartConversionSynchronous(ADC_Channel_0);
	Local_u8AnalogValue  = (u16) ((u8)Local_u8DigitalValue * (u8)StepSize);
	Local_u8TempValue    = (u8)((u32)Local_u8AnalogValue / 10UL);

	return(Local_u8TempValue);
}

u8 TempValue   = 255;
void LM35_u8GetTempratureASynchronous(u8 *Ref_u8Digital)
{
	u8 Local_u8DigitalValue  = 0;
	u16 Local_u8AnalogValue  = 0;
	Local_u8AnalogValue = (u16) ((u8)(*Ref_u8Digital)) * (u8)StepSize;
	TempValue = (u8)((u32)Local_u8AnalogValue / 10UL);

}

u8 LM35_ASynchronous (void)
{
	ACD_voidStartConversionASynchronous(ADC_Channel_0, &LM35_u8GetTempratureASynchronous);
	return(TempValue);
}





