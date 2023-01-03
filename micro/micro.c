#include "pico/stdlib.h"
#include "pico/multicore.h"
#include <stdio.h>

#define CORE_START_FLAG 0
uint CORE_STOP_FLAG = 0;

const uint L_G_PIN = 11;
const uint L_Y_PIN = 13;
const uint L_R_PIN = 14;
const uint MOTION_SENSOR_PIN = 22;

// void motionSensorActive(){
//     multicore_fifo_push_blocking(CORE_START_FLAG);
//     while (true) {
//         if (gpio_get(MOTION_SENSOR_PIN)==1){
//             gpio_put(LED_PIN,1);
//             printf("MOVEMENT DETECTED");
//             sleep_ms(5000);
//         }
//         else{
//             gpio_put(LED_PIN,0);
//         }
//     }
// }

void callTest(){
    const uint time = 500;
    gpio_put(L_G_PIN,0);
    gpio_put(L_Y_PIN,0);
    gpio_put(L_R_PIN,0);

    gpio_put(L_G_PIN,1);
    sleep_ms(time);
    gpio_put(L_G_PIN,0);

    gpio_put(L_Y_PIN,1);
    sleep_ms(time);
    gpio_put(L_Y_PIN,0);

    gpio_put(L_R_PIN,1);
    sleep_ms(time);
    gpio_put(L_R_PIN,0);

    for(int i =0;i<3;i++){
        sleep_ms(time);
        gpio_put(L_G_PIN,1);
        gpio_put(L_Y_PIN,1);
        gpio_put(L_R_PIN,1);
        sleep_ms(time);
        gpio_put(L_G_PIN,0);
        gpio_put(L_Y_PIN,0);
        gpio_put(L_R_PIN,0);
    }
}

int main() {
    stdio_init_all();
    gpio_init(L_G_PIN);
    gpio_init(L_Y_PIN);
    gpio_init(L_R_PIN);
    gpio_init(MOTION_SENSOR_PIN);
    gpio_set_dir(L_G_PIN, GPIO_OUT);
    gpio_set_dir(L_Y_PIN, GPIO_OUT);
    gpio_set_dir(L_R_PIN, GPIO_OUT);
    gpio_set_dir(MOTION_SENSOR_PIN,GPIO_IN);
    gpio_pull_down(L_G_PIN);
    gpio_pull_down(L_Y_PIN);
    gpio_pull_down(L_R_PIN);
    gpio_pull_down(MOTION_SENSOR_PIN);

    //multicore_launch_core1(motionSensorActive);
    //uint32_t g = multicore_fifo_pop_blocking();
    //if (g != CORE_START_FLAG) return 0;

    char buffer[1];

    while (true) {
        scanf("%c",&buffer);
        switch(buffer[0]){
            case '0':{callTest();break;}
            default:{break;}
        }
    }
}