/**
 * @file main.c
 * @brief Implementação de uma calculadora com correções de bugs para funcionar corretamente.
 * @date 15/04/2024
 * 
 * Este arquivo contém a implementação da função calc_bugada. A função permite ao usuário selecionar
 * uma operação matemática (soma, subtração, multiplicação ou divisão) entre dois números fornecidos,
 * realizando o cálculo e exibindo o resultado formatado.
 */

#include <stdio.h>
#include <math.h>

/**
 * @brief Implementação de uma calculadora com correções de bugs para funcionar corretamente.
 * 
 * A função permite ao usuário selecionar uma operação matemática (soma, subtração, multiplicação
 * ou divisão) entre dois números fornecidos. Caso a operação seja inválida ou a divisão por zero
 * seja tentada, mensagens apropriadas são exibidas. Os resultados são mostrados com formatação
 * adequada e, no caso da divisão, também exibe o resto da divisão.
 * 
 * @return void
 */
void calc_bugada(void) {
    short int opr;
    float num1, num2, result;

    // Seleção da operação
    printf("Selecione a operação a ser realizada:\n"
           "  \x1b[33m1\x1b[37m - Soma\n"
           "  \x1b[33m2\x1b[37m - Subtração\n"
           "  \x1b[33m3\x1b[37m - Multiplicação\n"
           "  \x1b[33m4\x1b[37m - Divisão\n");
    scanf("%hd", &opr);

    // Bloquear operações inválidas
    if (opr != 1 && opr != 2 && opr != 3 && opr != 4) {
        printf("Operação inválida");
        return;
    }

    // Seleção dos números
    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    printf("Digite o segundo número: ");
    scanf("%f", &num2);

    // Realização dos cálculos
    switch(opr) {
        case 1:
            result = num1 + num2;
            printf("O resultado da soma é próximo ou igual a: \x1b[33m%.2f\x1b[37m", result);
            break;
        case 2:
            result = num1 - num2;
            printf("O resultado da subtração é próximo ou igual a: \x1b[33m%.2f\x1b[37m", result);
            break;
        case 3:
            result = num1 * num2;
            printf("O resultado da multiplicação é próximo ou igual a: \x1b[33m%.2f\x1b[37m", result);
            break;
        case 4:
            // Bloquear divisão por 0
            if (num2 == 0) {
                printf("Não é possível dividir por zero!");
                return;
            } else {
                int resto;
                result = num1 / num2;
                resto = lroundf(num1) % lroundf(num2);
                if (resto == 0)
                    printf("O resultado da divisão é próximo ou igual a: \x1b[33m%.2f\x1b[37m, com resto próximo a \x1b[33m0\x1b[37m", result);
                else
                    printf("O resultado da divisão é próximo ou igual a: \x1b[33m%.2f\x1b[37m, com resto próximo a \x1b[33m%d\x1b[37m", result, resto);
            }
            break;
    }
}
