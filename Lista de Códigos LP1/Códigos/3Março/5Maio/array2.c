/**
 * @file main.c
 * @brief Programa que demonstra o uso de argumentos de linha de comando para manipular vetores.
 *
 * Este programa recebe um argumento de linha de comando que determina o tamanho de um vetor.
 * Em seguida, preenche o vetor com valores crescentes, calcula a soma dos elementos e a média,
 * e imprime esses resultados na tela.
 *
 * @author Bruno Costa Queiroz
 * @date 13/05/2024
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Função que recebe um argumento de linha de comando para definir o tamanho de um vetor.
 *
 * Esta função recebe um argumento de linha de comando que especifica o tamanho do vetor a ser criado.
 * Preenche o vetor com valores crescentes começando de 0 até n-1.
 * Calcula a soma dos elementos e a média, e imprime esses resultados na tela.
 *
 * @param argc Número de argumentos de linha de comando.
 * @param argv Vetor de strings contendo os argumentos de linha de comando.
 *             O primeiro argumento é esperado ser o tamanho do vetor.
 * @return Retorna 0 se executado com sucesso, -1 se nenhum argumento for passado.
 */
int array2( int argc, char *argv[] ) {
  if (argc <= 1) {
    printf("Sem argumentos...\n");
    return -1;
  }
  int n = atoi(argv[1]);
  int v[n];

  for (int i = 0; i < n; i++)
    v[i] = i;

  int soma = 0;
  for (int i = 0; i < n; i++)
    soma += v[i];

  printf("Tamanho = %d, Soma = %d, Média = %f\n", n, soma, (float)soma/n);

  return 0;
}

/**
 * @brief Função principal que inicia a execução do programa.
 *
 * Chama a função array2 para manipulação de vetores baseada nos argumentos de linha de comando.
 *
 * @param argc Número de argumentos de linha de comando.
 * @param argv Vetor de strings contendo os argumentos de linha de comando.
 * @return Retorna 0 indicando que o programa foi executado com sucesso.
 */
int main(int argc, char *argv[]) {
  array2(argc, argv);
  return 0;
}
