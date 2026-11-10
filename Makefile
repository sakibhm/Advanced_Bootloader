
CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

CFLAGS  = -mcpu=cortex-m4 -mthumb -std=c11 -Wall -Wextra -Iinc -g -O0
LDFLAGS = -T linker_STM32F446.ld -nostdlib

TARGET = build/main

# C source files
C_SOURCES = src/main.c

# Assembly source files
ASM_SOURCES = startup_STM32F446.s

# Convert source filenames into object filenames
C_OBJECTS = $(patsubst src/%.c,build/%.o,$(C_SOURCES))
ASM_OBJECTS = $(patsubst %.s,build/%.o,$(ASM_SOURCES))

OBJECTS = $(C_OBJECTS) $(ASM_OBJECTS)

all: $(TARGET).bin

# Link
$(TARGET).elf: $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

# ELF to binary
$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

# Compile C files
build/%.o: src/%.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

# Compile assembly files
build/%.o: %.s
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build

flash: $(TARGET).bin
	st-flash write $(TARGET).bin 0x08000000

.PHONY: all clean flash
