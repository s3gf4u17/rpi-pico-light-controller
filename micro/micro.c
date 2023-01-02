/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include <stdio.h>

#define CORE_TEST_FLAG 123

const uint LED = 5;

const uint MOTION_SENSOR = 22;

void core1entry(){
    multicore_fifo_push_blocking(CORE_TEST_FLAG);
    while (true) {
        if (gpio_get(MOTION_SENSOR)==1){
            gpio_put(LED,1);
            printf("MOVEMENT DETECTED");
            sleep_ms(5000);
        }
        else{
            gpio_put(LED,0);
        }
    }
}

int main() {
    stdio_init_all();
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);

    gpio_init(MOTION_SENSOR);
    gpio_set_dir(MOTION_SENSOR,GPIO_IN);
    gpio_pull_down(MOTION_SENSOR);

    multicore_launch_core1(core1entry);

    uint32_t g = multicore_fifo_pop_blocking();

    if (g != CORE_TEST_FLAG) return 0;

    char buffer[1];

    while (true) {
        scanf("%c",&buffer);
        printf("buffer read OK : %c",buffer);
    }
}