#include "arduino_uart.h"
#include <string.h>

int main() {
    // initialize UART
    uart_init();
    uint8_t receive_buffer[UART_BUFFER_SIZE];

    while(1) {
        printf("Enter a message:\n");
        fflush(stdout);
       // fgets(receive_buffer, UART_BUFFER_SIZE, stdin);
        gets(receive_buffer);
        printf("-- %s\n", receive_buffer);
        fflush(stdout);
    }

    return 0;
}
