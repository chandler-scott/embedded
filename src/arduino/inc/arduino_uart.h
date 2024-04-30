#ifndef ARDUINO_UART_H_
#define ARDUINO_UART_H_

#include <stdio.h>
#include <avr/io.h>

void uart_init();
int uart_putchar(char c, FILE *stream);
int uart_getchar(FILE *stream);

#endif /* ARDUINO_UART_H_ */

