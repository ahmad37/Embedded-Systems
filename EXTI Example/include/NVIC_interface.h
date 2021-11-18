/*******************************************/
/*Author : Ahmad                           */
/*Date : 19 AUG 2020                       */ 
/*VER : V01                                */
/*******************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/*Enable external interrupts*/ 
void MNVIC_voidEnableInterrupt(u8 copy_u8IntNumber);
/*Disable External interrupts*/
void MNVIC_voidDisableInterrupt(u8 copy_u8IntNumber); 
/*Set Pending Flag to High */ 
void MNVIC_voidSetPendingFlag(u8 copy_u8IntNumber);
/*Clear Pending Flag */  
void MNVIC_voidClearPendingFlag(u8 copy_u8IntNumber); 
/*Read the Status of Active Flag*/ 
u8   MNVIC_u8GetActiveFlag(u8 copy_u8IntNumber); 


//void MNVIC_voidSetPriority(u8 Copy_PeripheralIdx, u8 Copy_u8Priority);
void MNVIC_voidSetPriority(s8 copy_s8InterruptID, u8 copy_u8GroupPriority, u8 copy_u8SubPriority);
void MNVIC_voidInit(void);


#endif
