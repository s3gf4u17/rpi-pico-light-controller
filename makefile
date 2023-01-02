dev: install purge
	@mkdir build
	@cd build && export PICO_SDK_PATH=../pico-sdk && cmake .. && cd micro && make -j4
	@echo 'DONE'

purge:
	@rm -rf build/
	@echo 'DONE'

install:
	@git clone https://github.com/raspberrypi/pico-sdk pico-sdk 2>/dev/null || (cd pico-sdk ; git pull)
	@cd pico-sdk && git submodule update --init