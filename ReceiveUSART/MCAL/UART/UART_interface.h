#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H

void UART_voidInit();
void UART_TransmitData(u16 Copy_u8Data);
void UART_voidReceiveDataSynchronous(u8 * Ref_pu8ReceivedData);
void UART_voidReceiveStringSynchronous(u8 * Ref_pu8ReceivedData);
void USART_voidSendNumber(u32 Copy_u32Number);
void USART_voidSendSrting(const u8 * Ref_pu8String);
void UART_voidReceiveDataASynchronous(void(*NotificationFunction)(u8 *));


#endif
