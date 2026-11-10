#include <stdint.h>


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
    
    JumpToApp();
    
}
