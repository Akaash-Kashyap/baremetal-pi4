# baremetal-pi4
Learning how to write baremetal code on a raspberry pi

Using guide from 
https://www.rpi4os.com/

Guide on serial communication
https://learn.sparkfun.com/tutorials/serial-communication/all

Datasheet on the raspberry pi
https://datasheets.raspberrypi.com/bcm2711/bcm2711-peripherals.pdf
More info on raspberry pi stuff
https://www.raspberrypi.com/documentation/computers/raspberry-pi.html


Currently finished part 3

TODO: read and understand the code we added in from io.c

Goals:

1. LED Blinking (somewhat done needs refinement)

    Goal: Get an onboard or external LED to blink using direct register manipulation.
    Learning: Basic GPIO control, working with registers, timing, and delays without using OS abstractions.

2. UART Communication (done but need to understand it better)

    Goal: Set up UART for serial communication between the Raspberry Pi and a computer.
    Learning: Understand UART registers, configure baud rates, and handle character transmission.

3. Simple Bootloader

    Goal: Write a basic bootloader that loads and runs a simple program.
    Learning: Get familiar with the Raspberry Pi’s boot sequence, ARM assembly, and memory layout.
    https://github.com/s-matyukevich/raspberry-pi-os/blob/master/docs/lesson01/linux/kernel-startup.md
    https://developer.arm.com/documentation/ka002218/latest/
    https://www.youtube.com/watch?v=XpFsMB6FoOs

    looks like most of raspberry pi's firmware is proprietary, not sure how to overwrite the EEPROM boot
    loader and what i would write to it .

4. Implementing a Timer

    Goal: Configure a timer to toggle an LED or generate an interrupt.
    Learning: Work with timer registers, timing control, and potentially the basics of interrupt handling.

5. GPIO Button and Interrupts

    Goal: Set up a GPIO button and use interrupts to detect when it’s pressed.
    Learning: Use GPIO registers, handle debouncing, configure interrupts, and understand interrupt handling routines.

6. Display Text on HDMI (Framebuffer)

    Goal: Display basic text or shapes on an HDMI display by directly writing to the framebuffer.
    Learning: Work with the GPU to allocate framebuffer memory, understand video registers, and create basic graphics.

7. SPI Communication

    Goal: Use the SPI protocol to communicate with an external sensor or another device.
    Learning: SPI setup, data transfer registers, clock configuration, and peripheral interfacing.

8. Implement a Simple Scheduler

    Goal: Write a minimal task scheduler that can manage a few basic tasks (e.g., LED blinking, UART communication).
    Learning: Task switching, basic context saving, and understanding of cooperative multitasking.
