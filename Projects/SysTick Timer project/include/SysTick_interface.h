

#ifndef INCLUDE_SYSTICK_INTERFACE_H_
#define INCLUDE_SYSTICK_INTERFACE_H_


void STK_voidTimerInit(void);

void STK_voidStartTimer(void);

void STK_voidStopTimer(void);

void STK_voidLoadTimer(u32 copy_u32load);

void STK_voidDelay_ms(u32 copyu32_delay);



#endif /* INCLUDE_SYSTICK_INTERFACE_H_ */
