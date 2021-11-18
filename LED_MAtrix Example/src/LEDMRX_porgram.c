/********************************************/
/* Author : Ahmad */
/* Date : 31AUG 2020*/ 
/* VER :  V01 */ 
/******************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"


#include "LEDMRX_interface.h"
#include "LEDMRX_config.h"
#include "LEDMRX_private.h"



void HLEDMRX_voidInit(void)
{
/*Rows Direction*/ 	
GPIO_voidSetPinDir(LEDMRX_ROW0_PIN,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDir(LEDMRX_ROW1_PIN,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDir(LEDMRX_ROW2_PIN,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDir(LEDMRX_ROW3_PIN,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDir(LEDMRX_ROW4_PIN,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDir(LEDMRX_ROW5_PIN,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDir(LEDMRX_ROW6_PIN,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDir(LEDMRX_ROW7_PIN,OUTPUT_SPEED_2MHZ_PP);

/*Coloumns Directions */ 
GPIO_voidSetPinDir(LEDMRX_COL0_PIN,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDir(LEDMRX_COL1_PIN,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDir(LEDMRX_COL2_PIN,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDir(LEDMRX_COL3_PIN,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDir(LEDMRX_COL4_PIN,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDir(LEDMRX_COL5_PIN,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDir(LEDMRX_COL6_PIN,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDir(LEDMRX_COL7_PIN,OUTPUT_SPEED_2MHZ_PP);

}


void HLEDMRX_voidDisplay(u8 *copy_u8Data)
{
	u8 Local_u8Counter=60;//nom of frames
while(Local_u8Counter--)
{
	/*Col 0*/ 
    DisableAllCols();
	SetRowValues(copy_u8Data[0]);
	GPIO_voidSetPinValue(LEDMRX_COL0_PIN,LOW);
	MSTK_voidSetBusyWait(2500);//2.5 msec
	/*Col 1*/
	DisableAllCols();
	SetRowValues(copy_u8Data[1]);
	GPIO_voidSetPinValue(LEDMRX_COL1_PIN,LOW);
	MSTK_voidSetBusyWait(2500);//2.5 msec
	/*Col 2*/
	DisableAllCols();
	SetRowValues(copy_u8Data[2]);
	GPIO_voidSetPinValue(LEDMRX_COL2_PIN,LOW);
	MSTK_voidSetBusyWait(2500);//2.5 msec
    /*Col 3*/
    DisableAllCols();
	SetRowValues(copy_u8Data[3]);
	GPIO_voidSetPinValue(LEDMRX_COL3_PIN,LOW);
	MSTK_voidSetBusyWait(2500);//2.5 msec
    /*Col 4*/
    DisableAllCols();
	SetRowValues(copy_u8Data[4]);
	GPIO_voidSetPinValue(LEDMRX_COL4_PIN,LOW);
 	MSTK_voidSetBusyWait(2500);//2.5 msec
    /*Col 5*/
    DisableAllCols();
	SetRowValues(copy_u8Data[5]);
	GPIO_voidSetPinValue(LEDMRX_COL5_PIN,LOW);
	MSTK_voidSetBusyWait(2500);//2.5 msec
    /*Col 6*/
    DisableAllCols();
	SetRowValues(copy_u8Data[6]);
	GPIO_voidSetPinValue(LEDMRX_COL6_PIN,LOW);
	MSTK_voidSetBusyWait(2500);//2.5 msec
    /*Col 7*/	
    DisableAllCols();
	SetRowValues(copy_u8Data[7]);
	GPIO_voidSetPinValue(LEDMRX_COL7_PIN,LOW);
	MSTK_voidSetBusyWait(2500);//2.5 msec
	}
}

static void DisableAllCols(void)
{
  GPIO_voidSetPinValue(LEDMRX_COL0_PIN,HIGH); 
  GPIO_voidSetPinValue(LEDMRX_COL1_PIN,HIGH);
  GPIO_voidSetPinValue(LEDMRX_COL2_PIN,HIGH);
  GPIO_voidSetPinValue(LEDMRX_COL3_PIN,HIGH);
  GPIO_voidSetPinValue(LEDMRX_COL4_PIN,HIGH);
  GPIO_voidSetPinValue(LEDMRX_COL5_PIN,HIGH);
  GPIO_voidSetPinValue(LEDMRX_COL6_PIN,HIGH);
  GPIO_voidSetPinValue(LEDMRX_COL7_PIN,HIGH);
	
}

static void SetRowValues(u8 copy_u8Value)
{
u8 Local_u8BIT;	
 Local_u8BIT= GET_BIT(copy_u8Value,0);
 GPIO_voidSetPinValue(LEDMRX_ROW0_PIN,Local_u8BIT);

 Local_u8BIT= GET_BIT(copy_u8Value,1);
 GPIO_voidSetPinValue(LEDMRX_ROW1_PIN,Local_u8BIT);

 Local_u8BIT= GET_BIT(copy_u8Value,2);
 GPIO_voidSetPinValue(LEDMRX_ROW2_PIN,Local_u8BIT);

 Local_u8BIT= GET_BIT(copy_u8Value,3);
 GPIO_voidSetPinValue(LEDMRX_ROW3_PIN,Local_u8BIT);

 Local_u8BIT= GET_BIT(copy_u8Value,4);
 GPIO_voidSetPinValue(LEDMRX_ROW4_PIN,Local_u8BIT);

 Local_u8BIT= GET_BIT(copy_u8Value,5);
 GPIO_voidSetPinValue(LEDMRX_ROW5_PIN,Local_u8BIT);

 Local_u8BIT= GET_BIT(copy_u8Value,6);
 GPIO_voidSetPinValue(LEDMRX_ROW6_PIN,Local_u8BIT);

 Local_u8BIT= GET_BIT(copy_u8Value,7);
 GPIO_voidSetPinValue(LEDMRX_ROW7_PIN,Local_u8BIT); 

}
