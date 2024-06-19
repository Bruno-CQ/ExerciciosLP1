/**
 * @file main.c
 * @brief Programa para calcular o Máximo Divisor Comum (MDC) de uma lista de números.
 *
 * Este programa permite calcular o MDC de uma lista de números inteiros passados como argumentos ou inseridos pelo usuário.
 * A função principal é mdc(argc, argv[]), que lida com os argumentos e chama calcMDC(a, b) para calcular o MDC de cada par de números.
 * O resultado final é o MDC de todos os números fornecidos.
 *
 * @author Bruno Costa Queiroz
 * @date Data da última modificação: 2024-06-12
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Função para calcular o Máximo Divisor Comum (MDC) de dois números inteiros.
 *
 * Esta função utiliza o algoritmo de Euclides para calcular o MDC de dois números inteiros.
 *
 * @param a Primeiro número inteiro.
 * @param b Segundo número inteiro.
 * @return O MDC dos dois números inteiros dados.
 */
int calcMDC(int a, int b);

/**
 * @brief Função principal para calcular o MDC de uma lista de números inteiros.
 *
 * Esta função verifica os argumentos passados via linha de comando (argc, argv) ou solicita ao usuário que insira os números.
 * Em seguida, calcula o MDC de cada par consecutivo de números na lista e imprime o resultado final.
 *
 * @param argc Número de argumentos passados para o programa.
 * @param argv Vetor de strings que contém os argumentos passados para o programa.
 * @return Retorna 0 se o programa for executado com sucesso.
 */
int mdc(int argc, char *argv[]) {
  int q;
  printf("Quantidade de argumentos -> %s\n", argv[1]);

  if (argc == 2) {
    q = atoi(argv[1]);
  } else if (argc > 2) {
    printf("Muitos argumentos\n");
    return 1;
  } else {
    printf("Entre com um número.\n");
    return 1;
  }

  int v[q];

  for (int i = 0; i < q; i++) {
    printf("Digite o %dº número: ", i + 1);
    scanf("%d", &v[i]);
  }

  for (int i = 0; i < q - 1; i++) {
    int a = v[i], b = v[i + 1];
    v[i + 1] = calcMDC(a, b);
  }

  printf("MDC: %d\n", v[q - 1]);
  return 0;
}

int calcMDC(int a, int b) {
  int r;
  while (b != 0) {
    r = b;
    b = a % b;
    a = r;
  }
  return a;
}
