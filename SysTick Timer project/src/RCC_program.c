

#include "STD_TYPES.h"
#include "BIT_CALC.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"



void RCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerID )
{
	if (Copy_u8PerID <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB : SET_BIT(RCC_AHBENR  ,Copy_u8PerID);   	break;
			case RCC_APB1: SET_BIT(RCC_APB1ENR ,Copy_u8PerID);   	break;
			case RCC_APB2: SET_BIT(RCC_APB2ENR ,Copy_u8PerID);   	break;
			//default		 : /* return error code */				 	break;
		}
	}
	else
	{
		/* return error code */
	}
}

void RCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerID )
{
	if (Copy_u8PerID <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB : CLR_BIT(RCC_AHBENR  ,Copy_u8PerID);   	break;
			case RCC_APB1: CLR_BIT(RCC_APB1ENR ,Copy_u8PerID);   	break;
			case RCC_APB2: CLR_BIT(RCC_APB2ENR ,Copy_u8PerID);   	break;
			//default		 : /* return error code */				 	break;
		}
	}
	else
	{
		/* return error code */
	}
}

void RCC_voidInitSysClock(void)
{

#if CLK_EXTERNAL == ON
SET_BIT(RCC_CR,HSE_ON);
#elif CLK_EXTERNAL == OFF
CLR_BIT(RCC_CR,HSE_ON);
#endif

#if CLK_EXTERNAL_TYPE == XTAL
CLR_BIT(RCC_CR,HSE_BYP);
#elif CLK_EXTERNAL_TYPE == RC
SET_BIT(RCC_CR,HSE_BYP);
#endif

#if CLK_EXTERNAL_SECURITY == ON
SET_BIT(RCC_CR,CSS_ON);
#elif CLK_EXTERNAL_SECURITY == OFF
CLR_BIT(RCC_CR,CSS_ON);
#endif

#if CLK_INTERNAL == ON
SET_BIT(RCC_CR,HSI_ON);
#elif CLK_INTERNAL == OFF
CLR_BIT(RCC_CR,HSI_ON);
#endif

#if CLK_PLL == ON

	#if PLL_SOURCE == EXT
		SET_BIT(RCC_CFGR,PLL_SRC);

		#if PLL_EXT_PRESCALER == PLL_HSE_NO_DIV
			CLR_BIT(RCC_CFGR,PLL_XTPRE);
		#elif PLL_EXT_PRESCALER == PLL_HSE_DIV_BY_2
			SET_BIT(RCC_CFGR,PLL_XTPRE);
		#endif
	#elif PLL_SOURCE == INT_DIV_BY_2
		CLR_BIT(RCC_CFGR,PLL_SRC);
	#endif
/* choose PLL PRESCALER  */ /*(1111-1111-1100-0011)-(1111-1111-1111-1111)  */
		/*   00000-0111-0000000000000    */
 RCC_CFGR = (RCC_CFGR & 0xffc3ffff ) | (PLL_PRESCALER<<PLLMUL) ; /* 7<<18 */
/* turn ON PLL as the last thing */
SET_BIT(RCC_CR,PLL_ON);
#elif CLK_PLL == OFF
CLR_BIT(RCC_CR,PLL_ON);
#endif


/* choose cpu clock source  */
	
RCC_CFGR = (RCC_CFGR & 0xfffffffc) | (CPU_CLK_SOURCE) ;



}
