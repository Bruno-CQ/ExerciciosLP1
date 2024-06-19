/**
 * @file numeros.c
 * @brief Função para operações com três números inteiros.
 * @date 15/04/2024
 * 
 * Este arquivo contém a implementação da função numeros, que recebe três números
 * inteiros como argumentos da linha de comando e realiza operações simples com eles.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Função para realizar operações com três números inteiros.
 * 
 * Esta função recebe três números inteiros a partir dos argumentos da linha de comando,
 * e realiza operações simples de iteração sobre esses números.
 * 
 * @param argc Número de argumentos passados na linha de comando.
 * @param argv Vetor de strings que contém os argumentos passados na linha de comando.
 * @return void
 */
void numeros(int argc, char *argv[]) {
    unsigned int resp = 0; // Variável para armazenar a resposta
    int limite = 10; // Limite definido arbitrariamente
    int a, b, c; // Variáveis para armazenar os números

    // Verifica se foram passados exatamente três argumentos
    if (argc == 4) {
        a = atoi(argv[1]); // Converte o primeiro argumento para inteiro
        b = atoi(argv[2]); // Converte o segundo argumento para inteiro
        c = atoi(argv[3]); // Converte o terceiro argumento para inteiro
    } else if (argc > 4) {
        printf("Muitos argumentos\n");
        return;
    } else {
        printf("Faltam argumentos\n");
        return;
    }

    // Loop para iterar sobre o primeiro número
    for (int i = a; i >= 0; i--) {
        resp += i; // Soma o valor de i à variável resp

        // Loop para iterar sobre o segundo número
        for (int j = b; j >= 0; j--) {

            // Loop para iterar sobre o terceiro número
            for (int k = c; k >= 0; k--) {
                printf("Resposta %d%d%d\n", i, j, k); // Imprime o padrão de resposta
            }
        }
    }
}
