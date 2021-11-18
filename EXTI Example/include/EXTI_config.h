/*********************************************************************/
/* Name    : Ahmad Abdulrahem							             */
/* VER     : V01 										             */
/* PurPose :											           	 */  
/*********************************************************************/
#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

/*Options:
           (0)     Disabled 
            1,2,.. Enabled   */                
#define  EXTI_LINE0_ENABLE     (1)         /*PINA0,PIB0,PINC0,...*/
#define  EXTI_LINE1_ENABLE     (1)         /*PINA1,PIB1,PINC1,...*/
#define  EXTI_LINE2_ENABLE     (1)
#define  EXTI_LINE3_ENABLE     (1)
#define  EXTI_LINE4_ENABLE     (1)
#define  EXTI_LINE5_ENABLE     (1)
#define  EXTI_LINE6_ENABLE     (1)
#define  EXTI_LINE7_ENABLE     (1)
#define  EXTI_LINE8_ENABLE     (1)
#define  EXTI_LINE9_ENABLE     (1)
#define  EXTI_LINE10_ENABLE    (1)
#define  EXTI_LINE11_ENABLE    (0)
//#define  EXTI_LINE12_ENABLE    (0)
//#define  EXTI_LINE13_ENABLE    (0)
//#define  EXTI_LINE14_ENABLE    (0)
//#define  EXTI_LINE15_ENABLE    (0)
//#define  EXTI_LINE16_ENABLE    (0)          /*Connected to PVD output*/
//#define  EXTI_LINE16_ENABLE    (0)          /*Connected to RTC output*/
//#define  EXTI_LINE16_ENABLE    (0)          /*Connected to USB Wakeup Event*/
//#define  EXTI_LINE16_ENABLE    (0)          /*Connected to Ethernet Wakeup Event- Connectivity Line Devices*/
                 

/* Options:
            RISING =1,
            FALLING=2,
            ON_CHANGE=3 */
#define  EXTI_LINE0_EDGE     (1)
#define  EXTI_LINE1_EDGE     (3)
#define  EXTI_LINE2_EDGE     (1)
#define  EXTI_LINE3_EDGE     (1)
#define  EXTI_LINE4_EDGE     (1)
#define  EXTI_LINE5_EDGE     (1)
#define  EXTI_LINE6_EDGE     (1)
#define  EXTI_LINE7_EDGE     (1)
#define  EXTI_LINE8_EDGE     (1)
#define  EXTI_LINE9_EDGE     (2)
#define  EXTI_LINE10_EDGE    (3)
//#define  EXTI_LINE11_EDGE    (0)
//#define  EXTI_LINE12_EDGE    (0)
//#define  EXTI_LINE13_EDGE    (0)
//#define  EXTI_LINE14_EDGE    (0)
//#define  EXTI_LINE15_EDGE    (0)
//#define  EXTI_LINE16_EDGE    (0)
//#define  EXTI_LINE16_EDGE    (0)
//#define  EXTI_LINE16_EDGE    (0)
//#define  EXTI_LINE16_EDGE    (0)

#endif
