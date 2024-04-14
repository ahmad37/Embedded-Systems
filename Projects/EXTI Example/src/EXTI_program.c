/*********************************************************************/
/* Name    : Ahmad Abdulrahem							             */
/* VER     : V01 										             */
/* PurPose :											           	 */  
/*********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h" 

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h" 

void (*EXTI_CallBack[20])(void);


/*Enable EXTI Lines   Corresponding to your Choice in config file/
  Set Edge Sense Mode Corresponding to your Choice in config file*/
void MEXTI_voidInit()
{
	/*Enable The Line */ 
	#if   EXTI_LINE0_ENABLE  !=0  /* Check If User Enable This Line */  
		 SET_BIT(EXTI->IMR , LINE0); /*Enable EXTI Line0 */
		/*ENABLE EDGE*/
		#if  EXTI_LINE0_EDGE ==   1  //RISING EDGE
	     SET_BIT(EXTI->RTSR , LINE0);
	     #elif EXTI_LINE0_EDGE == 2  //FALLING EDGE
		 SET_BIT(EXTI->FTSR , LINE0);
	     #elif EXTI_LINE0_EDGE == 3  //ON_CAHNGE RISING+FALLING EDGE
	     SET_BIT(EXTI->RTSR , LINE0);
	     SET_BIT(EXTI->FTSR , LINE0);
	     #else
		    #error "Wrong External Interrupt 0 Edge Sense Mode"
	     #endif
    #endif
/**************************************************************/
	#if EXTI_LINE1_ENABLE !=0
	     SET_BIT(EXTI->IMR , LINE1); /*Enable EXTI Line1 */

	     /*ENABLE EDGE*/
	     #if  EXTI_LINE1_EDGE ==   1  //RISING EDGE
	      SET_BIT(EXTI->RTSR , LINE1);
	      #elif EXTI_LINE1_EDGE == 2  //FALLING EDGE
	      SET_BIT(EXTI->FTSR , LINE1);
	      #elif EXTI_LINE1_EDGE == 3  //ON_CAHNGE RISING+FALLING EDGE
	      SET_BIT(EXTI->RTSR , LINE1);
	      SET_BIT(EXTI->FTSR , LINE1);
	      #else
	         #error "Wrong External Interrupt 1 Edge Sense Mode"
	      #endif
	#endif
/******************************************************************/
 #ifdef   EXTI_LINE2_ENABLE
      #if EXTI_LINE2_ENABLE !=0
          SET_BIT(EXTI->IMR , LINE2); /*Enable EXTI Line2 */

                 /*ENABLE EDGE*/
           #if  EXTI_LINE2_EDGE ==   1  //RISING EDGE
            SET_BIT(EXTI->RTSR , LINE2);
            #elif EXTI_LINE2_EDGE == 2  //FALLING EDGE
            SET_BIT(EXTI->FTSR , LINE2);
            #elif EXTI_LINE2_EDGE == 3  //ON_CAHNGE RISING+FALLING EDGE
            SET_BIT(EXTI->RTSR , LINE2);
            SET_BIT(EXTI->FTSR , LINE2);
            #else
               #error "Wrong External Interrupt 2 Edge Sense Mode"
            #endif//#end of #if
      #endif  //end of #if
 #endif  //end of #ifdef
/******************************************************************/
 #ifdef   EXTI_LINE3_ENABLE
      #if EXTI_LINE3_ENABLE !=0
          SET_BIT(EXTI->IMR , LINE3); /*Enable EXTI Line3 */

                 /*ENABLE EDGE*/
           #if  EXTI_LINE3_EDGE ==   1  //RISING EDGE
            SET_BIT(EXTI->RTSR , LINE3);
            #elif EXTI_LINE3_EDGE == 2  //FALLING EDGE
            SET_BIT(EXTI->FTSR , LINE3);
            #elif EXTI_LINE3_EDGE == 3  //ON_CAHNGE RISING+FALLING EDGE
            SET_BIT(EXTI->RTSR , LINE3);
            SET_BIT(EXTI->FTSR , LINE3);
            #else
               #error "Wrong External Interrupt 3 Edge Sense Mode"
            #endif//#end of #if
      #endif  //end of #if
 #endif  //end of #ifdef
/******************************************************************/
#ifdef    EXTI_LINE4_ENABLE
      #if EXTI_LINE4_ENABLE !=0
          SET_BIT(EXTI->IMR , LINE4); /*Enable EXTI Line4 */

                 /*ENABLE EDGE*/
           #if  EXTI_LINE4_EDGE ==   1  //RISING EDGE
            SET_BIT(EXTI->RTSR , LINE4);
            #elif EXTI_LINE4_EDGE == 2  //FALLING EDGE
            SET_BIT(EXTI->FTSR , LINE4);
            #elif EXTI_LINE4_EDGE == 3  //ON_CAHNGE RISING+FALLING EDGE
            SET_BIT(EXTI->RTSR , LINE4);
            SET_BIT(EXTI->FTSR , LINE4);
            #else
               #error "Wrong External Interrupt 4 Edge Sense Mode"
            #endif//#end of #if
      #endif  //end of #if
 #endif  //end of #ifdef
/******************************************************************/
#ifdef    EXTI_LINE5_ENABLE
      #if EXTI_LINE5_ENABLE !=0
          SET_BIT(EXTI->IMR , LINE5); /*Enable EXTI Line5 */

                 /*ENABLE EDGE*/
           #if  EXTI_LINE5_EDGE ==   1  //RISING EDGE
            SET_BIT(EXTI->RTSR , LINE5);
            #elif EXTI_LINE5_EDGE == 2  //FALLING EDGE
            SET_BIT(EXTI->FTSR , LINE5);
            #elif EXTI_LINE5_EDGE == 3  //ON_CAHNGE RISING+FALLING EDGE
            SET_BIT(EXTI->RTSR , LINE5);
            SET_BIT(EXTI->FTSR , LINE5);
            #else
               #error "Wrong External Interrupt 5 Edge Sense Mode"
            #endif//#end of #if
      #endif  //end of #if
 #endif  //end of #ifdef
/******************************************************************/
#ifdef    EXTI_LINE6_ENABLE
      #if EXTI_LINE6_ENABLE !=0
          SET_BIT(EXTI->IMR , LINE6); /*Enable EXTI Line6 */

                 /*ENABLE EDGE*/
           #if  EXTI_LINE6_EDGE ==   1  //RISING EDGE
            SET_BIT(EXTI->RTSR , LINE6);
            #elif EXTI_LINE6_EDGE == 2  //FALLING EDGE
            SET_BIT(EXTI->FTSR , LINE6);
            #elif EXTI_LINE6_EDGE == 3  //ON_CAHNGE RISING+FALLING EDGE
            SET_BIT(EXTI->RTSR , LINE6);
            SET_BIT(EXTI->FTSR , LINE6);
            #else
               #error "Wrong External Interrupt 6 Edge Sense Mode"
            #endif//#end of #if
      #endif  //end of #if
 #endif  //end of #ifdef
/******************************************************************/
#ifdef    EXTI_LINE7_ENABLE
      #if EXTI_LINE7_ENABLE !=0
          SET_BIT(EXTI->IMR , LINE7); /*Enable EXTI Line7 */

                 /*ENABLE EDGE*/
           #if  EXTI_LINE7_EDGE ==   1  //RISING EDGE
            SET_BIT(EXTI->RTSR , LINE7);
            #elif EXTI_LINE7_EDGE == 2  //FALLING EDGE
            SET_BIT(EXTI->FTSR , LINE7);
            #elif EXTI_LINE7_EDGE == 3  //ON_CAHNGE RISING+FALLING EDGE
            SET_BIT(EXTI->RTSR , LINE7);
            SET_BIT(EXTI->FTSR , LINE7);
            #else
               #error "Wrong External Interrupt 7 Edge Sense Mode"
            #endif//#end of #if
      #endif  //end of #if
 #endif  //end of #ifdef
/******************************************************************/
#ifdef    EXTI_LINE8_ENABLE
      #if EXTI_LINE8_ENABLE !=0
          SET_BIT(EXTI->IMR , LINE8); /*Enable EXTI Line8 */

                 /*ENABLE EDGE*/
           #if  EXTI_LINE8_EDGE ==   1  //RISING EDGE
            SET_BIT(EXTI->RTSR , LINE8);
            #elif EXTI_LINE8_EDGE == 2  //FALLING EDGE
            SET_BIT(EXTI->FTSR , LINE8);
            #elif EXTI_LINE8_EDGE == 3  //ON_CAHNGE RISING+FALLING EDGE
            SET_BIT(EXTI->RTSR , LINE8);
            SET_BIT(EXTI->FTSR , LINE8);
            #else
               #error "Wrong External Interrupt 8 Edge Sense Mode"
            #endif//#end of #if
      #endif  //end of #if
 #endif  //end of #ifdef
/******************************************************************/
#ifdef    EXTI_LINE9_ENABLE
      #if EXTI_LINE9_ENABLE !=0
          SET_BIT(EXTI->IMR , LINE9); /*Enable EXTI Line9 */

                 /*ENABLE EDGE*/
           #if  EXTI_LINE9_EDGE ==   1  //RISING EDGE
            SET_BIT(EXTI->RTSR , LINE9);
            #elif EXTI_LINE9_EDGE == 2  //FALLING EDGE
            SET_BIT(EXTI->FTSR , LINE9);
            #elif EXTI_LINE9_EDGE == 3  //ON_CAHNGE RISING+FALLING EDGE
            SET_BIT(EXTI->RTSR , LINE9);
            SET_BIT(EXTI->FTSR , LINE9);
            #else
               #error "Wrong External Interrupt 9 Edge Sense Mode"
            #endif//#end of #if
      #endif  //end of #if
 #endif  //end of #ifdef
/******************************************************************/
#ifdef    EXTI_LINE10_ENABLE
      #if EXTI_LINE10_ENABLE !=0
          SET_BIT(EXTI->IMR , LINE10); /*Enable EXTI Line10 */

                 /*ENABLE EDGE*/
           #if  EXTI_LINE10_EDGE ==   1  //RISING EDGE
            SET_BIT(EXTI->RTSR , LINE10);
            #elif EXTI_LINE10_EDGE == 2  //FALLING EDGE
            SET_BIT(EXTI->FTSR , LINE10);
            #elif EXTI_LINE10_EDGE == 3  //ON_CAHNGE RISING+FALLING EDGE
            SET_BIT(EXTI->RTSR , LINE10);
            SET_BIT(EXTI->FTSR , LINE10);
            #else
               #error "Wrong External Interrupt 10 Edge Sense Mode"
            #endif//#end of #if
      #endif  //end of #if
 #endif  //end of #ifdef
/******************************************************************/
#ifdef    EXTI_LINE11_ENABLE
      #if EXTI_LINE11_ENABLE !=0
          SET_BIT(EXTI->IMR , LINE11); /*Enable EXTI Line11 */

                 /*ENABLE EDGE*/
           #if  EXTI_LINE11_EDGE ==   1  //RISING EDGE
            SET_BIT(EXTI->RTSR , LINE11);
            #elif EXTI_LINE11_EDGE == 2  //FALLING EDGE
            SET_BIT(EXTI->FTSR , LINE11);
            #elif EXTI_LINE11_EDGE == 3  //ON_CAHNGE RISING+FALLING EDGE
            SET_BIT(EXTI->RTSR , LINE11);
            SET_BIT(EXTI->FTSR , LINE11);
            #else
               #error "Wrong External Interrupt 12 Edge Sense Mode"
            #endif//#end of #if
      #endif  //end of #if
 #endif  //end of #ifdef
/******************************************************************/
#ifdef    EXTI_LINE12_ENABLE
      #if EXTI_LINE12_ENABLE !=0
          SET_BIT(EXTI->IMR , LINE12); /*Enable EXTI Line12 */

                 /*ENABLE EDGE*/
           #if  EXTI_LINE12_EDGE ==   1  //RISING EDGE
            SET_BIT(EXTI->RTSR , LINE12);
            #elif EXTI_LINE12_EDGE == 2  //FALLING EDGE
            SET_BIT(EXTI->FTSR , LINE12);
            #elif EXTI_LINE12_EDGE == 3  //ON_CAHNGE RISING+FALLING EDGE
            SET_BIT(EXTI->RTSR , LINE12);
            SET_BIT(EXTI->FTSR , LINE12);
            #else
               #error "Wrong External Interrupt 12 Edge Sense Mode"
            #endif//#end of #if
      #endif  //end of #if
 #endif  //end of #ifdef
/******************************************************************/
#ifdef    EXTI_LINE13_ENABLE
      #if EXTI_LINE13_ENABLE !=0
          SET_BIT(EXTI->IMR , LINE13); /*Enable EXTI Line13 */

                 /*ENABLE EDGE*/
           #if  EXTI_LINE13_EDGE ==   1  //RISING EDGE
            SET_BIT(EXTI->RTSR , LINE13);
            #elif EXTI_LINE13_EDGE == 2  //FALLING EDGE
            SET_BIT(EXTI->FTSR , LINE12);
            #elif EXTI_LINE13_EDGE == 3  //ON_CAHNGE RISING+FALLING EDGE
            SET_BIT(EXTI->RTSR , LINE13);
            SET_BIT(EXTI->FTSR , LINE13);
            #else
               #error "Wrong External Interrupt 13 Edge Sense Mode"
            #endif//#end of #if
      #endif  //end of #if
 #endif  //end of #ifdef
/******************************************************************/
#ifdef    EXTI_LINE14_ENABLE
      #if EXTI_LINE14_ENABLE !=0
          SET_BIT(EXTI->IMR , LINE14); /*Enable EXTI Line14 */

                 /*ENABLE EDGE*/
           #if  EXTI_LINE14_EDGE ==   1  //RISING EDGE
            SET_BIT(EXTI->RTSR , LINE14);
            #elif EXTI_LINE14_EDGE == 2  //FALLING EDGE
            SET_BIT(EXTI->FTSR , LINE14);
            #elif EXTI_LINE14_EDGE == 3  //ON_CAHNGE RISING+FALLING EDGE
            SET_BIT(EXTI->RTSR , LINE14);
            SET_BIT(EXTI->FTSR , LINE14);
            #else
               #error "Wrong External Interrupt 14 Edge Sense Mode"
            #endif//#end of #if
      #endif  //end of #if
 #endif  //end of #ifdef
/******************************************************************/
#ifdef    EXTI_LINE15_ENABLE
      #if EXTI_LINE15_ENABLE !=0
          SET_BIT(EXTI->IMR , LINE15); /*Enable EXTI Line15 */

                 /*ENABLE EDGE*/
           #if  EXTI_LINE15_EDGE ==   1  //RISING EDGE
            SET_BIT(EXTI->RTSR , LINE15);
            #elif EXTI_LINE15_EDGE == 2  //FALLING EDGE
            SET_BIT(EXTI->FTSR , LINE15);
            #elif EXTI_LINE15_EDGE == 3  //ON_CAHNGE RISING+FALLING EDGE
            SET_BIT(EXTI->RTSR , LINE15);
            SET_BIT(EXTI->FTSR , LINE15);
            #else
               #error "Wrong External Interrupt 15 Edge Sense Mode"
            #endif//#end of #if
      #endif  //end of #if
 #endif  //end of #ifdef
/******************************************************************/
}


