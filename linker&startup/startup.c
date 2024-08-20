#include<stdio.h>
#include <stdint.h>

#define RAM_START 0x20000000U
#define RAM_SIZE (128*1024)
#define RAM_END  (RAM_START+RAM_SIZE)

#define STACK_START RAM_END

extern  uint32_t _etext;
extern  uint32_t _sdata;
extern  uint32_t _edata;
extern  uint32_t _sbss;
extern  uint32_t _ebss;

void main(void);

void Default_Handler(void)
{
    while(1);
}

void Reset_Handler(void)
{
    //copy .data frome flash to ram
    uint32_t data_size=(uint32_t)&_edata-(uint32_t)&_sdata;
    uint32_t* SRC =(uint32_t*)&_etext;
    uint32_t* DES=(uint32_t*)&_sdata;
    for(uint32_t i=0;i<data_size;i++)
    {
        *DES=*SRC;
        DES++;
        SRC++;
    }

    //reseve memory in ram for .bss
    data_size=(uint32_t)&_ebss-(uint32_t)&_sbss ;
    DES=(uint32_t*)&_sbss;
    for(uint32_t i=0;i<data_size;i++)
    {
        *DES=0u;
    }
    //call main
    main();
    while(1);
}

void NMI_Handler (void)__attribute__((weak,alias("Default_Handler")));

 //uint32_t vec[]  __attribute__(section("isr_victor"))