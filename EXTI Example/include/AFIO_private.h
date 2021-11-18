/*********************************************************************/
/* Name    : Ahmad Abdulrahem							             */
/* VER     : V01 										             */
/* PurPose :											           	 */  
/*********************************************************************/
#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

/************************EXTERNAL INTERRUPT ***********************************/
/*EXTICR1: Enable EXTI lines 0:3.
31---30---29---28---27---26---25---24---23---22---21---20---19---18---17---16---+
|------------------------------RESERVED ----------------------------------------|
+-------------------------------------------------------------------------------+
15---14---13---12---11---10---9----8----7----6----5----4----3----2----1-----0---+
|    EXTI3      |---|     EXTI2      |--|    EXTI1     |---|       EXTI0        |
+------------------------------------------------------------------------------*/
/* -------------------------------------------------+
| BITs    |   lable   |         DESCRIPTION         |
|---------|---------- |-----------------------------|
| 0000    | PA[x] pin | Enable EXTI LINEx OF PORTA  | 
| 0001    | PB[x] pin | Enable EXTI LINEx OF PORTB  |
| 0010    | PC[x] pin | Enable EXTI LINEx OF PORTC  |
| 0011    | PD[x] pin | Enable EXTI LINEx OF PORTD  |
| 0100    | PE[x] pin | Enable EXTI LINEx OF PORTE  |
| 0101    | PF[x] pin | Enable EXTI LINEx OF PORTF  |
| 0110    | PG[x] pin | Enable EXTI LINEx OF PORTG  |
+---------+----------+------------------------------*/
/*Example1: if you want To Enable PIN2 of PORTA as External Interrupt
               you should Put EXTI2 filed with 0000
			
  Example2: if you want To Enable PIN3 of PORTB as External Interrupt
            you should Put EXTI3 filed with 0001				
			*/

typedef struct
{
	volatile u32 MAPR; 
	volatile u32 EXTICR1;  /*Enable EXTI lines 0  : 3  */
	volatile u32 EXTICR2;  /*Enable EXTI lines 4  : 7  */
	volatile u32 EXTICR3;  /*Enable EXTI lines 8  : 11 */
	volatile u32 EXTICR4;  /*Enable EXTI lines 12 : 15 */
	volatile u32 MAPR2;
}AFIO_t; 

#define AFIO  ((volatile AFIO_t*)(0x40010000))

/*These Values will be Passed TO SetEXTI() Function*/
typedef enum
{
	ENABLE_EXTI_PORTA = 0b0000,
	ENABLE_EXTI_PORTB = 0b0001,
	ENABLE_EXTI_PORTC = 0b0010,
	ENABLE_EXTI_PORTD = 0b0011,
	ENABLE_EXTI_PORTE = 0b0100,
	ENABLE_EXTI_PORTF = 0b0101,
	ENABLE_EXTI_PORTG = 0b0110
}EXTI_PORT; 
/******************************************************************************/ 

#endif
