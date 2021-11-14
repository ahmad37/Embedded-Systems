/*******************************************/
/*Author : Ahmad */
/*Date : 19 AUG 2020*/ 
/*VER : V01*/
/********************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_BASE_ADDRESS 0xE000E100
#define NVIC_ISER0  *((u32*)(NVIC_BASE_ADDRESS+0x000)) /*ENABLE external interrupts from 0 to 31*/
#define NVIC_ISER1  *((u32*)(NVIC_BASE_ADDRESS+0x004)) /*ENABLE external interrupts from 32 to 63*/
					
#define NVIC_ICER0  *((u32*)(NVIC_BASE_ADDRESS+0x080))       /*DISABLE external interrupts from 0 to 31*/
#define NVIC_ICER1  *((u32*)(NVIC_BASE_ADDRESS+0x080+0x004)) /*DISABLE external interrupts from 32 to 63*/

/*set pending flag - useful in debugging or testing - simulate that the interrupt is fired*/ 
#define NVIC_ISPR0  *((u32*)(NVIC_BASE_ADDRESS+0x100)) /*DISABLE external interrupts from 0 to 31*/
#define NVIC_ISPR1  *((u32*)(NVIC_BASE_ADDRESS+0x100+0x004)) /*DISABLE external interrupts from 32 to 63*/

/*cLEAR pending flag - useful in debugging or testing - simulate that the interrupt is fired*/ 
#define NVIC_ICPR0  *((u32*)(NVIC_BASE_ADDRESS+0x180)) /*DISABLE external interrupts from 0 to 31*/
#define NVIC_ICPR1  *((u32*)(NVIC_BASE_ADDRESS+0x180+0x004)) /*DISABLE external interrupts from 32 to 63*/

/*read Active Flag Status*/
#define NVIC_IABR0  *((volatile u32*)(NVIC_BASE_ADDRESS+0x200))     /*DISABLE external interrupts from 32 to 63*/
#define NVIC_IABR1  *((volatile u32*)(NVIC_BASE_ADDRESS+0x200+0x004)) /*DISABLE external interrupts from 32 to 63*/

/*Set Priority          */ 
#define NVIC_IPR          ((u8*)0xE000E400)



/*These Macros will be options in config file */         /* ---------------------------------*/
/*Choose bits Ditribtion of Priority and SubPriority */  /*| Group   |     Sub  |  INFO     |*/
							                             /*|---------|----------|-----------|*/             
#define MNVIC_GROUP_4_SUB_0      0x05FA0300  		     /*| 16      |     None | No Nesting|*/
#define MNVIC_GROUP_3_SUB_1      0x05FA0400  		     /*| 8       |     2    |           |*/
#define MNVIC_GROUP_2_SUB_2      0x05FA0500  		     /*| 4       |     4    |           |*/
#define MNVIC_GROUP_1_SUB_3      0x05FA0600  		     /*| 2       |     8    |           |*/
#define MNVIC_GROUP_0_SUB_4      0x05FA0700  		     /*| None    |     16   |           |*/
													     /* ---------------------------------*/




#endif