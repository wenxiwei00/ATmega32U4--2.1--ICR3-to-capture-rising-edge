/* Name: main.c
 * Author: WENXI WEI
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include "MEAM_general.h"
#include "m_usb.h"

#define PRINTNUM(x) m_usb_tx_uint(x); m_usb_tx_char(10); m_usb_tx_char(13)
#define INPUT_CAPTURE_PIN PC7 // Use ICP1 pin for input capture (you may need to change this)

volatile uint16_t capturedValue = 0;


ISR(TIMER3_CAPT_vect) {
    capturedValue = ICR3; // Store captured value
}

void setup() {
    // Set input capture pin as input with pull-up enabled
    DDRC &= ~(1 << INPUT_CAPTURE_PIN);
    PORTC |= (1 << INPUT_CAPTURE_PIN);

    // Set Timer/Counter3 for input capture
    TCCR3B = (1 << CS32) | (1 << CS30) | (1 << ICES3); // Set prescaler to 1024 and rising edge

    TIMSK3 = (1 << ICIE3); // Enable input capture interrupt

    sei(); // Enable global interrupts
}


int main() {
    setup();
    m_usb_init(); // Initialize USB transmission
    while (1) {
        PRINTNUM(capturedValue);
        _delay_ms(10); // Wait for 10ms      
    }
    return 0;
}


