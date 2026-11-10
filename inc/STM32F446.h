#ifndef STM32F446_H
#define STM32F446_H

#include <stdint.h>

#define FLASH_INTERFACE_REGISTER_BASE 0x40023C00

#define KEY1 0x45670123
#define KEY2 0xCDEF89AB
#define FLASH_PSIZE_32BIT  0b10
#define SECTOR7 0b0111
#define SECTOR5 0b0101

typedef struct{
    volatile uint32_t ACR;
    volatile uint32_t KEYR;
    volatile uint32_t OPTKEYR;
    volatile uint32_t SR;
    volatile uint32_t CR;
    volatile uint32_t OPTCR;
}Flash_TypeDef;

#define FLASH ((Flash_TypeDef*)FLASH_INTERFACE_REGISTER_BASE)

// for temporary use for flash_write operation
#define S7_ADD1 0x08060000
#define S7_ADD2 0x08060004
#define S7_ADD3 0x08060008
#define S7_ADD4 0x0806000C

#define S5_ADD1 0x08020000
#define S5_ADD2 0x08020004
#define S5_ADD3 0x08020008
#define S5_ADD4 0x0802000C

#define DATA1 0x54534554
#define DATA2 0x544F4F42
#define DATA3 0x4D524946
#define DATA4 0x454E4F44




#endif