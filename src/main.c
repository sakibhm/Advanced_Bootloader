#include <stdint.h>
#include "STM32F446.h"
#include "flash.h"


#define APP_BASE 0x08020000

void JumpToApp(void){

    volatile uint32_t app_stack = *(volatile uint32_t *)(APP_BASE);
    volatile uint32_t app_reset = *(volatile uint32_t *)(APP_BASE + 4);

    __asm volatile ("MSR msp, %0" : : "r" (app_stack));

    void(*jump)(void) = (void(*)(void))app_reset;

    jump();

}


int main(void)
{
    
    //JumpToApp();

    flash_erase_sector(SECTOR7);
    flash_erase_sector(SECTOR5);

    flash_write(S7_ADD1, DATA1);
    flash_write(S7_ADD2, DATA2);
    flash_write(S7_ADD3, DATA3);
    flash_write(S7_ADD4, DATA4);

    flash_write(S5_ADD1, DATA1);
    flash_write(S5_ADD2, DATA2);
    flash_write(S5_ADD3, DATA3);
    flash_write(S5_ADD4, DATA4);



    while(1){

    }


    return 0;
}
