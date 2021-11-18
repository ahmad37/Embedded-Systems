/*
 * DIO_interface.h
 *
 *  Created on: Aug 12, 2020
 *      Author: mazen
 */

#ifndef INCLUDE_DIO_INTERFACE_H_
#define INCLUDE_DIO_INTERFACE_H_


#define DIO_HIGH 	1
#define DIO_LOW 	0


#define PORTA 0
#define PORTB 1
#define PORTC 2


#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7
#define PIN8	8
#define PIN9	9
#define PIN10	10
#define PIN11	11
#define PIN12	12
#define PIN13	13
#define PIN14	14
#define PIN15	15

#define INPUT_ANALOG		0b0000
#define INPUT_FLOATING		0b0001
#define INPUT_PULL			0b0010


#define OUTPUT_10MHZ_GPPP	0b0100
#define OUTPUT_10MHZ_GPOD	0b0101
#define OUTPUT_10MHZ_AFPP	0b0110
#define OUTPUT_10MHZ_AFOD	0b0111


#define OUTPUT_2MHZ_GPPP	0b1000
#define OUTPUT_2MHZ_GPOD	0b1001
#define OUTPUT_2MHZ_AFPP	0b1010
#define OUTPUT_2MHZ_AFOD	0b1011


#define OUTPUT_50MHZ_GPPP	0b1100
#define OUTPUT_50MHZ_GPOD	0b1101
#define OUTPUT_50MHZ_AFPP	0b1110
#define OUTPUT_50MHZ_AFOD	0b1111

void DIO_voidSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN , u8 Copy_u8MODE);

void DIO_voidSetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN , u8 Copy_u8Value);

u8 DIO_voidGetPinValue(u8 Copy_u8PORT, u8 Copyu8PIN );



#endif /* INCLUDE_DIO_INTERFACE_H_ */
