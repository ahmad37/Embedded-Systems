/*
 * main.c
 *
 *  Created on: Sep 9, 2020
 *      Author: Ahmad
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "OS_interface.h"

void Task1(void){
	static u8 PinValue1=0;
	GPIO_voidSetPinValue(GPIOA,PIN0,TOG_BIT(PinValue1,PIN0));

}
void Task2(void){
	static u8 PinValue2=0;
	GPIO_voidSetPinValue(GPIOA,PIN1,TOG_BIT(PinValue2,PIN0));
}
void Task3(void){
	static u8 PinValue3=0;
	GPIO_voidSetPinValue(GPIOA,PIN2,TOG_BIT(PinValue3,PIN0));
}


void main(void)
{
	/*RCC init 	            */
	RCC_voidInitSysClock();
	/*Enable GPIOA Clock      */
	RCC_voidEnableClock(RCC_APB2,2);
	/*Pins Initializations    */
	GPIO_voidSetPinDir(GPIOA,PIN0,OUTPUT_SPEED_10MHZ_PP);
	GPIO_voidSetPinDir(GPIOA,PIN1,OUTPUT_SPEED_10MHZ_PP);
	GPIO_voidSetPinDir(GPIOA,PIN2,OUTPUT_SPEED_10MHZ_PP);

	/*Create Tasks --(priority,periodicty,first delay,add of task)*/
	SOS_voidCreatTask(0, 5000, 0 , &Task2);  /*come every 1 sec*/
	SOS_voidCreatTask(1, 1000, 1 , &Task1);  /*come every 2 sec*/
	SOS_voidCreatTask(2, 3000, 2 , &Task3);  /*come every 3 sec*/
	/*Start Scheduler         */
	SOS_voidStartScheduler();

	while(1){
	}

}











