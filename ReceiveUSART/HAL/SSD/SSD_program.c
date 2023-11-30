#include "../../LIB/Std_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_private.h"

#include "SSD_interface.h"



u8 Global_u8ArrayStoreNumbers[10] = {0b00111111,
						             0b00000110,
						             0b01011011,
                                     0b01001111,
                                     0b01100110,
                                     0b01101101,
                                     0b01111101,
                                     0b00000111,
                                     0b01111111,
                                     0b01101111};

void SSD_voidDisplayNumbers (u8 Copy_u8PortName, u8 Copy_u8DisplayNumber, u8 Copy_u8Type)
{
    if(Copy_u8PortName <= PORTD && Copy_u8DisplayNumber <= 9 && Copy_u8Type <= CommanAnode)
    {
        switch (Copy_u8PortName)
        {
            case PORTA:
                    switch(Copy_u8Type)
                    {
                        case CommanCathod:
                            DIO_voidSetPortSpecificValue(PORTA, Global_u8ArrayStoreNumbers[Copy_u8DisplayNumber]);
                        case CommanAnode:
                            DIO_voidSetPortSpecificValue(PORTA, ~Global_u8ArrayStoreNumbers[Copy_u8DisplayNumber]);
                        break;
                    }
            break;
        }
    }
    else
    {
        
    }   
           
}
        
