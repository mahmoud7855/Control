#include "../../LIB/BIT_MATH.h"
#include "../../LIB/Std_Types.h"

#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"


static void (*EXTI_INT0_Function)(void) = NULL_POINTER;

void EXTI_voidInit(void)
{
    #if EXTI_INT0_ENABLE == EXTI_ENABLE
        /*Enable GICR*/
        SET_BIT(GICR, GICR_INT0);
        #if EXTI_INT0_SENSE_MODE == EXTI_RISING_EDGE
            SET_BIT(MCUCR, MCUCR_ISC00);
            SET_BIT(MCUCR, MCUCR_ISC01);
        #elif EXTI_INT0_SENSE_MODE == EXTI_FALLING_EDGE
            CLR_BIT(MCUCR, MCUCR_ISC00);
            SET_BIT(MCUCR, MCUCR_ISC01);
        #elif EXTI_INT0_SENSE_MODE == EXTI_ON_CHANGE
            SET_BIT(MCUCR, MCUCR_ISC00);
            CLR_BIT(MCUCR, MCUCR_ISC01);
        #elif EXTI_INT0_SENSE_MODE == EXTI_LOW_LEVEL
            CLR_BIT(MCUCR, MCUCR_ISC00);
            CLR_BIT(MCUCR, MCUCR_ISC01);
        #else

        #endif

    #elif EXTI_INT0_ENABLE == EXTI_DISABLE
        /*Disable GICR*/
        CLR_BIT(GICR, GICR_INT0);
    #else  
        #error "Error, Exit_INT0_SENSE_MODE_CONFIGRATION"

    #endif

    #if EXTI_INT1_ENABLE == EXTI_ENABLE
        /*Enable GICR*/
        SET_BIT(GICR, GICR_INT1);
        #if EXTI_INT1_SENSE_MODE == EXTI_RISING_EDGE
            SET_BIT(MCUCR, MCUCR_ISC10);
            SET_BIT(MCUCR, MCUCR_ISC11);
        #elif EXTI_INT1_SENSE_MODE == EXTI_FALLING_EDGE
            CLR_BIT(MCUCR, MCUCR_ISC10);
            SET_BIT(MCUCR, MCUCR_ISC11);
        #elif EXTI_INT1_SENSE_MODE == EXTI_ON_CHANGE
            SET_BIT(MCUCR, MCUCR_ISC10);
            CLR_BIT(MCUCR, MCUCR_ISC11);
        #elif EXTI_INT1_SENSE_MODE == EXTI_LOW_LEVEL
            CLR_BIT(MCUCR, MCUCR_ISC10);
            CLR_BIT(MCUCR, MCUCR_ISC11);
        #else

        #endif
    #elif EXTI_INT1_ENABLE == EXTI_DISABLE
        /*Disable GICR*/
        CLR_BIT(GICR, GICR_INT0);
    #else  
        #error "Error, Exit_INT0_SENSE_MODE_CONFIGRATION"

    #endif

    #if EXTI_INT2_ENABLE == EXTI_ENABLE
        /*Enable GICR*/
        SET_BIT(GICR, GICR_INT1);
        #if EXTI_INT2_SENSE_MODE == EXTI_RISING_EDGE
            SET_BIT(MCUCSR, MCUCSR_ISC2);
        #elif EXTI_INT2_SENSE_MODE == EXTI_FALLING_EDGE
            CLR_BIT(MCUCSR, MCUCSR_ISC2);
            
        #else

        #endif
    #elif EXTI_INT2_ENABLE == EXTI_DISABLE
        /*Disable GICR*/
        CLR_BIT(GICR, GICR_INT0);
    #else  
        #error "Error, Exit_INT0_SENSE_MODE_CONFIGRATION"

    #endif

    

}

