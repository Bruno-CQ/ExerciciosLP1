/**
 * @file main.c
 * @brief Implementação da função para calcular o resto da divisão de um número inteiro por 6.
 * @date 26/03/2024
 * 
 * Este arquivo contém a implementação da função um_6. A função solicita ao usuário um número inteiro
 * e calcula o resto da divisão desse número por 6, exibindo o resultado ajustado para 6 se for zero.
 */

#include <stdio.h>

/**
 * @brief Calcula o resto da divisão de um número inteiro por 6.
 * 
 * A função solicita ao usuário um número inteiro e calcula o resto da divisão desse número por 6.
 * Se o resultado for zero, ajusta o valor para 6 antes de exibi-lo.
 * 
 * @return void
 */
void um_6() {
    int value, result;

    printf("Digite um número inteiro: ");
    scanf("%d", &value);

    result = (value % 6);

    if (result == 0)
        result = 6;

    printf("O resultado é %d\n", result);

    return;
}
