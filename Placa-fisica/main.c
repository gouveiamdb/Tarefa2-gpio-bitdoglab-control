#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>

// Pinos GPIO dos LEDs
#define RED_LED 13
#define BLUE_LED 12
#define GREEN_LED 11

// Definição de funções
void init_leds();
void turn_on_green();
void turn_on_leds();
void turn_off_leds();


int main() {
    return 0;
}


void init_leds() {
    gpio_init(RED_LED);
    gpio_init(BLUE_LED);
    gpio_init(GREEN_LED);
    gpio_set_dir(RED_LED, GPIO_OUT);
    gpio_set_dir(BLUE_LED, GPIO_OUT);
    gpio_set_dir(GREEN_LED, GPIO_OUT);
}

// Rotina 1 - liga o LED verde e desliga demais GPIOs
void turn_on_green() {
    // função que desliga os outros

    gpio_put(GREEN_LED, true);
}

// Rotina 4 - liga todos os LEDs (luz branca)
void turn_on_leds() {
    gpio_put(RED_LED, true);
    gpio_put(BLUE_LED, true);
    gpio_put(GREEN_LED, true);
}

// Rotina 5 - desliga todos os LEDs
void turn_off_leds() {
    gpio_put(RED_LED, false);
    gpio_put(BLUE_LED, false);
    gpio_put(GREEN_LED, false);
}
