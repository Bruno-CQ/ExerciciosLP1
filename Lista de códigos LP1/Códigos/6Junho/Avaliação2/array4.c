/**
 * @file array4.c
 * @brief Funções para manipulação de arrays e cálculos estatísticos.
 *
 * Este programa gera um array de números aleatórios, ordena-o, calcula estatísticas como média,
 * mediana, desvio padrão, e conta o número de ocorrências de cada elemento. Também calcula essas
 * estatísticas para os números que não se repetem.
 *
 * @author Bruno Costa Queiroz
 * @date 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/**
 * @brief Função para gerar um número aleatório entre 0 e 1000.
 *
 * @return O número aleatório gerado.
 */
int aleatorio();

/**
 * @brief Calcula a média dos elementos de um array.
 *
 * @param v Array de inteiros.
 * @param n Tamanho do array.
 * @return A média dos elementos do array.
 */
int cMedia(int v[], int n);

/**
 * @brief Calcula a mediana dos elementos de um array ordenado.
 *
 * @param v Array de inteiros ordenado.
 * @param n Tamanho do array.
 * @return A mediana dos elementos do array.
 */
int cMediana(int v[], int n);

/**
 * @brief Calcula o desvio padrão dos elementos de um array em relação à média.
 *
 * @param v Array de inteiros.
 * @param n Tamanho do array.
 * @param media A média dos elementos do array.
 * @return O desvio padrão dos elementos do array.
 */
int cDesvio(int v[], int n, int media);

/**
 * @brief Conta o número de vezes que cada elemento aparece no array.
 *
 * @param v Array de inteiros.
 * @param n Tamanho do array.
 * @param c Array de contagem, onde c[i] contém o número de ocorrências do número i.
 */
void repeticao(int v[], int n, int c[]);

/**
 * @brief Função principal que executa o programa para a opção Array Int.
 *
 * Esta função gera um array de números aleatórios, ordena-o, calcula estatísticas como média,
 * mediana, desvio padrão e contagem de ocorrências. Também calcula essas estatísticas para os
 * números que não se repetem.
 *
 * @return 0 se o programa executou com sucesso.
 */
int array4() {
  int noR = 0, base = 10000;
  int array[base], aux, contador[1001] = {0};
  int media = 0, mediana = 0, desvio = 0;
  int media2 = 0, mediana2 = 0, desvio2 = 0;

  srand(time(NULL));
  for (int i = 0; i < base; i++) {
    array[i] = aleatorio();
  }

  // Ordena o array usando o algoritmo de ordenação Bubble Sort
  for (int i = 0; i < base; i++) {
    for (int j = i + 1; j < base; j++) {
      if (array[i] > array[j]) {
        aux = array[i];
        array[i] = array[j];
        array[j] = aux;
      }
    }
  }

  printf("Três menores números: %d, %d, %d\n", array[0], array[1], array[2]);
  printf("Três maiores números: %d, %d, %d\n", array[9999], array[9998], array[9997]);

  media = cMedia(array, base);
  mediana = cMediana(array, base);
  desvio = cDesvio(array, base, media);

  printf("Média: %d\nMediana: %d\nDesvio Padrão: %d\n", media, mediana, desvio);

  repeticao(array, base, contador);

  // Imprime o número de ocorrências de cada elemento no array
  for (int i = 0; i < 1001; i++) {
    if (contador[i] > 0) {
      printf("O número %d apareceu %d vezes\n", i, contador[i]);
    }
  }

  // Conta quantos números não se repetem
  for (int i = 0; i < 1001; i++) {
    if (contador[i] <= 1) {
      noR++;
    }
  }

  // Cria um novo array com os números que não se repetem
  int array2[noR], j = 0;
  for (int i = 0; i < 1001; i++) {
    if (contador[i] <= 1) {
      array2[j++] = i;
    }
  }

  // Calcula estatísticas para o array de números que não se repetem
  media2 = cMedia(array2, noR);
  mediana2 = cMediana(array2, noR);
  desvio2 = cDesvio(array2, noR, media2);

  printf("Dos números que não repetiram:\nMédia: %d\nMediana: %d\nDesvio Padrão: %d\n", media2, mediana2, desvio2);

  return 0;
}

/**
 * @brief Função que gera um número aleatório entre 0 e 1000.
 *
 * @return O número aleatório gerado.
 */
int aleatorio() {
  return rand() % 1001;
}

/**
 * @brief Calcula a média dos elementos de um array.
 *
 * @param v Array de inteiros.
 * @param n Tamanho do array.
 * @return A média dos elementos do array.
 */
int cMedia(int v[], int n) {
  int soma = 0;
  for (int i = 0; i < n; i++) {
    soma += v[i];
  }
  return soma / n;
}

/**
 * @brief Calcula a mediana dos elementos de um array ordenado.
 *
 * @param v Array de inteiros ordenado.
 * @param n Tamanho do array.
 * @return A mediana dos elementos do array.
 */
int cMediana(int v[], int n) {
  if (n % 2 == 0) {
    return (v[n / 2] + v[(n / 2) - 1]) / 2;
  } else {
    return v[n / 2];
  }
}

/**
 * @brief Calcula o desvio padrão dos elementos de um array em relação à média.
 *
 * @param v Array de inteiros.
 * @param n Tamanho do array.
 * @param media A média dos elementos do array.
 * @return O desvio padrão dos elementos do array.
 */
int cDesvio(int v[], int n, int media) {
  int soma = 0;
  for (int i = 0; i < n; i++) {
    soma += (v[i] - media) * (v[i] - media);
  }
  return sqrt(soma / n);
}

/**
 * @brief Conta o número de vezes que cada elemento aparece no array.
 *
 * @param v Array de inteiros.
 * @param n Tamanho do array.
 * @param c Array de contagem, onde c[i] contém o número de ocorrências do número i.
 */
void repeticao(int v[], int n, int c[]) {
  for (int i = 0; i < n; i++) {
    c[v[i]]++;
  }
}
