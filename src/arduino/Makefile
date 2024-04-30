# Project Name: 
# Author: Chandler Scott
# Description: 
# Makefile for building all Arduino projects including direct library compilation

CC = avr-gcc
CFLAGS = -Os -DF_CPU=16000000UL -mmcu=atmega328p
LIB_INC = ../lib/inc
LIB_SRC = $(wildcard ../lib/src/*.c)

.PHONY: all projects clean

all: libs projects

libs:
	$(CC) $(CFLAGS) -I$(LIB_INC) -c $(LIB_SRC)

projects:
	for dir in projects/*; do \
	  $(MAKE) -C $$dir; \
	done

clean:
	rm -f *.o
	for dir in projects/*; do \
	  $(MAKE) -C $$dir clean; \
	done

