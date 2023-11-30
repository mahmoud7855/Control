#ifndef _LM35_INTERFACE_H
#define _LM35_INTERFACE_H

u8 LM35_ASynchronous (void);
void LM35_u8GetTempratureASynchronous(u8 *Ref_u8Digital);
u8 LM35_u8GetTempratureSynchronous (void);
void LM35_voidInit(void);

#endif
