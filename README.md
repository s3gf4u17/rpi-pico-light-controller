## how to build

    mkdir build
    cd build
    export PICO_SDK_PATH=<path-to-picoSDK>
    cmake ..
    cd blink
    make -j4

## how to run

simply drag blink.uf2 file to rpi booted as mass storage device (hold BOOTSEL)

## python listener

    virtualenv --python=python3 venv
    source venv/bin/activate
    pip install pyserial
    python3 listener.py