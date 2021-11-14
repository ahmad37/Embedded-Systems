/* *************************************************** */
/* Author      : Ahmad                                 */
/* Version     : v01                                   */
/* date        : 8 JUN 2020                            */
/* **************************************************  */

#include "STD_TYPES.h"
#include "delay.h"

void delay_ms(u32 ms)
{
	u32 i;

	for(i = 0; i < (SYSTEMCORECLOCK/(6000)) * ms; i++){
		__asm ("NOP");
	}
}