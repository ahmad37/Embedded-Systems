/*********************************************************************/
/* Name    : Ahmad Abdulrahem							             */
/* VER     : V01 										             */
/* PurPose :											           	 */  
/*********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"

void ESP_voidInit(void)
{	
  u8 Local_u8Result=0;

   while(Local_u8Result==0)
   {
     /* Stop Echo from ESP */
     MUSART1_voidTransmite("ATE0\r\n");
     Local_u8Result = u8ESPValidateCommand(); /*when return 1- command sended is true get out of the loop*/
   }
  Local_u8Result=0; /*set variable to 0 again */

   while(Local_u8Result==0)
    {
      /*Set ESP in Station Mode*/	
      MUSART1_voidTransmite("AT+CWMODE=1\r\n");
      Local_u8Result = u8ESPValidateCommand();  
    }	
}

/*Used to Check if the command sends correctly to 
ESP or Not
After Every Command the ESP Must return "OK" 
otherwise the command is not true */
u8 u8ESPValidateCommand(void)
{
  u8 Local_u8Response[100] = {0}; 
  u8 i=0;
  u8 Dummy=0;
  u8 Result =0; 
 
 while (Dummy!=255)/*while the esp not sending any thing*/
   {
    Dummy=MUSART1_u8Receive();
    Local_u8Response[i]=Dummy;
    i++; 
   }
  
  /*Check if Ok */
   if(Local_u8Response[0]=='O' && Local_u8Response[0]=='K' )
	 Result=1; /*received OK respose*/

  return Result; 
}

u8 ESP_ConnectWiFi(u8*wifi_name, u8* wifi_password)
{  u8 Local_u8Result=0; 

	while(Local_u8Result==0)
    {
      /*Set ESP in Station Mode*/	
      MUSART1_voidTransmite("AT+CWJAP="wifi_name","wifi_password",80\r\n");
      Local_u8Result = u8ESPValidateCommand();  
    }
	return Local_u8Result; /*should return 1 every time. due to it will never reach here till it  equal 1  */ 
}

u8 ESP_ConnectServer(u8*server_ip)
{
	u8 Local_u8Result=0; 
	
	while(Local_u8Result==0)
    {
       /*Set ESP in Station Mode*/	
       MUSART1_voidTransmite("AT+CIPSTART="TCP","server_ip",80\r\n");
       Local_u8Result = u8ESPValidateCommand();  
     }
    return Local_u8Result; /*should return 1 every time. due to it will never reach here till it  equal 1  */ 
}

/*to use this function you need to connect to server first*/
u8 ESP_SenDataToServer(u8*server_ip)
{
	u8 Local_u8Result=0; 
	
	/*Send the size of data first */
	while(Local_u8Result==0)
    {
       /*Set ESP in Station Mode*/	
       MUSART1_voidTransmite("AT+CIPSEND=60\r\n");
       Local_u8Result = u8ESPValidateCommand();  
     }
	 Local_u8Result=0; 
	 /*send your data*/
	 while(Local_u8Result==0)
    {
       /*Set ESP in Station Mode*/	
       MUSART1_voidTransmite("GET http://imtarmdiploma.freevar.com/status.txt \r\n");
       Local_u8Result = u8ESPValidateCommand();  
     }
	 
    //return Local_u8Result; /*should return 1 every time. due to it will never reach here till it  equal 1  */ 
}	
	