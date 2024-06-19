/**
 * @file main.c
 * @brief Implementação das funções para desenhar formas geométricas e calcular propriedades.
 * @date 26/03/2024
 * 
 * Este arquivo contém a implementação das funções formas, linha e quadrado. As funções linha
 * e quadrado são utilizadas para desenhar e calcular propriedades geométricas de uma linha e
 * de um quadrado, respectivamente. A função formas seleciona entre linha e quadrado com base
 * no parâmetro de entrada.
 */

#include <stdio.h>
#include <math.h>

/**
 * @brief Função para desenhar uma linha e calcular propriedades.
 * 
 * Esta função solicita ao usuário as coordenadas x e y de um ponto, determina a posição do ponto
 * em relação aos eixos e ao quadrante, calcula a distância do ponto à origem e o produto das
 * coordenadas.
 * 
 * @return void
 */
void linha() {
  float x, y, z;

  printf("Digite as coordenadas x e y: ");
  scanf("%f %f", &x, &y);

  (x == 0 && y == 0) ? printf("Origem\n") :
     (x == 0) ? printf("Eixo Y\n") :
     (y == 0) ? printf("Eixo X\n") :
     (x > 0 && y > 0) ? printf("Q1\n") :
     (x < 0 && y > 0) ? printf("Q2\n") :
     (x < 0 && y < 0) ? printf("Q3\n") : printf("Q4\n");

  z = sqrt(x * x + y * y);
  printf("A distância é %.2f\n", z);

  z = x * y;
  printf("O produto em notação científica é %.2e\n", z);
}

/**
 * @brief Função para desenhar um quadrado e calcular suas propriedades.
 * 
 * Esta função solicita ao usuário o lado de um quadrado, calcula a diagonal, o perímetro e a área
 * do quadrado.
 * 
 * @return void
 */
void quadrado() {
  float lado, diagonal, perimetro, area;

  printf("Digite o lado do quadrado: ");
  scanf("%f", &lado);

  diagonal = lado * sqrt(2);
  perimetro = 4 * lado;
  area = lado * lado;

  printf("Diagonal: %.2f\n Perímetro: %.2f\n Área: %f\n", diagonal, perimetro, area);
}

/**
 * @brief Função para selecionar entre desenhar uma linha ou um quadrado.
 * 
 * Esta função recebe um parâmetro inteiro 'a' para selecionar entre desenhar uma linha (se 'a' for 1)
 * ou um quadrado (se 'a' for diferente de 1). Caso 'a' seja diferente de 1, desenha um quadrado.
 * 
 * @param a Indica a escolha entre desenhar uma linha (1) ou um quadrado (diferente de 1).
 * @return void
 */
void formas(int a) {
  if (a == 1)
    linha();
  else
    quadrado();
}
