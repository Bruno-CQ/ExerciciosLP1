/**
 * @file ex1.c
 * @brief Função principal que utiliza funções da biblioteca de soma e subtração.
 */

#include <stdio.h>
#include "soma.h"

/**
 * @brief Função principal que utiliza as funções soma e menos da biblioteca.
 *
 * Esta função demonstra o uso das funções `soma` e `menos` da biblioteca.
 *
 * @param argc Número de argumentos da linha de comando.
 * @param argv Vetor de argumentos da linha de comando.
 * @return 0 se o programa for executado com sucesso.
 */
int biblioteca(int argc, char *argv[]) {
    int va = 10, vb = 20, res = 0;

    res = soma(va, vb);
    printf("Soma a + b = %i\n", res);

    res = menos(va, vb);
    printf("menos + b = %i\n", res);

    return 0;
}
