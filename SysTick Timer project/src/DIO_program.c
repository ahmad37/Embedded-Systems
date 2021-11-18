/*
 * DIO_program.c
 *
 *  Created on: Aug 12, 2020
 *      Author: mazen
 */

#include "STD_TYPES.h"
#include "BIT_CALC.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


void DIO_voidSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN , u8 Copy_u8MODE)
{
	switch(Copy_u8PORT)
	{
	case PORTA:
		if(Copy_u8PIN < 8)
		{
			GPIOA_CRL &= ~( (0b1111)<<(Copy_u8PIN * 4)  ) ;
			GPIOA_CRL |= ( (Copy_u8MODE)<<(Copy_u8PIN * 4)  ) ;
		}
		else if(Copy_u8PIN < 16)
		{
			GPIOA_CRH &= ~( (0b1111)<<((Copy_u8PIN-8) * 4)  ) ;
			GPIOA_CRH |= ( (Copy_u8MODE)<<((Copy_u8PIN-8) * 4)  ) ;
		}
		break ;
	case PORTB:
		if(Copy_u8PIN < 8)
		{
			GPIOB_CRL &= ~( (0b1111)<<(Copy_u8PIN * 4)  ) ;
			GPIOB_CRL |= ( (Copy_u8MODE)<<(Copy_u8PIN * 4)  ) ;
		}
		else if(Copy_u8PIN < 16)
		{
			GPIOB_CRH &= ~( (0b1111)<<((Copy_u8PIN-8) * 4)  ) ;
			GPIOB_CRH |= ( (Copy_u8MODE)<<((Copy_u8PIN-8) * 4)  ) ;
		}
		break ;
	case PORTC:
		if(Copy_u8PIN < 8)
		{
			GPIOC_CRL &= ~( (0b1111)<<(Copy_u8PIN * 4)  ) ;
			GPIOC_CRL |= ( (Copy_u8MODE)<<(Copy_u8PIN * 4)  ) ;
		}
		else if(Copy_u8PIN < 16)
		{
			GPIOC_CRH &= ~( (0b1111)<<((Copy_u8PIN-8) * 4)  ) ;
			GPIOC_CRH |= ( (Copy_u8MODE)<<((Copy_u8PIN-8) * 4)  ) ;
		}
		break ;
	}
}

void DIO_voidSetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN , u8 Copy_u8Value)
{
if(Copy_u8PIN < 16)
{
	if(Copy_u8Value==DIO_LOW)
	{
		switch(Copy_u8PORT)
		{
			case PORTA: CLR_BIT(GPIOA_ODR,Copy_u8PIN); break;
			case PORTB: CLR_BIT(GPIOB_ODR,Copy_u8PIN); break;
			case PORTC: CLR_BIT(GPIOC_ODR,Copy_u8PIN); break;
		}
	}
	else if(Copy_u8Value==DIO_HIGH)
	{
		switch(Copy_u8PORT)
		{
			case PORTA: SET_BIT(GPIOA_ODR,Copy_u8PIN); break;
			case PORTB: SET_BIT(GPIOB_ODR,Copy_u8PIN); break;
			case PORTC: SET_BIT(GPIOC_ODR,Copy_u8PIN); break;
		}

	}

}


}

u8 DIO_voidGetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN )
{
	u8 LOC_u8value = 0;
	if(Copy_u8PIN < 16)
	{

		switch(Copy_u8PORT)
			{
		case PORTA: LOC_u8value = GET_BIT(GPIOA_IDR,Copy_u8PIN); break;
		case PORTB: LOC_u8value = GET_BIT(GPIOB_IDR,Copy_u8PIN); break;
		case PORTC: LOC_u8value = GET_BIT(GPIOC_IDR,Copy_u8PIN); break;
			}
	}


return LOC_u8value ;
}
