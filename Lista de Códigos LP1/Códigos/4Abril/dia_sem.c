/**
 * @file dia_semana.c
 * @brief Função para identificar o dia da semana baseado em um número de 1 a 7.
 * @date 15/04/2024
 * 
 * Este arquivo contém a implementação da função dia_sem, que identifica o dia da
 * semana com base em um número fornecido como argumento de linha de comando. A função
 * aceita um único argumento inteiro (de 1 a 7) e imprime o nome correspondente do dia
 * da semana. Se nenhum argumento for fornecido ou se forem fornecidos muitos argumentos,
 * a função exibe mensagens apropriadas e encerra a execução.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Função para identificar o dia da semana baseado em um número de 1 a 7.
 * 
 * Esta função verifica os argumentos fornecidos na linha de comando e imprime o nome
 * do dia da semana correspondente ao número fornecido. Se nenhum argumento for fornecido,
 * ou se forem fornecidos muitos argumentos, a função exibe mensagens apropriadas.
 * 
 * @param argc Número de argumentos passados para o programa.
 * @param argv Vetor de strings que contém os argumentos passados para o programa.
 * @return void
 */
void dia_sem(int argc, char *argv[]) {
    int diaSemana = 0;

    // Imprime todos os argumentos passados para o programa
    for (int i = 0; i < argc; i++) {
        printf("%d -> %s\n", i, argv[i]);
    }

    // Verifica se foi passado exatamente um argumento
    if (argc == 2) {
        diaSemana = atoi(argv[1]); // Converte o argumento para inteiro
    } else if (argc > 2) {
        printf("Muitos argumentos\n");
        return;
    } else {
        printf("Entre com o dia da semana (número).\n");
        return;
    }

    // Identifica o dia da semana baseado no número fornecido
    switch (diaSemana) {
        case 1:
            printf("Domingo\n");
            break;
        case 2:
            printf("Segunda\n");
            break;
        case 3:
            printf("Terça-Feira\n");
            break;
        case 4:
            printf("Quarta-Feira\n");
            break;
        case 5:
            printf("Quinta-Feira\n");
            break;
        case 6:
            printf("Sexta-Feira\n");
            break;
        case 7:
            printf("Sábado\n");
            break;
        default:
            printf("Dia inválido...\n");
            break;
    }

    return;
}
