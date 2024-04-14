/**************************************************/
/* Author : Ahmad Abdulrahem                      */
/* Date   : 10 AUG 2020                           */
/* Version: V01                                   */
/**************************************************/

/*LIB includes*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*interface include - From lower layers only*/ 
  //No lower layers - I'm In MCAL:D 

/*Driver includes */ 
#include "RCC_interface.h"
#include "RCC_config.h"
#include "RCC_private.h"


void RCC_voidInitSysClock(void)
{
	/*Check What it's the clock source depened on ur choice in RCC_config.h*/ 
	#if   RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	      RCC_CR =   0x00010000; /*Enable HSE without bypass*/
	      RCC_CFGR = 0x00000001;  
		  /*Choose(Assign) HSE Crystal to be Processor Clock*/ 
	#elif RCC_CLOCK_TYPE == RCC_HSE_RC  
		  RCC_CR = 0x00050000; /*Enable HSE with bypass*/
	      RCC_CFGR = 0x00000001; /*Choose(Assign) HSE RC to be Processor Clock*/
	#elif RCC_CLOCK_TYPE == RCC_HSI /*Enable HSI - Trimming=1*/
	      RCC_CR =   0x00000081;  /*Enable HSI */
		  RCC_CFGR = 0x00000000; /*Choose(Assign) HSI RC to be Processor Clock*/
	
	#elif RCC_CLOCK_TYPE == RCC_PLL
	      #if RCC_PLL_INPUT   == RCC_PLL_IN_HSI_DIV_2
 	           RCC_CFGR = 0x00000002;
			   RCC_CFGR |= (RCC_PLL_MUL_VAL -2)<<18; 
			   SET_BIT(RCC_CFGR,24); 
			   RCC_CR = 0x01010081; 			   
			    
		  #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
 	           RCC_CFGR = 0x00030002;
			   RCC_CFGR |= (RCC_PLL_MUL_VAL -2)<<18; 
			   SET_BIT(RCC_CFGR,24); 
			   RCC_CR = 0x01010000; 			   
			   
		  #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
		       RCC_CFGR = 0x00010002;
			   RCC_CFGR |= (RCC_PLL_MUL_VAL -2)<<18; 
			   SET_BIT(RCC_CFGR,24); 
			   RCC_CR = 0x01010000; 			   
		   #endif
	#else 
		#error ("You Choosed Wrong Choice")
	#endif
} 

/* This Function to Enable any Clock Source */
void RCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId )
{
	if (Copy_u8PerId <=31)
	{
	  switch (Copy_u8BusId){
		  case RCC_AHB  :  SET_BIT(RCC_AHBENR ,Copy_u8PerId);  break;
		  case RCC_APB1 :  SET_BIT(RCC_APB1ENR,Copy_u8PerId);  break;
		  case RCC_APB2 :  SET_BIT(RCC_APB2ENR,Copy_u8PerId);  break;
		 
	    }	
	}
	else{	
		/*Return Error*/ 
	}
}

/* This Function to Disable any Clock Source */
void RCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId )
{	
	if (Copy_u8PerId <=31)
	{
	  switch (Copy_u8BusId){
		  case RCC_AHB  :  CLR_BIT(RCC_AHBENR ,Copy_u8PerId);  break;
		  case RCC_APB1 :  CLR_BIT(RCC_APB1ENR,Copy_u8PerId);  break;
		  case RCC_APB2 :  CLR_BIT(RCC_APB2ENR,Copy_u8PerId);  break;
	    }		
	}
	else{		
		/*Return Error*/ 
	}
}











