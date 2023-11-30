/***********************************************************************
 * Auther: Mahmoud G. Mahmoud
 * Creation date: 20 Oct, 2023
 * Version: v1.0 
 * Compiler: 
 * Controller: ATMEGA32
 * Leyer: MCAL
 ***********************************************************************/
/***********************************************************************
 * Version    Date                    Auther            Description
 * v1.0       20 Oct, 2023      Mahmoud G. Mahmoud      
***********************************************************************/


/*Library Inclusion*/
#include "../../LIB/Std_Types.h"
#include "../../LIB/BIT_MATH.h"

/*Lower Layer Inclusion*/


/*Self Layer Inclusion*/


/*Self Files Inclusion*/
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"



         

void ADC_voidInit(void)
{
    /*Select The Prescaler = 64*/
    ADCSRA &= ADC_PRESCALER_MASK_CLR;
    ADCSRA |= ADC_PRESCALER_SELECT_VALUE;
    /*Adjustment*/
    #if ADC_RESULT_ADJUSTMENT == ACD_LEFT_ADJUST
        SET_BIT(ADMUX, ADMUX_ADLAR);
    #elif ADC_RESULT_ADJUSTMENT == ACD_RIGHT_ADJUST
        CLR_BIT(ADMUX, ADMUX_ADLAR);
    #endif
    /*Default Choose ACD Channel */
    ADMUX &= ADC_Channel_MASK_CLR;
    ADMUX |= ADC_Channel_0;
    /*Select Mode Of ADC*/
    #if ADC_MODE_SELECT == ADC_SINGLE_CONVERSION_MODE
        CLR_BIT(ADCSRA, ADCSRA_ADATE);
    #elif ADC_MODE_SELECT == ADC_AUTO_TRIGGER_MODE
        SET_BIT(ADCSRA, ADCSRA_ADATE);
        SFIOR &= ADC_AUTO_TRIG_SRC_MASK_CLR;
        SFIOR |= ADC_AUTO_TRIG_SRC_FREE_RUNNING_MSK;
    #endif
    /*Referance voltage*/
    ADCSRA &= ADC_REFERANCE_VOLTAGE_MASK_CLR;
    ADCSRA |= ADC_REFERANCE_VOLTAGE_SELECT_VALUE;
    /*Enable ADC*/
    SET_BIT(ADCSRA, ADCSRA_ADEN);   
}




u8 ACD_voidStartConversionSynchronous(u8 Copu_u8ADCChannel)
{
    /* Choose ACD Channel */
    ADMUX &= ADC_Channel_MASK_CLR;
    ADMUX |= Copu_u8ADCChannel;
    /*Trigger ADC*/
    SET_BIT(ADCSRA, ADCSRA_ADSC);
    /*Polling (Busy Wait) Till The ADC End Conversion*/
    while(GET_BIT(ADCSRA, ADCSRA_ADIF) == 0);

    /*Clear ADC Flag*/
    SET_BIT(ADCSRA, ADCSRA_ADIF);

    /*Return The Digital Value*/
    #if ADC_RESULT_ADJUSTMENT == ACD_LEFT_ADJUST
        return (ADCH);
    #elif ADC_RESULT_ADJUSTMENT == ACD_RIGHT_ADJUST
        return (ADCL);
    #endif
}

void(*ADC_NotificationFunction)(u8 *) = NULL_POINTER;
void ACD_voidStartConversionASynchronous(u8 Copu_u8ADCChannel, void(*NotificationFunction)(u8 *))
{
    ADC_NotificationFunction = NotificationFunction;
    /* Choose ACD Channel */
    ADMUX &= ADC_Channel_MASK_CLR;
    ADMUX |= Copu_u8ADCChannel;
    /*Enable PIE*/
    SET_BIT(ADCSRA, ADCSRA_ADIE);
    /*Trigger ADC*/
    SET_BIT(ADCSRA, ADCSRA_ADSC);
}

u8 ADC_u8Result = 0;
void __vector_16(void)   __attribute__((signal));
void __vector_16(void)
{
    if(ADC_NotificationFunction != NULL_POINTER)
    {
        #if ADC_RESULT_ADJUSTMENT == ACD_LEFT_ADJUST
            ADC_u8Result = ADCH;
            ADC_NotificationFunction(&ADC_u8Result);
        #elif ADC_RESULT_ADJUSTMENT == ACD_RIGHT_ADJUST
            ADC_u8Result = ADCL;
            ADC_NotificationFunction(&ADC_u8Result);
        #endif    

    }
    else
    {
        
    }
}




