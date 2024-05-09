#include "arduino_uart.h"
#include "log.h"
#include <string.h>

int main() {
    // initialize UART
    uart_init();
    uint8_t receive_buffer[UART_BUFFER_SIZE];

    while(1) {
        print_info("Enter a message:");
        fflush(stdout);
        fgets(receive_buffer, UART_BUFFER_SIZE, stdin);
        print_ack();
        print_info("message received.");
        fflush(stdout);
    }

    return 0;
}
