/*********************************************************************/
/* Name    : Ahmad Abdulrahem							             */
/* VER     : V01 										             */
/* PurPose :											           	 */  
/*********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"
 
void MUSART1_voidinit (void)
{
  /* Set Baud Rate- BRR reg-need some calculations*/
   //Baud Rate at 9600 -> BRR=0x341
    MUSART1 -> BRR = 0x341;  
   //Baud Rate at 115200  
   
  /* 1- Enable RX   -bit 2
     2- Enable TX   -bit 3 
	 3- Enable UART -bit 13 */
   
    SET_BIT( MUSART1 -> CR1 ,2 );  
    SET_BIT( MUSART1 -> CR1 ,3 );
	SET_BIT( MUSART1 -> CR1 ,13);
	
  /* RESET(CLEAR) ALL FLAGS OF STATUS REGISTER  */	
  MUSART1->SR =0; 
  
}
void MUSART1_voidTransmit(u8 arr[])
{
  u8 i=0;
   while (arr[i] != '\0')
     {
	   MUSART1-DR = arr[i];/*Send data*/
	   /*wait to the end of transmission*/
       while(( MUSART1->SR & (1<< 6)/*0x40*/)==0 ); /*check TC flag - Transmission Complete flag*/  	   
	   i++; 
	}
}
u8 MUSART1_u8Receive(void)
{
  u8 Data=0; 
   /*Wait Flag to be Set - RC receive Complete*/
    while(( MUSART1->SR & (1<< 5)/*0x40*/)==0 );
   /* save data */
   Data = (u8)USART1->DR; 
   /*return data */
   return Data;
}