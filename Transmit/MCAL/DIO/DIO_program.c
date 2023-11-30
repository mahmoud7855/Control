/*Library Inclusion*/
#include "../../LIB/Std_Types.h"
#include "../../LIB/BIT_MATH.h"

/*Lower Layer Inclusion*/


/*Self Layer Inclusion*/


/*Self Files Inclusion*/
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidSetPinDirection (u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
    if(Copy_u8PortName <= PORTD && Copy_u8PinNumber <= PIN7 && Copy_u8PinValue <= OUTPUT)
    {
        switch (Copy_u8PortName)
        {
            case PORTA:
                if(Copy_u8PinValue == OUTPUT)
                {
                    SET_BIT(DIO_DDRA, Copy_u8PinNumber);
                }
                else if(Copy_u8PinValue == INPUT)
                {
                    CLR_BIT(DIO_DDRA, Copy_u8PinNumber);
                }
                else
                {

                }
                break;
            case PORTB:
                if(Copy_u8PinValue == OUTPUT)
                {
                    SET_BIT(DIO_DDRB, Copy_u8PinNumber);
                }
                else if(Copy_u8PinValue == INPUT)
                {
                    CLR_BIT(DIO_DDRB, Copy_u8PinNumber);
                }
                else
                {

                }
                break;
            case PORTC:
                if(Copy_u8PinValue == OUTPUT)
                {
                    SET_BIT(DIO_DDRC, Copy_u8PinNumber);
                }
                else if(Copy_u8PinValue == INPUT)
                {
                    CLR_BIT(DIO_DDRC, Copy_u8PinNumber);
                }
                else
                {

                }
                break;
            case PORTD:
                if(Copy_u8PinValue == OUTPUT)
                {
                    SET_BIT(DIO_DDRD, Copy_u8PinNumber);
                }
                else if(Copy_u8PinValue == INPUT)
                {
                    CLR_BIT(DIO_DDRD, Copy_u8PinNumber);
                }
                else
                {

                }
                break;

            default:
            break;
        }
    }
    else
    {

    }
}

void DIO_voidSetPinValue (u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
    if(Copy_u8PortName <= PORTD && Copy_u8PinNumber <= PIN7 && Copy_u8PinValue <= HIGH)
    {
        switch(Copy_u8PortName)
        {
            case PORTA:
            if(Copy_u8PinValue == HIGH)
            {
                SET_BIT(DIO_PORTA, Copy_u8PinNumber);
            }
            else if(Copy_u8PinValue == LOW)
            {
                CLR_BIT(DIO_PORTA, Copy_u8PinNumber);
            }
            else
            {

            }
            break;

            case PORTB:
            if(Copy_u8PinValue == HIGH)
            {
                SET_BIT(DIO_PORTB, Copy_u8PinNumber);
            }
            else if(Copy_u8PinValue == LOW)
            {
                CLR_BIT(DIO_PORTB, Copy_u8PinNumber);
            }
            else
            {

            }
            break;

            case PORTC:
            if(Copy_u8PinValue == HIGH)
            {
                SET_BIT(DIO_PORTC, Copy_u8PinNumber);
            }
            else if(Copy_u8PinValue == LOW)
            {
                CLR_BIT(DIO_PORTC, Copy_u8PinNumber);
            }
            else
            {

            }
            break;

            case PORTD:
            if(Copy_u8PinValue == HIGH)
            {
                SET_BIT(DIO_PORTD, Copy_u8PinNumber);
            }
            else if(Copy_u8PinValue == LOW)
            {
                CLR_BIT(DIO_PORTD, Copy_u8PinNumber);
            }
            else
            {

            }
            break;

            default:
            break;
        }
    }
    else
    {

    }
}

