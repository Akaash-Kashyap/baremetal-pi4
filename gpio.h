// important definitions


#define GPIO_BASE                   0xFE200000

#define GPFSEL_0 0
#define GPFSEL_1 1
#define GPFSEL_2 2
#define GPFSEL_3 3
#define GPFSEL_4 4

#define GPSET_0 7
#define GPSET_1 8

#define GPCLR_0 10
#define GPCLR_1 11

//https://datasheets.raspberrypi.com/bcm2835/bcm2835-peripherals.pdf page 90

// functions
int GPIO_init();
int GPIO_start(int pin, int status);
int ledOn();
int ledOff();
