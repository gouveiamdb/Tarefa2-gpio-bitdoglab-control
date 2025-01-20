## Descrição do Projeto

Este projeto implementa um sistema de controle para LEDs e um buzzer utilizando um Raspberry Pi Pico. A comunicação é feita via USB/Serial, e os comandos são processados para controlar os dispositivos conectados aos pinos GPIO. Este projeto é úteis para aplicações de aprendizado em eletrônica e controle de hardware.

## Funcionalidades

Controle de três LEDs (vermelho, azul e verde);

Controle do buzzer para emitir um som por dois segundos;

Ligação de todos os LEDs simultaneamente (cor branca);

Desliga todos os LEDs.

## Comandos Disponíveis

Digite os seguintes comandos para controlar os dispositivos:

vermelho: Liga o LED vermelho;

azul: Liga o LED azul;

verde: Liga o LED verde;

buzzer: Ativa o buzzer por 2 segundos;

on: Liga todos os LEDs;

off: Desliga todos os LEDs;

## Estrutura do Projeto

serial.c: Arquivo principal que contém a lógica de controle e interação com o usuário.

CMakeLists.txt: Arquivo de configuração para compilação com suporte ao Raspberry Pi Pico.

## Requisitos

Hardware:

Raspberry Pi Pico ou Pico W;

LEDs e resistores compatíveis;

Buzzer piezoelétrico;

Cabos jumper e protoboard.

Software:

CMake (versão mínima: 3.13);

SDK do Raspberry Pi Pico (configurado corretamente);

Compilador C/C++ (compatível com o Pico).

## Configuração e Compilação

Clone este repositório:

git clone <URL_DO_REPOSITORIO>

Navegue até o diretório do projeto:

cd <DIRETORIO>

Crie um diretório de build:

mkdir build && cd build

Configure o projeto com o CMake:

cmake ..

Compile o projeto:

make

Envie o binário para o Raspberry Pi Pico conforme o SDK.

## Execução

Conecte o Raspberry Pi Pico ao computador, abra um terminal serial (ex.: minicom ou IDE suportada) e digite os comandos para interagir com o sistema.

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