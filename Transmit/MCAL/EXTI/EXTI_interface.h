#ifndef _EXTI_INTERFACE_
#define _EXTI_INTERFACE_

#define EXTI_INT0         0
#define EXTI_INT1         1
#define EXTI_INT2         3


#define EXTI_RISING_EDGE    1
#define EXTI_FALLING_EDGE   2
#define EXTI_ON_CHANGE      3
#define EXTI_LOW_LEVEL      4

#define EXTI_ENABLE         0
#define EXTI_DISABLE        1

void EXTI_voidInit(void);
void EXTI_voidChangeSenceMode(u8 Copy_u8InterruptNum, u8 Copy_u8SignalSence);
void EXTI_voidInterruptContal(u8 Copy_u8InterruptNum, u8 Copy_u8InterruptState);
u8 EXTI_voidGetInterruptFlag(u8 Copy_u8InterruptNum);
void EXTI_voidSetCallBack(void(*NotificationFunction)(void));

#endif