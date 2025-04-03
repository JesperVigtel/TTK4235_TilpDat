#include <stdint.h>

#define GPIO ((NRF_GPIO_REGS*)0x50000000) // Base address for GPIO module

typedef struct {
    volatile uint32_t RESERVED0[321]; // Reserved space to align with OUT register
    volatile uint32_t OUT;           // Output register
    volatile uint32_t OUTSET;        // Set output register
    volatile uint32_t OUTCLR;        // Clear output register
    volatile uint32_t IN;            // Input register
    volatile uint32_t DIR;           // Direction register
    volatile uint32_t DIRSET;        // Set direction register
    volatile uint32_t DIRCLR;        // Clear direction register
    volatile uint32_t LATCH;         // Latch register
    volatile uint32_t DETECTMODE;    // Detect mode register
    volatile uint32_t RESERVED1[118]; // Reserved space to align with PIN_CNF
    volatile uint32_t PIN_CNF[32];   // Pin configuration registers
} NRF_GPIO_REGS;

void button_init() {
    // Configure BUTTON 1 (P0.13) and BUTTON 2 (P0.14) as inputs with pull-up resistors
    GPIO->PIN_CNF[13] = (0 << 0) | (3 << 2); // Input, pull-up
    GPIO->PIN_CNF[14] = (0 << 0) | (3 << 2); // Input, pull-up
}

int main(void) {
    // Configure LED Matrix (P0.17 to P0.20)
    for (int i = 17; i <= 20; i++) {
        GPIO->DIRSET = (1 << i);   // Set pin as output
        GPIO->OUTCLR = (1 << i);   // Turn off LED (active low)
    }

    // Configure buttons
    button_init();

    int sleep = 0;
    while (1) {
        if ((GPIO->IN & (1 << 13)) == 0) { // BUTTON 1 pressed (active low)
            for (int i = 17; i <= 20; i++) {
                GPIO->OUTCLR = (1 << i); // Turn on LEDs (active low)
            }
        } else if ((GPIO->IN & (1 << 14)) == 0) { // BUTTON 2 pressed (active low)
            for (int i = 17; i <= 20; i++) {
                GPIO->OUTSET = (1 << i); // Turn off LEDs
            }
        }

        // Simple delay
        sleep = 10000;
        while (--sleep);
    }

    return 0;
}