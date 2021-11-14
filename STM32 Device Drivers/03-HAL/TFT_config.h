/*.h .c file Headers Template */
/*********************************************************************/
/* Name    : Ahmad Abdulrahem							             */
/* VER     : V01 										             */
/* PurPose :											           	 */  
/*********************************************************************/
#ifndef TFT_CONFIG_H
#define TFT_CONFIG_H

/*Write pin in pair port,pin*/
#define TFT_A0_PIN  GPIOA,PIN2
#define TFT_RST_PIN GPIOA,PIN1

/*
1- clock Idle = High -> polarity =high 
2- Read at = rising edge so write on falling 
so as a master uc i will do the oppsite Write then read
so Phase = 1 

3- MSB is First to send 

4- no prescaller 
  
  spi1->cr1= 000001000111;
  */ 

#endif