/* *************************************************** */
/* Author      : Ahmad                                 */
/* Version     : v01                                   */
/* date        : 8 JUN 2020                             */
/* **************************************************  */
#ifndef DELAY_H_
#define DELAY_H_



#ifndef SYSTEMCORECLOCK 
	#define SYSTEMCORECLOCK 8000000
#endif



// 6000 for keil and 12000 for eclipce
// must define the system clock first if not the default is 8 MHZ
void delay_ms(u32 ms) ;


#endif 