void MEXTI_voidEnableExtInt(EXTI_line_t copy_enu8EXTLine)
{
	 SET_BIT(EXTI->IMR , copy_enu8EXTLine);
}                                                                        
void MEXTI_voidDisableExtInt(EXTI_line_t copy_enu8EXTLine)
{
	 CLR_BIT(EXTI->IMR , copy_enu8EXTLine);
} 
/*This Function To Set Interrupt by Software - Usfull in Debugging*/                                                                       
void MEXTI_voidSwTrigger(EXTI_line_t copy_enu8EXTLine)
{
	SET_BIT(EXTI->SWIER , copy_enu8EXTLine); /*Return To 0 Automatically By HW- After Pending Flag cleared*/ 
	SET_BIT(EXTI->IMR   , copy_enu8EXTLine);
	SET_BIT(EXTI->PR    , copy_enu8EXTLine);
}                                                                       

/*This Function to SET Edge Mode Like init() but in Run Time*/ 
void MEXTI_voidSetEdge(EXTI_line_t copy_enu8EXTLine, EXTI_Edge_Mode Edge)
{
	switch(Edge)
	{
		case RISING:  
                       SET_BIT(EXTI->RTSR , copy_enu8EXTLine);
        		break; 
		case FALLING:  
		               SET_BIT(EXTI->FTSR , copy_enu8EXTLine);
				break; 
		case ON_CHANGE:  
                       SET_BIT(EXTI->RTSR , copy_enu8EXTLine);
	                   SET_BIT(EXTI->FTSR , copy_enu8EXTLine);
      		    break; 
	 }	
}

