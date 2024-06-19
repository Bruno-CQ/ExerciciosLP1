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
int aleatorio4();

/**
 * @brief Calcula a média dos elementos de um array.
 *
 * @param v Array de inteiros.
 * @param n Tamanho do array.
 * @return A média dos elementos do array.
 */
float cMedia4(int v[], int n);

/**
 * @brief Calcula a mediana dos elementos de um array ordenado.
 *
 * @param v Array de inteiros ordenado.
 * @param n Tamanho do array.
 * @return A mediana dos elementos do array.
 */
float cMediana4(int v[], int n);

/**
 * @brief Calcula o desvio padrão dos elementos de um array em relação à média.
 *
 * @param v Array de inteiros.
 * @param n Tamanho do array.
 * @param media A média dos elementos do array.
 * @return O desvio padrão dos elementos do array.
 */
float cDesvio4(int v[], int n, float media);

/**
 * @brief Conta o número de vezes que cada elemento aparece no array.
 *
 * @param v Array de inteiros.
 * @param n Tamanho do array.
 * @param c Array de contagem, onde c[i] contém o número de ocorrências do número i.
 */
void repeticao4(int v[], int n, int c[]);

/**
 * @brief Função principal que executa o programa para a opção Array Float.
 *
 * Esta função gera um array de números aleatórios, ordena-o, calcula estatísticas como média,
 * mediana, desvio padrão e contagem de ocorrências. Também calcula essas estatísticas para os
 * números que não se repetem.
 *
 * @return 0 se o programa executou com sucesso.
 */
int array7() {
  const int base = 10000;
  int array[base][base], aux, contador[1001] = {0};
  float media = 0, mediana = 0, desvio = 0;
  float media2 = 0, mediana2 = 0, desvio2 = 0;
  float mediana3 = 0, desvio3 = 0;
  float media4 = 0, mediana4 = 0, desvio4 = 0;
  int noR, soma;
  int arrayLin[base], arrayCol[base];

  srand(time(NULL));
  for (int i = 0; i < base; i++) {
    for (int j = 0; j < base; j++) {
      array[i][j] = aleatorio4();
    }
  }

  // Ordena o array usando o algoritmo de ordenação Bubble Sort
  for (int i = 0; i < base; i++) {
    for (int j = 0; j < base; j++) {
      for (int k = 0; k < base; k++) {
        for (int l = 0; l < base; l++) {
          if (array[i][j] > array[k][l]) {
            aux = array[i][j];
            array[i][j] = array[k][l];
            array[k][l] = aux;
          }
        }
      }
    }
  }

  printf("Três menores números: %d, %d, %d\n", array[0][0], array[0][1], array[0][2]);
  printf("Três maiores números: %d, %d, %d\n", array[9999][9999], array[9999][9998], array[9999][9997]);

  for (int i = 0; i < base; i++) {
    for (int j = 0; j < base; j++ ) {
      arrayCol[i] = 0, arrayLin[i] = 0;
      arrayLin[i] += array[i][j];
      arrayCol[i] += array[j][i];
    }
  }

  media = cMedia4(arrayCol, base);
  mediana = (array[(base / 2) - 1][base] + array[base / 2][0]) / 2.0;
  for (int i = 0; i < base; i++) {
    for (int j = 0; j < base; j++) {
      soma += pow((array[i][j] - media), 2);
    }
  }
  desvio = sqrt(soma / base);

  printf("Média: %.2f\nMediana: %.2f\nDesvio Padrão: %.2f\n", media, mediana, desvio);

  for (int i = 0; i < base; i++) {
    repeticao4(array[i], base, contador);
  }

  mediana3 = cMediana4(arrayCol, base);
  desvio3 = cDesvio4(arrayCol, base, media);

  media4 = cMedia4(arrayLin, base);
  mediana4 = cMediana4(arrayLin, base);
  desvio4 = cDesvio4(arrayLin, base, media4);

  printf("Das colunas:\n");
  printf("Média: %.2f\nMediana: %.2f\nDesvio Padrão: %.2f\n", media, mediana3, desvio3);
  printf("Das linhas:\n");
  printf("Média: %.2f\nMediana: %.2f\nDesvio Padrão: %.2f\n", media4, mediana4, desvio4);
  

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
  media2 = cMedia4(array2, noR);
  mediana2 = cMediana4(array2, noR);
  desvio2 = cDesvio4(array2, noR, media2);

  printf("Dos números que não repetiram:\nMédia: %.2f\nMediana: %.2f\nDesvio Padrão: %.2f\n", media2, mediana2, desvio2);

  return 0;
}

/**
 * @brief Função que gera um número aleatório entre 0 e 1000.
 *
 * @return O número aleatório gerado.
 */
int aleatorio4() {
  return rand() % 1001;
}

/**
 * @brief Calcula a média dos elementos de um array.
 *
 * @param v Array de inteiros.
 * @param n Tamanho do array.
 * @return A média dos elementos do array.
 */
float cMedia4(int v[], int n) {
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
float cMediana4(int v[], int n) {
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
float cDesvio4(int v[], int n, float media) {
  float soma = 0;
  for (int i = 0; i < n; i++) {
    soma += pow((v[i] - media), 2);
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
void repeticao4(int v[], int n, int c[]) {
  for (int i = 0; i < n; i++) {
    c[v[i]]++;
  }
}
