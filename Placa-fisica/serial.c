#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>

// Pino GPIO para o buzzer
#define BUZZER_PIN 10

// Pinos GPIO dos LEDs
#define RED_LED 13
#define BLUE_LED 12
#define GREEN_LED 11

// Inicializa os LEDs
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
    gpio_put(RED_LED, false);
    gpio_put(BLUE_LED, false);
    gpio_put(BUZZER_PIN, false);

    gpio_put(GREEN_LED, true);
}

// Rotina 2 - liga o LED azul e desliga demais GPIOs
void turn_on_blue() {
    gpio_put(RED_LED, false);
    gpio_put(GREEN_LED, false);
    gpio_put(BUZZER_PIN, false);

    gpio_put(BLUE_LED, true);
}

// Rotina 3 - liga o LED vermelho e desliga demais GPIOs
void turn_on_red() {
    gpio_put(GREEN_LED, false);
    gpio_put(BLUE_LED, false);
    gpio_put(BUZZER_PIN, false);

    gpio_put(RED_LED, true);
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

// Rotina 6

// Rotina 7


int main() {
    stdio_init_all();  // Inicializar saída padrão (USB/Serial)

    // Configure o LED vermelho como saída
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_put(LED_RED, 0);  // Desligar o LED inicialmente

    char buffer[100];  // Buffer para armazenar entradas do terminal

    printf("Digite 'vermelho' para ligar o LED.\n");

    while (1) {
        // Esperar entrada do terminal
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Remover nova linha do buffer
            buffer[strcspn(buffer, "\n")] = 0;

            // Verificar se a entrada é "vermelho"
            if (strcmp(buffer, "vermelho") == 0) {
                gpio_put(LED_RED, 1);  // Ligar o LED
                printf("LED ligado!\n");
            } else {
                gpio_put(LED_RED, 0);  // Desligar o LED se a palavra não for "vermelho"
                printf("LED desligado!\n");
            }
        }

        sleep_ms(100);  // Pequeno delay para evitar sobrecarga da CPU
    }
    
    return 0;
}