void DIO_voidSetPinPullUp (u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PullupState)
{
    if(Copy_u8PortName <= PORTD && Copy_u8PinNumber <= PIN7 && Copy_u8PullupState <= PULLUP)
    {
        switch (Copy_u8PortName)
        {
            case PORTA:
                switch (Copy_u8PullupState)
                {
                    case PULLUP:
                        CLR_BIT(DIO_DDRA, Copy_u8PinNumber);
                        SET_BIT(DIO_PORTA, Copy_u8PinNumber);
                    break;

                    case NOPULLUP:
                        CLR_BIT(DIO_PORTA, Copy_u8PinNumber);
                    break;
                }
            break;

            case PORTB:
                switch (Copy_u8PullupState)
                {
                    case PULLUP:
                        CLR_BIT(DIO_DDRB, Copy_u8PinNumber);
                        SET_BIT(DIO_PORTB, Copy_u8PinNumber);
                    break;

                    case NOPULLUP:
                        CLR_BIT(DIO_PORTB, Copy_u8PinNumber);
                    break;
                }
            break;

            case PORTC:
                switch (Copy_u8PullupState)
                {
                    case PULLUP:
                        CLR_BIT(DIO_DDRC, Copy_u8PinNumber);
                        SET_BIT(DIO_PORTC, Copy_u8PinNumber);
                    break;

                    case NOPULLUP:
                        CLR_BIT(DIO_PORTC, Copy_u8PinNumber);
                    break;
                }
            break;

            case PORTD:
                switch (Copy_u8PullupState)
                {
                    case PULLUP:
                        CLR_BIT(DIO_DDRD, Copy_u8PinNumber);
                        SET_BIT(DIO_PORTD, Copy_u8PinNumber);
                    break;

                    case NOPULLUP:
                        CLR_BIT(DIO_PORTD, Copy_u8PinNumber);
                    break;
            
                }
            break;

            default:
            break;
        }
    }
    else
    {

    }
}

u8 DIO_u8GetPinValue (u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
    
	u8 DIO_u8StorePinValue = 0;
    if(Copy_u8PortName <= PORTD && Copy_u8PinNumber <= PIN7)
    {
        switch (Copy_u8PortName)
        {
            case PORTA:
                DIO_u8StorePinValue = GET_BIT(DIO_PINA, Copy_u8PinNumber);
            break;

            case PORTB:
                DIO_u8StorePinValue = GET_BIT(DIO_PINB, Copy_u8PinNumber);
            break;

            case PORTC:
                DIO_u8StorePinValue = GET_BIT(DIO_PINC, Copy_u8PinNumber);
            break;

            case PORTD:
                DIO_u8StorePinValue = GET_BIT(DIO_PIND, Copy_u8PinNumber);
            break;

            default:
            break;
        }


    }
    else
    {

    }
    return(DIO_u8StorePinValue);
}

void DIO_voidSetPortSpecificDirection (u8 Copy_u8PortName, u8 Copy_u8PinDirection)
{
    if(Copy_u8PortName <= PORTD && Copy_u8PinDirection <= 0XFF)
    {
        switch (Copy_u8PortName)
        {
            case PORTA:
                DIO_DDRA = Copy_u8PinDirection;
            break;

            case PORTB:
                DIO_DDRB = Copy_u8PinDirection;
            break;

            case PORTC:
                DIO_DDRC = Copy_u8PinDirection;
            break;

            case PORTD:
                DIO_DDRD = Copy_u8PinDirection;
            break;

            default:

            break;
        }
    }
    else
    {

    }
}

void DIO_voidSetPortSpecificValue (u8 Copy_u8PortName, u8 Copy_u8PortValue)
{
    if(Copy_u8PortName <= PORTD && Copy_u8PortValue <= 0XFF)
    {
        switch (Copy_u8PortName)
        {
            case PORTA:
                DIO_PORTA = Copy_u8PortValue;
            break;

            case PORTB:
                DIO_PORTB = Copy_u8PortValue;
            break;

            case PORTC:
                DIO_PORTC = Copy_u8PortValue;
            break;

            case PORTD:
                DIO_PORTD = Copy_u8PortValue;
            break;

            default:

            break;
        }
    }
    else
    {

    }
}
void DIO_voidSetPortDirection(u8 Copy_u8PortName, u8 Copy_u8PortValue)
{
    if(Copy_u8PortName <= PORTD && Copy_u8PortValue <= OUTPUT)
    {
        switch (Copy_u8PortName)
        {
            case PORTA:
                if(Copy_u8PortValue == OUTPUT)
                {
                    DIO_DDRA = 0XFF;
                }
                else if(Copy_u8PortValue == INPUT)
                {
                    DIO_DDRA = 0X00;
                }
                else
                {

                }
            break;
            case PORTB:
                if(Copy_u8PortValue == OUTPUT)
                {
                    DIO_DDRB = 0XFF;
                }
                else if(Copy_u8PortValue == INPUT)
                {
                    DIO_DDRB = 0X00;
                }
                else
                {

                }
            break;
            case PORTC:
                if(Copy_u8PortValue == OUTPUT)
                {
                    DIO_DDRC = 0XFF;
                }
                else if(Copy_u8PortValue == INPUT)
                {
                    DIO_DDRC = 0X00;
                }
                else
                {

                }
            break;
            case PORTD:
                if(Copy_u8PortValue == OUTPUT)
                {
                    DIO_DDRD = 0XFF;
                }
                else if(Copy_u8PortValue == INPUT)
                {
                    DIO_DDRD = 0X00;
                }
                else
                {

                }
            break;

            default:
            break;
        }
    }
    else
    {

    }
}

