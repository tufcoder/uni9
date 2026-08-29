# Estrutura de Dados

Usaremos a linguagem de programação C para os exemplos dessa matéria.

## Compiladores

* [Compilador C Online](https://www.onlinegdb.com/online_c_compiler)
* **GCC** (Linux / Windows WSL2)
* **CLANG** (MacOS / Linux)

## Editores de Texto ou IDEs

Escolha livre. Eu estou usando o **neovim**.

## Como Compilar e Executar

```bash
gcc -Wall -Wextra -Werror -pedantic main.c && ./a.out
```

## Conteúdo das Aulas

### Aula 01: Vetores

> **Data:** 2026-08-10

Nesta aula aprendemos sobre os vetores (*arrays*) fixos com um programa de cálculo de média de notas.

* Demonstração de **testes de mesa**.
* **Tipos de dados abordados:** `int` e `float`.
* **Funções de I/O:**
   * **stdio.h**: `printf` e `scanf`.
* [Ver código da Aula 01](./aula01-2026-08-10/main.c).

### Aula 02: Continuação de Vetores

> **Data:** 2026-08-17

Continuando os exercícios sobre Vetores em C.

* [ex01.c](./aula02-2026-08-17/ex01.c) - Programa para varrer um vetor de inteiros e achar o maior valor e imprimir o seu índice.
* [ex02.c](./aula02-2026-08-17/ex02.c) - Programa para varrer um vetor de inteiros e achar o menor valor e imprimir o seu índice.
* [ex03.c](./aula02-2026-08-17/ex03.c) - Programa para varrer um vetor de inteiros e multiplicar o valor de cada elemento por 10.
* Exemplos do professor dos exercícios acima.
    * [prof01.c](./aula02-2026-08-17/prof01.c)
    * [prof02.c](./aula02-2026-08-17/prof02.c)
    * [prof03.c](./aula02-2026-08-17/prof03.c)
* Atividades para entrega
   * [atv01.c](./aula02-2026-08-17/atv01.c) - Programa para concatenar dois vetores de inteiros de 10 elementos em um terceiro vetor de 20 elementos e printar o terceiro vetor com todos os elementos.
   * [atv02.c](./aula02-2026-08-17/atv02.c) - Programa para varrer um vetor de inteiros e encontrar o maior elemento.
   * [atv03.c](./aula02-2026-08-17/atv03.c) - Programa para ler dois inteiros A e B e calcular a diferença entre B e A e printar os valores de A até B.
   * [atv04.c](./aula02-2026-08-17/atv04.c) - Programa para calcular a comissão de vendas de 10% e bônus de R$ 50,00 caso as vendas ultrapassem R$ 1000,00.

### Aula 03: Matrizes

> **Data:** 2026-08-24

Nesta aula foi demonstrado o uso de uma matriz em um exercício de Farmácia e outro exercício para
calculo de médias e índices.

* [prof01.c](./aula03-2026-08-24/prof01.c) - Exemplo do professor sobre matriz com um programa que armazena a nota de vários alunos.
* [ex01.c](./aula03-2026-08-24/ex01.c) - Programa para armazenar e calcular o estoque de uma Farmácia.
* [ex01v2.c](./aula03-2026-08-24/ex01v2.c) - Programa alternativo ao ex01.c
