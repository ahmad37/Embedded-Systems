/*.h .c file Headers Template */
/*********************************************************************/
/* Name    : Ahmad Abdulrahem							             */
/* VER     : V01 										             */
/* PurPose :											           	 */  
/*********************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include "GPIO_interface.h" 
#include "SPI_interface.h" 
#include "STK_interface.h"

#include"TFT_interface.h"
#include"TFT_private.h"
#include"TFT_config.h"

/*Ever Command has ID so you send the command ID
 , Some of it has Parametrs
   parameter sends as data 
 */
void HTFT_voidInitialize(void)
{
	/* Send Reset Pulse - tft go sleep mode automatically */
	//(IDLE)low..HIGH(100US)..LOW(1US)..HIGH(100US)..LOW(100US)..HIGH(120MS)....
	GPIO_voidSetPinValue(TFT_RST_PIN,HIGH);
	MSTK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(TFT_RST_PIN,LOW);
	MSTK_voidSetBusyWait(1);
	GPIO_voidSetPinValue(TFT_RST_PIN,HIGH);
	MSTK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(TFT_RST_PIN,LOW);
	MSTK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(TFT_RST_PIN,HIGH);
	MSTK_voidSetBusyWait(120000); 
	/* Send Command - SLPOUT-Sleep out to out of sleep Mode-0x11*/
    voidWritCommand(0x11); 
	/*WAIT 150 MS  */
	MSTK_voidSetBusyWait(150000);
	/*send Command - Color Mode command - ID=0x31
	Then Send the command Parametr(option)
	RGB444  0x03
	RGB565  0x05
	RGB666  0x06
	*/
	voidWritCommand(0x31); /*color mode command*/ 
	voidWritData(0x05);  /*c\Parameter of last command to choose RGB565*/
	/* Display On command - DISPON -ID =0x29 */
    voidWritCommand(0x29);
}
/*this function draw on whole LCD*/
void HTFT_voidDisplayImage(const u16* copy_u16Image)
{ u16 counter=0;
	/*set x address command - ID=0x2A
	 * ARGUMENTS:
	 * start = 2byte   -> 0    0x00
	 * end   = 2byte   ->127   0x7F
	 * */
	 voidWritCommand(0x2A);
	 voidWritData(0x00);    /*START ADDRESS OF X-AXIX*/
	 voidWritData(127);     /*END   ADDRESS OF X-AXIX*/
	
	/*set Y address command - ID=0x2B
	  * ARGUMENTS:
	  * start = 2byte   -> 0    0x00
	  * end   = 2byte   ->159   0x7F */
	 voidWritCommand(0x2B);
	 voidWritData(0x00); /*START ADDRESS OF X-AXIX*/
	 voidWritData(159); /*END   ADDRESS OF X-AXIX*/

	/*RAM WRITE command
	 * this command important before you send to lcd
	 * */
	 voidWritCommand(0x2C);

	 /*****START TO DRAW *****/
	 for (counter=0;counter<2048;counter++)/*160*128 =20480pixels*/
	 {  /*DATA will send in two sending - due to send data function acceptes 8bit variable
	      and data is 16 bit
	     */
		 voidWritData(copy_u16Image[counter]>>8);/*Send HIGH byte */
		 voidWritData(copy_u16Image[counter]);   /*Send LOW  byte */
	 }

}

static void voidWritCommand(u8 copy_u8Command)
{
	u8 Local_u8Temp; 
	/*SET A0 pin of LCD to LOW*/
	GPIO_voidSetPinValue(TFT_A0_PIN,LOW);
	/* Send Command over SPI*/
	MSPI1_voidSendReceiveSynch(copy_u8Command, &Local_u8Temp);
}

static void voidWritData(u8 copy_u8DATA)
{
	u8 Local_u8Temp;
	/*SET A0 pin of LCD to HIGH*/
	GPIO_voidSetPinValue(TFT_A0_PIN,HIGH);
	/* Send DATA over SPI*/
	MSPI1_voidSendReceiveSynch(copy_u8DATA, &Local_u8Temp);
}



