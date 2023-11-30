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
#include "../DIO/DIO_interface.h"
#include "../GIE/GIE_interface.h"

/*Self Files Inclusion*/
#include "TIMER_private.h"
#include "TIMER_interface.h"
#include "TIMER_config.h"



         

void TIMER_voidTimer0Init(void)
{

    #if (TIMER0_MODE == TIMER_NORMAL_MODE)
        TCCR0 &= TIMER0_SELECT_MODE_MASK_CLR;
        TCCR0 |= TIMER0_NORMAL_MODE_MSK;
    #elif (TIMER0_MODE == TIMER_CTC_MODE)
        TCCR0 &= TIMER0_SELECT_MODE_MASK_CLR;
        TCCR0 |= TIMER0_CTC_MODE_MSK;
        #if (TIMER0_CTC_SUB_MODE == TIMER_NORMAL_PORT)
            TCCR0 &= TIMER0_SUB_MODE_MSK_CLR;
            TCCR0 |= TIMER0_NORMAL_PORT_MSK;
        #elif (TIMER0_CTC_SUB_MODE == TIMER_TOGGLE_OC0_ON_COMPARE_MATCH)
            TCCR0 &= TIMER0_SUB_MODE_MSK_CLR;
            TCCR0 |= TIMER0_TOGGLE_OC0_ON_COMPARE_MATCH_MSK;
        #elif (TIMER0_CTC_SUB_MODE == TIMER_CLEAR_OC0_ON_COMPARE_MATCH)
            TCCR0 &= TIMER0_SUB_MODE_MSK_CLR;
            TCCR0 |= TIMER0_CLEAR_OC0_ON_COMPARE_MATCH_MSK;
        #elif (TIMER0_CTC_SUB_MODE == TIMER_SET_OC0_ON_COMPARE_MATCH)
            TCCR0 &= TIMER0_SUB_MODE_MSK_CLR;
            TCCR0 |= TIMER0_SET_OC0_ON_COMPARE_MATCH_MSK;
        #else
            #error "Error!!, Undefined Enter Value";
        #endif
    #elif (TIMER0_MODE == TIMER_FAST_PWM_MODE)
        TCCR0 &= TIMER0_SELECT_MODE_MASK_CLR;
        TCCR0 |= TIMER0_FAST_PWM_MODE_MSK;
        #if (TIMER0_PWM_SUB_MODE == TIMER_NORMAL_PORT)
            TCCR0 &= TIMER0_SUB_MODE_MSK_CLR;
            TCCR0 |= TIMER0_NORMAL_PORT_MSK;
        #elif (TIMER0_PWM_SUB_MODE == TIMER_CLR_ON_COMP_SET_ON_TOP)
            TCCR0 &= TIMER0_SUB_MODE_MSK_CLR;
            TCCR0 |= TIMER0_CLR_ON_COMP_SET_ON_TOP_MSK;
        #elif (TIMER0_PWM_SUB_MODE == TIMER_SET_ON_COMP_CLEAR_ON_TOP)
            TCCR0 &= TIMER0_SUB_MODE_MSK_CLR;
            TCCR0 |= TIMER0_SET_ON_COMP_CLEAR_ON_TOP_MSK;
        #else
            #error "Error!!!";
        #endif
    #elif (TIMER0_MODE == TIMER_PWM_PHASE_CORRECR_MODE)
        TCCR0 &= TIMER0_SELECT_MODE_MASK_CLR;
        TCCR0 |= TIMER0_PWM_PHASE_CORRECR_MODE_MSK;
        #if (TIMER0_PWM_SUB_MODE == TIMER_NORMAL_PORT)
            TCCR0 &= TIMER0_SUB_MODE_MSK_CLR;
            TCCR0 |= TIMER0_NORMAL_PORT_MSK;
        #elif (TIMER0_PWM_SUB_MODE == TIMER_SET_ON_UP_COUNT_CLR_ON_DOWN_COUNT)
            TCCR0 &= TIMER0_SUB_MODE_MSK_CLR;
            TCCR0 |= TIMER0_SET_ON_UP_COUNT_CLR_ON_DOWN_COUNT_MSK;
        #elif (TIMER0_PWM_SUB_MODE == TIMER_CLR_ON_UP_COUNT_SET_ON_DOWN_COUNT)
            TCCR0 &= TIMER0_SUB_MODE_MSK_CLR;
            TCCR0 |= TIMER0_CLR_ON_UP_COUNT_SET_ON_DOWN_COUNT_MSK;
        #else
            #error "Error!!!"
        #endif    



    #endif
        

    TCCR0 &= TIMER_PRESCALER_MASK_CLR;
    TCCR0 |= TIMER_COUNTER_PRESCALER_SELECT;
}


