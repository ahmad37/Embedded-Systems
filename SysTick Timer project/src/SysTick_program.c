/*
 * SysTick_program.c
 *
 *  Created on: Aug 24, 2020
 *      Author: mazen
 */

#include "STD_TYPES.h"
#include "BIT_CALC.h"

#include "SysTick_interface.h"
#include "SysTick_private.h"
#include "SysTick_config.h"

void STK_voidTimerInit(void)
{
#if STK_Interrupt_Enable == ENABLE
	 SET_BIT(STK_CTRL,STK_TICKINT) ;
#endif

#if STK_CLK_SOURCE == AHB
	 SET_BIT(STK_CTRL,STK_CLKSOURCE) ;
#endif

}

void STK_voidStartTimer(void)
{
SET_BIT(STK_CTRL,STK_EN);
}

void STK_voidStopTimer(void)
{
	CLR_BIT(STK_CTRL,STK_EN);

}



void STK_voidLoadTimer(u32 copy_u32load)
{
STK_LOAD = copy_u32load ;
}

void STK_voidDelay_ms(u32 copyu32_delay)
{
	u32 dummy = 0;
	//assuming a 1us timer tick

	u32 ms_counter = copyu32_delay;
	/* write to VAL to reset it  */
	STK_VAL = 0 ;

	/* load timer with 1000 */
		STK_voidLoadTimer(1000) ;
		/* start timer   */
		STK_voidStartTimer();
	do
	{
	/* poll on COUNT_FLAG  */
		while( GET_BIT(STK_CTRL,STK_COUNT_FLAG) == 0) {}

		/*  decrement ms_counter */
		ms_counter-- ;

		/* clear flag by reading it */
				dummy =  STK_CTRL ;
		/* check to see if we reached our ms count */

	}while(ms_counter!=0 );

dummy += 1 ;

}
