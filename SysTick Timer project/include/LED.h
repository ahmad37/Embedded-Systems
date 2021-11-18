
#ifndef INCLUDE_LED_H_
#define INCLUDE_LED_H_

#include "STD_TYPES.h"


typedef struct
{
	u8 port;
	u8 pin ;
}LED_PIN;



void  LED_voidInit(LED_PIN pin_arr[],u32 no_leds);

void LED_voidTurnLedON(u32 led_no);

void LED_voidTurnLedOFF(u32 led_no);

void LED_voidTurnLedON_Batch(  u32 led_states);

void LED_voidTurnLedOFF_Batch(u32 led_states);

void LED_voidSetLedState_Batch(u32 led_states);

#endif /* INCLUDE_LED_H_ */
