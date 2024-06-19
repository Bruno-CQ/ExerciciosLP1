/**
 * @file main.c
 * @brief Implementação da função para realizar operações aritméticas com dois números inteiros.
 * @date 26/03/2024
 * 
 * Este arquivo contém a implementação da função q_opr2. A função solicita dois números inteiros
 * ao usuário e realiza diversas operações aritméticas com esses números, exibindo os resultados.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Realiza operações aritméticas com dois números inteiros.
 * 
 * A função solicita ao usuário dois números inteiros (a e b) e realiza as seguintes operações:
 * - Soma de a e b em hexadecimal.
 * - Multiplicação de a e b em octal.
 * - Módulo da diferença entre a e b em decimal.
 * - Divisão de a por b em decimal, se b for diferente de zero. Caso contrário, exibe uma mensagem de erro.
 * 
 * @return void
 */
void q_opr2() {
  int a, b, c;

  printf("Digite dois números inteiros: ");
  scanf("%d %d", &a, &b);
  printf("a = %d, b = %d\n", a, b);

  c = a + b;
  printf("a mais b em hexadecimal é igual a %x\n", c);

  c = a * b;
  printf("a vezes b em octal é igual a %o\n", c);

  c = abs(a - b);
  printf("O módulo de a menos b em decimal é igual a %d\n", c);

  if (b != 0) {
    c = a / b;
    printf("a dividido por b em decimal é igual a %d\n", c);

    (a % b == 0) ? printf("a é dividido de forma exata por b\n") : printf("a não é dividido de forma exata por b\n");
  } else {
    printf("Não é possível dividir por zero\n");
  }
  return;
}
