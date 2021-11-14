#ifndef CRC_PRIVATE_H
#define CRC_PRIVATE_H

/*Used as an input register when writing new data into the CRC calculator.
Holds the previous CRC calculation result when it is read.*/
#define CRC_DATA_REG_32BIT  *((volatile u32*)0x40023000)
/*Can be used as a temporary storage location for one byte.*/
#define CRC_OUTPUT_DATA_REG_8BIT *((volatile u32*)0x40023004)
/*Resets the CRC calculation unit and sets the data register to 0xFFFF FFFF.
This bit can only be set, it is automatically cleared by hardware*/
#define CRC_CNOTROL_REG     *((volatile u32*)0x40023008)


typedef struct
{
  volatile u32   DR;
  volatile u8    IDR;
           u8    RESERVED0;
           u16   RESERVED1;
  volatile u32   CR;
} CRC_TypeDef;

#define  CRC          ((CRC_TypeDef*)0x40023000)
#define  CRC_CR_RESET ((u8)0x01)  /*!< RESET bit */



#endif
