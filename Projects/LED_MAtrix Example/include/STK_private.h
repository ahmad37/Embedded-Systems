/*
 *  SysTick
 *
 *  Created on: Aug 29, 2020
 *      Author: Ahmad
 */
 
 #ifndef  STK_PRIVATE
 #define  STK_PRIVATE
 
 
 /*Registers*/ 
 
typedef struct{
	 u32 CTRL;
	 u32 LOAD;
     u32 VALUE ;
   }MSTK_Type;
   
 #define MSTK  ((volatile MSTK_Type*)0xE000E010)
 
 /*Define bits INDEX - CNTRL REGISTER*/
 #define ENABLE_BIT     0   /*TO ENABLE/DISABLE THE SYSTICK TIMER*/
 #define TICKINT_BIT    1   /*TO ENABLE/DISABLE SYSTICK INTERRUPT , 0= NO INTERRUPT : 1= INTERRUPT WILL HAPPENED*/
 #define CLKSOURCE_BIT  2   /*TO SET TIMER FREQUENCY , 0=AHB/8 : 1= AHB FREQUENCY*/ 
 #define COUNT_FLAG_BIT 16  /*RAISED IF INTERRUPT OCCUERED*/  
 //OTHER BITS ARE RESERVED IN CTRL REGISTER 


 #define     MSTK_SINGLE_INTERVAL    0
 #define     MSTK_PERIOD_INTERVAL    1


 /*
 typedef enum{
	 AHB_CLOCK_OVER_8=0,
	 AHB_CLOCK
 }STK_CLK_SOURCE_Typedef; 
 */
 
 /*CallBack*/ 
 
 #endif
