#ifndef _TIMER_PRIVATE_H
#define _TIMER_PRIVATE_H



/****************************** TIMER 0 ***************************************/
#define     TCCR0                      *((volatile u8 *)0x53)
#define     TCCR0_CS00                 BIT_0                           
#define     TCCR0_CS01                 BIT_1         
#define     TCCR0_CS02                 BIT_2        
#define     TCCR0_WGM00                BIT_3             
#define     TCCR0_COM00                BIT_4            
#define     TCCR0_COM01                BIT_5            
#define     TCCR0_WGM01                BIT_6            
#define     TCCR0_FOS0                 BIT_7


#define     TCNT0                      *((volatile u8 *)0x52)                                            
             

#define     OCR0                       *((volatile u8 *)0x5C)
#define     TIMSK                      *((volatile u8 *)0x59)
#define     TIMSK_TOIE0                BIT_0
#define     TIMSK_OCIE0                BIT_1
#define     TIMSK_TOIE1                BIT_2
#define     TIMSK_OCIE1B               BIT_3
#define     TIMSK_OCIE1A               BIT_4
#define     TIMSK_TICIE1               BIT_5
#define     TIMSK_TOIE2                BIT_6
#define     TIMSK_OCIE2                BIT_7
                                       

#define     TIFR                       *((volatile u16 *)0x58)
#define     TIFR_TOV0                  BIT_0
#define     TIFR_OVF0                  BIT_1  
#define     TIFR_TOV1                  BIT_2
#define     TIFR_OCF1B                 BIT_3
#define     TIFR_OCF1A                 BIT_4
#define     TIFR_ICF1                  BIT_5
#define     TIFR_TOV2                  BIT_6
#define     TIFR_OCF2                  BIT_7  
                               

/****************************** TIMER 1 ***************************************/
#define     TCCR1A              *((volatile u8 *)(0x4F))		// Timer/Counter1 A Control Register
#define     TCCR1A_WGM10        0                               // WaveGeneration Mode Bit 0
#define     TCCR1A_WGM11        1                               // WaveGeneration Mode Bit 1
#define     TCCR1A_FOC1B        2                               // Force Output Compare 1 Channel B
#define     TCCR1A_FOC1A        3                               // Force Output Compare 1 Channel A
#define     TCCR1A_COM1B0       4                               // Compare Output Mode 1 Channel B Bit 0
#define     TCCR1A_COM1B1       5                               // Compare Output Mode 1 Channel B Bit 1
#define     TCCR1A_COM1A0       6                               // Compare Output Mode 1 Channel A Bit 0
#define     TCCR1A_COM1A1       7                               // Compare Output Mode 1 Channel A Bit 1

#define     TCCR1B              *((volatile u8 *)(0x4E))		// Timer/Counter 1 B Control Register
#define     TCCR1B_CS10         0                               // Timer/Counter 1 Clock Selection Bit 0
#define     TCCR1B_CS11         1                               // Timer/Counter 1 Clock Selection Bit 1
#define     TCCR1B_CS12         2                               // Timer/Counter 1 Clock Selection Bit 2
#define     TCCR1B_WGM12        3                               // WaveGeneration Mode Bit 0
#define     TCCR1B_WGM13        4                               // WaveGeneration Mode Bit 1
#define     TCCR1B_ICES1        6                               // Timer/Counter 1 Input Capture Edge Selection
#define     TCCR1B_ICNC1        7                               // Timer/Counter 1 Input Capture Noise Cancellation

#define     TCNT1               *((volatile u16 *)0x4C)         // Timer/Counter 1 Regsiter
#define     OCR1A               *((volatile u16 *)0x4A)         // Timer/Counter 1 Output Compare Regsiter Channel A
#define     OCR1B               *((volatile u16 *)0x48)         // Timer/Counter 1 Output Compare Regsiter Channel B
#define     ICR1                *((volatile u16 *)0x46)         // Timer/Counter 1 Input Capture Register

#define     OVF_INDEX           0
#define     CTC_INDEX           1
#define     ICU_INDEX           2


/****************************** TIMER 2 ***************************************/
#define     TCCR2                      *((volatile u8 *)0x45)
#define     TCCR2_CS20                 BIT_0                           
#define     TCCR2_CS21                 BIT_1         
#define     TCCR2_CS22                 BIT_2        
#define     TCCR2_WGM20                BIT_3             
#define     TCCR2_COM20                BIT_4            
#define     TCCR2_COM21                BIT_5            
#define     TCCR2_WGM21                BIT_6            
#define     TCCR2_FOS2                 BIT_7