void EXTI_voidChangeSenceMode(u8 Copy_u8InterruptNum, u8 Copy_u8SignalSence)
{
    switch (Copy_u8InterruptNum)
    {
    case EXTI_INT0:
        switch (Copy_u8SignalSence)
        {
        case EXTI_RISING_EDGE:
            SET_BIT(MCUCR, MCUCR_ISC00);
            SET_BIT(MCUCR, MCUCR_ISC01);
            break;
        case EXTI_FALLING_EDGE:
            CLR_BIT(MCUCR, MCUCR_ISC00);
            SET_BIT(MCUCR, MCUCR_ISC01);
        case EXTI_ON_CHANGE:
            SET_BIT(MCUCR, MCUCR_ISC00);
            CLR_BIT(MCUCR, MCUCR_ISC01);
        case EXTI_LOW_LEVEL:
            CLR_BIT(MCUCR, MCUCR_ISC00);
            CLR_BIT(MCUCR, MCUCR_ISC01);
        default:
            break; 
        }
        break;
    case EXTI_INT1:
    switch (Copy_u8SignalSence)
        {
        case EXTI_RISING_EDGE:
            SET_BIT(MCUCR, MCUCR_ISC10);
            SET_BIT(MCUCR, MCUCR_ISC11);
            break;
        case EXTI_FALLING_EDGE:
            CLR_BIT(MCUCR, MCUCR_ISC10);
            SET_BIT(MCUCR, MCUCR_ISC11);
        case EXTI_ON_CHANGE:
            SET_BIT(MCUCR, MCUCR_ISC10);
            CLR_BIT(MCUCR, MCUCR_ISC11);
        case EXTI_LOW_LEVEL:
            CLR_BIT(MCUCR, MCUCR_ISC10);
            CLR_BIT(MCUCR, MCUCR_ISC11);
        default:
            break; 
        }

        break;
    case EXTI_INT2:
        switch (Copy_u8SignalSence)
        {
        case EXTI_RISING_EDGE:
            SET_BIT(MCUCSR, MCUCSR_ISC2);
            break;
        case EXTI_FALLING_EDGE:
            CLR_BIT(MCUCR, MCUCSR_ISC2);
        default:
            break; 
        }
    
    default:
        break;
    }

}

void EXTI_voidInterruptContal(u8 Copy_u8InterruptNum, u8 Copy_u8InterruptState)
{
    switch (Copy_u8InterruptNum)
    {
        case EXTI_INT0:
            switch(Copy_u8InterruptState)
            {
                case EXTI_ENABLE:
                    SET_BIT(GICR, GICR_INT0);
                    break;
                case EXTI_DISABLE:
                    CLR_BIT(GICR, GICR_INT0);
                    break;
            }
            break;
        case EXTI_INT1:
            switch(Copy_u8InterruptState)
            {
                case EXTI_ENABLE:
                    SET_BIT(GICR, GICR_INT1);
                    break;
                case EXTI_DISABLE:
                    CLR_BIT(GICR, GICR_INT1);
                    break;
            }
            break;
        case EXTI_INT2:
            switch(Copy_u8InterruptState)
            {
                case EXTI_ENABLE:
                    SET_BIT(GICR, GICR_INT2);
                    break;
                case EXTI_DISABLE:
                    CLR_BIT(GICR, GICR_INT2);
                    break;
            }
            break; 
        default:
        break;
    }

}

u8 EXTI_voidGetInterruptFlag(u8 Copy_u8InterruptNum)
{
    u8 Local_u8GetFlag = 0;
    switch (Copy_u8InterruptNum)
    {
    case EXTI_INT0:
        Local_u8GetFlag = GET_BIT(GIFR, GICR_INT0);
        break;
    case EXTI_INT1:
        Local_u8GetFlag = GET_BIT(GIFR, GICR_INT1);
        break;
    case EXTI_INT2:
        Local_u8GetFlag = GET_BIT(GIFR, GICR_INT2);
        break;

    default:
        break;
    }
    return (Local_u8GetFlag);

}
/* Solve The Problem Of The Arcitechture*/
void EXTI_voidSetCallBack(void(*NotificationFunction)(void))
{
    /*The Pointer That Shard At All Function And Store The Adress Of The Local pointer TO Function*/
    EXTI_INT0_Function =  NotificationFunction;
}
/*
 * ISR For INT0
 */
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    /*Excute The Application Function*/
    //Guard From The Garbish Value Of ISR
    if(EXTI_INT0_Function != NULL_POINTER)
    {
        EXTI_INT0_Function();
    }
    else
    {
        //Do Noting
    }
}

    
    


