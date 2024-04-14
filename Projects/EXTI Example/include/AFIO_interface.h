/*********************************************************************/
/* Name    : Ahmad Abdulrahem							             */
/* VER     : V01 										             */
/* PurPose :											           	 */  
/*********************************************************************/
#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

#include "AFIO_private.h" 

void MAFIO_voidEnableEXTI(EXTI_PORT copy_enumPORT , u8 copy_u8PIN);
void MAFIO_voidDisableEXTI(EXTI_PORT copy_enumPORT, u8 copy_u8PIN);



#endif