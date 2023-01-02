if (TARGET tinyusb_device)
    add_executable(micro
    micro.c
            )

# pull in common dependencies
target_link_libraries(micro
    pico_stdlib
    pico_multicore)

# enable usb output, disable uart output
pico_enable_stdio_usb(micro 1)
pico_enable_stdio_uart(micro 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(micro)

# add url via pico_set_program_url
example_auto_set_url(micro)
elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in the SDK")
endif()