/*

Author	:	Mazen
date	:	(2020-08-08 ) 
Version	:	V1.0


*/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* RCC register definitions */

#define RCC_BASE_ADDR 0x40021000

#define RCC_REG32_DEF(offset) *((volatile u32*)(RCC_BASE_ADDR + (offset)))

#define RCC_CR     		RCC_REG32_DEF(0x00)
#define RCC_CFGR		RCC_REG32_DEF(0x04)
#define RCC_CIR			RCC_REG32_DEF(0x08)
#define RCC_APB2RST		RCC_REG32_DEF(0x0c)
#define RCC_APB1RST		RCC_REG32_DEF(0x10)
#define RCC_AHBENR		RCC_REG32_DEF(0x14)
#define RCC_APB2ENR		RCC_REG32_DEF(0x18)
#define RCC_APB1ENR		RCC_REG32_DEF(0x1c)
#define RCC_BDCR		RCC_REG32_DEF(0x20)
#define RCC_CSR			RCC_REG32_DEF(0x24)



//RCC_CR bits
#define HSE_ON    16
#define HSE_RDY   17
#define HSE_BYP   18
#define CSS_ON    19
#define PLL_ON    24
#define PLL_RDY   25
#define HSI_ON    0
#define HSI_RDY   1


//RCC_CFGR bits
#define PLL_SRC     16
#define PLL_XTPRE   17
#define PLLMUL		18
#define SW			0
#define SWS			2



#define ENABLE    1
#define DISABLE   0
#define ON  	  1
#define OFF       0

/* EXTERNAL CLK types */
#define RC 		  1
#define XTAL	  0


/* PLL source options */
#define EXT 	 1
#define INT_DIV_BY_2 	 0

/* PLL PRESCALER Values */
#define PLL_PS_2	0
#define PLL_PS_3	1
#define PLL_PS_4	2
#define PLL_PS_5	3
#define PLL_PS_6	4
#define PLL_PS_7	5
#define PLL_PS_8	6
#define PLL_PS_9	7
#define PLL_PS_10	8
#define PLL_PS_11	9
#define PLL_PS_12	10
#define PLL_PS_13	11
#define PLL_PS_14	12
#define PLL_PS_15	13
#define PLL_PS_16	14
//#define PLL_PS_16	15

/* PLL HSE half value option */
#define PLL_HSE_NO_DIV		0
#define PLL_HSE_DIV_BY_2	1

/* CPU CLOCK SOURCE OPTIONS */
#define CPU_CLK_PLL			2
#define CPU_CLK_XTAL		1
#define	CPU_CLK_INT			0





#endif
