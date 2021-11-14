/*********************************************************************/
/* Name    : Ahmad Abdulrahem							             */
/* VER     : V01 										             */
/* PurPose :											           	 */  
/*********************************************************************/
#ifndef  USART_PRIVATE_H
#define  USART_PRIVATE_H

typedef struct {
 volatile u32 SR  ;   /* Status Register		      */
 volatile u32 DR  ;   /* Data Register				  */
 volatile u32 BRR ;   /* Baud Rate Register			  */
 volatile u32 CR1 ;   /* Control Register 1			  */
 volatile u32 CR2 ;   /* Control Register 2			  */
 volatile u32 CR3 ;   /* Control Register 3			  */
 volatile u32 GTPR;   /* Guard and Prescaler Register */
}UART_t; 
#define UART  ((volatile UART_t *)(0x)) 

#endif