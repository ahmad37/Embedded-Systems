/*********************************************************************/
/* Name    : Ahmad Abdulrahem							             */
/* VER     : V01 										             */
/* PurPose :											           	 */  
/*********************************************************************/
#ifndef EXTI_PRIVATE_H 
#define EXTI_PRIVATE_H
   
   
typedef struct
{ /*IMR(interrupt Mask Reg)- Used to Enable Exernal Intertupt Lines*/
	volatile u32 	IMR;
  /*IMR(Event Mask Reg)- Used to Enable Exernal Event Lines*/ 
    volatile u32 	EMR;
  /*RTSR(Rising Trigger Selection Reg)- Set Rising Edge To A corresponding EXTI Line*/	
    volatile u32 	RTSR;
  /*RTSR(Falling Trigger Selection Reg)- Set Falling Edge To A corresponding EXTI Line*/
    volatile u32 	FTSR;
   
    volatile u32 	SWIER;
 
    volatile u32 	PR;	
}EXTI_t;

#define EXTI  ((volatile EXTI_t *)(0x40010400))                                                                    
                                                                       

                                                                       
#endif
