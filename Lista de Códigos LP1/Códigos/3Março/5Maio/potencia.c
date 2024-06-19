/**
 * @file main.c
 * @brief Programa que realiza operações matemáticas básicas: potenciação, soma e subtração.
 *
 * Este programa permite ao usuário inserir dois números (base e expoente) e realiza as seguintes operações:
 * 1. Potenciação: Calcula a potência da base elevada ao expoente.
 * 2. Soma: Calcula a soma dos dois números inseridos.
 * 3. Subtração: Calcula a diferença entre os dois números, garantindo um resultado não negativo.
 *
 * @author Bruno Costa Queiroz
 * @date 10/05/2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Função que realiza operações de potenciação, soma e subtração.
 *
 * Esta função solicita ao usuário inserir dois números (base e expoente).
 * Em seguida, calcula e imprime o resultado da potência da base elevada ao expoente,
 * a soma dos dois números e a subtração dos números (garantindo um resultado não negativo).
 */
void potencia(void) {
  int a, n, v, w;
  printf("Digite o valor da base: ");
  scanf("%d", &a);
  printf("\nDigite o valor do expoente: ");
  scanf("%d", &n);

  pot(a, n);
  soma(a, n);
  sub(a, n);

  v = a * n;
  printf("\nSe potenciação fosse igual multiplicação seria: %d", v);

  return;
}

/**
 * @brief Função que calcula a potência de um número.
 *
 * Calcula e imprime o resultado da base elevada ao expoente usando a função pow() da biblioteca math.h.
 *
 * @param a Valor da base.
 * @param n Valor do expoente.
 * @return Retorna o resultado da potência (a^n).
 */
int pot(int a, int n) {
  int r = 0;
  r = pow(a, n);
  printf("\nO resultado é: %d", r);
  return r;
}

/**
 * @brief Função que calcula a soma de dois números.
 *
 * Calcula e imprime a soma dos dois números inseridos.
 *
 * @param a Primeiro número.
 * @param n Segundo número.
 */
void soma(int a, int n) {
  int s = 0;
  s = a + n;
  printf("\nA soma dos valores é: %d", s);
}

/**
 * @brief Função que calcula a subtração de dois números.
 *
 * Calcula e imprime a diferença entre os dois números inseridos, garantindo um resultado não negativo.
 *
 * @param a Primeiro número.
 * @param n Segundo número.
 * @return Retorna o resultado da subtração (valor absoluto da diferença entre a e n).
 */
int sub(int a, int n) {
  int u = 0;
  if (a > n) {
    u = a - n;
    printf("\nA subtração de %d por %d é: %d", a, n, u);
    return u;
  } else {
    u = n - a;
    printf("\nA subtração de %d por %d é: %d", n, a, u);
    return u;
  }
}

/**
 * @brief Função principal que inicia a execução do programa.
 *
 * Chama a função potencia para realizar as operações matemáticas com os números inseridos pelo usuário.
 *
 * @return Retorna 0 indicando que o programa foi executado com sucesso.
 */
int main() {
  potencia();
  return 0;
}