void EXTI_SetCallBack(void (*Fptr)(void),EXTI_line_t LINE){

	   switch(LINE)
	      {
	      case 0 : EXTI_CallBack [0 ] =Fptr; break;
	      case 1 : EXTI_CallBack [1 ] =Fptr; break;
	      case 2 : EXTI_CallBack [2 ] =Fptr; break;
	      case 3 : EXTI_CallBack [3 ] =Fptr; break;
	      case 4 : EXTI_CallBack [4 ] =Fptr; break;
	      case 5 : EXTI_CallBack [5 ] =Fptr; break;
	      case 6 : EXTI_CallBack [6 ] =Fptr; break;
	      case 7 : EXTI_CallBack [7 ] =Fptr; break;
	      case 8 : EXTI_CallBack [8 ] =Fptr; break;
	      case 9 : EXTI_CallBack [9 ] =Fptr; break;
	      case 10: EXTI_CallBack [10] =Fptr; break;
	      case 11: EXTI_CallBack [11] =Fptr; break;
	      case 12: EXTI_CallBack [12] =Fptr; break;
	      case 13: EXTI_CallBack [13] =Fptr; break;
	      case 14: EXTI_CallBack [14] =Fptr; break;
	      case 15: EXTI_CallBack [15] =Fptr; break;
	      case 16: EXTI_CallBack [16] =Fptr; break;  /*Connected to PVD output*/
	      case 17: EXTI_CallBack [17] =Fptr; break;  /*Connected to RTC output*/
	      case 18: EXTI_CallBack [18] =Fptr; break;  /*Connected to USB Wakeup Event*/
	      case 19: EXTI_CallBack [19] =Fptr; break;  /*Connected to Ethernet Wakeup Event- Connectivity Line Devices*/
	      }
}

