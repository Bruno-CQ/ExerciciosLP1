/**
 * @file main.c
 * @brief Implementação da função para calcular a soma dos números naturais até um dado inteiro.
 * @date 26/03/2024
 * 
 * Este arquivo contém a implementação da função prog_arit. A função calcula a soma dos números
 * naturais até um dado inteiro positivo fornecido pelo usuário. Se o número fornecido for negativo,
 * a função exibe uma mensagem indicando que o número é negativo e retorna imediatamente.
 */

#include <stdio.h>

/**
 * @brief Calcula a soma dos números naturais até um dado inteiro positivo.
 * 
 * A função solicita ao usuário um número inteiro positivo. Se o número fornecido for negativo, a função
 * exibe uma mensagem informando que o número é negativo e retorna imediatamente. Caso contrário, a função
 * calcula a soma dos números naturais de 1 até o número fornecido e exibe o resultado.
 * 
 * @return void
 */
void prog_arit() {
  int valor, pa = 0;

  printf("Digite um número inteiro: ");
  scanf("%d", &valor);

  if (valor < 0) {
    printf("O número digitado é negativo\n");
    return;
  }

  for (int i = 0; i <= valor; i++) {
    pa += i;
  }

  printf("O resultado é %d\n", pa);
  return;
}