void TIMER_voidTimer1Init(void)
{
    TCCR1B &= TIMER_PRESCALER_MASK_CLR;
    TCCR1B |= TIMER_COUNTER_PRESCALER_SELECT;

    TCCR1A &= TIMER1_SELECT_MODE_MASK_CLR_A;
    TCCR1A |= TIMER1_SELECT_MODE_A;

    TCCR1B &= TIMER1_SELECT_MODE_MASK_CLR_B;
    TCCR1B |= TIMER1_SELECT_MODE_B;

    #if(OC1A_CHANNEL == ENABLE)
        #if (TIMER1_MODE == TIMER_NORMAL_MODE)
        #elif (TIMER1_MODE == TIMER_FAST_PWM_MODE)
            #if (TIMER1_SUB_MODE == TIMER_NORMAL_PORT)
                CLR_BIT(TCCR1A, TCCR1A_COM1A1);
                CLR_BIT(TCCR1A, TCCR1A_COM1A0);
            #elif (TIMER1_SUB_MODE == TIMER_CLR_ON_COMP_SET_ON_TOP)
                SET_BIT(TCCR1A, TCCR1A_COM1A1);
                CLR_BIT(TCCR1A, TCCR1A_COM1A0);
            #elif (TIMER1_SUB_MODE == TIMER_SET_ON_COMP_CLEAR_ON_TOP)
                SET_BIT(TCCR1A, TCCR1A_COM1A1);
                SET_BIT(TCCR1A, TCCR1A_COM1A0);
            #endif
        #elif (TIMER1_MODE == TIMER_CTC_MODE)
            #if (TIMER1_SUB_MODE == TIMER_NORMAL_PORT)
                CLR_BIT(TCCR1A, TCCR1A_COM1A1);
                CLR_BIT(TCCR1A, TCCR1A_COM1A0);
            #elif (TIMER1_SUB_MODE == TIMER_TOGGLE_OC0_ON_COMPARE_MATCH)
                CLR_BIT(TCCR1A, TCCR1A_COM1A1);
                SET_BIT(TCCR1A, TCCR1A_COM1A0);
            #elif (TIMER1_SUB_MODE == TIMER_CLEAR_OC0_ON_COMPARE_MATCH)
                SET_BIT(TCCR1A, TCCR1A_COM1A1);
                CLR_BIT(TCCR1A, TCCR1A_COM1A0);
            #elif (TIMER1_SUB_MODE == TIMER_SET_OC0_ON_COMPARE_MATCH)
                SET_BIT(TCCR1A, TCCR1A_COM1A1);
                SET_BIT(TCCR1A, TCCR1A_COM1A0);
            #endif
        #elif (TIMER1_MODE == TIMER_PWM_PHASE_CORRECR_MODE)
            #if (TIMER1_SUB_MODE == TIMER_NORMAL_PORT)
                CLR_BIT(TCCR1A, TCCR1A_COM1A1);
                CLR_BIT(TCCR1A, TCCR1A_COM1A0);
            #elif (TIMER1_SUB_MODE == TIMER_SET_ON_UP_COUNT_CLR_ON_DOWN_COUNT)
                SET_BIT(TCCR1A, TCCR1A_COM1A1);
                SET_BIT(TCCR1A, TCCR1A_COM1A0);
            #elif (TIMER1_SUB_MODE == TIMER_CLR_ON_UP_COUNT_SET_ON_DOWN_COUNT)
                SET_BIT(TCCR1A, TCCR1A_COM1A1);
                CLR_BIT(TCCR1A, TCCR1A_COM1A0);
                #endif
        #endif
    #elif (OC1A_CHANNEL == DISABLE)
    #endif

    #if (OC1B_CHANNEL == ENABLE)
        
        #if (TIMER1_MODE == TIMER_NORMAL_MODE)
        #elif (TIMER1_MODE == TIMER_FAST_PWM_MODE)
            #if (TIMER1_SUB_MODE == TIMER_NORMAL_PORT)
                CLR_BIT(TCCR1B, TCCR1A_COM1B1);
                CLR_BIT(TCCR1B, TCCR1A_COM1B0);
            #elif (TIMER1_SUB_MODE == TIMER_CLR_ON_COMP_SET_ON_TOP)
                SET_BIT(TCCR1B, TCCR1A_COM1B1);
                CLR_BIT(TCCR1B, TCCR1A_COM1B0);
            #elif (TIMER1_SUB_MODE == TIMER_SET_ON_COMP_CLEAR_ON_TOP)
                SET_BIT(TCCR1B, TCCR1A_COM1B1);
                SET_BIT(TCCR1B, TCCR1A_COM1B0);
            #endif
        #elif (TIMER1_MODE == TIMER_CTC_MODE)
            #if (TIMER1_SUB_MODE == TIMER_NORMAL_PORT)
                CLR_BIT(TCCR1B, TCCR1A_COM1B1);
                CLR_BIT(TCCR1B, TCCR1A_COM1B0);
            #elif (TIMER1_SUB_MODE == TIMER_TOGGLE_OC0_ON_COMPARE_MATCH)
                CLR_BIT(TCCR1B, TCCR1A_COM1B1);
                SET_BIT(TCCR1B, TCCR1A_COM1B0);
            #elif (TIMER1_SUB_MODE == TIMER_CLEAR_OC0_ON_COMPARE_MATCH)
                SET_BIT(TCCR1B, TCCR1A_COM1B1);
                CLR_BIT(TCCR1B, TCCR1A_COM1B0);
            #elif (TIMER1_SUB_MODE == TIMER_SET_OC0_ON_COMPARE_MATCH)
                SET_BIT(TCCR1B, TCCR1A_COM1B1);
                SET_BIT(TCCR1B, TCCR1A_COM1B0);
            #endif
        #elif (TIMER1_MODE == TIMER_PWM_PHASE_CORRECR_MODE)
            #if (TIMER1_SUB_MODE == TIMER_NORMAL_PORT)
                CLR_BIT(TCCR1B, TCCR1A_COM1B1);
                CLR_BIT(TCCR1B, TCCR1A_COM1B0);
            #elif (TIMER1_SUB_MODE == TIMER_SET_ON_UP_COUNT_CLR_ON_DOWN_COUNT)
                SET_BIT(TCCR1B, TCCR1A_COM1B1);
                SET_BIT(TCCR1B, TCCR1A_COM1B0);
            #elif (TIMER1_SUB_MODE == TIMER_CLR_ON_UP_COUNT_SET_ON_DOWN_COUNT)
                SET_BIT(TCCR1B, TCCR1A_COM1B1);
                CLR_BIT(TCCR1B, TCCR1A_COM1B0);
            #endif
        #endif
    
    #elif(OC1B_CHANNEL == DISABLE)

    #endif

}