void EXTI0_IRQHandler(void)
{
	EXTI_CallBack[0]();
	SET_BIT(EXTI->PR,0); //reset flag
}
void EXTI1_IRQHandler(void)
{
	EXTI_CallBack[1]();
	SET_BIT(EXTI->PR,1); //reset flag
}
void EXTI2_IRQHandler(void)
{
	EXTI_CallBack[2]();
	SET_BIT(EXTI->PR,2); //reset flag
}
void EXTI3_IRQHandler(void)
{
	EXTI_CallBack[3]();
	SET_BIT(EXTI->PR,3); //reset flag
}
void EXTI4_IRQHandler(void)
{
	EXTI_CallBack[4]();
	SET_BIT(EXTI->PR,4); //reset flag
}
void EXTI5_IRQHandler(void)
{
	EXTI_CallBack[5]();
	SET_BIT(EXTI->PR,5); //reset flag
}
void EXTI6_IRQHandler(void)
{
	EXTI_CallBack[6]();
	SET_BIT(EXTI->PR,6); //reset flag
}
void EXTI7_IRQHandler(void)
{
	EXTI_CallBack[7]();
	SET_BIT(EXTI->PR,7); //reset flag
}
void EXTI8_IRQHandler(void)
{
	EXTI_CallBack[8]();
	SET_BIT(EXTI->PR,8); //reset flag
}
void EXTI9_IRQHandler(void)
{
	EXTI_CallBack[9]();
	SET_BIT(EXTI->PR,9); //reset flag
}
void EXTI10_IRQHandler(void)
{
	EXTI_CallBack[10]();
	SET_BIT(EXTI->PR,10); //reset flag
}
void EXTI11_IRQHandler(void)
{
	EXTI_CallBack[11]();
	SET_BIT(EXTI->PR,11); //reset flag
}
void EXTI12_IRQHandler(void)
{
	EXTI_CallBack[12]();
	SET_BIT(EXTI->PR,12); //reset flag
}
void EXTI13_IRQHandler(void)
{
	EXTI_CallBack[13]();
	SET_BIT(EXTI->PR,13); //reset flag
}
void EXTI14_IRQHandler(void)
{
	EXTI_CallBack[14]();
	SET_BIT(EXTI->PR,14); //reset flag
}
void EXTI15_IRQHandler(void)
{
	EXTI_CallBack[15]();
	SET_BIT(EXTI->PR,15); //reset flag
}
/*Connected to PVD output*/
void EXTI16_IRQHandler(void)
{
	EXTI_CallBack[16]();
	SET_BIT(EXTI->PR,16); //reset flag
}
/*Connected to RTC output*/
void EXTI17_IRQHandler(void)
{
	EXTI_CallBack[17]();
	SET_BIT(EXTI->PR,17); //reset flag
}
/*Connected to USB Wakeup Event*/
void EXTI18_IRQHandler(void)
{
	EXTI_CallBack[18]();
	SET_BIT(EXTI->PR,18); //reset flag
}
/*Connected to Ethernet Wakeup Event- Connectivity Line Devices*/
void EXTI19_IRQHandler(void)
{
	EXTI_CallBack[19]();
	SET_BIT(EXTI->PR,19); //reset flag
}