void DIO_voidSetPortValue(u8 Copy_u8PortName, u8 Copy_u8PortValue)
{
    if(Copy_u8PortName <= PORTD && Copy_u8PortValue <= HIGH)
    {
        switch (Copy_u8PortName)
        {
            case PORTA:
                if(Copy_u8PortValue == HIGH)
                {
                    DIO_PORTA = 0XFF;
                }
                else if(Copy_u8PortValue == LOW)
                {
                    DIO_PORTA = 0X00;
                }
                else
                {

                }
            break;
            case PORTB:
                if(Copy_u8PortValue == HIGH)
                {
                    DIO_PORTB = 0XFF;
                }
                else if(Copy_u8PortValue == LOW)
                {
                    DIO_PORTB = 0X00;
                }
                else
                {

                }
            break;
            case PORTC:
                if(Copy_u8PortValue == HIGH)
                {
                    DIO_PORTC = 0XFF;
                }
                else if(Copy_u8PortValue == INPUT)
                {
                    DIO_PORTC = 0X00;
                }
                else
                {

                }
            break;
            case PORTD:
                if(Copy_u8PortValue == HIGH)
                {
                    DIO_PORTD = 0XFF;
                }
                else if(Copy_u8PortValue == LOW)
                {
                    DIO_PORTD = 0X00;
                }
                else
                {

                }
            break;

            default:
            break;
        }
    }
    else
    {

    }
}

u8 DIO_u8GetPortValue (u8 Copy_u8PortName)
{
	u8 DIO_u8StorePinValue = 0x00;
    
    if(Copy_u8PortName <= PORTD)
    {
	    switch(Copy_u8PortName)
	    {
	    	case PORTA:
	    		if(DIO_PINA == 0XFF)
	    		{
	    			DIO_u8StorePinValue = 0XFF;
	    		}
                else
                {

                }
	    	break;
	    	case PORTB:
	    		if(DIO_PINB == 0XFF)
	    		{
	    			DIO_u8StorePinValue = 0XFF;
	    		}
                else
                {

                }
	    	break;
	    	case PORTC:
	    		if(DIO_PINC == 0XFF)
	    		{
	    			DIO_u8StorePinValue = 0XFF;
	    		}
                else
                {

                }
	    	break;
	    	case PORTD:
	    		if(DIO_PIND == 0XFF)
	    		{
	    			DIO_u8StorePinValue = 0XFF;
	    		}
                else
                {

                }
	    	break;

            default:
            break;
	    }
    }
    else
    {

    }

	return(DIO_u8StorePinValue);
}

void DDIO_voidSetPortPullUp(u8 Copy_u8PortName)
{
    if(Copy_u8PortName <= PORTD)
    {
	    switch(Copy_u8PortName)
	    {
	    	case PORTA:
	    		DIO_DDRA = 0X00;
	    		DIO_PORTA = 0XFF;
	    	break;
	    	case PORTB:
	    		DIO_DDRB = 0X00;
	    		DIO_PORTB = 0XFF;
	    	break;
	    	case PORTC:
	    		DIO_DDRC = 0X00;
	    		DIO_PORTC = 0XFF;
	    	break;
	    	case PORTD:
	    		DIO_DDRD = 0X00;
	    		DIO_PORTD = 0XFF;
	    	break;
            default:
            break;
	    }
    }
    else
    {
        
    }
}


