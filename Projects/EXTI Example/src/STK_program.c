/*
 *  SysTick
 *
 *  Created on: Aug 29, 2020
 *      Author: Ahmad
 */
 
/*include libs*/ 
#include "STD_TYPES.h"
#include "BIT_MATH.h" 

#include "STK_interface.h" 
#include "STK_config.h"
#include "STK_private.h" 


/*Global Function Pointer used to point the any function that passed by user and called in systick handler in background*/   
void (*MSTK_CallBack)(void); 

/*GS for Global static - this variable to Check interval single/periodic used in systick handler*/
static u8 GS_IntervalMode;  
 
 /*initialize SysTick Timer - choose the clock source and disable the timer and interrupt
       Enabling Systick timer and intterupt are be done in other reguarly used functions*/               
 void MSTK_voidInit(void)
 {
	/*Set the Clock depend on the configuration file STK_config.h*/
    #if STK_CLOCK_SOURCE == AHB_CLOCK
	 MSTK->CTRL = 0x00000004;/*Disable Systick timer - Set AHB as a clock*/
	#else 
	 MSTK->CTRL = 0; /*Disable Systick timer - Set AHB/8 as a clock*/
	 MSTK->CTRL = 0x00;
	 #endif
	
 } 
 /*this function like a normal delay - Syncronous function*/
void MSTK_voidSetBusyWait(u32 copy_u32Ticks)
{
	/*Set Load Register with the Passed Value*/
	MSTK->LOAD=copy_u32Ticks;
	/*Enable(start) Systick timer*/ 
	SET_BIT(MSTK->CTRL,ENABLE_BIT);
	
	/*Wait till flag is raised- complete*/
	while ((GET_BIT(MSTK->CTRL,COUNT_FLAG_BIT))==0)asm("NOP");
	/*stop timer- CLEAR REGISTRES*/
	CLR_BIT(MSTK->CTRL,ENABLE_BIT);
	MSTK->LOAD = 0;
	MSTK->VALUE=0;
	
} 

/*Asynchronus Function Delay-- used to make one event at a time after a certain delay*/ 
void MSTK_voidSetIntervalSingle(u32 copy_u32Ticks, void(*copy_ptr)(void))
{   
	  MSTK->LOAD = copy_u32Ticks;
		SET_BIT(MSTK->CTRL, 0);
		MSTK_CallBack = copy_ptr ;
		/* Set Mode to Single */
		GS_IntervalMode = MSTK_SINGLE_INTERVAL;
		SET_BIT(MSTK->CTRL, 1);
	
//	 /*Set interval mode flag to Single Interval*/
//   	 GS_IntervalMode =MSTK_SINGLE_INTERVAL;
//
//	 /*Set Call Back */
//	 MSTK_CallBack=copy_ptr;
//
//	 /*Set Load Register with the Passed Value*/
//	 MSTK->LOAD =copy_u32Ticks;
//
//	 /*Enable Systick timer*/
//	 SET_BIT(MSTK->CTRL,ENABLE_BIT);
//
//	 /*Enable SysTick Interrupt*/
//     SET_BIT(MSTK->CTRL,TICKINT_BIT);
	
	
}
/*Asyncrounous Function Delay - used to make a preiodic Events*/ 
void MSTK_voidSetIntervalPeriodic(u32 copy_u32Ticks, void(*copy_ptr)(void))
{
	/* Load ticks to load register */
		MSTK -> LOAD = copy_u32Ticks;

		/* Start Timer */
		SET_BIT(MSTK->CTRL, 0);

		/* Save CallBack */
		MSTK_CallBack = copy_ptr;

		/* Set Mode to Single */
		GS_IntervalMode = MSTK_PERIOD_INTERVAL;

		/* Enable STK Interrupt */
		SET_BIT(MSTK->CTRL, 1);
	
} 
void MSTK_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(MSTK->CTRL, TICKINT_BIT);
	
	/* Stop Timer */
	SET_BIT(MSTK->CTRL, ENABLE_BIT);
	MSTK -> LOAD = 0;
	MSTK -> VALUE  = 0;

}
 
/*Get the Elapsed Time*/
u32  MSTK_u32GetElapsedTime(void)
{ 
	/*return with { STK_LOAD - STK_VALUE } */
	return (MSTK->LOAD - MSTK->VALUE);
	
} 

/*Get The Remaining Time*/ 
u32  MSTK_u32GetRemainingTime(void)
{
	/*return the value of STK_VALUE  register*/ 
   return MSTK->VALUE;
}

/*Interrupt Handler of SysTick Timer*/
/*used to make a single shot delay ,  peroidic delay - for Asynchronus fuctions*/  
void SysTick_Handler(void)
{
	//Pesudo Code.
	/*check interval mode 
	   //if (mode==single) 
	       MSTK_CallBack(); 
	       stop timer 
		   stop interrupt 
		   claer load register
	   //else //peroidic//
           //load the load_register again
           //MSTK_CallBack(); */
		   
   	volatile u8 Local_u8Temporary;  //To read(clear) Interrupt flag
	
	if (GS_IntervalMode == MSTK_SINGLE_INTERVAL)
	{
		/* Disable SysTick Interrupt */
		CLR_BIT(MSTK->CTRL, TICKINT_BIT);
	
		/* Stop Timer - Clear Registers*/
		CLR_BIT(MSTK->CTRL, ENABLE_BIT);
		MSTK -> LOAD = 0;
		MSTK -> VALUE  = 0;
	}
	
	/* Callback notification */
	MSTK_CallBack();
	
	/* Clear interrupt flag - by reading it's value */
	Local_u8Temporary = GET_BIT(MSTK->CTRL,16);        		   


}











