#include "pico/stdlib.h"
#include "pico/multicore.h"
#include <stdio.h>

#define CORE_START_FLAG 0
uint CORE_STOP_FLAG = 0;

const uint LED_PIN_GREEN = 0;
const uint LED_PIN_YELLOW = 0;
const uint LED_PIN_RED = 0;
const uint LED_PIN = 5;
const uint MOTION_SENSOR_PIN = 22;

void core1entry(){
    multicore_fifo_push_blocking(CORE_START_FLAG);
    while (true) {
        if (gpio_get(MOTION_SENSOR_PIN)==1){
            gpio_put(LED_PIN,1);
            printf("MOVEMENT DETECTED");
            sleep_ms(5000);
        }
        else{
            gpio_put(LED_PIN,0);
        }
    }
}

int main() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(MOTION_SENSOR_PIN);
    gpio_set_dir(MOTION_SENSOR_PIN,GPIO_IN);
    gpio_pull_down(MOTION_SENSOR_PIN);

    multicore_launch_core1(core1entry);

    uint32_t g = multicore_fifo_pop_blocking();

    if (g != CORE_START_FLAG) return 0;

    char buffer[1];

    while (true) {
        scanf("%c",&buffer);
        printf("buffer read OK : %c",buffer);
    }
}