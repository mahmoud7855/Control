#ifndef _UART_PRIVATE_H
#define _UART_PRIVATE_H

#define UDR                 *((volatile u8 *)0x2C)

#define UCSRA               *((volatile u8 *)0x2B)
#define UCSRA_MPCM          BIT_0
#define UCSRA_U2X           BIT_1
#define UCSRA_PE            BIT_2
#define UCSRA_DOR           BIT_3
#define UCSRA_FE            BIT_4
#define UCSRA_UDRE          BIT_5
#define UCSRA_TXC           BIT_6
#define UCSRA_RXC           BIT_7

#define UCSRB               *((volatile u8 *)0x2A)
#define UCSRB_TXB8          BIT_0
#define UCSRB_RXB8          BIT_1
#define UCSRB_UCSZ2         BIT_2
#define UCSRB_TXEN          BIT_3
#define UCSRB_RXEN          BIT_4
#define UCSRB_UDREI         BIT_5
#define UCSRB_TXCIE         BIT_6
#define UCSRB_RXCIE         BIT_7

#define UCSRC               *((volatile u8 *)0x40)
#define UCSRC_UCPOL         BIT_0
#define UCSRC_UCSZ0         BIT_1
#define UCSRC_UCSZ1         BIT_2
#define UCSRC_USBS          BIT_3
#define UCSRC_UPM0          BIT_4
#define UCSRC_UPM1          BIT_5
#define UCSRC_UMSEL         BIT_6
#define UCSRC_URSEL         BIT_7

#define UBRRH              *((volatile u8 *)0x40)
#define UBRRH_URSEL        7
#define UBRRL              *((volatile u8 *)0x29)

/*Caracter Size*/
#define _5_BIT             5
#define _6_BIT             6
#define _7_BIT             7
#define _8_BIT             8
#define _9_BIT             9

/*Parity Mode*/
#define DISABLE            0
#define ODD_PARITY         1
#define EVEN_PARITY        2

/*Stop Bit*/
#define _1_BIT             0
#define _2_BIT             1

/*USART MODE*/
#define ASYNCHRONOUS       0
#define SYNCHRONOUS        1


/*BOUD RATE*/
#define BOUD_9600          9600
#define BOUD_11520         11520


/*Transmission Speed*/
#define DOUBLE_SPEED       0
#define NO_DOUBLE_SPEED    1

#define ENABLE             1


#define NULL_TERMINATOR			   '\0'



#endif