#define     TCNT2                      *((volatile u8 *)0x52)                                            
#define     OCR2                       *((volatile u8 *)0x5C)


#define     TIMSK                      *((volatile u8 *)0x59)
#define     TIMSK_TOIE0                BIT_0
#define     TIMSK_OCIE0                BIT_1
#define     TIMSK_TOIE1                BIT_2
#define     TIMSK_OCIE1B               BIT_3
#define     TIMSK_OCIE1A               BIT_4
#define     TIMSK_TICIE1               BIT_5
#define     TIMSK_TOIE2                BIT_6
#define     TIMSK_OCIE2                BIT_7
                                       

#define     TIFR                       *((volatile u16 *)0x58)
#define     TIFR_TOV0                  BIT_0
#define     TIFR_OVF0                  BIT_1  
#define     TIFR_TOV1                  BIT_2
#define     TIFR_OCF1B                 BIT_3
#define     TIFR_OCF1A                 BIT_4
#define     TIFR_ICF1                  BIT_5
#define     TIFR_TOV2                  BIT_6
#define     TIFR_OCF2                  BIT_7  

/********************************************************************************************/

#define TIMER0_SELECT_MODE_MASK_CLR                     0b10110111
#define TIMER0_NORMAL_MODE_MSK                          0b00000000
#define TIMER0_PWM_PHASE_CORRECR_MODE_MSK               0b01000000
#define TIMER0_CTC_MODE_MSK                             0b00001000
#define TIMER0_FAST_PWM_MODE_MSK                        0b01001000


#define TIMER0_SUB_MODE_MSK_CLR                         0b11001111
#define TIMER0_NORMAL_PORT_MSK                          0b00000000
#define TIMER0_CLR_ON_COMP_SET_ON_TOP_MSK               0b00100000
#define TIMER0_SET_ON_COMP_CLEAR_ON_TOP_MSK             0b00110000
#define TIMER0_SET_ON_UP_COUNT_CLR_ON_DOWN_COUNT_MSK    0b00100000                 
#define TIMER0_CLR_ON_UP_COUNT_SET_ON_DOWN_COUNT_MSK    0b00110000


#define TIMER0_TOGGLE_OC0_ON_COMPARE_MATCH_MSK          0b00010000
#define TIMER0_CLEAR_OC0_ON_COMPARE_MATCH_MSK           0b00100000
#define TIMER0_SET_OC0_ON_COMPARE_MATCH_MSK             0b00110000


/********************************************************************************************/

#define TIMER1_SELECT_MODE_MASK_CLR_A                             0b11111100
#define TIMER1_NORMAL_MODE_MSK_A                                  0b00000000
#define TIMER1_PWM_PHASE_CORRECT_MODE_8BIT_MSK_A                  0b00000001
#define TIMER1_PWM_PHASE_CORRECT_MODE_9BIT_MSK_A                  0b00000010
#define TIMER1_PWM_PHASE_CORRECT_MODE_10BIT_MSK_A                 0b00000011
#define TIMER1_CTC_MODE_MSK_A                                     0b00000000
#define TIMER1_FAST_PWM_MODE_8BIT_MSK_A                           0b00000001
#define TIMER1_FAST_PWM_MODE_9BIT_MSK_A                           0b00000010
#define TIMER1_FAST_PWM_MODE_10BIT_MSK_A                          0b00000011
#define ICU_PWM_PHASE_FREQ_CORRECT_MODE_MSK_A                     0b00000000
#define TIMER1_PWM_PHASE_FREQ_CORRECT_MODE_MSK_A                  0b00000001
#define ICU_PWM_PHASE_CORRECT_MODE_MSK_A                          0b00000010
#define TIMER1_PWM_PHASE_CORRECT_MODE_MSK_A                       0b00000011
#define ICU_CTC_MODE_MSK_A                                        0b00000000
#define ICU_FAST_PWM_MODE_MSK_A                                   0b00000010
#define TIMER1_FAST_PWM_MODE_MSK_A                                0b00000011

