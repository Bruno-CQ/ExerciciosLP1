/**
 * @file main.c
 * @brief Implementação da função q_opr1 para realizar operações matemáticas básicas com feedback melhorado.
 * @date 20/03/2024
 * 
 * Este arquivo contém a implementação da função q_opr1 que realiza operações matemáticas básicas 
 * (adição, subtração, multiplicação, divisão) com feedback melhorado para o usuário.
 */

#include <stdio.h>

/**
 * @brief Função para realizar operações matemáticas básicas com feedback melhorado.
 * 
 * Esta função solicita dois valores e uma operação ao usuário (adição, subtração, multiplicação, divisão),
 * verifica a validade da opção escolhida e imprime o resultado em diferentes formatos: inteiro, real, real longo,
 * exponencial e hexadecimal.
 * 
 * @return void
 */
void q_opr1() {
    float v1 = 0;
    float var1 = 0;
    float var2 = 0;
    int opt = 0;

    printf("Entre com primeiro valor: ");
    scanf("%f", &var1);

    printf("Entre com segundo valor: ");
    scanf("%f", &var2);

    printf("1: Adição \n2: Subtração \n3: Multiplicação \n4: Divisão \n");
    scanf("%i", &opt);

    // Validar a opção escolhida pelo usuário
    while (opt < 1 || opt > 4) {
        printf("Opção inválida, escolha novamente: ");
        scanf("%i", &opt);
    }

    // Executar a operação escolhida e calcular o resultado
    if (opt == 1)
        v1 = var1 + var2;
    else if (opt == 2)
        v1 = var1 - var2;
    else if (opt == 3)
        v1 = var1 * var2;
    else if (opt == 4)
        v1 = var1 / var2;

    // Imprimir o resultado em diferentes formatos
    printf("Resultado em:\nInteiro: %i\nReal: %f\nReal Longo: %lf\nExponencial: %E\nHexadecimal: %X \n", (int)v1, v1, v1, v1, (int)v1);
    return;
}
