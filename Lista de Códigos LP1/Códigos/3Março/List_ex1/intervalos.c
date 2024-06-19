/**
 * @file main.c
 * @brief Implementação das funções para verificar intervalos de tipos de dados inteiros.
 * @date 26/03/2024
 * 
 * Este arquivo contém a implementação das funções intervalos, testshort e testint. As funções
 * testshort e testint verificam se um número inteiro está dentro dos intervalos de short int e
 * int, respectivamente. A função intervalos seleciona entre testshort e testint com base no
 * parâmetro de entrada.
 */

#include <stdio.h>

/**
 * @brief Função para verificar se um número inteiro está dentro do intervalo de short int.
 * 
 * Esta função solicita ao usuário um número inteiro, converte-o para short int e verifica se o
 * valor está dentro do intervalo dos short int.
 * 
 * @return void
 */
void testshort() {
  int valorInt;
  short int miniValor;

  printf("Digite um número inteiro: ");
  scanf("%d", &valorInt);

  miniValor = (short int)valorInt;
  printf("O valor digitado foi %d\n", valorInt);

  (valorInt == miniValor) ? printf("E este valor pertence ao intervalo dos short int.\n") : printf("E este valor é maior que um short int.\n");
}

/**
 * @brief Função para verificar se um número inteiro longo sem sinal está dentro do intervalo de int.
 * 
 * Esta função solicita ao usuário um número inteiro longo sem sinal, converte-o para int e verifica
 * se o valor está dentro do intervalo dos int.
 * 
 * @return void
 */
void testint() {
  int valorInt;
  unsigned long int valorLong;

  printf("Digite um número inteiro longo sem sinal: ");
  scanf("%lu", &valorLong);

  valorInt = (int)valorLong;
  printf("O valor digitado foi %lu\n", valorLong);

  (valorLong == valorInt) ? printf("E este valor pertence ao intervalo dos int.\n") : printf("E este valor é maior que um int.\n");
}

/**
 * @brief Função para selecionar entre verificar o intervalo de short int ou int.
 * 
 * Esta função recebe um parâmetro inteiro 'a' para selecionar entre chamar testshort (se 'a' for 1)
 * ou testint (se 'a' for diferente de 1).
 * 
 * @param a Indica a escolha entre verificar o intervalo de short int (1) ou int (diferente de 1).
 * @return void
 */
void intervalos(int a) {
  if (a == 1)
    testshort();
  else
    testint();
}
