#include "arduino_uart.h"

int main() {
    // Initialize UART
    uart_init();
    uint8_t receive_buffer[UART_BUFFER_SIZE];

    while(1) {
        // Use printf and scanf as usual
        printf("Enter a message:\r\n"); 

        // uart_read(receive_buffer);
        gets(receive_buffer);
        printf("-- %s\n", receive_buffer);
    }

    // End of program
    return 0;
}

