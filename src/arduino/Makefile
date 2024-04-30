# Project Name: 
# Author: Chandler Scott
# Description: 
# Makefile for building all Arduino projects including direct library compilation
CC = avr-gcc
CFLAGS = -Os -DF_CPU=16000000UL -mmcu=atmega328p
LIB_INC = ../lib/inc  # Include the parent directory of the library header files
LIB_SRC = $(wildcard ../lib/src/*.c)
ARDUINO_INC = inc
PROJECTS_DIR = projects

# Define all projects
PROJECTS = $(wildcard $(PROJECTS_DIR)/*)

# Object files directory
OBJ_DIR = obj

# Compile all source files in LIB_SRC and OBJ_DIR
LIB_OBJ := $(patsubst ../lib/src/%.c,$(OBJ_DIR)/lib/%.o,$(LIB_SRC))

# Include dependency files
-include $(LIB_OBJ:.o=.d)

.PHONY: all clean

all: $(LIB_OBJ) $(PROJECTS)

tidy:
	rm -rf $(OBJ_DIR)

# Compile libraries
$(OBJ_DIR)/lib/%.o: ../lib/src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(ARDUINO_INC) -I$(LIB_INC) -MMD -MP -c $< -o $@

# Build each project
$(PROJECTS): $(LIB_OBJ)
	$(MAKE) -C $@
	@$(MAKE) tidy


clean:
	rm -rf $(OBJ_DIR)/*
	for dir in $(PROJECTS); do \
		$(MAKE) -C $$dir clean; \
	done