void TIMER_voidTimer1SetPreloadValue(u16 Copy_u16PreloadValue)
{
    TCNT1 = Copy_u16PreloadValue;
}

void TIMER_voidTimer1SetCompareMatchTime(u16 Copy_u16CompareMatchValue)
{
    OCR1A = Copy_u16CompareMatchValue;
}

void TIMER_voidTimer1SetCompMatchValueB(u16 Copy_u16CompareMatchValue)
{
    OCR1B = Copy_u16CompareMatchValue;
}

void TIMER_voidTimer1SetTopValue(u16 Copy_u16TopValue)
{
    ICR1 = Copy_u16TopValue;
}



void TIMER_voiTimer0dSetPreloadValue (u8 Copy_PreloadValue)
{
    TCNT0 = Copy_PreloadValue;
}

void TIMER_voidTimer0SetCOMatchValue (u8 Copy_COMPValue)
{
    OCR0 = Copy_COMPValue;
}


u16 TIMER_GetValueTCNT1(void)
{
	return(TCNT1);
}

u16 TIMER_GetValueICR1(void)
{
	return(ICR1);
}


void TIMER_voidSetBusyWait_COMPMode (u32 Copy_u32Timeout)
{
    /*TIMER 2*/

    /*Set CTC Mode*/
    TCCR2 &= TIMER0_SELECT_MODE_MASK_CLR;
    TCCR2 |= TIMER0_CTC_MODE_MSK;

    TCCR2 &= TIMER_PRESCALER_MASK_CLR;
    TCCR2 |= TIMER_PRESCALER_DIV_BY_64;

	OCR2 = 125;

    u8 Local_u8TCCR2OldValue = TCCR2;
    u8 Local_u8OCR2OldValue = OCR2;

    u32 Local_u32TicksToWait = 0;
    while(Local_u32TicksToWait <= Copy_u32Timeout)
    {
        while(GET_BIT(TIFR, TIFR_OCF2) == 0);
        SET_BIT(TIFR, TIFR_OCF2);
        Local_u32TicksToWait++;
    }

    TCCR2 = Local_u8TCCR2OldValue;
    OCR2 = Local_u8OCR2OldValue;
}

