/*
 * main.c
 *
 *  Created on: Sep 11, 2020
 *      Author: Ahmad
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"
#include "EXTI_private.h"


/**************************************/
void Tog_FALLING_EDGE(void){
	GPIO_u8TogglePin(GPIOA,PIN9);
}
/**************************************/
void Tog_RISING_EDGE(void){
	GPIO_u8TogglePin(GPIOA,PIN10);
}
/**************************************/
void Tog_ON_CHANGE(void){
	GPIO_u8TogglePin(GPIOA,PIN11);
}
/*************************************/

void main(void)
{
	/*RCC init */
	RCC_voidInitSysClock();
	/*GPIO clock enable*/
	RCC_voidEnableClock(RCC_APB2,2);
	RCC_voidEnableClock(RCC_APB2,3);
	RCC_voidEnableClock(RCC_APB2,4);
	/*Enable AFIO clock*/
	RCC_voidEnableClock(RCC_APB2,0);
/**********************************************/
	/*stk INIT */
	MSTK_voidInit();
	/*pin Direction*/
	GPIO_voidSetPinDir  (GPIOA,PIN0,INPUT_PULLUP_PULLDOWN);  //PUSH BUTTON 1
	GPIO_voidSetPinValue(GPIOA,PIN0 ,HIGH);//Pull up - to sense low volatage
	GPIO_voidSetPinDir  (GPIOA,PIN9,OUTPUT_SPEED_10MHZ_PP);  //led1

	/*pin Direction*/
	GPIO_voidSetPinDir  (GPIOA,PIN1,INPUT_PULLUP_PULLDOWN);  //PUSH BUTTON 2
	GPIO_voidSetPinValue(GPIOA,PIN1 ,LOW);//Pull DOWN - to sense HIGH volatage
	GPIO_voidSetPinDir  (GPIOA,PIN10,OUTPUT_SPEED_10MHZ_PP);  //led2

	/*pin Direction*/
	GPIO_voidSetPinDir(GPIOA,PIN2,INPUT_FLOATING);  //PUSH BUTTON 3
     //GPIO_voidSetPinValue(GPIOA,PIN2 ,HIGH);//Pull up - to sense low volatage
	GPIO_voidSetPinDir(GPIOA,PIN11,OUTPUT_SPEED_10MHZ_PP);  //led3

	/*Set Call Back - FUnctions To be Run Inside Interrupt*/
	EXTI_SetCallBack(Tog_FALLING_EDGE,PIN0);
	EXTI_SetCallBack(Tog_RISING_EDGE ,PIN1);
	EXTI_SetCallBack(Tog_ON_CHANGE   ,PIN2);



	/*Remaping AFIO- Not necessary here due to EXTI Enabled on PORTA by default*/
	MAFIO_voidEnableEXTI(ENABLE_EXTI_PORTA,LINE0);/* AFIO Enable EXTI on PORTA ,PIN0*/
	MAFIO_voidEnableEXTI(ENABLE_EXTI_PORTA,LINE1);
	MAFIO_voidEnableEXTI(ENABLE_EXTI_PORTA,LINE2);



	/*NVIC init */
	MEXTI_voidInit();

	/*Interrupt Enable*/
	MNVIC_voidEnableInterrupt(6); /*Enable EXT0 from NVIC*/
	MNVIC_voidEnableInterrupt(7); /*Enable EXT1 from NVIC*/
	MNVIC_voidEnableInterrupt(8); /*Enable EXT2 from NVIC*/
/************************************************/
	while(1){
	        }
}
