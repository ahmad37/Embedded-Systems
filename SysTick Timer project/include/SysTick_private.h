
#ifndef INCLUDE_SYSTICK_PRIVATE_H_
#define INCLUDE_SYSTICK_PRIVATE_H_


#define STK_BASE_ADDR 0xE000E010

#define STK_REG32_DEF(offset) *((volatile u32*)(STK_BASE_ADDR + (offset)))


#define STK_CTRL 	STK_REG32_DEF(0x00)
#define STK_LOAD 	STK_REG32_DEF(0x04)
#define STK_VAL  	STK_REG32_DEF(0x08)
#define STK_CALIB	STK_REG32_DEF(0x0c)


/* CLK_SOURCE OPTIONS */

#define AHB   1
#define AHB_8 0

/* ENABLE/DISABLE options (general purpose) */
#define ENABLE    1
#define DISABLE   0

#define STK_EN   0
#define STK_TICKINT 1
#define STK_CLKSOURCE 2
#define STK_COUNT_FLAG 16



#endif /* INCLUDE_SYSTICK_PRIVATE_H_ */
