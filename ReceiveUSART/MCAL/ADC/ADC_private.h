#ifndef _ADC_PRIVATE_H
#define _ADC_PRIVATE_H

#define     ADMUX                       *((volatile u8 *)0x27)
#define     ADMUX_MUX0                  BIT_0
#define     ADMUX_MUX1                  BIT_1
#define     ADMUX_MUX2                  BIT_2
#define     ADMUX_MUX3                  BIT_3
#define     ADMUX_MUX4                  BIT_4
#define     ADMUX_ADLAR                 BIT_5
#define     ADMUX_REFS0                 BIT_6
#define     ADMUX_REFS1                 BIT_7

#define ACD_LEFT_ADJUST                 0
#define ACD_RIGHT_ADJUST                1


#define ADC_SINGLE_CONVERSION_MODE      0
#define ADC_AUTO_TRIGGER_MODE           1



#define     ADCSRA                      *((volatile u8 *)0x26)
#define     ADCSRA_ADPS0                BIT_0                           
#define     ADCSRA_ADPS1                BIT_1         
#define     ADCSRA_ADPS2                BIT_2        
#define     ADCSRA_ADIE                 BIT_3             
#define     ADCSRA_ADIF                 BIT_4            
#define     ADCSRA_ADATE                BIT_5            
#define     ADCSRA_ADSC                 BIT_6            
#define     ADCSRA_ADEN                 BIT_7


#define     SFIOR                      *((volatile u8 *)0x50)
#define     SFIOR_ADTS0                BIT_0                           
#define     SFIOR_ADTS0                BIT_1         
#define     SFIOR_ADTS0                BIT_2        
             

#define     ADCL                        *((volatile u8 *)0x24)
#define     ADCH                        *((volatile u8 *)0x25)

#define     ADC                         *((volatile u16 *)0x24)

#define ADC_PRESCALER_MASK_CLR          0b11111000
#define ADC_PRESCALER_DIV_BY_2          0b00000000
#define ADC_PRESCALER_DIV_BY_4          0b00000010
#define ADC_PRESCALER_DIV_BY_8          0b00000011
#define ADC_PRESCALER_DIV_BY_16         0b00000100
#define ADC_PRESCALER_DIV_BY_32         0b00000101
#define ADC_PRESCALER_DIV_BY_64         0b00000110 
#define ADC_PRESCALER_DIV_BY_128        0b00000111  

#define ADC_Channel_MASK_CLR            0b11100000
#define ADC_REFERANCE_VOLTAGE_MASK_CLR  0b00111111
#define ADC_AREF_VOLTAGE                0b00000000
#define ADC_AVCC_VOLTAGE                0b01000000
#define ADC_INTERNAL_VOLTAGE            0b11000000


#define ADC_AUTO_TRIG_SRC_MASK_CLR                0b00011111
#define ADC_AUTO_TRIG_SRC_FREE_RUNNING_MSK        0b00000000
#define ADC_AUTO_TRIG_SRC_ANALOG_COMP_MSK         0b00100000
#define ADC_AUTO_TRIG_SRC_EXIT0_MSK               0b01000000
#define ADC_AUTO_TRIG_SRC_TIMER0_COMP_MSK         0b01100000
#define ADC_AUTO_TRIG_SRC_TIMER0_OVF_MSK          0b10000000
#define ADC_AUTO_TRIG_SRC_TIMER1_COMP_MSK         0b10100000
#define ADC_AUTO_TRIG_SRC_TIMER1_OVF_MSK          0b11000000
#define ADC_AUTO_TRIG_SRC_TIMER1_CAPT_MSK         0b11100000

              



#endif