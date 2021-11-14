/*********************************************************************/
/* Name    : Ahmad Abdulrahem							             */
/* VER     : V01 										             */
/* PurPose :											           	 */  
/*********************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"AFIO_interface.h"
#include"AFIO_private.h"
#include"AFIO_config.h"

#include "GPIO_interface.h"

void MAFIO_voidEnableEXTI(EXTI_PORT copy_enumPORT, u8 copy_u8PIN )	
{	
    switch(copy_u8PIN)
	    {    /*pin number refer to line number too*/ 
			/*From PIN0 to PIN3 - Enabled by EXTICR1*/
			case PIN0 : AFIO->EXTICR1 |=(copy_enumPORT<<copy_u8PIN*4);  break; 
			case PIN1 : AFIO->EXTICR1 |=(copy_enumPORT<<copy_u8PIN*4);  break; 
			case PIN2 : AFIO->EXTICR1 |=(copy_enumPORT<<copy_u8PIN*4);  break; 
			case PIN3 : AFIO->EXTICR1 |=(copy_enumPORT<<copy_u8PIN*4);  break; 
			
			case PIN4 : AFIO->EXTICR2 |=(copy_enumPORT<<(copy_u8PIN-4)*4);  break;
			case PIN5 : AFIO->EXTICR2 |=(copy_enumPORT<<(copy_u8PIN-4)*4);  break;
			case PIN6 : AFIO->EXTICR2 |=(copy_enumPORT<<(copy_u8PIN-4)*4);  break;
			case PIN7 : AFIO->EXTICR2 |=(copy_enumPORT<<(copy_u8PIN-4)*4);  break;
			
			case PIN8 : AFIO->EXTICR3 |=(copy_enumPORT<<(copy_u8PIN-8)*4);  break;
			case PIN9 : AFIO->EXTICR3 |=(copy_enumPORT<<(copy_u8PIN-8)*4);  break;
			case PIN10: AFIO->EXTICR3 |=(copy_enumPORT<<(copy_u8PIN-8)*4);  break;
			case PIN11: AFIO->EXTICR3 |=(copy_enumPORT<<(copy_u8PIN-8)*4);  break;
																	   
			case PIN12: AFIO->EXTICR4 |=(copy_enumPORT<<(copy_u8PIN-12)*4);  break;
			case PIN13: AFIO->EXTICR4 |=(copy_enumPORT<<(copy_u8PIN-12)*4);  break;
			case PIN14: AFIO->EXTICR4 |=(copy_enumPORT<<(copy_u8PIN-12)*4);  break;
			case PIN15: AFIO->EXTICR4 |=(copy_enumPORT<<(copy_u8PIN-12)*4);  break;
		}
}

void MAFIO_voidDisableEXTI(EXTI_PORT copy_enumPORT, u8 copy_u8PIN)	
{	
    switch(copy_u8PIN)
	    {    /*pin number refer to line number too*/ 
			/*From PIN0 to PIN3 - Enabled by EXTICR1*/
			case PIN0 : AFIO->EXTICR1 &= ~ (copy_enumPORT <<  copy_u8PIN*4);      break;
			case PIN1 : AFIO->EXTICR1 &= ~ (copy_enumPORT <<  copy_u8PIN*4);      break;
			case PIN2 : AFIO->EXTICR1 &= ~ (copy_enumPORT <<  copy_u8PIN*4);      break;
			case PIN3 : AFIO->EXTICR1 &= ~ (copy_enumPORT <<  copy_u8PIN*4);      break;

			case PIN4 : AFIO->EXTICR2 &= ~ (copy_enumPORT << (copy_u8PIN-4)*4);   break;
			case PIN5 : AFIO->EXTICR2 &= ~ (copy_enumPORT << (copy_u8PIN-4)*4);   break;
			case PIN6 : AFIO->EXTICR2 &= ~ (copy_enumPORT << (copy_u8PIN-4)*4);   break;
			case PIN7 : AFIO->EXTICR2 &= ~ (copy_enumPORT << (copy_u8PIN-4)*4);   break;

			case PIN8 : AFIO->EXTICR3 &= ~ (copy_enumPORT << (copy_u8PIN-8)*4);   break;
			case PIN9 : AFIO->EXTICR3 &= ~ (copy_enumPORT << (copy_u8PIN-8)*4);   break;
			case PIN10: AFIO->EXTICR3 &= ~ (copy_enumPORT << (copy_u8PIN-8)*4);   break;
			case PIN11: AFIO->EXTICR3 &= ~ (copy_enumPORT << (copy_u8PIN-8)*4);   break;

			case PIN12: AFIO->EXTICR4 &= ~ (copy_enumPORT << (copy_u8PIN-12)*4);  break;
			case PIN13: AFIO->EXTICR4 &= ~ (copy_enumPORT << (copy_u8PIN-12)*4);  break;
			case PIN14: AFIO->EXTICR4 &= ~ (copy_enumPORT << (copy_u8PIN-12)*4);  break;
			case PIN15: AFIO->EXTICR4 &= ~ (copy_enumPORT << (copy_u8PIN-12)*4);  break;
		}
}




