#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>


/**
 * @brief GPIO pin configuration for buzzer and LEDs.
 */
#define BUZZER_PIN 10 ///< GPIO pin for the buzzer.
#define RED_LED 13    ///< GPIO pin for the red LED.
#define BLUE_LED 12   ///< GPIO pin for the blue LED.
#define GREEN_LED 11  ///< GPIO pin for the green LED.


// Function prototypes
/**
 * @brief Initializes the GPIO pins for the LEDs.
 */
void init_leds();

/**
 * @brief Turns on the green LED and turns off other outputs.
 */
void turn_on_green();

/**
 * @brief Turns on the blue LED and turns off other outputs.
 */
void turn_on_blue();

/**
 * @brief Turns on the red LED and turns off other outputs.
 */
void turn_on_red();

/**
 * @brief Turns on all LEDs to produce white light.
 */
void turn_on_leds();

/**
 * @brief Turns off all LEDs.
 */
void turn_off_leds();

/**
 * @brief Initializes the GPIO pin for the buzzer.
 */
void init_buzzer();

/**
 * @brief Activates the buzzer for 2 seconds.
 */
void beep_buzzer();

/**
 * @brief Prints the instructions for using the program.
 */
void print_instructions();

/**
 * @brief Main program entry point.
 *
 * Initializes peripherals and processes user input to control LEDs and buzzer.
 *
 * @return int Exit status of the program (always 0).
 */
int main() {
    stdio_init_all();  // Initialize USB/serial communication.
    init_leds();       // Initialize LED GPIO pins.
    init_buzzer();     // Initialize buzzer GPIO pin.

    char buffer[100];  // Buffer for storing user input.

    print_instructions();

    while (1) {
        // Wait for user input.
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            buffer[strcspn(buffer, "\n")] = 0;  // Remove trailing newline.

            if (strcmp(buffer, "vermelho") == 0) {
                turn_on_red();
                printf("LED vermelho ligado!\n");
            } else if (strcmp(buffer, "azul") == 0) {
                turn_on_blue();
                printf("LED azul ligado!\n");
            } else if (strcmp(buffer, "verde") == 0) {
                turn_on_green();
                printf("LED verde ligado!\n");
            } else if (strcmp(buffer, "buzzer") == 0) {
                beep_buzzer();
                printf("Buzzer ligado!\n");
            } else if (strcmp(buffer, "on") == 0) {
                turn_on_leds();
                printf("Todos LEDs ligados!\n");
            } else if (strcmp(buffer, "off") == 0) {
                turn_off_leds();
                printf("Todos LEDs desligados!\n");
            } else {
                printf("Comando inválido. Tente novamente.\n");
            }
        }

        sleep_ms(100);  // Delay to avoid CPU overload.
    }

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


void turn_on_green() {
    gpio_put(RED_LED, false);
    gpio_put(BLUE_LED, false);
    gpio_put(BUZZER_PIN, false);
    gpio_put(GREEN_LED, true);
}

/**
 * @brief Turns on the blue LED and turns off other outputs.
 */
void turn_on_blue() {
    gpio_put(RED_LED, false);
    gpio_put(GREEN_LED, false);
    gpio_put(BUZZER_PIN, false);
    gpio_put(BLUE_LED, true);
}

/**
 * @brief Turns on the red LED and turns off other outputs.
 */
void turn_on_red() {
    gpio_put(GREEN_LED, false);
    gpio_put(BLUE_LED, false);
    gpio_put(BUZZER_PIN, false);
    gpio_put(RED_LED, true);
}

/**
 * @brief Turns on all LEDs to produce white light.
 */
void turn_on_leds() {
    gpio_put(RED_LED, true);
    gpio_put(BLUE_LED, true);
    gpio_put(GREEN_LED, true);
}

/**
 * @brief Turns off all LEDs.
 */
void turn_off_leds() {
    gpio_put(RED_LED, false);
    gpio_put(BLUE_LED, false);
    gpio_put(GREEN_LED, false);
}

/**
 * @brief Initializes the GPIO pin for the buzzer.
 */
void init_buzzer() {
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
    gpio_put(BUZZER_PIN, false);
}

/**
 * @brief Activates the buzzer for 2 seconds.
 */
void beep_buzzer() {
    gpio_put(BUZZER_PIN, true);
    sleep_ms(2000);
    gpio_put(BUZZER_PIN, false);
}

/**
 * @brief Prints the instructions for using the program.
 */
void print_instructions() {
    printf("Por favor, digite:\n");
    printf("'vermelho' = ligar LED vermelho;\n");
    printf("'azul' = ligar LED azul;\n");
    printf("'verde' = ligar LED verde;\n");
    printf("'buzzer' = ligar o buzzer;\n");
    printf("'on' = ligar todos os LEDs (cor branca);\n");
    printf("'off' = desligar todos os LEDs;\n");
    printf("'reboot' = modo de gravação.\n");
}
