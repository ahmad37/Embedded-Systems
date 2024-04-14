/**************************************************/
/* Author : Ahmad Abdulrahem                      */
/* Date   : 10 AUG 2020                           */
/* Version: V01                                   */
/**************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_



/*Bus Names - used to Enable Buses */
#define RCC_AHB   0
#define RCC_APB1  1
#define RCC_APB2  2
/***********************************/

void RCC_voidInitSysClock(void); 
void RCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId ); 
void RCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId ); 

#endif