void TIMER_voidTimer0ControlInterrupt(u8 Copy_u8InterruptType, u8 Copy_u8Mode)
{
    
    switch (Copy_u8InterruptType)
    {
    case OVF:
        switch (Copy_u8Mode)
        {
        case ENABLE:
            SET_BIT(TIMSK, TIMSK_TOIE0);
            break;
        case DISABLE:
            CLR_BIT(TIMSK, TIMSK_TOIE0);
        default:
            break;
        }
        break;
    case COMP:
        switch (Copy_u8Mode)
        {
        case ENABLE:
            SET_BIT(TIMSK, TIMSK_OCIE0);
            break;
        case DISABLE:
            CLR_BIT(TIMSK, TIMSK_OCIE0);
        default:
            break;
        }  
    break;

    default:
    break;    
    }
    
}

void TIMER_voidTimer1ControlInterrupt(u8 Copy_u8Cannel, u8 Copy_u8InterruptType, u8 Copy_u8Mode)
{
    switch (Copy_u8Cannel)
    {
    case OC1A:
        switch (Copy_u8InterruptType)
        {
        case OVF:
            switch (Copy_u8Mode)
            {
            case ENABLE:
                SET_BIT(TIMSK, TIMSK_TOIE2);
            break;
            case DISABLE:
                CLR_BIT(TIMSK, TIMSK_TOIE2);
            break;
            }
        break;
        case COMP:
            switch (Copy_u8Mode)
            {
            case ENABLE:
                SET_BIT(TIMSK, TIMSK_OCIE1A);
            break;
            case DISABLE:
                CLR_BIT(TIMSK, TIMSK_OCIE1A);
            break;
            }
        break;
        }
    break;
    case OC1B:
        switch (Copy_u8InterruptType)
        {
        case OVF:
            switch (Copy_u8Mode)
            {
            case ENABLE:
                SET_BIT(TIMSK, TIMSK_TOIE2);
            break;
            case DISABLE:
                CLR_BIT(TIMSK, TIMSK_TOIE2);
            break;
            }
            break;
        case COMP:
            switch (Copy_u8Mode)
            {
            case ENABLE:
                SET_BIT(TIMSK, TIMSK_OCIE1A);
            break;
            case DISABLE:
                CLR_BIT(TIMSK, TIMSK_OCIE1A);
            break;
            }
            break;
        }
    break;

    default:
    break;        
    }
    
}

