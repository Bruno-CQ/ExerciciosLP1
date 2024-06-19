/**
 * @file main.c
 * @brief Programa que simula o lançamento de um dado e conta a frequência de cada face até sortear todas.
 *
 * Este programa permite ao usuário inserir um número base para determinar quantas vezes o dado será lançado
 * até que todas as seis faces sejam sorteadas pelo menos uma vez. Em seguida, imprime a quantidade de vezes
 * que cada face do dado foi sorteada até atingir esse critério.
 *
 * @author Bruno Costa Queiroz
 * @date 12/05/2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Função que simula o lançamento de um dado de seis faces.
 *
 * Gera um número aleatório entre 1 e 6, representando o resultado do lançamento do dado.
 *
 * @return Valor entre 1 e 6, representando o resultado do lançamento do dado.
 */
int roll();

/**
 * @brief Função que verifica a quantidade de vezes que cada face do dado foi sorteada até que todas sejam sorteadas ao menos uma vez.
 *
 * Esta função recebe um número base especificado pelo usuário para determinar quantos lançamentos são necessários
 * até que todas as seis faces do dado sejam sorteadas pelo menos uma vez. Imprime a quantidade de vezes que cada face
 * foi sorteada até atingir esse critério.
 *
 * @param argc Número de argumentos passados para o programa.
 * @param argv Vetor de strings que contém os argumentos passados para o programa.
 * @param base Número base especificado pelo usuário para determinar quantas vezes o dado será lançado.
 * @return Retorna 0 se a função executar corretamente.
 */
int verify(int argc, char *argv[], int base);

/**
 * @brief Função principal que inicia a execução do programa.
 *
 * Esta função solicita ao usuário inserir um número base para determinar quantas vezes o dado será lançado.
 * Chama a função verify para iniciar a simulação dos lançamentos do dado e contagem das faces sorteadas.
 *
 * @param argc Número de argumentos passados para o programa.
 * @param argv Vetor de strings que contém os argumentos passados para o programa.
 * @return Retorna 0 indicando que o programa foi executado com sucesso.
 */
int dado(int argc, char *argv[]) {
  unsigned long int base;
  printf("Base para revelação de quantidade de sorteios -> %s\n", argv[1]);

  if (argc == 2) {
    base = atoi(argv[1]);
  } else if (argc > 2) {
    printf("Muitos argumentos\n");
    return 1;
  } else {
    printf("Entre com um número.\n");
    return 1;
  }

  srand(time(NULL));
  verify(argc, argv, base);
  return 0;
}

int main(int argc, char *argv[]) {
  dado(argc, argv);
  return 0;
}

int roll() {
  return rand() % 6 + 1;
}

int verify(int argc, char *argv[], int base) {
  short int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;
  short int a2 = 0, b2 = 0, c2 = 0, d2 = 0, e2 = 0, f2 = 0, n;
  unsigned long int a1 = 0, b1 = 0, c1 = 0, d1 = 0, e1 = 0, f1 = 0, a3 = 0;

  while (a2 == 0 || b2 == 0 || c2 == 0 || d2 == 0 || e2 == 0 || f2 == 0) {
    for (int i = 0; i < 6; i++) {
      n = roll();
      printf("Dado: %d\n", n);

      if (a == n) {
        a1 += 1;
        a2 = 1;
      }
      if (b == n) {
        b1 += 1;
        b2 = 1;
      }
      if (c == n) {
        c1 += 1;
        c2 = 1;
      }
      if (d == n) {
        d1 += 1;
        d2 = 1;
      }
      if (e == n) {
        e1 += 1;
        e2 = 1;
      }
      if (f == n) {
        f1 += 1;
        f2 = 1;
      }

      if (a2 == 1 && b2 == 1 && c2 == 1 && d2 == 1 && e2 == 1 && f2 == 1) {
        a1++;
        printf("Levou %ld tentativas para sortear os 6 lados\n", a1);
        if (a1 >= base) {
          printf("O número 1 foi lançado %ld vezes\n", a1);
          printf("O número 2 foi lançado %ld vezes\n", b1);
          printf("O número 3 foi lançado %ld vezes\n", c1);
          printf("O número 4 foi lançado %ld vezes\n", d1);
          printf("O número 5 foi lançado %ld vezes\n", e1);
          printf("O número 6 foi lançado %ld vezes\n", f1);
        }
      } else if (i == 5) {
        a2 = 0;
        b2 = 0;
        c2 = 0;
        d2 = 0;
        e2 = 0;
        f2 = 0;
        a1++;
      }
    }
  }
  return 0;
}
