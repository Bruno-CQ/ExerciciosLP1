/**
 * @file array5.c
 * @brief Funções para manipulação de arrays e cálculos estatísticos com floats.
 *
 * Este programa gera um array de números aleatórios, ordena-o, calcula estatísticas como média,
 * mediana, desvio padrão, e contagem de ocorrências. Também calcula essas estatísticas para os
 * números que não se repetem.
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
int aleatorio2();

/**
 * @brief Calcula a média dos elementos de um array.
 *
 * @param v Array de inteiros.
 * @param n Tamanho do array.
 * @return A média dos elementos do array.
 */
float cMedia2(int v[], int n);

/**
 * @brief Calcula a mediana dos elementos de um array ordenado.
 *
 * @param v Array de inteiros ordenado.
 * @param n Tamanho do array.
 * @return A mediana dos elementos do array.
 */
float cMediana2(int v[], int n);

/**
 * @brief Calcula o desvio padrão dos elementos de um array em relação à média.
 *
 * @param v Array de inteiros.
 * @param n Tamanho do array.
 * @param media A média dos elementos do array.
 * @return O desvio padrão dos elementos do array.
 */
float cDesvio2(int v[], int n, float media);

/**
 * @brief Conta o número de vezes que cada elemento aparece no array.
 *
 * @param v Array de inteiros.
 * @param n Tamanho do array.
 * @param c Array de contagem, onde c[i] contém o número de ocorrências do número i.
 */
void repeticao2(int v[], int n, int c[]);

/**
 * @brief Função principal que executa o programa para a opção Array Float.
 *
 * Esta função gera um array de números aleatórios, ordena-o, calcula estatísticas como média,
 * mediana, desvio padrão e contagem de ocorrências. Também calcula essas estatísticas para os
 * números que não se repetem.
 *
 * @return 0 se o programa executou com sucesso.
 */
int array5() {
  int noR = 0, base = 10000;
  int array[base], aux, contador[1001] = {0};
  float media = 0, mediana = 0, desvio = 0;
  float media2 = 0, mediana2 = 0, desvio2 = 0;

  srand(time(NULL));
  for (int i = 0; i < base; i++) {
    array[i] = aleatorio2();
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

  printf("Três menores números: %.2f, %.2f, %.2f\n", array[0], array[1], array[2]);
  printf("Três maiores números: %.2f, %.2f, %.2f\n", array[9999], array[9998], array[9997]);

  media = cMedia2(array, base);
  mediana = cMediana2(array, base);
  desvio = cDesvio2(array, base, media);

  printf("Média: %.2f\nMediana: %.2f\nDesvio Padrão: %.2f\n", media, mediana, desvio);

  repeticao2(array, base, contador);

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
  media2 = cMedia2(array2, noR);
  mediana2 = cMediana2(array2, noR);
  desvio2 = cDesvio2(array2, noR, media2);

  printf("Dos números que não repetiram:\nMédia: %.2f\nMediana: %.2f\nDesvio Padrão: %.2f\n", media2, mediana2, desvio2);

  return 0;
}

/**
 * @brief Função que gera um número aleatório entre 0 e 1000.
 *
 * @return O número aleatório gerado.
 */
int aleatorio2() {
  return rand() % 1001;
}

/**
 * @brief Calcula a média dos elementos de um array.
 *
 * @param v Array de inteiros.
 * @param n Tamanho do array.
 * @return A média dos elementos do array.
 */
float cMedia2(int v[], int n) {
  float soma = 0;
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
float cMediana2(int v[], int n) {
  if (n % 2 == 0) {
    return (v[n / 2] + v[(n / 2) - 1]) / 2.0;
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
float cDesvio2(int v[], int n, float media) {
  float soma = 0;
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
void repeticao2(int v[], int n, int c[]) {
  for (int i = 0; i < n; i++) {
    c[v[i]]++;
  }
}
