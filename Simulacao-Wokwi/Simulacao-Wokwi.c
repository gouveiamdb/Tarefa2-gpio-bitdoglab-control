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
    exibir_mensagem_inicial(); ///< Exibe a mensagem inicial.

    char entrada_usuario[128];  ///< Buffer para armazenar a entrada do usuário.

    while (true) {
        if (fgets(entrada_usuario, sizeof(entrada_usuario), stdin) != NULL) {
            entrada_usuario[strcspn(entrada_usuario, "\n")] = '\0';  ///< Remove o caractere de nova linha.
            processar_comando(entrada_usuario);  ///< Processa o comando digitado.
        }

        sleep_ms(50);  ///< Pequeno delay para otimizar o loop.

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

void exibir_mensagem_inicial() {
    printf("Essa simulação controla um LED e um Buzzer usando comandos digitados.\n");
    printf("Use os seguintes comandos para interagir:\n");
    printf("  - 'vermelho': Liga o LED vermelho.\n");
    printf("  - 'azul': Liga o LED azul.\n");
    printf("  - 'verde': Liga o LED verde.\n");
    printf("  - 'branco': Liga todos os LEDs.\n");
    printf("  - 'buzzer': Emite som no Buzzer por 2 segundos.\n");
    printf("  - 'desligar': Desliga todos os LEDs.\n");
    printf("Qualquer outro comando será considerado inválido e os Leds serão apagados.\n\n");
}

