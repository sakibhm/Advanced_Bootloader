#include "STM32F446.h"
#include <stdint.h>

void flash_unlock(void){

    FLASH->KEYR = KEY1;
    FLASH->KEYR = KEY2;
}

void flash_lock(void){

    FLASH->CR = (1 << 31); 
}

void flash_wait_busy(void){

    while(FLASH->SR & (1 << 16)){
        
    }

}

void flash_set_psize(uint32_t psize){

    FLASH->CR &= ~(0b11 << 8);
    FLASH->CR |= (psize << 8);

}

void flash_set_EOPIE(void){
    FLASH->CR |= (1 << 24);
}

void flash_check_EOP(void){

    while(!(FLASH->SR & (1 << 0)))
    {

    }

}

void flash_clear_EOP(void){
    FLASH->SR = (1U << 0); //acknowledge EOP
}

void flash_clear_SR(void){
    FLASH->CR &= ~(0b1 << 1);  // Clear SER
    FLASH->CR &= ~(0b1111 << 3); // Clear SNB
}



void flash_erase_sector(uint32_t sector, uint32_t psize){

    flash_unlock();
    flash_wait_busy();
    flash_set_psize(psize);
    flash_set_EOPIE();

    //Sector erase activated.
    FLASH->CR |= (1<<1); 

    //select flash sector
    FLASH->CR &= ~(0b1111 << 3);
    FLASH->CR |= (sector << 3);

    //set STRT bit
    FLASH->CR |= (1 << 16);

    flash_wait_busy();
    flash_check_EOP();
    flash_clear_EOP();

    flash_clear_SR();

    flash_lock();



}

void enable_pg(void){
    FLASH->CR |= (1 << 0);
}


void disable_pg(void){
    FLASH->CR &= ~(1 << 0);
}

void flash_write(uint32_t address, uint32_t data){

    flash_unlock();
    flash_wait_busy();
    enable_pg();
    flash_set_psize(FLASH_PSIZE_32BIT); 
    flash_set_EOPIE();

    *(volatile uint32_t *)address = data;

    flash_wait_busy();
    flash_check_EOP();
    flash_clear_EOP();

    flash_clear_SR();

    disable_pg();

    flash_lock();

}