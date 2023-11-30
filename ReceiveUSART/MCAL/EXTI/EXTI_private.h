#ifndef _EXTI_PRIVATE_H
#define _EXTI_PRIVATE_H


                    
#define MCUCR               *((volatile u8 *)0x55)
#define MCUCR_ISC00         BIT_0
#define MCUCR_ISC01         BIT_1
#define MCUCR_ISC10         BIT_2
#define MCUCR_ISC11         BIT_3




#define MCUCSR              *((volatile u8 *)0x54)
#define MCUCSR_ISC2         BIT_6


#define GICR                *((volatile u8 *)0x5B)
#define GICR_INT0           BIT_6
#define GICR_INT1           BIT_7
#define GICR_INT2           BIT_5


#define GIFR                *((volatile u8 *)0x5A)
#define GIFR_INT0           BIT_6
#define GIFR_INT1           BIT_7
#define GIFR_INT2           BIT_5

#endif