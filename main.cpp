/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"


#define PWM PB_10


#define BTN1 PE_9
#define LED1 PE_11

#define logic00 PE_11

int lot = 0;
InterruptIn button(BTN1);
PwmOut PWM01(PWM);

DigitalOut led(LED1);
DigitalOut flash(LED2);
DigitalOut hi1(logic00);

void flip()
{
    led = !led;
    if(lot == 1)
    {
        lot = 0;
        PWM01.period(0.003);
        PWM01=0.5;
    }
    else {
        lot = 1;
        PWM01.period(0.002);
        PWM01=0.5;
    }
}

int main()
{
    button.mode(PullDown);
    button.rise(&flip);  // attach the address of the flip function to the rising edge
    while (1) 
    {   
        if (lot == 1)
        {
            flash = !flash;
            thread_sleep_for(250);
        }
        
    }
}
