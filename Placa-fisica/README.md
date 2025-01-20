# README

## Descrição do Projeto

Este projeto é um sistema interativo que controla LEDs e um buzzer utilizando o Raspberry Pi Pico. A comunicação com o dispositivo é realizada via USB/serial, permitindo o envio de comandos pelo terminal para acionar os dispositivos conectados aos pinos GPIO. O projeto é ideal para estudantes e entusiastas de eletrônica.

## Funcionalidades
- Controle individual dos LEDs vermelho, azul e verde;
- Controle do buzzer para emitir som por dois segundos;
- Liga e desliga todos os LEDs simultaneamente.

## Comandos Disponíveis
- **`vermelho`**: Liga o LED vermelho.
- **`azul`**: Liga o LED azul.
- **`verde`**: Liga o LED verde.
- **`buzzer`**: Ativa o buzzer por 2 segundos.
- **`on`**: Liga todos os LEDs.
- **`off`**: Desliga todos os LEDs.

## Estrutura do Projeto
- **`serial.c`**: Contém o código principal para controle dos dispositivos.
- **`CMakeLists.txt`**: Arquivo de configuração para compilação no Raspberry Pi Pico.

## Requisitos
1. **Hardware**:
    - Raspberry Pi Pico ou Pico W;
    - LEDs e resistores adequados;
    - Buzzer piezoelétrico;
    - Protoboard e cabos jumper.

2. **Software**:
    - CMake (versão mínima: 3.13);
    - SDK do Raspberry Pi Pico;
    - Compilador compatível (ex.: GCC para ARM).

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
4. Configure o projeto usando o CMake:
   ```bash
   cmake ..
   ```
5. Compile o código:
   ```bash
   make
   ```
6. Copie o binário gerado para o Raspberry Pi Pico:
   ```bash
   cp serial.uf2 /media/<USUARIO>/RPI-RP2
   ```

## Execução
1. Conecte o Raspberry Pi Pico ao computador via USB.
2. Abra um terminal serial (ex.: `minicom`, `PuTTY` ou terminal embutido em IDEs).
3. Configure a porta serial para 115200 bps.
4. Envie os comandos listados para interagir com o sistema.

## Exemplo de Saída
Ao enviar o comando `vermelho`, o terminal retorna:
```
LED vermelho ligado!
```
Para o comando `buzzer`:
```
Buzzer ligado!
```
## Vídeo Explicativo
[Assista ao vídeo explicativo clicando aqui.](https://youtu.be/8GTAyxUcUm8)

## Autor
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