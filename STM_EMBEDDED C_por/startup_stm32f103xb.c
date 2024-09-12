#include <stdint.h>

#define RAM_START 0x20000000U
#define RAM_SIZE (20*1024)  
#define STACK_START  0x20002800

extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

void main(void);
void LCD_Handler(void);  

void Default_Handler(void)
{
    while (1);
}

void Reset_Handler(void)
{
   
    uint32_t data_size = (uint32_t)&_edata - (uint32_t)&_sdata;
    uint32_t *src = (uint32_t*)&_etext;
    uint32_t *dst = (uint32_t*)&_sdata;
    
    for (uint32_t i = 0; i < data_size; i++) {
        *dst++ = *src++;
    }

 
    data_size = (uint32_t)&_ebss - (uint32_t)&_sbss;
    dst = (uint32_t*)&_sbss;
    
    for (uint32_t i = 0; i < data_size; i++) {
        *dst++ = 0;
    }

 
    main();

    while (1);
}

void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void LCD_Handler(void) __attribute__((weak, alias("Default_Handler")));  


__attribute__((section(".isr_vector")))
uint32_t *isr_vectors[] = {
    (uint32_t*)STACK_START,   
    (uint32_t*)Reset_Handler, 
    (uint32_t*)NMI_Handler,   
    (uint32_t*)HardFault_Handler, 
    (uint32_t*)LCD_Handler    
};
