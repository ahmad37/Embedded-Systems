#ifndef CRC_INTERFACE_H
#define CRC_INTERFACE_H


void MCRC_voidSetIDRegister(u8 IDValue);
u32  MCRC_u32GetCRC(void);
u32  MCRC_voidCalcCRC(u32 Data);
void MCRC_voidResetDR(void);

void crc_init(void);

#endif
