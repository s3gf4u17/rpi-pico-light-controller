## how to build

    mkdir build
    cd build
    export PICO_SDK_PATH=<path-to-picoSDK>
    cmake ..
    cd blink
    make -j4

## how to run

simply drag blink.uf2 file to rpi booted as mass storage device (hold BOOTSEL)