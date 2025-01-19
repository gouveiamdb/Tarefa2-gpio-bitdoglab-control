#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>

#define LED_VERDE 11     // Pino do LED verde
#define LED_AZUL 12      // Pino do LED azul
#define LED_VERMELHO 13  // Pino do LED vermelho
#define BUZZER 21

void inicializar_sistema() {
    stdio_init_all();  // Inicializa a saída padrão (USB/Serial)
    
// Inicializa e configura os pinos dos LEDs
    gpio_init(LED_VERDE); // Inicializa o pino do LED
    gpio_set_dir(LED_VERDE, GPIO_OUT); // Configura como saída
    gpio_put(LED_VERDE, 0); // Garante que o LED está desligado inicialmente

    gpio_init(LED_AZUL); // Inicializa o pino do LED
    gpio_set_dir(LED_AZUL, GPIO_OUT); // Configura como saída
    gpio_put(LED_AZUL, 0); // Garante que o LED está desligado inicialmente

    gpio_init(LED_VERMELHO); // Inicializa o pino do LED
    gpio_set_dir(LED_VERMELHO, GPIO_OUT); // Configura como saída
    gpio_put(LED_VERMELHO, 0); // Garante que o LED está desligado inicialmente

    // Inicializa e configura o pino do buzzer
    gpio_init(BUZZER); 
    gpio_set_dir(BUZZER, GPIO_OUT);  
    gpio_put(BUZZER, 0);
}

void desligar_todos_os_leds() {
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
}

void processar_comando(const char *comando) {
     if (strcmp(comando, "verde") == 0) {
        desligar_todos_os_leds();
        gpio_put(LED_VERDE, 1);  // Liga o LED verde
        printf("LED verde ativado!\n");
    } 
    else if (strcmp(comando, "azul") == 0) {
        desligar_todos_os_leds();
        gpio_put(LED_AZUL, 1);  // Liga o LED azul
        printf("LED azul ativado!\n");
    } 
    else if (strcmp(comando, "vermelho") == 0) {
        desligar_todos_os_leds();
        gpio_put(LED_VERMELHO, 1);  // Liga o LED vermelho
        printf("LED vermelho ativado!\n");
    } 
    else if (strcmp(comando, "branco") == 0) {
        gpio_put(LED_VERDE, 1);
        gpio_put(LED_AZUL, 1);
        gpio_put(LED_VERMELHO, 1);
        printf("Todos os LEDs ativados (luz branca)!\n");
    } 
    else if (strcmp(comando, "desligar") == 0) {
        desligar_todos_os_leds();
        printf("Todos os LEDs desligados!\n");
    } 
    else if (strcmp(comando, "buzzer") == 0) {
        gpio_put(BUZZER, 1);
        //TESTER ADICIONAR UM PRINTF de BUZZER ATIVADO AQUI.
        sleep_ms(2000);
        gpio_put(BUZZER, 0);
        //TESTER ADICIONAR UM PRINTF de BUZZER DESATIVADO AQUI.
    } 
    else {
        printf("Comando inválido!\n");
    }
}

int main() {
    inicializar_sistema();

    char entrada_usuario[128];  // Buffer para armazenar a entrada

    printf("Comandos disponíveis:\n");
    printf("- 'verde': Liga o LED verde.\n");
    printf("- 'azul': Liga o LED azul.\n");
    printf("- 'vermelho': Liga o LED vermelho.\n");
    printf("- 'branco': Liga todos os LEDs (luz branca).\n");
    printf("- 'desligar': Desliga todos os LEDs.\n");
    printf("- 'buzzer': Ativa o buzzer por 2 segundos.\n");
    //TESTER ADICIONAR AQUI O PRINTF do mesmo estilo do quetem acima só que para o buzzer, o comando para ligar o buzzer é 'buzzer'

    while (true) {
        if (fgets(entrada_usuario, sizeof(entrada_usuario), stdin) != NULL) {
            entrada_usuario[strcspn(entrada_usuario, "\n")] = '\0';  // Remove a nova linha
            processar_comando(entrada_usuario);  // Processa o comando digitado
        }

        sleep_ms(50);  // Pequeno delay para otimizar o loop
    }

    return 0;
}
