#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>

#define LED_PIN 13  // Pino do LED

void inicializar_sistema() {
    stdio_init_all();  // Inicializa a saída padrão (USB/Serial)
    gpio_init(LED_PIN);  // Inicializa o pino do LED
    gpio_set_dir(LED_PIN, GPIO_OUT);  // Configura como saída
    gpio_put(LED_PIN, 0);  // Garante que o LED está desligado inicialmente
}

void processar_comando(const char *comando) {
    if (strcmp(comando, "vermelho") == 0) {
        gpio_put(LED_PIN, 1);  // Liga o LED
        printf("LED ativado!\n");
    } else {
        gpio_put(LED_PIN, 0);  // Desliga o LED
        printf("Comando inválido! LED desativado.\n");
    }
}

int main() {
    inicializar_sistema();

    char entrada_usuario[128];  // Buffer para armazenar a entrada

    printf("Use o comando 'vermelho' para ligar o LED.\n");

    while (true) {
        if (fgets(entrada_usuario, sizeof(entrada_usuario), stdin) != NULL) {
            entrada_usuario[strcspn(entrada_usuario, "\n")] = '\0';  // Remove a nova linha
            processar_comando(entrada_usuario);  // Processa o comando digitado
        }

        sleep_ms(50);  // Pequeno delay para otimizar o loop
    }

    return 0;
}
