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

#ifndef _EXTI_CONFIG_
#define _EXTI_CONFIG_



#define EXTI_INT0_ENABLE        EXTI_ENABLE
#define EXTI_INT1_ENABLE        EXTI_DISABLE
#define EXTI_INT2_ENABLE        EXTI_DISABLE


#define EXTI_INT0_SENSE_MODE    EXTI_RISING_EDGE
#define EXTI_INT1_SENSE_MODE    EXTI_RISING_EDGE
#define EXTI_INT2_SENSE_MODE    EXTI_RISING_EDGE


#endif