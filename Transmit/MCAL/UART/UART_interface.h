#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H

void UART_voidInit();
void UART_TransmitData(u16 Copy_u8Data);
void UART_voidReceiveDataSynchronous(u8 * Ref_pu8ReceivedData);
void UART_TransmitNumber(u32 Copy_u32Number);
void UART_TransmitSrting(const u8 * Ref_pu8String);

#endif
