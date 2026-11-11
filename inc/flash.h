#ifndef FLASH_H
#define FLASH_H

#include <stdint.h>

//       FLASH ERASE    //
void flash_unlock(void);
void flash_lock(void);

void flash_wait_busy(void);
void flash_set_psize(uint32_t psize);

void flash_set_EOPIE(void);
void flash_check_EOP(void);
void flash_clear_EOP(void);
void flash_clear_SR(void);
void flash_lock(void);

void flash_erase_sector(uint32_t sector);


//      FLASH WRITE        //

void enable_pg(void);
void disable_pg(void);

void flash_write(uint32_t address, uint32_t data);
#endif