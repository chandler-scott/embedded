#include "arduino_uart.h"

#define BUFFER_SIZE 64


int main() {
    // Initialize UART
    uart_init();

    // Use printf and scanf as usual
    printf("Enter a message: \r\n"); // Move cursor to beginning of line and add carriage return

    // Buffer to store the received message
    char receive_buffer[BUFFER_SIZE];
    int index = 0;

    // Loop to receive characters and echo them back
    while (1) {
        // Receive a character
        char received_char = uart_getchar(stdin);

        // If newline or carriage return is received, terminate the message and print it
        if (received_char == '\n' || received_char == '\r') {
            receive_buffer[index] = '\0'; // Terminate the string
            printf("\r\nYou entered: %s\r\n", receive_buffer); // Move to new line after printing
            break;
        }

        // Echo back the character
        uart_putchar(received_char, stdout);

        // Store the character in the buffer
        receive_buffer[index++] = received_char;

        // Check if buffer is full
        if (index >= BUFFER_SIZE - 1) {
            // Terminate the string
            receive_buffer[BUFFER_SIZE - 1] = '\0';
            printf("\r\nMessage buffer full. Aborting input.\r\n");
            break;
        }
    }

    // End of program
    return 0;
}

