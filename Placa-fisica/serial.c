#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>

#define LED_RED 13  // Definição do pino do LED vermelho

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