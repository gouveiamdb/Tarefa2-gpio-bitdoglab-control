## Descrição do Projeto

Este projeto é uma simulação educacional que utiliza o Raspberry Pi Pico para controlar LEDs RGB e um buzzer com base em comandos fornecidos via terminal. O objetivo é demonstrar como interagir com GPIOs em sistemas embarcados de maneira simples e eficaz.

## Funcionalidades
- Controle individual dos LEDs (vermelho, azul e verde);
- Controle simultâneo de todos os LEDs (modo "branco");
- Controle do buzzer para emitir som por 2 segundos;
- Feedback interativo via terminal.

## Comandos Disponíveis
- **`vermelho`**: Liga o LED vermelho.
- **`azul`**: Liga o LED azul.
- **`verde`**: Liga o LED verde.
- **`branco`**: Liga todos os LEDs.
- **`buzzer`**: Ativa o buzzer por 2 segundos.
- **`desligar`**: Desliga todos os LEDs.

## Estrutura do Projeto
- **`Simulacao-Wokwi.c`**: Contém o código principal do projeto;
- **`CMakeLists.txt`**: Arquivo de configuração para compilação do projeto.

## Requisitos
1. **Hardware**:
    - Raspberry Pi Pico ou Pico W;
    - LEDs RGB com resistores;
    - Buzzer piezoelétrico;
    - Protoboard e cabos jumper.

2. **Software**:
    - CMake (versão mínima: 3.13);
    - SDK do Raspberry Pi Pico;
    - Compilador GCC para ARM.

## Configuração e Compilação
1. Clone este repositório:
   ```bash
   git clone <URL_DO_REPOSITORIO>
   ```
2. Navegue até o diretório do projeto:
   ```bash
   cd <DIRETORIO>
   ```
3. Crie um diretório de build:
   ```bash
   mkdir build && cd build
   ```
4. Configure o projeto com CMake:
   ```bash
   cmake ..
   ```
5. Compile o código:
   ```bash
   make
   ```
6. Copie o arquivo binário para o Raspberry Pi Pico:
   ```bash
   cp Simulacao-Wokwi.uf2 /media/<USUARIO>/RPI-RP2
   ```

## Execução
1. Conecte o Raspberry Pi Pico ao computador via USB.
2. Abra um terminal serial (ex.: `minicom`, `PuTTY` ou IDE apropriada).
3. Configure a porta serial para 115200 bps.
4. Envie comandos para interagir com o sistema.

## Exemplo de Saída
- Comando: `verde`
  ```
  Comando registrado com sucesso, LED verde ativado!
  ```
- Comando: `buzzer`
  ```
  Comando registrado com sucesso, Buzzer ativado!
  Buzzer desativado!
  ```
## Vídeo Explicativo
[Assista ao vídeo explicativo clicando aqui.](https://youtu.be/4bupQjVBHUE)

## Autores

Projeto desenvolvido por:
Thiago de Andrade Barros Machado - https://github.com/ThiagoMachado2
Pedro Henrique Ferreira Amorim da Silva - https://github.com/PedroHenriqueFAS
Matheus Gouveia de Deus Bastos - https://github.com/gouveiamdb
Naylane do Nascimento Ribeiro - https://github.com/naylane
Marcelo Barbosa de Almeida  - https://github.com/marcelofainor
Levi Silva Freitas - https://github.com/Lvi01
Alécio Vinicius Oliveira Silva - https://github.com/Al3ci0
Joel Junior Nunes Araujo - https://github.com/eijoeljunior289
Laiza Gordiano - https://github.com/laizagordiano