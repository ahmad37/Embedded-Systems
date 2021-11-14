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
	
	#elif EXTI_LINE1 _ENABLE !=0
							 
    #elif EXTI_LINE2 _ENABLE !=0
	
    #elif EXTI_LINE3 _ENABLE !=0
    
	#elif EXTI_LINE4 _ENABLE !=0
    
	#elif EXTI_LINE5 _ENABLE !=0
	
    #elif EXTI_LINE6 _ENABLE !=0
	
    #elif EXTI_LINE7 _ENABLE !=0
    
	#elif EXTI_LINE8 _ENABLE !=0
    
	#elif EXTI_LINE9 _ENABLE !=0
    
	#elif EXTI_LINE10_ENABLE !=0
    #elif EXTI_LINE11_ENABLE !=0
    #elif EXTI_LINE12_ENABLE !=0
    #elif EXTI_LINE13_ENABLE !=0
    #elif EXTI_LINE14_ENABLE !=0
    #elif EXTI_LINE15_ENABLE !=0
    #elif EXTI_LINE16_ENABLE !=0
	#elif EXTI_LINE17_ENABLE !=0
	#elif EXTI_LINE18_ENABLE !=0
	#elif EXTI_LINE19_ENABLE !=0
#endif             

	
	
	/*Enable EXTI - AFIO driver */ 
	
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
	      case 0:  EXTI_CallBack [0 ] =Fptr; break;
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




