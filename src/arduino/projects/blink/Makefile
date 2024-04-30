# Project Name: 
# Author: Chandler Scott
# Description: 

CC = avr-gcc
CFLAGS = -Os -DF_CPU=16000000UL -mmcu=atmega328p
SRC = main.c  # Or whatever your source files are
OBJ = $(SRC:.c=.o)
TARGET_ELF = $(EMBEDDED_BUILD_DIR)/blink.elf
TARGET_HEX = $(EMBEDDED_BUILD_DIR)/blink.hex  # Add a variable for the .hex file

all: $(TARGET_ELF)  # Change the target to the .hex file

tidy:
	rm -f *.o $(TARGET_ELF)

$(TARGET_ELF): $(OBJ)
	$(CC) $(CFLAGS) -I../../lib/inc -o $@ $^
	avr-objcopy -O ihex $@ $(TARGET_HEX)  # Convert the .elf to .hex after building
	@$(MAKE) tidy

%.o: %.c
	$(CC) $(CFLAGS) -I../../lib/inc -c $<

clean:
	rm -f $(OBJ) $(TARGET_ELF) $(TARGET_HEX)  # Add the .hex file to the clean target

