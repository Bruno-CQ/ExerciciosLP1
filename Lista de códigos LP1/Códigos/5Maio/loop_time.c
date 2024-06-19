/**
 * @file main.c
 * @brief Programa que realiza operações de loop e calcula o tempo de execução para somas e números primos.
 *
 * Este programa permite ao usuário escolher entre duas operações de loop:
 * 1. Soma dos números de 0 até um valor especificado.
 * 2. Soma dos números primos até um valor especificado.
 * Para cada operação, o programa calcula o tempo de execução e imprime o resultado e o tempo.
 * 
 * As funções foram unidas e renomeadas para loop_time, com mudanças para evitar números inválidos até 15/06/2024.
 *
 * @author Bruno Costa Queiroz
 * @date 15/06/2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/**
 * @brief Função que executa a operação de loop escolhida pelo usuário e calcula o tempo de execução.
 *
 * Esta função permite ao usuário escolher entre duas operações de loop:
 * 1. Soma dos números de 0 até um valor especificado.
 * 2. Soma dos números primos até um valor especificado.
 * Solicita o número de loops necessários e garante que seja um número válido (maior ou igual a 0).
 * Calcula o tempo de execução da operação escolhida e imprime o resultado e o tempo de execução.
 *
 * @param a Escolha da operação:
 *          - 1 para calcular a soma dos números de 0 até 100000000.
 *          - Qualquer outro valor para calcular a soma dos números primos até um número especificado pelo usuário.
 */
void loop_time(int a) {
  float time;
  printf("Teste 1\n");

  if (a == 1) {
    time = loop_pa(100000000);
  } else {
    unsigned long int loops;

    printf("Digite o número de loops: ");
    scanf("%ld", &loops);
    while (loops < 0) {
      printf("Número inválido, digite novamente: ");
      scanf("%ld", &loops);
    }

    time = loopzin(loops);
  }
  printf("Tempo: %f\n", time);
}

/**
 * @brief Função que calcula a soma dos números de 0 até um valor especificado.
 *
 * Esta função realiza um loop para somar os números de 0 até um valor especificado (nOfLoop).
 * Calcula o tempo de execução do loop e imprime a soma.
 *
 * @param nOfLoop Valor até o qual os números serão somados.
 * @return Tempo de execução do loop em segundos.
 */
float loop_pa(int nOfLoop) {
  unsigned long int soma = 0;
  float tempo = 0, start, end;
  start = clock();

  for (int i = 0; i < nOfLoop; i++) {
    soma += i;
  }

  end = clock();
  tempo = (end - start) / CLOCKS_PER_SEC;
  printf("Soma: %ld\n", soma);

  return tempo;
}

/**
 * @brief Função que calcula a soma dos números primos até um valor especificado.
 *
 * Esta função realiza um loop para verificar se cada número até nOfLoop é primo.
 * Calcula a soma dos números primos encontrados e o tempo de execução do loop.
 * Imprime a soma dos números primos.
 *
 * @param nOfLoop Valor até o qual os números primos serão somados.
 * @return Tempo de execução do loop em segundos.
 */
float loopzin(int nOfLoop) {
  unsigned long int add = 0;
  float time = 0, start, end;
  start = clock();

  for (int num = 2; num <= nOfLoop; num++) {
    bool primo = true;
    for (int i = 2; i * i <= num; i++) {
      if (num % i == 0) {
        primo = false;
        break;
      }
    }
    if (primo) {
      add += num;
    }
  }

  end = clock();

  time = (end - start) / CLOCKS_PER_SEC;
  printf("Resultado: %ld\n", add);
  return time;
}

/**
 * @brief Função principal que inicia a execução do programa.
 *
 * Chama a função loop_time para iniciar a escolha da operação de loop e calcular o tempo de execução.
 *
 * @return Retorna 0 indicando que o programa foi executado com sucesso.
 */
int main() {
  loop_time(1); // Chamada inicial para testar a operação de soma até 100000000
  return 0;
}
