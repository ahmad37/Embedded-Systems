/*
 * main.c
 *
 *  Created on: Aug 31, 2020
 *      Author: Ahmad
 */

/*lib includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* RCC INCLUDES*/
#include "RCC_interface.h"

/*GPIO INCLUDES */
#include "GPIO_interface.h"

#include "NVIC_interface.h"

/*Systick timer */
#include "STK_interface.h"





void main(void){

	    /* Enable HSE Crystal As Clock Source */
		 RCC_voidInitSysClock();
		 /*Enable GPIOA Clock */
		 RCC_voidEnableClock(RCC_APB2, 2);
		 /*Enable GPIOB Clock */
		 RCC_voidEnableClock(RCC_APB2, 3);
		 /*Enable GPIOC Clock */
		 RCC_voidEnableClock(RCC_APB2, 4);

		 /*init systick*/
		 MSTK_voidInit();


  while (1)
  {


  }

}
