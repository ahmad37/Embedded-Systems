/**************************************************/
/* Author : Ahmad Abdulrahem                      */
/* Date   : 10 AUG 2020                           */
/* Version: V01                                   */
/**************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/*Register Definitions */ 
#define  RCC_CR 		*(( u32 *)0x40021000)  //Responsable for Clock Control (Enable different Clock Source)
#define  RCC_CFGR 		*(( u32 *)0x40021004)  //Responsable for Clock Control (Choosing Clock Source)
#define  RCC_CIR 		*(( u32 *)0x40021008)
#define  RCC_APB2RSTR 	*(( u32 *)0x4002100C)
#define  RCC_APB1RSTR 	*(( u32 *)0x40021010)
#define  RCC_AHBENR 	*(( u32 *)0x40021014)  //Responsable for Clock Control  (Enable/disable Clock of Peripherals)
#define  RCC_APB2ENR 	*(( u32 *)0x40021018)  //Responsable for Clock Control  (Enable/disable Clock of Peripherals)
#define  RCC_APB1ENR 	*(( u32 *)0x4002101C)  //Responsable for Clock Control   (Enable/disable Clock of Peripherals)
#define  RCC_BDCR 		*(( u32 *)0x40021020)
#define  RCC_CSR		*(( u32 *)0x40021024)

/*Clock Types*/ 
#define  RCC_HSE_CRYSTAL 0
#define  RCC_HSE_RC      1
#define  RCC_HSI 	     2
#define  RCC_PLL		 3

/*PLL Input Clock Options*/
#define RCC_PLL_IN_HSI_DIV_2     0
#define RCC_PLL_IN_HSE_DIV_2     1
#define	RCC_PLL_IN_HSE           2




#endif

