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

// Rotina 6 - aciona o buzzer por 2 segundos

// Rotina 7 - sai do modo de execução e habilitar o modo de gravação via software (reboot)


int main() {
    stdio_init_all();  // Inicializar saída padrão (USB/Serial)
    init_leds();

    char buffer[100];  // Buffer para armazenar entradas do terminal

    printf("Por favor, digite:\n");
    printf("'vermelho' = ligar LED vermelho;\n");
    printf("'azul' = ligar LED azul;\n");
    printf("'verde' = ligar LED verde;\n");
    printf("'buzzer' = ligar o buzzer;\n");
    printf("'on' = ligar todos os LEDs (cor branca);\n");
    printf("'off' = desligar todos os LEDs;\n");
    printf("'reboot' = modo de gravacao.\n");

    while (1) {
        // Esperar entrada do terminal
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Remover nova linha do buffer
            buffer[strcspn(buffer, "\n")] = 0;

            // Verificar se a entrada é "vermelho"
            if (strcmp(buffer, "vermelho") == 0) {
                turn_on_red();
                printf("LED vermelho ligado!\n");
            } else if (strcmp(buffer, "azul") == 0) {
                turn_on_blue();
                printf("LED azul ligado!\n");
            } else if (strcmp(buffer, "verde") == 0) {
                turn_on_green;
                printf("LED verde ligado!\n");
            } else if (strcmp(buffer, "buzzer") == 0) {
                // *** chama a funcao do buzzer aqui ***
                printf("Buzzer ligado!\n");
            } else if (strcmp(buffer, "on") == 0) {
                turn_on_leds();
                printf("Todos LEDs ligados!\n");
            } else if (strcmp(buffer, "off") == 0) {
                turn_off_leds();
                printf("Todos LEDs desligados!\n");
            } else if (strcmp(buffer, "reboot") == 0) {
                // ** chama a função aqui ***
            }
        }

        sleep_ms(100);  // Pequeno delay para evitar sobrecarga da CPU
    }

    return 0;
}
