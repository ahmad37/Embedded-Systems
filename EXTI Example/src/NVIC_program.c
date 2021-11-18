/*******************************************/
/*Author : Ahmad                           */
/*Date : 19 AUG 2020                       */ 
/*VER : V01                                */
/*******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h" 

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_voidInit(void)
{   /*Set Group and SubGroup Based on config file */
	#ifndef  SCB_AIRCR
    #define  SCB_AIRCR  *((u32*)0xE000ED0C)
	#endif
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}

//void MNVIC_voidSetPriority(u8 Copy_PeripheralIdx, u8 Copy_u8Priority)
//{
//	if (Copy_PeripheralIdx < 60)
//	{
//		NVIC_IPR[Copy_PeripheralIdx] = Copy_u8Priority<<4;
//	}
//
//	else
//	{
//		/* Report Error */
//	}
//}
/*you can define interrupt IDs as macros*/ 
void MNVIC_voidSetPriority(s8 copy_s8InterruptID, u8 copy_u8GroupPriority, u8 copy_u8SubPriority)
{
u8 Local_u8Priority=copy_u8SubPriority|(copy_u8GroupPriority<<((MNVIC_GROUP_SUB_DISTRIBUTION-0x05FA0300)/256));
	
	/*check Interrupt ID to Know if the interrupt is a core peripheral or periphral*/
   	
	/*core peripheral*/ 
	
	/*External Periphral- interrupts 0:59 */
	if((copy_s8InterruptID >=0) && (copy_s8InterruptID <60) )
	{
		NVIC_IPR[copy_s8InterruptID]=Local_u8Priority<<4; 
	}
	/*Set Group and SubGroup Based on config file */
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}

/*TO Enable write 1 on corresponding bit - 0 has no effect*/
void MNVIC_voidEnableInterrupt(u8 copy_u8IntNumber)
{
	/*Check boundaries*//*I comments on the conditions which will be always true*/
	if(/*copy_u8IntNumber >=0 &&*/ copy_u8IntNumber <=31)
	{
		/*direct write better than Read/Modify/Write here due to the register doesn't effect by 0- and this faster*/
		NVIC_ISER0 = (1<<copy_u8IntNumber);	 
	}
	else if (/*copy_u8IntNumber >=32 &&*/ copy_u8IntNumber <=59)
	{
		copy_u8IntNumber -= 32; 
		NVIC_ISER1 = (1<<copy_u8IntNumber);
	}
  	else
	{  
		/*return ErrorStatus */
	}
} 

/*TO disable write 1 on corresponding bit - 0 has no effect*/
void MNVIC_voidDisableInterrupt(u8 copy_u8IntNumber)
{
	/*Check boundaries*//*I comments on the conditions which will be always true*/
	if(/*copy_u8IntNumber >=0 &&*/ copy_u8IntNumber <=31)
	{ 
		/*direct write better than Read/Modify/Write here due to the register doesn't effect by 0- and this faster*/
		NVIC_ICER0 = (1<<copy_u8IntNumber);		 
	}
	else if (/*copy_u8IntNumber >=32 &&*/ copy_u8IntNumber <=59)
	{
		copy_u8IntNumber -= 32; 
		NVIC_ICER1 = (1<<copy_u8IntNumber);   
	}
  	else
	{  
		/*return ErrorStatus */
	}
} 

/*TO Enable Pending Flag*/
void MNVIC_voidSetPendingFlag(u8 copy_u8IntNumber)
{
	/*Check boundaries*//*I comments on the conditions which will be always true*/	
	if(/*copy_u8IntNumber >=0 &&*/ copy_u8IntNumber <=31)
	{
		/*direct write better than Read/Modify/Write here due to the register doesn't effect by 0- and this faster*/
		NVIC_ISPR0 = (1<<copy_u8IntNumber);
	}
	else if (/*copy_u8IntNumber >=32 &&*/ copy_u8IntNumber <=59)
	{
		copy_u8IntNumber -= 32; 
		NVIC_ISPR1 = (1<<copy_u8IntNumber);   
	}
  	else
	{ 
		/*return ErrorStatus */
	}	
}

/*TO Clear Pending Flag*/
void MNVIC_voidClearPendingFlag(u8 copy_u8IntNumber)
{
	/*Check boundaries*//*I comments on the conditions which will be always true*/	
	if(/*copy_u8IntNumber >=0 &&*/ copy_u8IntNumber <=31)
	{
		/*direct write better than Read/Modify/Write here due to the register doesn't effect by 0- and this faster*/
		NVIC_ICPR0 = (1<<copy_u8IntNumber);
	}
	else if (/*copy_u8IntNumber >=32 &&*/ copy_u8IntNumber <=59)
	{
		copy_u8IntNumber -= 32; 
		NVIC_ICPR1 = (1<<copy_u8IntNumber);   
	}
  	else
	{  
		/*return ErrorStatus */	
	}
} 
/*Read the status of the active flags*/ 
u8 MNVIC_u8GetActiveFlag(u8 copy_u8IntNumber)
{
	u8 Local_u8Result; 
	/*Check boundaries*/ /*I comments on the conditions which will be always true*/
	if(/*copy_u8IntNumber >=0 &&*/ copy_u8IntNumber <=31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0,copy_u8IntNumber);
	}
	else if (/*copy_u8IntNumber >=32 &&*/ copy_u8IntNumber <=59)
	{
		copy_u8IntNumber -= 32; 
	    Local_u8Result = GET_BIT(NVIC_IABR1,copy_u8IntNumber);
	}
  	else
	{  
       return Local_u8Result; 
	}	

} 
