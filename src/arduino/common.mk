# Arduino make flags
CC = avr-gcc
CFLAGS += -Os -DF_CPU=16000000UL -mmcu=atmega328p -I$(EMBEDDED_ROOT_DIR)/src/arduino/inc -I$(EMBEDDED_ROOT_DIR)/src/lib/inc

PROJECT_NAME := $(shell basename "$(CURDIR)")

SRC = main.c
OBJ = $(SRC:.c=.o)

TARGET_ELF = $(EMBEDDED_BUILD_DIR)/$(PROJECT_NAME).elf
TARGET_HEX = $(EMBEDDED_BUILD_DIR)/$(PROJECT_NAME).hex

ARDUINO_SRC_DIR = $(EMBEDDED_ROOT_DIR)/src/arduino/src
LIB_SRC_DIR = $(EMBEDDED_ROOT_DIR)/src/lib/src

ARDUINO_SRCS = $(wildcard $(ARDUINO_SRC_DIR)/*.c)
LIB_SRCS = $(wildcard $(LIB_SRC_DIR)/*.c)

ARDUINO_OBJS = $(ARDUINO_SRCS:.c=.o)
LIB_OBJS = $(LIB_SRCS:.c=.o)

DEPS = $(ARDUINO_OBJS:.o=.d) $(LIB_OBJS:.o=.d)
