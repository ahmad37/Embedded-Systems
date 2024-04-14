

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB     0
#define RCC_APB1	1
#define RCC_APB2	2

#define GPIOA_EN    2
#define GPIOB_EN	3
#define GPIOC_EN	4

void RCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerID );
void RCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerID );

void RCC_voidInitSysClock(void); //use configurations in RCC_config.h 




#endif
