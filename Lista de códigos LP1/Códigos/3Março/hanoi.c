/**
 * @file main.c
 * @brief Implementação da função hanoi para resolver o problema das Torres de Hanoi.
 * @date 20/03/2024
 * 
 * Este arquivo contém a implementação da função hanoi, que resolve o problema das Torres de Hanoi
 * utilizando um método específico para mover os discos entre três pinos.
 */

#include <stdio.h>

/**
 * @brief Função para resolver o problema das Torres de Hanoi.
 * 
 * Esta função simula a solução do problema das Torres de Hanoi com 5 discos, movendo-os entre três
 * posições (1, 2 e 3) de acordo com um método específico. O usuário deve seguir as instruções 
 * fornecidas pela função para realizar os movimentos corretos.
 * 
 * @return void
 */
void hanoi() {
    int D1pos = 1;
    int D2pos = 1;
    int D3pos = 1;
    int D4pos = 1;
    int D5pos = 1;

    printf("Mova o disco 1 para a posição 2 ou 3: ");
    scanf("%i", &D1pos);

    // Validar a escolha do usuário para o primeiro movimento
    while (D1pos != 2 && D1pos != 3) {
        printf("Movimento inválido, escolha novamente: ");
        scanf("%i", &D1pos);
    }

    // Realizar os movimentos conforme o método específico das Torres de Hanoi
    if (D1pos == 2) {
        printf("Mova o disco 2 para a posição 3\n");
        D2pos = 3;
    } else {
        printf("Mova o disco 2 para a posição 2\n");
        D2pos = 2;
    }

    printf("Mova o disco 1 para a posição do disco 2\n");
    D1pos = D2pos;

    if (D2pos == 2) {
        printf("Mova o disco 3 para a posição 3\n");
        D3pos = 3;
    } else {
        printf("Mova o disco 3 para a posição 2\n");
        D3pos = 2;
    }

    printf("Mova o disco 1 para a posição 1\n");
    D1pos = 1;
    printf("Mova o disco 2 para a posição do disco 3\n");
    D2pos = D3pos;
    printf("Mova o disco 1 para a posição do disco 2\n");
    D1pos = D2pos;

    if (D3pos == 2) {
        printf("Mova o disco 4 para a posição 3\n");
        D4pos = 3;
    } else {
        printf("Mova o disco 4 para a posição 2\n");
        D4pos = 2;
    }

    printf("Mova o disco 1 para a posição do disco 4\n");
    D1pos = D4pos;
    printf("Mova o disco 2 para a posição 1\n");
    D2pos = 1;
    printf("Mova o disco 1 para a posição do disco 2\n");
    D1pos = D2pos;
    printf("Mova o disco 3 para a posição do disco 4\n");
    D3pos = D4pos;

    if (D4pos == 2) {
        printf("Mova o disco 1 para a posição 3\n");
        D1pos = 3;
    } else {
        printf("Mova o disco 1 para a posição 2\n");
        D1pos = 2;
    }

    printf("Mova o disco 2 para a posição do disco 3\n");
    D2pos = D3pos;
    printf("Mova o disco 1 para a posição do disco 2\n");
    D1pos = D2pos;

    if (D4pos == 2) {
        printf("Mova o disco 5 para a posição 3\n");
        D5pos = 3;
    } else {
        printf("Mova o disco 5 para a posição 2\n");
        D5pos = 2;
    }

    printf("Mova o disco 1 para a posição 1\n");
    D1pos = 1;
    printf("Mova o disco 2 para a posição do disco 5\n");
    D2pos = D5pos;
    printf("Mova o disco 1 para a posição do disco 2\n");
    D1pos = D2pos;
    printf("Mova o disco 3 para a posição 1\n");
    D3pos = 1;
    printf("Mova o disco 1 para a posição do disco 4\n");
    D1pos = D4pos;
    printf("Mova o disco 2 para a posição do disco 3\n");
    D2pos = D3pos;
    printf("Mova o disco 1 para a posição do disco 2\n");
    D1pos = D2pos;
    printf("Mova o disco 4 para a posição do disco 5\n");
    D4pos = D5pos;
    printf("Mova o disco 1 para a posição do disco 4\n");
    D1pos = D4pos;

    if (D1pos == 2) {
        printf("Mova o disco 2 para a posição 3\n");
        D2pos = 3;
    } else {
        printf("Mova o disco 2 para a posição 2\n");
        D2pos = 2;
    }

    printf("Mova o disco 1 para a posição do disco 2\n");
    D1pos = D2pos;
    printf("Mova o disco 3 para a posição do disco 4\n");
    D3pos = D4pos;
    printf("Mova o disco 1 para a posição 1\n");
    D1pos = 1;
    printf("Mova o disco 2 para a posição do disco 3\n");
    D2pos = D3pos;
    printf("Mova o disco 1 para a posição do disco 2\n");
    D1pos = D2pos;

    printf("\nPosições finais dos discos:\nDisco 1: %i\nDisco 2: %i\nDisco 3: %i\nDisco 4: %i\nDisco 5: %i\n", D1pos, D2pos, D3pos, D4pos, D5pos);
    return;
}