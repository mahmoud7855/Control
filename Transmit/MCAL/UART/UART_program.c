#include "../../LIB/Std_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "UART_config.h"
#include "UART_interface.h"
#include "UART_private.h"

void UART_voidInit()
{
    u8 Local_u8UCSRCTemp = 0;
    #if(TX_CIRCUIT == ENABLE)
        SET_BIT(UCSRB, UCSRB_TXEN);
    #elif(TX_CIRCUIT == DISABLE)
        CLR_BIT(UCSRB, UCSRB_TXEN);
    #endif

    #if(RX_CIRCUIT == ENABLE)
        SET_BIT(UCSRB, UCSRB_RXEN);
    #elif(RX_CIRCUIT == DISABLE)
        CLR_BIT(UCSRB, UCSRB_RXEN);
    #endif

    /*Caracter Size Select*/
    #if(UART_Character_SIZE == _5_BIT)
        SET_BIT(UBRRH, UBRRH_URSEL);
        CLR_BIT(Local_u8UCSRCTemp, UCSRA_UCSZ0);
        CLR_BIT(Local_u8UCSRCTemp, UCSRA_UCSZ1);
        CLR_BIT(UCSRB, UCSRB_UCSZ2);

    #elif(UART_Character_SIZE == _6_BIT)
        SET_BIT(UBRRH, UBRRH_URSEL);
        SET_BIT(Local_u8UCSRCTemp, UCSRA_UCSZ0);
        CLR_BIT(Local_u8UCSRCTemp, UCSRA_UCSZ1);
        CLR_BIT(UCSRB, UCSRB_UCSZ2);

    #elif(UART_Character_SIZE == _7_BIT)
        SET_BIT(UBRRH, UBRRH_URSEL);
        CLR_BIT(Local_u8UCSRCTemp, UCSRA_UCSZ0);
        SET_BIT(Local_u8UCSRCTemp, UCSRA_UCSZ1);
        CLR_BIT(UCSRB, UCSRB_UCSZ2);

    #elif(UART_Character_SIZE == _8_BIT)
        SET_BIT(UBRRH, UBRRH_URSEL);
        SET_BIT(Local_u8UCSRCTemp, UCSRC_UCSZ0);
        SET_BIT(Local_u8UCSRCTemp, UCSRC_UCSZ1);
        CLR_BIT(UCSRB, UCSRB_UCSZ2);

    #elif(UART_Character_SIZE == _9_BIT)
        SET_BIT(UBRRH, UBRRH_URSEL);
        SET_BIT(Local_u8UCSRCTemp, UCSRA_UCSZ0);
        SET_BIT(Local_u8UCSRCTemp, UCSRA_UCSZ1);
        SET_BIT(UCSRB, UCSRB_UCSZ2);
    #endif

    /*Parity Mode Select*/
    #if(PARITY_MODE == DISABLE)
        SET_BIT(Local_u8UCSRCTemp, UCSRC_URSEL);
        CLR_BIT(Local_u8UCSRCTemp, UCSRC_UPM0);
        CLR_BIT(Local_u8UCSRCTemp, UCSRC_UPM1);
    
    #elif(PARITY_MODE == ODD_PARITY)
        SET_BIT(Local_u8UCSRCTemp, UCSRC_URSEL);
        SET_BIT(Local_u8UCSRCTemp, UCSRC_UPM0);
        CLR_BIT(Local_u8UCSRCTemp, UCSRC_UPM1);

    #elif(PARITY_MODE == EVEN_PARITY)   
        SET_BIT(Local_u8UCSRCTemp, UCSRC_URSEL);
        CLR_BIT(Local_u8UCSRCTemp, UCSRC_UPM0);
        SET_BIT(Local_u8UCSRCTemp, UCSRC_UPM1);
    #endif

    /*Stop Bit Select*/
    #if(STOP_BIT_SELECT == _1_BIT)
        SET_BIT(Local_u8UCSRCTemp, UCSRC_URSEL);
        CLR_BIT(Local_u8UCSRCTemp, UCSRC_USBS);
    #elif(STOP_BIT_SELECT == _2_BIT)
        SET_BIT(Local_u8UCSRCTemp, UCSRC_URSEL);
        SET_BIT(Local_u8UCSRCTemp, UCSRC_USBS);
    #endif
    /*USART Mode Select*/
    #if(USART_MODE_SELECT == ASYNCHRONOUS)
        SET_BIT(Local_u8UCSRCTemp, UCSRC_URSEL);
        CLR_BIT(Local_u8UCSRCTemp, UCSRC_UMSEL);
    #elif(USART_MODE_SELECT == SYNCHRONOUS)
        SET_BIT(Local_u8UCSRCTemp, UCSRC_URSEL);
        SET_BIT(Local_u8UCSRCTemp, UCSRC_UMSEL);
    #endif

    /*Boud Rate Select*/
    #if(BOUD_RATE == BOUD_9600)
        CLR_BIT(UBRRH, UBRRH_URSEL);
        UBRRL = 51;
        UBRRH = 0;
    #elif(BOUD_RATE == BOUD_11520)
        CLE_BIT(UBRRH, UBRRH_URSEL);
        UBRRL = 3;
        UBRRH = 0;
    #endif

    /*Transmission Speed*/
    #if(TRANSMISSION_SPEED == DOUBLE_SPEED)
        SET_BIT(UCSRA, UCSRA_U2X);
    #elif(TRANSMISSION_SPEED == NO_DOUBLE_SPEED)
        CLR_BIT(UCSRA, UCSRA_U2X);
    #endif
    UCSRC = Local_u8UCSRCTemp;
}

u8 TransmitedData = 0;
void UART_TransmitData(u16 Copy_u8Data)
{
    while(GET_BIT(UCSRA, UCSRA_UDRE) == 0);
    UDR = Copy_u8Data;
    while (GET_BIT(UCSRA, UCSRA_TXC) == 0);
    SET_BIT(UCSRA, UCSRA_TXC);
}

void UART_voidReceiveDataSynchronous(u8 * Ref_pu8ReceivedData)
{
    while (GET_BIT(UCSRA, UCSRA_RXC) == 0);
    *Ref_pu8ReceivedData = UDR;
    
}

void UART_TransmitNumber(u32 Copy_u32Number)
{
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
        UART_TransmitData(Local_u8SpllitedNumber[Local_s8LoopCounter] + '0');
        Local_s8LoopCounter--;
    }  
}

void UART_TransmitSrting(const u8 * Ref_pu8String)
{
	u8 Local_u8LoopCounter = 0;
	while(Ref_pu8String[Local_u8LoopCounter] != NULL_TERMINATOR)
    {
		UART_TransmitData(Ref_pu8String[Local_u8LoopCounter]);
		Local_u8LoopCounter++;
	}
}




