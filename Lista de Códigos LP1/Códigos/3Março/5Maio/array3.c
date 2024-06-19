/**
 * @file main.c
 * @brief Programa que permite escolher entre diferentes operações com matrizes de várias dimensões.
 *
 * Este programa permite ao usuário escolher entre operações com matrizes unidimensionais, bidimensionais e tridimensionais.
 * Para cada tipo de matriz, o programa solicita as dimensões, preenche a matriz com valores calculados,
 * calcula a soma dos elementos e imprime os elementos da matriz, a soma e a média dos valores.
 * 
 * As funções são organizadas em um menu simples que é exibido ao usuário para fazer a escolha.
 * Este código inclui mudanças no nome da função principal para array3 até 15/06/2024.
 *
 * @author Bruno Costa Queiroz
 * @date 15/05/2024
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Função principal que apresenta um menu para escolher entre operações com matrizes de diferentes dimensões.
 *
 * Esta função apresenta um menu simples para o usuário escolher entre operações com matrizes unidimensionais, bidimensionais ou tridimensionais.
 * Dependendo da escolha do usuário, chama a função correspondente para manipular a matriz escolhida.
 * Imprime os elementos da matriz, a soma dos elementos e a média dos valores na matriz.
 *
 * @return Retorna 0 se executado com sucesso.
 */
int array3(void) {
  int n;
  printf("Escolha a função:\n1 - 1 Dimensão\n2 - 2 Dimensões\n3 - 3 Dimensões\n");
  scanf("%d", &n);
  switch (n) {
    case 1:
      unidimensional();
      break;
    case 2:
      bidimensional();
      break;
    case 3:
      tridimensional();
      break;
    default:
      printf("Função não encontrada.\n");
  }
  return 0;
}

/**
 * @brief Função que manipula uma matriz unidimensional.
 *
 * Esta função solicita ao usuário a quantidade de linhas da matriz unidimensional, preenche a matriz com valores crescentes,
 * calcula a soma dos elementos e imprime os elementos da matriz, a soma e a média dos valores.
 *
 * @return Retorna 0 se executado com sucesso.
 */
int unidimensional(void) {
  int linha, s = 0;
  printf("Digite a quantidade de linhas: ");
  scanf("%d", &linha);
  int m[linha];
  for (int i = 0; i < linha; i++) {
    m[i] = i + 1;
    s += m[i];
    printf("m[%d] = %d\n", i, m[i]);
  }
  printf("Soma: %d\nMédia: %f", s, (float)(s / linha));
  return 0;
}

/**
 * @brief Função que manipula uma matriz bidimensional.
 *
 * Esta função solicita ao usuário a quantidade de linhas e colunas da matriz bidimensional, preenche a matriz com valores calculados,
 * calcula a soma dos elementos e imprime os elementos da matriz, a soma e a média dos valores.
 *
 * @return Retorna 0 se executado com sucesso.
 */
int bidimensional(void) {
  int linha, coluna, s = 0;
  printf("Digite a quantidade de linhas e colunas: ");
  scanf("%d %d", &linha, &coluna);
  int m[linha][coluna];
  for (int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++) {
      m[i][j] = i * coluna + j;
      s += m[i][j];
      printf("m[%d][%d] = %d\n", i, j, m[i][j]);
    }
  }
  printf("Soma: %d\nMédia: %f", s, (float)(s / (linha * coluna)));
  return 0;
}

/**
 * @brief Função que manipula uma matriz tridimensional.
 *
 * Esta função solicita ao usuário a quantidade de linhas, colunas e profundidade da matriz tridimensional,
 * preenche a matriz com valores calculados, calcula a soma dos elementos e imprime os elementos da matriz,
 * a soma e a média dos valores.
 *
 * @return Retorna 0 se executado com sucesso.
 */
int tridimensional(void) {
  int linha, coluna, profundidade, s = 0;
  printf("Digite a quantidade de linhas, colunas e profundidade: ");
  scanf("%d %d %d", &linha, &coluna, &profundidade);
  int m[linha][coluna][profundidade];
  for (int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++) {
      for (int k = 0; k < profundidade; k++) {
        m[i][j][k] = i * (coluna * profundidade) + j * coluna + k;
        s += m[i][j][k];
        printf("m[%d][%d][%d] = %d\n", i, j, k, m[i][j][k]);
      }
    }
  }
  printf("Soma: %d\nMédia: %f", s, (float)(s / (linha * coluna * profundidade)));
  return 0;
}

/**
 * @brief Função principal que inicia a execução do programa.
 *
 * Chama a função array3 para apresentar o menu de escolha ao usuário e iniciar a execução do programa.
 *
 * @return Retorna 0 indicando que o programa foi executado com sucesso.
 */
int main() {
  array3();
  return 0;
}
