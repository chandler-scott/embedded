# Project Name: 
# Author: Chandler Scott
# Description: 

CC = avr-gcc
CFLAGS = -Os -DF_CPU=16000000UL -mmcu=atmega328p -I../../lib/inc -I../../inc
SRC = main.c  
OBJ = $(SRC:.c=.o)
TARGET_ELF = $(EMBEDDED_BUILD_DIR)/hello_world.elf
TARGET_HEX = $(EMBEDDED_BUILD_DIR)/hello_world.hex  
UART_SRC = ../../src/arduino_uart.c  # Assuming the UART library source file is named uart.c
UART_OBJ = $(UART_SRC:.c=.o)

all: $(TARGET_ELF)  # Change the target to the .hex file

tidy:
	rm -f *.o $(TARGET_ELF)

$(TARGET_ELF): $(OBJ) $(UART_OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	avr-objcopy -O ihex $@ $(TARGET_HEX)  # Convert the .elf to .hex after building
	@$(MAKE) tidy

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(UART_OBJ): $(UART_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(UART_OBJ) $(TARGET_ELF) $(TARGET_HEX)  # Add the .hex file to the clean target

