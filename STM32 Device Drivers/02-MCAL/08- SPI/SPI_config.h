/*********************************************************************/
/* Name    : Ahmad Abdulrahem							             */
/* VER     : V01 										             */
/* PurPose :											           	 */  
/*********************************************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/*write it in a pair port,pin*/
#define MSPI_SLAVE_PIN 


/*
 OPTIONS: 
     SPI_MASTER
	 SPI_SLAVE
*/
#define SPI_MODE  SPI_MASTER
/*
OPTIONS; 
 SPI_POLARITY_LOW
 SPI_POLARITY_HIGH
 */
#define SPI_POLARITY SPI_POLARITY_LOW
/*
OPTIONS: 
SPI_PHASE_HIGH
SPI_PHASE_LOW
*/
#define SPI_CLOCK_PHASE SPI_PHASE_HIGH

/*SPI CRC OPTIONS: 
SPI_CRC_ENABLE 
SPI_CRC_DISABLE*/
#define SPI_CRC  SPI_CRC_DISABLE

#define DATA_DIRECTION   

#endif