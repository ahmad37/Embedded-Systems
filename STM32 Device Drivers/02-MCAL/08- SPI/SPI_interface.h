/*********************************************************************/
/* Name    : Ahmad Abdulrahem							             */
/* VER     : V01 										             */
/* PurPose :											           	 */  
/*********************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H 

void MSPI1_voidInit(void);/*Home Work*/

/*I make this function like this due to SPI full-duplex*/ 
void MSPI1_voidSendReceiveSynch(u8 copy_u8DataToTeansmit,  u8 *copy_u8DataToReceive); 


void MSPI1_voidSendReceiveAsynch(u8 copy_u8DataToTeansmit, void (*Callback)(u8) ); 




#endif