#define TIMER1_SELECT_MODE_MASK_CLR_B                             0b11100111
#define TIMER1_NORMAL_MODE_MSK_B                                  0b00000000
#define TIMER1_PWM_PHASE_CORRECT_MODE_8BIT_MSK_B                  0b00000000
#define TIMER1_PWM_PHASE_CORRECT_MODE_9BIT_MSK_B                  0b00000000
#define TIMER1_PWM_PHASE_CORRECT_MODE_10BIT_MSK_B                 0b00000000
#define TIMER1_CTC_MODE_MSK_B                                     0b00001000
#define TIMER1_FAST_PWM_MODE_8BIT_MSK_B                           0b00001000
#define TIMER1_FAST_PWM_MODE_9BIT_MSK_B                           0b00001000
#define TIMER1_FAST_PWM_MODE_10BIT_MSK_B                          0b00001000
#define ICU_PWM_PHASE_FREQ_CORRECT_MODE_MSK_B                     0b00010000
#define TIMER1_PWM_PHASE_FREQ_CORRECT_MODE_MSK_B                  0b00010000
#define ICU_PWM_PHASE_CORRECT_MODE_MSK_B                          0b00010000
#define TIMER1_PWM_PHASE_CORRECT_MODE_MSK_B                       0b00010000
#define ICU_CTC_MODE_MSK_B                                        0b00011000
#define ICU_FAST_PWM_MODE_MSK_B                                   0b00011000
#define TIMER1_FAST_PWM_MODE_MSK_B                                0b00011000

#define ENABLE                                                    0
#define DISABLE                                                   1




/********************************************************************************************/

#define TIMER2_SELECT_MODE_MASK_CLR                     0b10110111
#define TIMER2_NORMAL_MODE_MSK                          0b00000000
#define TIMER2_PWM_PHASE_CORRECR_MODE_MSK               0b01000000
#define TIMER2_CTC_MODE_MSK                             0b00001000
#define TIMER2_FAST_PWM_MODE_MSK                        0b01001000


#define TIMER2_SUB_MODE_MSK_CLR                         0b11001111
#define TIMER2_NORMAL_PORT_MSK                          0b00000000
#define TIMER2_CLR_ON_COMP_SET_ON_TOP_MSK               0b00100000
#define TIMER2_SET_ON_COMP_CLEAR_ON_TOP_MSK             0b00110000
#define TIMER2_SET_ON_UP_COUNT_CLR_ON_DOWN_COUNT_MSK    0b00100000                 
#define TIMER2_CLR_ON_UP_COUNT_SET_ON_DOWN_COUNT_MSK    0b00110000


#define TIMER2_TOGGLE_OC2_ON_COMPARE_MATCH_MSK          0b00010000
#define TIMER2_CLEAR_OC2_ON_COMPARE_MATCH_MSK           0b00100000
#define TIMER2_SET_OC2_ON_COMPARE_MATCH_MSK             0b00110000


/********************************************************************************************/
#define TIMER_PRESCALER_MASK_CLR                       0b11111000
#define TIMER_NO_CLK_SRC                               0b00000000
#define TIMER_NO_PRESCALING                            0b00000001
#define TIMER_PRESCALER_DIV_BY_8                       0b00000010
#define TIMER_PRESCALER_DIV_BY_64                      0b00000011
#define TIMER_PRESCALER_DIV_BY_256                     0b00000100
#define TIMER_PRESCALER_DIV_BY_1024                    0b00000101 
#define COUNTER_EXTI_CLK_RISING_EDGE                   0b00000110
#define COUNTER_EXTI_CLK_FALLING_EDGE                  0b00000111


#define TIMER_NORMAL_PORT                              0
#define TIMER_CLR_ON_COMP_SET_ON_TOP                   1
#define TIMER_SET_ON_COMP_CLEAR_ON_TOP                 2
#define TIMER_SET_ON_UP_COUNT_CLR_ON_DOWN_COUNT        3                 
#define TIMER_CLR_ON_UP_COUNT_SET_ON_DOWN_COUNT        4


#define TIMER_NORMAL_PORT_OPERATION                    0
#define TIMER_TOGGLE_OC0_ON_COMPARE_MATCH              1
#define TIMER_CLEAR_OC0_ON_COMPARE_MATCH               2
#define TIMER_SET_OC0_ON_COMPARE_MATCH                 3


#define TIMER_NORMAL_MODE                              0
#define TIMER_PWM_PHASE_CORRECR_MODE                   1
#define TIMER_CTC_MODE                                 2
#define TIMER_FAST_PWM_MODE                            3



#endif

