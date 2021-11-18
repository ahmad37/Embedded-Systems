#include "TM4C123.h"                    // Device header
/*
you will know how to : 
1- Enable GPIO Peripheral
2- Enable Alternate Fuction (Remap) Pins 
2- Use Timers and Set Modes 
*/

void Timer3A_RisingEdgeCounterInit(void); 
int Timer3A_RisingEdgeCounterCapture(void);
uint32_t Rising_Edge_Counter=0; 


int main(void)
{
 /*Enable Clocks*/
  SYSCTL->RCGCTIMER |=0x08; /*Enable Timer 3 Clock*/
	SYSCTL->RCGCGPIO  |=0x02; /*Enable Port B clock*/
  
  GPIOB->DIR &=~0x04; /*set PB2 push button direction input*/	
  GPIOB->DEN |=0x04; /*Digitaly Enable PB2 Push Button Pin*/
  GPIOB->AFSEL |=0x04; /*ENABLE AF on PB2*/ 
  GPIOB->PCTL &=~0x00000F00;  /*Configure PB2 as T3CCP0 Pin*/
  GPIOB->PCTL &=~0x00000700;	
  
	Timer3A_RisingEdgeCounterInit();
	
	while (1)
	{
	 Rising_Edge_Counter=  Timer3A_RisingEdgeCounterCapture();
	}

}

void Timer3A_RisingEdgeCounterInit(void)
{
  TIMER3->CTL=0x00; /*ENSURE TIMER3A DISABLED BEFORE ANY CHANGE */	
  TIMER3->CFG=0x04; /* Configure as 16-bit timer mode*/
	TIMER3->TAMR=0x13; /* up-counting,edge counting,capture mode*/
	TIMER3->TAMATCHR=0xFFFF; /* set max counting value (overflow value), this value are compared with TAR reg to determine  */
	TIMER3->TAPMR=0xFF; /*PRESCALER: USED WITH TAMATCHR REG TO EXTEND THE SIZE TO 0xFFFFFF  */
	TIMER3->CTL |=1; /*ENABLE TH TIMER3A */
}

int Timer3A_RisingEdgeCounterCapture(void)
{
  return TIMER3->TAR; /*COMPARED WITH TAMATCHR REG TO DETERMINE MATCH EVENT*/
}
