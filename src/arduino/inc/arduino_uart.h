#ifndef ARDUINO_UART_H_
#define ARDUINO_UART_H_

#include <stdio.h>
#include <stdint.h>  // Include standard integer type definitions
#include <avr/io.h>

#define UART_BUFFER_SIZE 64

void uart_init();
int uart_put(char c, FILE *stream);  // Changed from uart_putchar
int uart_get(FILE *stream);             // Changed from uart_getchar
void uart_read(uint8_t* buffer);        // Ensure this uses uint8_t

#endif // ARDUINO_UART_H_

