CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
CFLAGS  = -mcpu=cortex-m4 -mthumb -nostdlib -g -O0

all: build/main.bin

# turn the linked file into a raw binary
build/main.bin: build/main.elf
	$(OBJCOPY) -O binary build/main.elf build/main.bin

# link the object files into one file
build/main.elf: build/main.o build/startup_STM32F446.o linker_STM32F446.ld
	$(CC) $(CFLAGS) -T linker_STM32F446.ld build/main.o build/startup_STM32F446.o -o build/main.elf

# compile each source file
build/main.o: main.c
	mkdir -p build
	$(CC) $(CFLAGS) -c main.c -o build/main.o

build/startup_STM32F446.o: startup_STM32F446.s
	mkdir -p build
	$(CC) $(CFLAGS) -c startup_STM32F446.s -o build/startup_STM32F446.o

clean:
	rm -rf build

flash : build/main.bin
	st-flash write build/main.bin 0x08000000