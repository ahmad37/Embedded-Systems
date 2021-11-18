#include "STD_TYPES.h"
#include "BIT_MATH.h"


/*Info About SRAM founded in Page 53 in Register Description Manual PDF*/
#define SRAM_START_ADDRESS    (0x20000000)
#define SRAM_SIZE             (96*1024)    /* 96KByte*/
#define SRAM_END_ADDRESS      ((SRAM_START_ADDRESS)+(SRAM_SIZE))

#define STACK_START_ADDRESS   SRAM_END_ADDRESS




/*Info: all interrupt vectors info are found in ..
      Page : 204
	  File : Register Description Manual PDF
	  Table 63. Vector table for other STM32F10xxx devices
*/
/*alias("") - used to rename the function to another name - help me to not define all isr() for all interrupt , i just use Defalut_Handler() for all interrupts, 
       and this is very usefull to handle interrupt which not defined an isr for it 
	   
  waek : Help the user to write it's own ISR with the same name also with different arguments - (make override of the perivous isr declaration) 	   
 */
  void Reset_Handler          (void) ;
  void NMI_Handler            (void) __attribute__((weak, alias("Default_Handler") ));
  void HardFault_Handler      (void) __attribute__((weak, alias("Default_Handler") ));
  void MemManage_Handler      (void) __attribute__((weak, alias("Default_Handler") ));
  void BusFault_Handler       (void) __attribute__((weak, alias("Default_Handler") ));
  void UsageFault_Handler     (void) __attribute__((weak, alias("Default_Handler") ));
  void 0                      (void) __attribute__((weak, alias("Default_Handler") ));
  void SVCall_Handler         (void) __attribute__((weak, alias("Default_Handler") ));
  void Debug Monitor_Handler  (void) __attribute__((weak, alias("Default_Handler") ));
  void 0                      (void) __attribute__((weak, alias("Default_Handler") ));
  void PendSV_Handler         (void) __attribute__((weak, alias("Default_Handler") ));
  void SysTick_Handler        (void) __attribute__((weak, alias("Default_Handler") ));
  void WWDG_Handler           (void) __attribute__((weak, alias("Default_Handler") ));
  void PVD_Handler            (void) __attribute__((weak, alias("Default_Handler") ));
  void TAMPER_Handler         (void) __attribute__((weak, alias("Default_Handler") ));
  void RTC_Handler            (void) __attribute__((weak, alias("Default_Handler") ));
  void FLASH_Handler          (void) __attribute__((weak, alias("Default_Handler") ));
  void RCC_Handler            (void) __attribute__((weak, alias("Default_Handler") ));
  void EXTI0_Handler          (void) __attribute__((weak, alias("Default_Handler") ));
  void EXTI1_Handler          (void) __attribute__((weak, alias("Default_Handler") ));
  void EXTI2_Handler          (void) __attribute__((weak, alias("Default_Handler") ));
  void EXTI3_Handler          (void) __attribute__((weak, alias("Default_Handler") ));
  void EXTI4_Handler          (void) __attribute__((weak, alias("Default_Handler") ));
  void DMA1_Channel1_Handler  (void) __attribute__((weak, alias("Default_Handler") ));
  void DMA1_Channel2_Handler  (void) __attribute__((weak, alias("Default_Handler") ));
  void DMA1_Channel3_Handler  (void) __attribute__((weak, alias("Default_Handler") ));
  void DMA1_Channel4_Handler  (void) __attribute__((weak, alias("Default_Handler") ));
  void DMA1_Channel5_Handler  (void) __attribute__((weak, alias("Default_Handler") ));
  void DMA1_Channel6_Handler  (void) __attribute__((weak, alias("Default_Handler") ));
  void DMA1_Channel7_Handler  (void) __attribute__((weak, alias("Default_Handler") ));
  void ADC1_2_Handler         (void) __attribute__((weak, alias("Default_Handler") ));
  void USB_HP_CAN_Handler     (void) __attribute__((weak, alias("Default_Handler") ));
  void TX_Handler             (void) __attribute__((weak, alias("Default_Handler") ));
  void USB_LP_CAN_Handler     (void) __attribute__((weak, alias("Default_Handler") ));
  void RX0_Handler            (void) __attribute__((weak, alias("Default_Handler") ));
  void CAN_RX1_Handler        (void) __attribute__((weak, alias("Default_Handler") ));
  void CAN_SCE_Handler        (void) __attribute__((weak, alias("Default_Handler") ));
  void EXTI9_5_Handler        (void) __attribute__((weak, alias("Default_Handler") ));
  void TIM1_BRK_Handler       (void) __attribute__((weak, alias("Default_Handler") ));
  void TIM1_UP_Handler        (void) __attribute__((weak, alias("Default_Handler") ));
  void TIM1_TRG_COM_Handler   (void) __attribute__((weak, alias("Default_Handler") ));
  void TIM1_CC_Handler        (void) __attribute__((weak, alias("Default_Handler") ));
  void TIM2_Handler           (void) __attribute__((weak, alias("Default_Handler") ));
  void TIM3_Handler           (void) __attribute__((weak, alias("Default_Handler") ));
  void TIM4_Handler           (void) __attribute__((weak, alias("Default_Handler") ));
  void I2C1_EV_Handler        (void) __attribute__((weak, alias("Default_Handler") ));
  void I2C1_ER_Handler        (void) __attribute__((weak, alias("Default_Handler") ));
  void I2C2_EV_Handler        (void) __attribute__((weak, alias("Default_Handler") ));
  void I2C2_ER_Handler        (void) __attribute__((weak, alias("Default_Handler") ));
  void SPI1_Handler           (void) __attribute__((weak, alias("Default_Handler") ));
  void SPI2_Handler           (void) __attribute__((weak, alias("Default_Handler") ));
  void USART1_Handler         (void) __attribute__((weak, alias("Default_Handler") ));
  void USART2_Handler         (void) __attribute__((weak, alias("Default_Handler") ));
  void USART3_Handler         (void) __attribute__((weak, alias("Default_Handler") ));
  void EXTI15_10_Handler      (void) __attribute__((weak, alias("Default_Handler") ));
  void RTCAlarm_Handler       (void) __attribute__((weak, alias("Default_Handler") ));
  void USBWakeup_Handler      (void) __attribute__((weak, alias("Default_Handler") ));
  void TIM8_BRK_Handler       (void) __attribute__((weak, alias("Default_Handler") ));
  void TIM8_UP_Handler        (void) __attribute__((weak, alias("Default_Handler") ));
  void TIM8_TRG_COM_Handler   (void) __attribute__((weak, alias("Default_Handler") ));
  void TIM8_CC_Handler        (void) __attribute__((weak, alias("Default_Handler") ));
  void ADC3_Handler           (void) __attribute__((weak, alias("Default_Handler") ));
  void FSMC_Handler           (void) __attribute__((weak, alias("Default_Handler") ));
  void SDIO_Handler           (void) __attribute__((weak, alias("Default_Handler") ));
  void TIM5_Handler           (void) __attribute__((weak, alias("Default_Handler") ));
  void SPI3_Handler           (void) __attribute__((weak, alias("Default_Handler") ));
  void UART4_Handler          (void) __attribute__((weak, alias("Default_Handler") ));
  void UART5_Handler          (void) __attribute__((weak, alias("Default_Handler") ));
  void TIM6_Handler           (void) __attribute__((weak, alias("Default_Handler") ));
  void TIM7_Handler           (void) __attribute__((weak, alias("Default_Handler") ));
  void DMA2_Channel1_Handler  (void) __attribute__((weak, alias("Default_Handler") ));
  void DMA2_Channel2_Handler  (void) __attribute__((weak, alias("Default_Handler") ));
  void DMA2_Channel3_Handler  (void) __attribute__((weak, alias("Default_Handler") ));
  void DMA2_Channel4_5_Handler(void) __attribute__((weak, alias("Default_Handler") ));



