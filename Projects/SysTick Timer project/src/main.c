

#include "STD_TYPES.h"
#include "BIT_CALC.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SysTick_interface.h"


#include "LED.h"


#define LED_PORT PORTA
#define LEDS	8


LED_PIN my_leds[LEDS] = {
		{LED_PORT,PIN0},
		{LED_PORT,PIN1},
		{LED_PORT,PIN2},
		{LED_PORT,PIN3},
		{LED_PORT,PIN4},
		{LED_PORT,PIN5},
		{LED_PORT,PIN6},
		{LED_PORT,PIN7},
};

void LEDEFFECT_pingpong(void);
void LEDEFFECT_InOut(void);
void LEDEFFECT_Flash(void);



int main(void)
{
	/*Initialize*/
	 RCC_voidInitSysClock();
	 RCC_voidEnableClock(RCC_APB2,GPIOA_EN);

STK_voidTimerInit();


LED_voidInit(my_leds,LEDS) ;




	while(1)
	{


		for(int i=0; i<4 ; i++)
		{
			LEDEFFECT_pingpong();
		}

		for(int i=0; i<4 ; i++)
		{
			LEDEFFECT_InOut();
		}

		for(int i=0; i<8; i++)
		{
			LEDEFFECT_Flash();
		}





	}
}

void LEDEFFECT_pingpong(void)
{
	u32 state = 0;
	for(int i=0; i<LEDS; i++)
	{

		LED_voidSetLedState_Batch(SET_BIT(state,i));
		STK_voidDelay_ms(200);
		LED_voidSetLedState_Batch(CLR_BIT(state,i));
		STK_voidDelay_ms(200);

	}
	for(int i=LEDS; i>=0; i--)
	{
		LED_voidSetLedState_Batch(SET_BIT(state,i));
		STK_voidDelay_ms(200);
		LED_voidSetLedState_Batch(CLR_BIT(state,i));
		STK_voidDelay_ms(200);

	}
}

void LEDEFFECT_InOut(void)
{
	u32 current_state = 0 ;
	u8  offset = 3 ;

	for(int i=0; i<LEDS ; )
	{
		current_state = ((2<<i)-1)<<offset ;
		LED_voidSetLedState_Batch(current_state);

		i+=2;
		offset--;

		STK_voidDelay_ms(200);
	}

	offset = 0 ;

	for(int i=8; i!=0 ; )
		{
			current_state = ((2<<i)-1)<<offset ;
			LED_voidSetLedState_Batch(current_state);

			i-=2;
			offset++;
			STK_voidDelay_ms(200);

		}

}

void LEDEFFECT_Flash(void)
{
	LED_voidSetLedState_Batch(0xff);

	STK_voidDelay_ms(500);

	LED_voidSetLedState_Batch(0x000000000);

	STK_voidDelay_ms(500);

}


