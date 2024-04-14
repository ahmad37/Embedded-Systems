#include "TM4C123.h"                    // Device header

#define  GREEN  (1U<<1)
#define  RED    (1U<<2)
#define  BLUE   (1U<<4)

void Timer1A_1HZ_Init (void);
void Timer2A_10HZ_Init(void);

int main()
{
	SYSCTL->RCGCGPIO |=0x20; 
	GPIOF->DIR =0x0E; 
	GPIOF->DEN =0x0E; 
	
	Timer1A_1HZ_Init ();
	Timer2A_10HZ_Init();
	__enable_irq(); /*Enable Global Interrupt*/
  while(1){
	
	}
}

void Timer1A_1HZ_Init(void)
{
		SYSCTL->RCGCTIMER |=0x02; /*Enable Clock of Timer 1*/
		TIMER1->CTL &=~(1<<0); /*turn Timer1 OFF*/
		TIMER1->CFG |=  0x04 ; /*Set 16bit Mode*/
		TIMER1->TAMR|=  0x02 ; /*Periodic, Count down*/
	  TIMER0->TAPR= 250;   /*16000000hz/250=64000hZ*/
	  TIMER1->TAILR=64000; 
	  TIMER1->ICR = 0x1; 
	  TIMER1->IMR=0x01;
  	TIMER1->CTL |= (1<<0); /*turn Timer1 On*/
		NVIC->ISER[0] |=0x00200000;/*Enable IRQ 21*/
	
}	


void Timer2A_10HZ_Init(void)
{ 
	SYSCTL->RCGCTIMER |=0x04;  /*enable Timer Clock*/
	TIMER1->CTL =0;            /*Turn Timer OFF*/
	TIMER1->CFG |=  0x04 ;     /*16bit mode*/
  TIMER1->TAMR|=  0x02 ;     /*Periodic , counting down */
	TIMER0->TAPR= 250;         /*Use a prescaller to widen the timer resolution*/
  TIMER1->TAILR=64000;	
	TIMER1->ICR = 0x1;          /*Clear interrupt flag*/
	TIMER1->IMR=0x01;           /*Interrupt Mask Register-Enable interrupt from peripheral */
	TIMER1->CTL = 0x01;         /*turn Timer1 On*/
	NVIC  ->ISER[0] |=0x00800000; /*Enable IRQ 23*/
}
/*Runs Once a second*/
void TIMER1A_Handler(void)
{  volatile int clear; 
	if(TIMER1->MIS&0x1)/*Masked Interrupt Status_ Timer1A Timeout Flag*/
	{
		GPIOF->DATA^=RED; /*TOGGLE RED LED*/
		clear=TIMER1->ICR; 
	}
	else 
	{
		 TIMER1->ICR = TIMER1->MIS; /*CLEAR ALL FLAGS*/
	   clear=TIMER1->ICR; /*Clear Interrupt Flag*/
	}
}

void TIMER2A_Handler(void)
{
	volatile int clear; 
	if(TIMER2->MIS&0x1)/*Masked Interrupt Status_ Timer1A Timeout Flag*/
	{
		GPIOF->DATA^=GREEN; /*TOGGLE GREEN LED*/
		TIMER2->ICR=0x1; /*Clear Timer2A timeout flag*/
		clear=TIMER2->ICR; /*Clear Interrupt Flag*/
	}
	else 
	{
		 TIMER2->ICR = TIMER2->MIS; /*CLEAR ALL FLAGS*/
	   clear=TIMER2->ICR;
	}
}
