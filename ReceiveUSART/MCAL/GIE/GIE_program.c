#include "../../LIB/BIT_MATH.h"
#include "../../LIB/Std_Types.h"


#include "GIE_private.h"
#include "GIE_interface.h"
#include "GIE_config.h"



void GIE_voidEnableGlobalInterrupt(void)
{
    /*Set The I_BIT To Enable The Global Intterupt*/
    SET_BIT(SREG, SREG_I);
}


void GIE_voidDisableGlobalInterrupt(void)
{
    /*Set The I_BIT To Enable The Global Intterupt*/
    CLR_BIT(SREG, SREG_I);
}