/* Interrupts Vector Table- Save All Address of All Interrupt Handlers in an array */
/*Note:
The addresses of all isr vectors will be the address of
 Default_Handler() unless the user write it's own isr */
u32 Interrupt_Vector[]__attribuite__((section(".isr_vector"))) ={
          STACK_START_ADDRESS    , 
 (u32) &  Reset_Handler          , /*cast add of fun to (u32)*/
 (u32) &  NMI_Handler            ,
 (u32) &  HardFault_Handler      ,
 (u32) &  MemManage_Handler      ,
 (u32) &  BusFault_Handler       ,
 (u32) &  UsageFault_Handler     ,
 (u32) &  0                      ,
 (u32) &  SVCall_Handler         ,
 (u32) &  Debug Monitor_Handler  ,
 (u32) &  0                      ,
 (u32) &  PendSV_Handler         ,
 (u32) &  SysTick_Handler        ,
 (u32) &  WWDG_Handler           ,
 (u32) &  PVD_Handler            ,
 (u32) &  TAMPER_Handler         ,
 (u32) &  RTC_Handler            ,
 (u32) &  FLASH_Handler          ,
 (u32) &  RCC_Handler            ,
 (u32) &  EXTI0_Handler          ,
 (u32) &  EXTI1_Handler          ,
 (u32) &  EXTI2_Handler          ,
 (u32) &  EXTI3_Handler          ,
 (u32) &  EXTI4_Handler          ,
 (u32) &  DMA1_Channel1_Handler  ,
 (u32) &  DMA1_Channel2_Handler  ,
 (u32) &  DMA1_Channel3_Handler  ,
 (u32) &  DMA1_Channel4_Handler  ,
 (u32) &  DMA1_Channel5_Handler  ,
 (u32) &  DMA1_Channel6_Handler  ,
 (u32) &  DMA1_Channel7_Handler  ,
 (u32) &  ADC1_2_Handler         ,
 (u32) &  USB_HP_CAN_Handler     ,
 (u32) &  TX_Handler             ,
 (u32) &  USB_LP_CAN_Handler     ,
 (u32) &  RX0_Handler            ,
 (u32) &  CAN_RX1_Handler        ,
 (u32) &  CAN_SCE_Handler        ,
 (u32) &  EXTI9_5_Handler        ,
 (u32) &  TIM1_BRK_Handler       ,
 (u32) &  TIM1_UP_Handler        ,
 (u32) &  TIM1_TRG_COM_Handler   ,
 (u32) &  TIM1_CC_Handler        ,
 (u32) &  TIM2_Handler           ,
 (u32) &  TIM3_Handler           ,
 (u32) &  TIM4_Handler           ,
 (u32) &  I2C1_EV_Handler        ,
 (u32) &  I2C1_ER_Handler        ,
 (u32) &  I2C2_EV_Handler        ,
 (u32) &  I2C2_ER_Handler        ,
 (u32) &  SPI1_Handler           ,
 (u32) &  SPI2_Handler           ,
 (u32) &  USART1_Handler         ,
 (u32) &  USART2_Handler         ,
 (u32) &  USART3_Handler         ,
 (u32) &  EXTI15_10_Handler      ,
 (u32) &  RTCAlarm_Handler       ,
 (u32) &  USBWakeup_Handler      ,
 (u32) &  TIM8_BRK_Handler       ,
 (u32) &  TIM8_UP_Handler        ,
 (u32) &  TIM8_TRG_COM_Handler   ,
 (u32) &  TIM8_CC_Handler        ,
 (u32) &  ADC3_Handler           ,
 (u32) &  FSMC_Handler           ,
 (u32) &  SDIO_Handler           ,
 (u32) &  TIM5_Handler           ,
 (u32) &  SPI3_Handler           ,
 (u32) &  UART4_Handler          ,
 (u32) &  UART5_Handler          ,
 (u32) &  TIM6_Handler           ,
 (u32) &  TIM7_Handler           ,
 (u32) &  DMA2_Channel1_Handler  ,
 (u32) &  DMA2_Channel2_Handler  ,
 (u32) &  DMA2_Channel3_Handler  ,
 (u32) &  DMA2_Channel4_5_Handler
}; 


void Default_Handler(void)
{
	while(1); 
}

/* This Isr is the entry point of startup file code */
/*This Entry Point must Gived(mentioned) in linker script file 
via a
command Entry(Reset_Handler) */
void Reset_Handler(void)
{ /* The Adresses of all sections you can know from linker script file , you must write it first :D */ 
	
	/*copy .data sections to SRAM */
	/*Init .bss  sections to zero in SRAM */
	/*call Init fuction of std. libraly - used only if you use std libs and fuctions like printf(" ") */
    /*call main() - Entry Point */
	
}