/********************************************/
/* Author : Ahmad */
/* Date : 31AUG 2020*/ 
/* VER :  V01 */ 
/******************************************/

#ifndef LEDMRX_INTERFACE_H
#define LEDMRX_INTERFACE_H



void HLEDMRX_voidInit(void);
void HLEDMRX_voidDisplay(u8 *copy_u8Data); 
void DisableAllCols(void); 
void SetRowValues(u8 copy_u8Value); 


#endif 