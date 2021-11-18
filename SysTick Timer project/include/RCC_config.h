/*

Author	:	Mazen
date	:	(2020-08-08 ) 
Version	:	V1.0


*/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H




/* ************ ClOCK Config **************/

/////// CPU CLK SOURCE //////
#define CPU_CLK_SOURCE			CPU_CLK_XTAL

 /////// EXTERNAL CLK OPTIONS //////////
#define CLK_EXTERNAL			ON
#define CLK_EXTERNAL_TYPE		XTAL
#define CLK_EXTERNAL_SECURITY	ON


//////// INTERNAL CLK OPTIONS /////////

#define CLK_INTERNAL			OFF


//////// PLL OPTIONS /////////

#define CLK_PLL					ON

#if CLK_PLL==ON
#define PLL_SOURCE				EXT
#define PLL_EXT_PRESCALER		PLL_HSE_NO_DIV
#define PLL_PRESCALER			PLL_PS_9
#endif



#endif
