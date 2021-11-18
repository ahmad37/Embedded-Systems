#include "TM4C123.h"                    // Device header

#define ECHO     (1U<<6) //PB6
#define TRIGGER  (1U<<4) //PA4(OUTPUT)
#define BLUE_LED (1U<<2) // PF2 onboard blue led

uint32_t HighEdge,LowEdge; 
uint32_t Distance; 
const double _16MHZ_CLOCK = 62.5e-9; 
const uint32_t Multiplier = 5882; 


void Timer0_Init(void);
void DelayUS(uint32_t TimeUS);
void PortsInit(void); 
uint32_t MeasureDistanceUltraSonic(void);

int main(void){

/*CLOCK _ PINS CONFIGURATIONS */
PortsInit();
Timer0_Init();
	
	
uint32_t Distance_Value_in_cm; 	
while(1){

	Distance_Value_in_cm = MeasureDistanceUltraSonic(); 
	
	if(MeasureDistanceUltraSonic() <15)
	{
	    GPIOF->DATA |=BLUE_LED;
	}
	else{
			GPIOF->DATA &=~BLUE_LED;
	}
}


}

void Timer0_Init(void){
  SYSCTL->RCGCTIMER |=(1U<<0);
  SYSCTL->RCGCGPIO  |=(1U<<1); /*eNABLE portB clock*/
  GPIOB->DIR &=~ECHO; 
  GPIOB->DEN |=ECHO; 
  GPIOB->AFSEL |=ECHO;
  GPIOB->PCTL &=~0x0F000000; 
  GPIOB->PCTL |= 0x07000000; 	
			
  TIMER0->CTL &=~1; 
	TIMER0->CFG = 0x01; 
	TIMER0->TAMR=0x17; 
	TIMER0->CTL |=0x0C;/*Set TAEVENT bit to both edges*/
	TIMER0->CTL |=1;
	
}
void DelayUS(uint32_t TimeUS){

int i; 
	SYSCTL -> RCGCTIMER |=(1U<<1); 
	TIMER1 -> CTL       &=~1     ; 
	TIMER1 -> CFG        = 0x04  ; /*16 BIT MODE*/ 
	TIMER1 -> TAMR       = 0x02  ; /*PERIODIC*/ 
	TIMER1 -> TAILR      = 16-1  ; /*counts from 0 to 15 -> 16 TICK= 1us*/ 
	TIMER1 -> ICR        = 0x1   ;  
	TIMER1 -> CTL       |= 1     ;  
	
	for (i=0; i<TimeUS;i++)
   {
	   while((TIMER1->RIS &0x1)==0); 
		   TIMER1->ICR = 0x1; 
	 }
}

 void PortsInit(void){
 SYSCTL->RCGCGPIO|=(1U<<0) ;//ENABLE PORTA CLOCK
 SYSCTL->RCGCGPIO |= (1U<<5);//ENABLE PORTF CLOCK
 GPIOA->DIR |=TRIGGER;	 
 GPIOF->DIR |=BLUE_LED;
 GPIOA->DEN |=TRIGGER;
 GPIOF->DEN |=BLUE_LED;	
 }

uint32_t MeasureDistanceUltraSonic(void){

 GPIOA->DATA &=~TRIGGER;
 DelayUS(12); 
 GPIOA->DATA |=TRIGGER;
 DelayUS(12);
 GPIOA->DATA &=~TRIGGER;	
	

	/*Capture First Edge _ i.e Rising*/
	TIMER0->ICR=4; /*CLEAR TIMER FLAG FIRST BY WRITING 1 IN  CAECINT BIT */
	while((TIMER0->RIS &4)==0);/*WAIT FLAG TO BE SET, CAPTURED*/
	HighEdge=TIMER0->TAR;/*HighEdge = the time at wich last edge event took place*/ 

	/*Capture Second Edge _ */
	TIMER0->ICR=4; /*CLEAR TIMER FLAG FIRST BY WRITING 1 IN  CAECINT BIT */
	while((TIMER0->RIS &4)==0);/*WAIT FLAG TO BE SET, CAPTURED*/
	LowEdge=TIMER0->TAR;/*LowEdge = the time at wich last edge event took place*/ 

	Distance =LowEdge-HighEdge; 
	Distance=_16MHZ_CLOCK*(double)Multiplier*(double)Distance; 
	 return Distance;
} 
 
 
 
 
 
