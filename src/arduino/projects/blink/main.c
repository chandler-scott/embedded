#include <avr/io.h>
#include <util/delay.h>

#define LED_1 PB5
#define LED_2 PD4
#define LED_3 PD5

void led_on(){
    // Turn on LED_1
    PORTB ^= (1 << LED_1);
}

void led_off(){
    // Turn off LED_1
    PORTB &= ~(1 << LED_1);
}

int main() {
    // Set LED pins as outputs
    DDRB |= (1 << LED_1);

    // Infinite loop to blink the LEDs
    while (1) {
        led_on();
        _delay_ms(1000); // Delay for 500 milliseconds


        for(int i = 0; i < 4; i++){
            led_off();
            _delay_ms(100); 
            led_on();
            _delay_ms(100);
        }
        led_off();
    }

    return 0;
}

