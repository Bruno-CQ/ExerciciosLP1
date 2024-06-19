/**
 * @file main.c
 * @brief Programa para converter entre Celsius e Fahrenheit.
 *
 * Este programa permite ao usuário converter temperaturas entre Celsius e Fahrenheit.
 * A função principal é temperatura(argc, argv[]), que verifica os argumentos passados e realiza a conversão conforme a escolha do usuário.
 * São fornecidas duas funções de conversão: celFar(temp) para Celsius para Fahrenheit e farCel(temp) para Fahrenheit para Celsius.
 *
 * @author Bruno Costa Queiroz
 * @date Data da última modificação: 2024-05-12
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Função para converter temperatura de Celsius para Fahrenheit.
 *
 * Esta função recebe uma temperatura em Celsius e retorna o equivalente em Fahrenheit.
 *
 * @param temp Temperatura em Celsius a ser convertida.
 * @return Temperatura equivalente em Fahrenheit.
 */
int celFar(int temp);

/**
 * @brief Função para converter temperatura de Fahrenheit para Celsius.
 *
 * Esta função recebe uma temperatura em Fahrenheit e retorna o equivalente em Celsius.
 *
 * @param temp Temperatura em Fahrenheit a ser convertida.
 * @return Temperatura equivalente em Celsius.
 */
int farCel(int temp);

/**
 * @brief Função principal para realizar conversão de temperatura.
 *
 * Esta função verifica os argumentos passados via linha de comando (argc, argv) ou solicita ao usuário que insira a temperatura.
 * Em seguida, permite ao usuário escolher entre converter Celsius para Fahrenheit ou Fahrenheit para Celsius e imprime o resultado da conversão.
 *
 * @param argc Número de argumentos passados para o programa.
 * @param argv Vetor de strings que contém os argumentos passados para o programa.
 * @return Retorna 0 se o programa for executado com sucesso.
 */
int temperatura(int argc, char *argv[]) {
  int temp, opc;
  printf("Temperatura -> %s\n", argv[1]);

  if (argc == 2) {
    temp = atoi(argv[1]);
  } else if (argc > 2) {
    printf("Muitos argumentos\n");
    return 1;
  } else {
    printf("Entre com um número.\n");
    return 1;
  }

  printf("Digite a opção de conversão:\n1 - Celsius para Fahrenheit\n2 - Fahrenheit para Celsius\n");
  scanf("%d", &opc);

  switch (opc) {
    case 1:
      printf("Temperatura em Fahrenheit: %d\n", celFar(temp));
      break;
    case 2:
      printf("Temperatura em Celsius: %d\n", farCel(temp));
      break;
    default:
      printf("Opção inválida.\n");
  }

  return 0;
}

int celFar(int temp) {
  return (temp * 9/5) + 32;
}

int farCel(int temp) {
  return (temp - 32) * 5/9;
}
