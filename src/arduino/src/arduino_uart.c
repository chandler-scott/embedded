#include "arduino_uart.h"
#include <avr/io.h>

// Define FILE stream for UART
FILE uart_stream = FDEV_SETUP_STREAM(uart_put, uart_get, _FDEV_SETUP_RW);

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

int uart_put(char c, FILE *stream) {
    // Wait for empty transmit buffer
    while (!(UCSR0A & (1 << UDRE0)));

    // Put data into buffer, sends the data
    UDR0 = (uint8_t)c;

    return 0;
}

int uart_get(FILE *stream) {
    // Wait for data to be received
    while (!(UCSR0A & (1 << RXC0)));

    // Get and return received data from buffer
    return UDR0;
}

void uart_read(uint8_t* buffer) {
    int index = 0;
    while (1) {
        uint8_t received_byte = (uint8_t)uart_get(stdin);  // Cast the return value

        // Handle newline or carriage return
        if (received_byte == '\n' || received_byte == '\r') {
            buffer[index] = '\0';  // Null-terminate the string
            break;
        }

        // Echo received byte
        uart_put(received_byte, stdout);

        // Store the byte
        buffer[index++] = received_byte;

        // Check if buffer is about to overflow
        if (index >= UART_BUFFER_SIZE - 1) {
            buffer[UART_BUFFER_SIZE - 1] = '\0';
            break;
        }
    }
    printf("\r\n");
}

