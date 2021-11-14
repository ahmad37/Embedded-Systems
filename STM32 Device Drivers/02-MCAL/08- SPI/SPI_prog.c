/*********************************************************************/
/* Name    : Ahmad Abdulrahem							             */
/* VER     : V01 										             */
/* PurPose :											           	 */  
/*********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//#include ".h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
/*SPI main()
fun (u8 data){//some code /}
main(){	
u8 receive; 
MSPI1_voidSendReceiveSynch(0x56,&receive); 
MSPI1_voidSendReceiveAsynch(0x56,fun);}*/
void MSPI_voidInitMaster(void)
{    SPI1->CR1->=0x0347;
	/*SET INIT PINS */
	/*SET MASTER/SLAVE */
	/*SET POLARITY*/
	/*SET PHASE*/
	/* */
}
void MSPI1_voidSendReceiveSynch(u8 copy_u8DataToTeansmit,u8 *copy_u8DataToReceive)
{
	/*Clear for Slave Select Pin SS */
	GPIO_vidSetOPinValue(MSPI_SLAVE_PIN, LOW); 
	
	/*SEND DATA*/
	SPI->DR = copy_u8DataToTeansmit; 
	
	/*WAIT FOR BUSY flag */
	while(GET_BIT(SPI->SR , 7) ==1); 
	
	/*return to the received data */
	*copy_u8DataToReceive = SPI->DR; 
	
	/*Set SlaveSElect PIN*/
	GPIO_vidSetOPinValue(MSPI_SLAVE_PIN, HIGH);
} 
void SPI1_IRQHandler(){
}

