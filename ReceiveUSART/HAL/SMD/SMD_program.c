#include <util/delay.h>

#include "../../LIB/Std_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "SMD_config.h"
#include "SMD_private.h"
#include "SMD_interface.h"

static u8 StrideAngle_OneStep = .1757;
u16 Local_u16TurnsNumber = 0;



void SMD_voidInit(void)
{
    DIO_voidSetPortSpecificDirection(SMD_PORT, SMD_PORT_PINS);
}
void SMD_voidContralFullStep (u16 Copy_u16Angle)
{
    
    Local_u16TurnsNumber = Copy_u16Angle / StrideAngle_OneStep;
    u16 Local_u16LoopCounter = 0;
    for(Local_u16LoopCounter = 0; Local_u16LoopCounter <= Local_u16TurnsNumber / 4; Local_u16LoopCounter++)
    {
        DIO_voidSetPinValue(SMD_PORT, SMD_BLUE_PIN, HIGH);
        DIO_voidSetPinValue(SMD_PORT, SMD_PINK_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_YELLOW_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_ORANGE_PIN, LOW);
        _delay_ms(10);
        DIO_voidSetPinValue(SMD_PORT, SMD_BLUE_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_PINK_PIN, HIGH);
        DIO_voidSetPinValue(SMD_PORT, SMD_YELLOW_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_ORANGE_PIN, LOW);
        _delay_ms(10);
        DIO_voidSetPinValue(SMD_PORT, SMD_BLUE_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_PINK_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_YELLOW_PIN, HIGH);
        DIO_voidSetPinValue(SMD_PORT, SMD_ORANGE_PIN, LOW);
        _delay_ms(10);
        DIO_voidSetPinValue(SMD_PORT, SMD_BLUE_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_PINK_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_YELLOW_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_ORANGE_PIN, HIGH);
    }
}
void SMD_voidContralHalfStep (u16 Copy_u16Angle)
{
    
    Local_u16TurnsNumber = Copy_u16Angle / StrideAngle_OneStep;
    u16 Local_u16LoopCounter = 0;
    for(Local_u16LoopCounter = 0; Local_u16LoopCounter <= Local_u16TurnsNumber / 8; Local_u16LoopCounter++)
    {
        DIO_voidSetPinValue(SMD_PORT, SMD_BLUE_PIN, HIGH);
        DIO_voidSetPinValue(SMD_PORT, SMD_PINK_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_YELLOW_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_ORANGE_PIN, LOW);
        _delay_ms(10);
        DIO_voidSetPinValue(SMD_PORT, SMD_BLUE_PIN, HIGH);
        DIO_voidSetPinValue(SMD_PORT, SMD_PINK_PIN, HIGH);
        DIO_voidSetPinValue(SMD_PORT, SMD_YELLOW_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_ORANGE_PIN, LOW);
        _delay_ms(10);
        DIO_voidSetPinValue(SMD_PORT, SMD_BLUE_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_PINK_PIN, HIGH);
        DIO_voidSetPinValue(SMD_PORT, SMD_YELLOW_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_ORANGE_PIN, LOW);
        _delay_ms(10);
        DIO_voidSetPinValue(SMD_PORT, SMD_BLUE_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_PINK_PIN, HIGH);
        DIO_voidSetPinValue(SMD_PORT, SMD_YELLOW_PIN, HIGH);
        DIO_voidSetPinValue(SMD_PORT, SMD_ORANGE_PIN, LOW);
        _delay_ms(10);
        DIO_voidSetPinValue(SMD_PORT, SMD_BLUE_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_PINK_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_YELLOW_PIN, HIGH);
        DIO_voidSetPinValue(SMD_PORT, SMD_ORANGE_PIN, LOW);
        _delay_ms(10);
        DIO_voidSetPinValue(SMD_PORT, SMD_BLUE_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_PINK_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_YELLOW_PIN, HIGH);
        DIO_voidSetPinValue(SMD_PORT, SMD_ORANGE_PIN, HIGH);
        _delay_ms(10);
        DIO_voidSetPinValue(SMD_PORT, SMD_BLUE_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_PINK_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_YELLOW_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_ORANGE_PIN, HIGH);
        _delay_ms(10);
        DIO_voidSetPinValue(SMD_PORT, SMD_BLUE_PIN, HIGH);
        DIO_voidSetPinValue(SMD_PORT, SMD_PINK_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_YELLOW_PIN, LOW);
        DIO_voidSetPinValue(SMD_PORT, SMD_ORANGE_PIN, HIGH);
    }
}

void SMD_voidStop(void)
{
    DIO_voidSetPortSpecificDirection(SMD_PORT, 0x00);
}




