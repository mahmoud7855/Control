#ifndef _TIMER_INTERFACE_H
#define _TIMER_INTERFACE_H

void TIMER_voidTimer0Init(void);
void TIMER_voidTimer1Init(void);
void TIMER_voidTimer0SetPreloadValue (u8 Copy_PreloadValue);
void TIMER_voidTimer0SetCOMatchValue (u8 Copy_COMPValue);
void TIMER_voidTimer1SetPreloadValue(u16 Copy_u16PreloadValue);
void TIMER_voidTimer1SetCompareMatchTime(u16 Copy_u16CompareMatchValue);
void TIMER_voidTimer1SetCompMatchValueB(u16 Copy_u16CompareMatchValue);
void TIMER_voidTimer1SetTopValue(u16 Copy_u16TopValue);
void ICU_voidTimer1SetICRValue(u16 Copy_u16ICRValue);
void TIMER_voiTimer0dSetPreloadValue (u8 Copy_PreloadValue);
u16 TIMER_GetValueICR1(void);
u16 TIMER_GetValueTCNT1(void);
void ICU_voidSenceModetrigger(u8 Copy_u8Mode);
void TIMER_voidSetBusyWait_COMPMode(u32 Copy_u32Timeout);
void ICU_voidTimer1ControlInterrupt(u8 Copy_u8Mode);
void TIMER_voidTimer1ControlInterrupt(u8 Copy_u8Cannel, u8 Copy_u8InterruptType, u8 Copy_u8Mode);
void TIMER_voidTimer0ControlInterrupt(u8 Copy_u8InterruptType, u8 Copy_u8Mode);
void TIMER_voidTimer0SetOVFCallBack (void (* Notification)(void));
void TIMER_voidTimer0SetCOMPFCallBack (void (* Notification)(void));
void ICU_voidCallBack (void (* Notification)(void));
void TIMER_voidTimer1SetCOMPACallBack (void (* Notification)(void));
void TIMER_voidTimer1SetCOMPBCallBack (void (* Notification)(void));
void TIMER_voidTimer1SetOVFCallBack (void (* Notification)(void));

#define OC1A            0
#define OC1B            1

#define OVF             0
#define COMP            1

#define ENABLE          0
#define DISBLE          1

#define RISING_EDGE     0
#define FALLING_EDGE    1



#endif
