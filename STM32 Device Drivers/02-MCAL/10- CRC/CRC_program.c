

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "CRC_interface.h"
#include "CRC_private.h"
#include "CRC_config.h"

/*
CRC_HandleTypeDef hcrc;
MX_CRC_Init();

hcrc.Instance = CRC ;
hcrc.Init.Defaultpoly
*/
  
u32  MCRC_u32CalcBlockCRC(u32 pBuffer[], u32 BufferLength)
{
 //Put 4 bytes through CRC one by one, get the CRC code at end
  u8 i;
  CRC->CR = 1;
  for (i = 0; i < BufferLength; i++) {
   CRC->DR = pBuffer[i];
   }
  //printMsg("%x \n", CRC->DR);
 return CRC->DR;
}

void crc_init(void) {
CRC->CR |= CRC_CR_RESET;   // Reset calculation
}
void MCRC_voidResetDR(void)
{
	/* Reset CRC generator */
	CRC_CNOTROL_REG =(u8)0x01;
}
u32  MCRC_voidCalcCRC(u32 Data)
{
	CRC_DATA_REG_32BIT = Data;
  return (CRC_DATA_REG_32BIT);
}
u32  MCRC_u32GetCRC(void)
{
  return (CRC_DATA_REG_32BIT);
}
void MCRC_voidSetIDRegister(u8 IDValue)
{
	CRC_DATA_REG_32BIT = IDValue;
}