void ICU_voidTimer1ControlInterrupt(u8 Copy_u8Mode)
{
    switch (Copy_u8Mode)
    {
    case ENABLE:
        SET_BIT(TIMSK, TIMSK_TICIE1);
    break;
    case DISABLE:
        CLR_BIT(TIMSK, TIMSK_TICIE1);
    break;

    default:
    break;
    }
}

void ICU_voidSenceModetrigger(u8 Copy_u8Mode)
{
    switch(Copy_u8Mode)
    {
        case RISING_EDGE:
            SET_BIT(TCCR1B, TCCR1B_ICES1);
        break;
        case FALLING_EDGE:
            CLR_BIT(TCCR1B, TCCR1B_ICES1);
        break;
    }

}

/* CallBack Timer 0 */
void (* TIMER0_OVFNotification)(void) = NULL_POINTER;
void TIMER_voidTimer0SetOVFCallBack (void (* Notification)(void))
{
    TIMER0_OVFNotification = Notification;
}

void (* TIMER0_COMPNotification)(void) = NULL_POINTER;
void TIMER_voidTimer0SetCOMPFCallBack (void (* Notification)(void))
{
    TIMER0_COMPNotification = Notification;
}

/* CallBack Timer 1 */
void (* TIMER1_OVFNotification)(void) = NULL_POINTER;
void TIMER_voidTimer1SetOVFCallBack (void (* Notification)(void))
{
    TIMER1_OVFNotification = Notification;
}

void (* TIMER1_COMPANotification)(void) = NULL_POINTER;
void TIMER_voidTimer1SetCOMPACallBack (void (* Notification)(void))
{
    TIMER1_COMPANotification = Notification;
}

void (* TIMER1_COMPBNotification)(void) = NULL_POINTER;
void TIMER_voidTimer1SetCOMPBCallBack (void (* Notification)(void))
{
    TIMER1_COMPBNotification = Notification;
}

void (* ICU_Notification)(void) = NULL_POINTER;
void ICU_voidCallBack (void (* Notification)(void))
{
    ICU_Notification = Notification;
}


void vector_6 (void) __attribute__((signal));
void vector_6 (void)
{
    if(ICU_Notification != NULL_POINTER)
    {
        ICU_Notification();
    }
    else
    {
        //Do Noting
    }
}

void vector_7 (void) __attribute__((signal));
void vector_7 (void)
{
    if(TIMER1_COMPANotification != NULL_POINTER)
    {
        TIMER1_COMPANotification();
    }
    else
    {
        //Do Noting
    }
}

void vector_8 (void) __attribute__((signal));
void vector_8 (void)
{
    if(TIMER1_COMPBNotification != NULL_POINTER)
    {
        TIMER1_COMPBNotification();
    }
    else
    {
        //Do Noting
    }
}

void vector_9 (void) __attribute__((signal));
void vector_9 (void)
{
    if(TIMER1_OVFNotification != NULL_POINTER)
    {
        TIMER1_OVFNotification();
    }
    else
    {
        //Do Noting
    }
}

void vector_10 (void) __attribute__((signal));
void vector_10 (void)
{
    if(TIMER0_COMPNotification != NULL_POINTER)
    {
        TIMER0_COMPNotification();
    }
    else
    {
        //Do Noting
    }
}

void vector_11 (void) __attribute__((signal));
void vector_11 (void)
{
    if(TIMER0_OVFNotification != NULL_POINTER)
    {
        TIMER0_OVFNotification();
    }
    else
    {
        //Do Noting
    }
}

































































