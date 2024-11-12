//TODO refactor 

// include
#include "kernel.h"
#include "io.h"

volatile unsigned int tim;



void main()
{
    // GPIO_init();
    // // gpio[GPFSEL_4] = (1 << 6); // sets gpio 42 as output (led gpio)
    // GPIO_start(42,1);
    // while(1){
    //     for(tim = 0; tim < 50000; tim++)
    //         ;
    //     ledOn();
    //     for(tim = 0; tim < 50000; tim++)
    //         ;
    //     ledOff();
    // }
    uart_init();
    uart_writeText("Hello World!\n");
    while(1);
}