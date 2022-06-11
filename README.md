# Configuração do ambiente de desenvolvimento bare metal

Autora: Lesly Montúfar

## Índice 

* [Descrição](#descrição)
* [Preparo do ambiente bare metal de desenvolvimento](#preparo-do-ambiente-bare-metal-de-desenvolvimento)
* [Makefile e startup.c](#makefile-e-startupc) 
* [main.c e linker script](#mainc-e-linker-script) 

## Descrição

Foram seguidos os seguintes passos:

1. Siga os [roteiros anexos](https://github.com/LeslyMontufar/11811ETE001-ATV1/blob/main/roteiros) para instalação e configuração do seu ambiente bare metal de desenvolvimento. 
2. Crie os arquivos básicos do seu primeiro programa (main.c, startup.c, linker script, Makefile). 
3. Teste todo o ambiente.


## Preparo do ambiente bare metal de desenvolvimento

### Instalando a toolchain GCC ARM
Como visto abaixo, a toolchain foi instalada corretamente.

![1](https://github.com/LeslyMontufar/11811ETE001-ATV1/blob/main/img/1.jpeg)

### Instalando as ferramentas de gravação e depuração de código
OpenOCD foi instalado corretamente, como visto na imagem abaixo, e pode ser utilizado com o STLink.

![2](https://github.com/LeslyMontufar/11811ETE001-ATV1/blob/main/img/2.jpeg)

### Utilizando wsl com a IDE Visual Stdio Code
As extensões foram baixadas e agora é possível desenvolver pela IDE Visual Stdio Code.

![3](https://github.com/LeslyMontufar/11811ETE001-ATV1/blob/main/img/3.jpeg)

### Instalando o USBIP no wls2
O driver USB do STLink foi baixado, pois mostrado abaixo, o STLink foi reconhecido. Além disso, o STLink pode ser conectado ao wsl, como visto no PowerShell, em que ele é vinculado ao Ubuntu-20.04. A seguir, vê-se os direito de acesso do dispositivo.

![4](https://github.com/LeslyMontufar/11811ETE001-ATV1/blob/main/img/4.jpeg)

![5](https://github.com/LeslyMontufar/11811ETE001-ATV1/blob/main/img/5.jpeg)

![6](https://github.com/LeslyMontufar/11811ETE001-ATV1/blob/main/img/6.jpeg)

## Makefile e startup.c
O Makefile é utilizado para automatizar o processo de compilação e, assim, evitar repertir comandos extensos inúmeras vezes. Já o startup.c, também no diretório `src/`, é um arquivo de inicialização cujo um de suas papeis é declarar e inicializar a Tabela de Vetores de Interrupção, que foi adaptado para o uC STM32F103. Abaixo, são vistas algumas funções conforme os registros existentes no STM32F103.

![7](https://github.com/LeslyMontufar/11811ETE001-ATV1/blob/main/img/7.jpg)

## main.c e linker script
A diferença no linker script foi mudar "M4" para "M3", já que minha placa usa o Cortex M3. O main.c contém o código de piscar o LED e está na pasta `src/`. Assim, foi gerado os arquivos `blinky.bin` e `blinky.elf` para ser interpretado pelo STM32.

