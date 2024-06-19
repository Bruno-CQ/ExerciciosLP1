/**
 * @file main.c
 * @brief Programa que demonstra o uso de funções para manipulação de vetores.
 *
 * Este programa define três funções para manipular vetores e demonstra seu uso na função principal.
 * Cada função realiza uma operação específica com um vetor de tamanho especificado.
 * As funções incluem a criação de vetores estáticos e o cálculo da soma dos elementos.
 *
 * @author Bruno Costa Queiroz
 * @date 13/05/2024
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Preenche um vetor com valores fixos e imprime na tela.
 *
 * Esta função cria um vetor de tamanho n e preenche com valores fixos.
 * Os valores são: 5, 50, 500, 5000, 50000.
 * Em seguida, imprime os valores na tela.
 *
 * @param n Tamanho do vetor a ser criado.
 * @return Sempre retorna 0.
 */
int vetor1(int n) {
  int v[n];
  v[0] = 5;
  v[1] = 50;
  v[2] = 500;
  v[3] = 5000;
  v[4] = 50000;
  printf("Vetor 1: %d %d %d %d %d\n", v[0], v[1], v[2], v[3], v[4]);
  return 0;
}

/**
 * @brief Preenche um vetor com valores crescentes e imprime na tela.
 *
 * Esta função cria um vetor de tamanho n e preenche com valores de 1 até n.
 * Em seguida, imprime os valores na tela.
 *
 * @param n Tamanho do vetor a ser criado.
 * @return Sempre retorna 0.
 */
int vetor2(int n) {
  int v[n];
  for (int i = 0; i < n; i++) {
    v[i] = i + 1;
  }
  printf("Vetor 2: %d %d %d %d %d\n", v[0], v[1], v[2], v[3], v[4]);
  return 0;
}

/**
 * @brief Preenche um vetor com valores multiplicados por 1000, calcula a soma e imprime na tela.
 *
 * Esta função cria um vetor de tamanho n e preenche com valores multiplicados por 1000.
 * Calcula a soma de todos os elementos do vetor e imprime o resultado na tela.
 *
 * @param n Tamanho do vetor a ser criado.
 * @return Sempre retorna 0.
 */
int vetor3(int n) {
  int v[n], soma = 0;
  for (int i = 0; i < n; i++) {
    v[i] = i * 1000;
    soma += v[i];
  }
  printf("Soma dos vetores: %d\n", soma);
  return 0;
}

/**
 * @brief Função principal que chama as funções de manipulação de vetores.
 *
 * Esta função define um tamanho fixo para os vetores (n = 5) e chama as três funções de manipulação de vetores.
 * Imprime os resultados das operações realizadas pelas funções na tela.
 *
 * @return Sempre retorna 0.
 */
int array1(void) {
  int n = 5;
  vetor1(n);
  vetor2(n);
  vetor3(n);

  return 0;
}

/**
 * @brief Função principal que inicia a execução do programa.
 *
 * Chama a função array1 para iniciar a execução do programa.
 *
 * @return Retorna 0 indicando que o programa foi executado com sucesso.
 */
int main() {
  array1();
  return 0;
}
