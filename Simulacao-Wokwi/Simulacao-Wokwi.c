#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>

#define LED_PIN_VERDE 11     ///< Pino conectado ao LED verde.
#define LED_PIN_AZUL 12      ///< Pino conectado ao LED azul.
#define LED_PIN_VERMELHO 13  ///< Pino conectado ao LED vermelho.
#define BUZZER 21            ///< Pino conectado ao buzzer.

/**
 * @brief Inicializa o sistema configurando os pinos e o terminal serial.
 * 
 * Faz a inicialização dos pinos dos LEDs e do buzzer, configurando-os como saída.
 * Também inicializa a saída padrão (USB/Serial) para exibir mensagens ao usuário.
 */
void inicializar_sistema();

/**
 * @brief Processa os comandos recebidos pelo usuário e executa ações correspondentes.
 * 
 * Os comandos válidos são:
 * - 'vermelho': Liga o LED vermelho.
 * - 'azul': Liga o LED azul.
 * - 'verde': Liga o LED verde.
 * - 'branco': Liga todos os LEDs.
 * - 'buzzer': Emite som no Buzzer por 2 segundos.
 * - 'desligar': Desliga todos os LEDs.
 * 
 * @param comando String contendo o comando digitado pelo usuário.
 */
void processar_comando(const char *comando);


/**
 * @brief Simula a entrada de comandos do usuário.
 * 
 * A função executa automaticamente uma sequência de comandos
 * que ativam e desativam os LEDs e o buzzer para simular
 * o comportamento esperado do programa.
 */
void simular_comandos();


/**
 * @brief Exibe a mensagem inicial com as instruções do programa.
 * 
 * Exibe as instruções para o usuário, informando os comandos disponíveis e o que cada um faz.
 */
void exibir_mensagem_inicial();


/**
 * @brief Apaga todos os LEDs conectados.
 * 
 * Desliga todos os LEDs (vermelho, azul e verde) conectados ao microcontrolador.
 */
void desligar_todos_os_leds();


/**
 * @brief Função principal do programa.
 *
 * Inicializa o sistema e entra em um loop infinito para processar os comandos digitados pelo usuário.
 * Utiliza a função fgets para ler a entrada do usuário e chama a função processar_comando para executar a ação correspondente. 
 */
int main() {

    inicializar_sistema(); ///< Inicializa o sistema.

    char entrada_usuario[128];  ///< Buffer para armazenar a entrada do usuário.

    sleep_ms(2000);  ///< Aguarda 2 segundos antes de iniciar a simulação.

    printf("\n");
    printf("\nIniciando simulação de comandos...\n");
    simular_comandos();  ///< Realiza a simulação de comandos.

    return 0;
}

void inicializar_sistema() {
    stdio_init_all();  ///< Inicializa a saída padrão (USB/Serial).
    
    gpio_init(LED_PIN_VERMELHO);  ///< Inicializa o pino do LED vermelho.
    gpio_set_dir(LED_PIN_VERMELHO, GPIO_OUT);  ///< Configura o pino do LED como saída.
    gpio_put(LED_PIN_VERMELHO, 0);  ///< Garante que o LED está desligado inicialmente.

    gpio_init(LED_PIN_AZUL);  ///< Inicializa o pino do LED azul.
    gpio_set_dir(LED_PIN_AZUL, GPIO_OUT);  ///< Configura o pino do LED como saída.
    gpio_put(LED_PIN_AZUL, 0);  ///< Garante que o LED está desligado inicialmente.

    gpio_init(LED_PIN_VERDE);  ///< Inicializa o pino do LED verde.
    gpio_set_dir(LED_PIN_VERDE, GPIO_OUT);  ///< Configura o pino do LED como saída.
    gpio_put(LED_PIN_VERDE, 0);  ///< Garante que o LED está desligado inicialmente.

    gpio_init(BUZZER);  ///< Inicializa o pino do buzzer.
    gpio_set_dir(BUZZER, GPIO_OUT);  ///< Configura o pino do buzzer como saída.
    gpio_put(BUZZER, 0);  ///< Garante que o buzzer está desligado inicialmente.
}

void desligar_todos_os_leds() {
    gpio_put(LED_PIN_VERMELHO, 0);  ///< Desliga o LED vermelho.
    gpio_put(LED_PIN_AZUL, 0);      ///< Desliga o LED azul.
    gpio_put(LED_PIN_VERDE, 0);     ///< Desliga o LED verde.
}

void processar_comando(const char *comando) {
    desligar_todos_os_leds();  ///< Garante que os LEDs estejam apagados antes de executar um novo comando.

    if (strcmp(comando, "verde") == 0) {
        gpio_put(LED_PIN_VERDE, 1);  ///< Liga o LED verde.
        printf("Comando registrado com sucesso, LED verde ativado!\n");
    }
    else if (strcmp(comando, "azul") == 0) {
        gpio_put(LED_PIN_AZUL, 1);  ///< Liga o LED azul.
        printf("Comando registrado com sucesso, LED azul ativado!\n");
    }
    else if (strcmp(comando, "vermelho") == 0) {
        gpio_put(LED_PIN_VERMELHO, 1);  ///< Liga o LED vermelho.
        printf("Comando registrado com sucesso, LED vermelho ativado!\n");
    }
    else if (strcmp(comando, "branco") == 0) {
        gpio_put(LED_PIN_VERMELHO, 1);  ///< Liga o LED vermelho.
        gpio_put(LED_PIN_AZUL, 1);      ///< Liga o LED azul.
        gpio_put(LED_PIN_VERDE, 1);     ///< Liga o LED verde.
        printf("Comando registrado com sucesso, os LEDs foram ativados!\n");
    }
    else if (strcmp(comando, "desligar") == 0) {
        printf("Comando registrado com sucesso, LEDs desativados!\n");
    } 
    else if (strcmp(comando, "buzzer") == 0) {
        gpio_put(BUZZER, 1);  ///< Liga o buzzer.
        printf("Comando registrado com sucesso, Buzzer ativado!\n");
        sleep_ms(2000);  ///< Mantém o buzzer ligado por 2 segundos.
        gpio_put(BUZZER, 0);  ///< Desliga o buzzer.
        printf("Buzzer desativado!\n");
    }
    else {
        printf("Comando inválido! Leds apagados\n");
    }
}


void simular_comandos() {
    const char *comandos[] = {
        "vermelho",
        "azul",
        "verde",
        "branco",
        "buzzer",
        "desligar",
        "comando_invalido"
    };

    size_t numero_comandos = sizeof(comandos) / sizeof(comandos[0]);

    for (size_t i = 0; i < numero_comandos; i++) {
        printf("\nSimulando comando: %s\n", comandos[i]);
        processar_comando(comandos[i]);
        sleep_ms(2000);  ///< Intervalo de 2 segundo entre os comandos.
    }
}
