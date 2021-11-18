/*
 * LED.c

 *
 *  Created on: Aug 15, 2020
 *      Author: mazen
 */

#include "LED.h"

#include "STD_TYPES.h"
#include "BIT_CALC.h"


#include "DIO_interface.h"



 LED_PIN *LED_arr_ptr = NULL;
 u32 NO_LEDS = 0 ;

void  LED_voidInit(LED_PIN* pin_arr,u32 no_leds)
{
	LED_arr_ptr = pin_arr ;
	NO_LEDS = no_leds ;


	if(no_leds != 1)
	{
		for(u32 i=0; i<no_leds; i++)
		{
			DIO_voidSetPinDirection(pin_arr[i].port,pin_arr[i].pin,OUTPUT_2MHZ_GPPP);
		}
	}
	else
	{
		DIO_voidSetPinDirection((*pin_arr).port,(*pin_arr).pin,OUTPUT_2MHZ_GPPP);
	}

}


void LED_voidTurnLedON(u32 led_no)
{

	DIO_voidSetPinValue(LED_arr_ptr[led_no].port,LED_arr_ptr[led_no].pin,DIO_HIGH);

}

void LED_voidTurnLedOFF(u32 led_no)
{

	DIO_voidSetPinValue(LED_arr_ptr[led_no].port,LED_arr_ptr[led_no].pin,DIO_LOW);

}


void LED_voidTurnLedON_Batch(  u32 led_states)
{

		for(u32 i=0; i<NO_LEDS; i++)
		{
			if(GET_BIT(led_states,i) == 1)
			{
				DIO_voidSetPinValue( LED_arr_ptr[i].port,LED_arr_ptr[i].pin,DIO_HIGH);
			}

		}


}
void LED_voidTurnLedOFF_Batch(u32 led_states)
{
	for(u32 i=0; i<NO_LEDS; i++)
	{
		if(GET_BIT(led_states,i) == 1)
		{
			DIO_voidSetPinValue( LED_arr_ptr[i].port,LED_arr_ptr[i].pin,DIO_LOW);
		}

	}

}

void LED_voidSetLedState_Batch(u32 led_states)
{

		for(u32 i=0; i<NO_LEDS; i++)
		{
			if(GET_BIT(led_states,i) == 1)
			{
				DIO_voidSetPinValue(LED_arr_ptr[i].port,LED_arr_ptr[i].pin,DIO_HIGH);
			}
			else
			{
				DIO_voidSetPinValue(LED_arr_ptr[i].port,LED_arr_ptr[i].pin,DIO_LOW);

			}
		}
}


