/*********************************************************************/
/* Name    : Ahmad Abdulrahem							             */
/* VER     : V01 										             */
/* PurPose :											           	 */  
/*********************************************************************/
#ifndef EXTI_INTERFACE_H 
#define EXTI_INTERFACE_H
                                                                       
/*include Private file to use the Enum Data Types*/
//#include "EXTI_private.h"

typedef enum{
 LINE0 =0, /*PINA0,PIB0,PINC0,...*/
 LINE1 ,   /*PINA1,PIB1,PINC1,...*/
 LINE2 ,
 LINE3 ,
 LINE4 ,
 LINE5 ,
 LINE6 ,
 LINE7 ,
 LINE8 ,
 LINE9 ,
 LINE10,
 LINE11,
 LINE12,
 LINE13,
 LINE14,
 LINE15,
 LINE16,   /*Connected to PVD output*/
 LINE17,   /*Connected to RTC output*/
 LINE18,   /*Connected to USB Wakeup Event*/
 LINE19    /*Connected to Ethernet Wakeup Event- Connectivity Line Devices*/
}EXTI_line_t;

typedef enum{
  RISING=1,
  FALLING,
  ON_CHANGE
}EXTI_Edge_Mode;


/*Set EXTx Line, SEt Edge*/                                                                       
void MEXTI_voidInit();                                                                        
void MEXTI_voidEnableExtInt(u8 copy_u8EXTLine);                                                                        
void MEXTI_voidDisableExtInt(u8 copy_u8EXTLine);                                                                       
void MEXTI_voidSwTrigger(u8 copy_u8EXTLine);  
void MEXTI_voidSetEdge(EXTI_line_t copy_enu8EXTLine, EXTI_Edge_Mode Edge);                                                                      


#endif
