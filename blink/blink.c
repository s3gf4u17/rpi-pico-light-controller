/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include <stdio.h>

//const uint LED_PIN = PICO_DEFAULT_LED_PIN;

//void lightOn(){gpio_put(LED_PIN,1);}

//void lightOff(){gpio_put(LED_PIN,0);}
const uint LED_PIN = PICO_DEFAULT_LED_PIN;

int main() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    char buffer[1];

    while (1) {
        scanf("%c",&buffer);
        printf("%c",buffer[0]);

        switch(buffer[0]){
            case '1': // turn LED ON
            {
                printf("Light turned on");
                gpio_put(LED_PIN,1);
                break;
            }
            case '0': // turn LED OFF
            {
                printf("Light turned off");
                gpio_put(LED_PIN,0);
                break;
            }
            default:
            {
                // wrong command used 
                printf("Wrong command used");
                break;
            }
        }
        sleep_ms(1000);
    }

    return 0;
}