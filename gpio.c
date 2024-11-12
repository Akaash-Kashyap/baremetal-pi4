// definitions for gpio accesses
#include "gpio.h"

volatile unsigned int* gpio;


int GPIO_init(){
    gpio = (unsigned int*) GPIO_BASE;
    return 0;
}

/*
status | function
0 | 000 = GPIO Pin nn is an input
1 | 001 = GPIO Pin nn is an output
4 | 100 = GPIO Pin nn takes alternate function 0
5 | 101 = GPIO Pin nn takes alternate function 1
6 | 110 = GPIO Pin nn takes alternate function 2
7 | 111 = GPIO Pin nn takes alternate function 3
3 | 011 = GPIO Pin nn takes alternate function 4
2 | 010 = GPIO Pin nn takes alternate function 5
*/

int GPIO_start(int pin, int status){

    int bank = pin / 10; // for 0-9 -> 0 | 10-19 -> 1 etc
    if(bank > 4){
        return 1;
    }

    int bank_pin = pin % 10; // 42 -> 2 (3rd set of bits to modify)

    int offset = (3 * bank_pin);
    gpio[bank] = (status << offset); // sets gpio 42 as output (led gpio)
    // gpio[GPFSEL_4] = (1 << 6); // sets gpio 42 as output (led gpio)
    return 0; 
}

int ledOn(){
    gpio[GPCLR_1] = (1 << 10); // clears gpio 42
    return 0;
}

int ledOff(){
    gpio[GPSET_1] = (1 << 10); // sets gpio 42 high
    return 0;
}