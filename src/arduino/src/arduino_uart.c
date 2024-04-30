#include "arduino_uart.h"
#include <avr/io.h>

// Define FILE stream for UART
FILE uart_stream = FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW);

void uart_init() {
    // Redirect standard input/output streams to UART
    stdout = stdin = &uart_stream;

    // Set baud rate to 9600
    UBRR0H = 0;
    UBRR0L = 103;

    // Enable transmitter and receiver
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);

    // Set frame format: 8 data bits, no parity, 1 stop bit
    UCSR0C = (3 << UCSZ00);
}

int uart_putchar(char c, FILE *stream) {
    // Wait for empty transmit buffer
    while (!(UCSR0A & (1 << UDRE0)));

    // Put data into buffer, sends the data
    UDR0 = c;

    return 0;
}

int uart_getchar(FILE *stream) {
    // Wait for data to be received
    while (!(UCSR0A & (1 << RXC0)));

    // Get and return received data from buffer
    return UDR0;
}

