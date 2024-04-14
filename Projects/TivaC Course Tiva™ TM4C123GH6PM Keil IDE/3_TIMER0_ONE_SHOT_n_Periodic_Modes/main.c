#include "TM4C123.h"                    // Device header

#define RED (1U<<1); 

#define BLUE (1U<<4); 


 void TIMER0_OneShotDelayMS (uint32_t mdelay ); 
 void TIMER0_PeriodicDelayMS(uint32_t mdelay );
 

void main(void){
/*Enable GPIOF Clock from SYSCTL struct */
 SYSCTL->RCGCGPIO |= 0x02;  
 //GPIOF->DIR|=RED; /*SET pin 1 as output*/
 //GPIOF->DEN|=RED; 	/*Digitally Enable Pin 1 of PORTF */
	
	
 GPIOF->DIR|=BLUE; /*SET pin 1 as output*/
 GPIOF->DEN |=BLUE; 	/*Digitally Enable Pin 1 of PORTF */
	
	while(1){                             

					 GPIOF->DATA ^=BLUE;        
		      // TIMER0_OneShotDelayMS(4000);   /*4SEC MAX DELAY*/
		       TIMER0_PeriodicDelayMS(200); /*10 SECONDS- MAX DELAY =49 DAYS!! */
		       
					}


//return 0;

}

/* 
job: Start Timer 0 - in one shot mode 
        One Shot mode that mean the Timer will do a job for one time only each time i will call it 
Description: 
      Generate Dalays in MS 
Cpu Clock : 16MHZ 
*/
void TIMER0_OneShotDelayMS(uint32_t mdelay )
{
 /*Enable Timer0 Clock*/	
  SYSCTL->RCGCTIMER |= 0x01; 
 /*Ensure the timer is disabled
  (the TnEN bit in the GPTMCTL register 
   is cleared)*/
	TIMER0->CTL = 0; /*Disable all thing :D */

	TIMER0->CFG =0x04;   /*for 16bit counter, 16/32-bit timer- max delay=4sec*/
  /* */	
	TIMER0->TAMR = 0x01; // for one shot mode ,0x02 for periodic mode

	TIMER0-> TAILR = 16000*mdelay-1;  //convert ms value to us by multply by 16000 due to clock is 16MHZ
	TIMER0->ICR = 0x1;
	
	TIMER0->CTL |= 0x01; /*Enable the timer */

	/*wait for timer flag to be set*/
	while((TIMER0->RIS & 0x01)==0); 
}
/*
*/
void TIMER0_PeriodicDelayMS(uint32_t mdelay )
{     int MsCounter=0;
 /*Enable Timer0 Clock*/	
  SYSCTL->RCGCTIMER |= 0x01; 
 /*Ensure the timer is disabled
  (the TnEN bit in the GPTMCTL register 
   is cleared)*/
	TIMER0->CTL |= 0x00; /*Disable all thing :D */
	
	TIMER0->CFG |=0x04;   /*for 16bit counter, 16/32-bit timer- max delay=4sec*/
  /* */	
	TIMER0->TAMR |= 0x02; // for PERIODIC mode ,0x02 for periodic mode

	TIMER0-> TAILR = 16000-1;  //gives me a 1ms second delay_to generate a fixed time interval and repeat it by x 
	TIMER0->ICR = 0x1;        //clear timer flag
	
	TIMER0->CTL |= 0x01; /*Enable the timer */

	/*Periodic Mode allows you to clear the timer and start again but in one shot it's one time only */
	for( MsCounter=0; MsCounter<mdelay; MsCounter++)
	 {
		/*wait for timer flag to be set*/
			while((TIMER0->RIS & 0x1)==0); /*Flag set after each 1ms*/
      
		 TIMER0->ICR =0x01; /*Clear the flag to start again*/				
   }
	
 }	 


