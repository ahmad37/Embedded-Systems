/*********************************************************************/
/* Name    : Ahmad Abdulrahem							             */
/* VER     : V01 										             */
/* PurPose :											           	 */  
/*********************************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/*Options for Configuration file */ 
#define SPI_MASTER        1
#define SPI_SLAVE         0
#define SPI_POLARITY_LOW  0
#define SPI_POLARITY_HIGH 1
#define SPI_PHASE_LOW     0
#define SPI_PHASE_HIGH    1
#define SPI_CRC_ENABLE    1
#define SPI_CRC_DISABLE   0

/*********************************/

 
/*NOTE: I2S is a protocol used to send/receive sounds */ 
typedef struct{
	volatile u32 CR1;      /*Control Register1*/ /*Not used in I2S Mode*/
    volatile u32 CR2;      /*Control Register2*/ /*Not used in I2S Mode*/
    volatile u32 SR;       /*Status Register*/
    volatile u32 DR;       /*Data Register */
    volatile u32 CRCPR;    /*Not used in I2S Mode*/
    volatile u32 RXCRCR;   /*Not used in I2S Mode*/
    volatile u32 TXCRCR;   /*Not used in I2S Mode*/
    volatile u32 I2SCFGR;  /*I2S Configuration register*/
    volatile u32 I2SSPR;   /*I2S Prescaller register*/
}SPI_t;  
#define SPI1  (volatile SPI_t* (0x0x40013000))
typedef struct{
	/* SPI_ PERPHERAL_NUMBER*/
	/* SPI_MASTER_OR_SLAVE*/ 
	/* Baud Rate*/
	/* POLARITY*/
	/* PHASE*/
	/* DATA ORDER*/
	/* DATA SIZE - DFF data frame formate , 8 or 16 bit*/
	/* Receive Only - USed When you want A broadcast sending from Master*/

/* *** STM Extra Feature of SPI Protocol **** */	
	/* CRC_STATE*/
	/* Bi-Directional*/ 
	/* SSM bit- Set/Reset NSS Automatic by H/W - No Need of S/w check - Only used with one slave in your network*/ 
	/*  */
	
}SPI_Config_t;
#define SPI_CONF (SPI_Config_t*)

/*
INIT FUN {
	SPI_Config_t configurations = {0}; 
	configurations.xx = data of xx in config file; 
	.
	.
	.
}
*/



/*
typedef enum {
	SPI1,
	SPI2,
	SPI3	
}SPI_NUM_t; 
typedef enum {
	SPI_CRC_ENABLE=0,
	SPI_CRC_DISABLE
}SPI_CRC_t; 
typdef enum{
	
};
*/


#endif