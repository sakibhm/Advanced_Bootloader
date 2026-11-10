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


#endif