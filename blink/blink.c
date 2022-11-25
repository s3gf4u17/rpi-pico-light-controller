/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include "limits.h"
#include <stdio.h>

// int main() {
//     stdio_init_all();
//     int counter = 0;
//     const uint LED_PIN = PICO_DEFAULT_LED_PIN;
//     gpio_init(LED_PIN);
//     gpio_set_dir(LED_PIN, GPIO_OUT);
//     gpio_put(LED_PIN, 1);
//     while (true) {
//         counter = (counter == INT_MAX) ? 0 : ++counter;
//         printf("%i Hello World!\n",counter);
//     }
// }

int main() {
    stdio_init_all();
    int ledStatus = 1;
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 1);

    char buffer[16];

    while (1) {
        scanf("%16s",buffer);
        printf("%s\n",buffer);
        if(ledStatus==1){
            ledStatus=0;
            gpio_put(LED_PIN,0);
        }else{
            ledStatus=1;
            gpio_put(LED_PIN,1);
        }
        sleep_ms(1000);
    }

    return 0;
}