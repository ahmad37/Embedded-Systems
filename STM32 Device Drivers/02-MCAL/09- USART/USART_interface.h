/*********************************************************************/
/* Name    : Ahmad Abdulrahem							             */
/* VER     : V01 										             */
/* PurPose :											           	 */  
/*********************************************************************/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

void MUSART1_voidinit (void);
void MUSART1_voidTransmit(u8 arr[]);
u8 MUSART1_u8Receive(void);

#endif