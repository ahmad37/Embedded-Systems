/*
 *  SysTick Interface
 *  Created on: Aug 29, 2020
 *  Author: Ahmad
 */
 
 #ifndef  STK_INTERFACE
 #define  STK_INTERFACE
 
 
 
/*choose colock from configuration file
  Disable SysTick Interrupt
  Disable SysTick
*/
void MSTK_voidInit(void); 
void MSTK_voidSetBusyWait(u32 copy_u32Ticks); 
void MSTK_voidSetIntervalSingle(u32 copy_u32Ticks, void(*copy_ptr)(void));
void MSTK_voidSetIntervalPeriodic(u32 copy_u32Ticks, void(*copy_ptr)(void)); 
void MSTK_voidStopInterval(void); 
u32  MSTK_u32GetElapsedTime(void); 
u32  MSTK_u32GetRemainingTime(void); 
 


 
 #endif