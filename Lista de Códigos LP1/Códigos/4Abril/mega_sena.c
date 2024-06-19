/**
 * @file mega_sena.c
 * @brief Função para realizar sorteios da Mega-Sena.
 * @date 15/04/2024
 * 
 * Este arquivo contém a implementação da função mega_sena, que realiza sorteios
 * da Mega-Sena de acordo com as opções escolhidas pelo usuário.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Função para realizar sorteios da Mega-Sena.
 * 
 * Esta função permite ao usuário escolher entre dois tipos de sorteio:
 * - Sortear até que todas as 6 dezenas sejam sorteadas.
 * - Sortear de apenas 1 pote até as 6 dezenas serem sorteadas.
 * 
 * @return void
 */
void mega_sena(void) {
    short int a, b, c, d, e, f, con; // Variáveis para armazenar as dezenas e a escolha do usuário

    srand(time(NULL)); // Inicializa a semente para gerar números aleatórios

    // Solicita as 6 dezenas ao usuário
    printf("Insira as 6 dezenas a serem sorteadas: ");
    scanf("%hd %hd %hd %hd %hd %hd", &a, &b, &c, &d, &e, &f);

    // Solicita ao usuário o tipo de sorteio
    printf("Escolha o tipo de sorteio:\n1 - Sortear até ganhar\n2 - Sortear de apenas 1 pote até as 6 dezenas saírem\n");
    scanf("%hd", &con);

    // Validação da escolha do usuário
    while (con != 1 && con != 2) {
        printf("Opção inválida. Escolha novamente: ");
        scanf("%hd", &con);
    }

    // Validação das dezenas inseridas pelo usuário
    while (a == b || a == c || a == d || a == e || a == f || 
           b == c || b == d || b == e || b == f || 
           c == d || c == e || c == f || 
           d == e || d == f || 
           e == f || 
           a <= 0 || a > 60 || 
           b <= 0 || b > 60 || 
           c <= 0 || c > 60 || 
           d <= 0 || d > 60 || 
           e <= 0 || e > 60 || 
           f <= 0 || f > 60) {
        printf("As dezenas devem estar entre 1 e 60 e não podem ser iguais. Tente novamente.\n");
        printf("Insira as 6 dezenas a serem sorteadas: ");
        scanf("%hd %hd %hd %hd %hd %hd", &a, &b, &c, &d, &e, &f);
    }

    // Chama a função correspondente ao tipo de sorteio escolhido
    if (con == 2) {
        pote(a, b, c, d, e, f);
    } else if (con == 1) {
        sorteio(a, b, c, d, e, f);
    }
}

/**
 * @brief Função para realizar sorteio até que todas as 6 dezenas sejam sorteadas.
 * 
 * Esta função sorteia números aleatórios até que todas as 6 dezenas escolhidas pelo usuário sejam sorteadas.
 * @param a Primeira dezena escolhida pelo usuário.
 * @param b Segunda dezena escolhida pelo usuário.
 * @param c Terceira dezena escolhida pelo usuário.
 * @param d Quarta dezena escolhida pelo usuário.
 * @param e Quinta dezena escolhida pelo usuário.
 * @param f Sexta dezena escolhida pelo usuário.
 * @return void
 */
void sorteio(int a, int b, int c, int d, int e, int f) {
    short int a2 = 0, b2 = 0, c2 = 0, d2 = 0, e2 = 0, f2 = 0; // Flags para indicar se cada dezena foi sorteada
    short int n, n2, nD[60], nR = 60; // Variáveis para o sorteio
    unsigned long int a1 = 0; // Contador de tentativas

    // Inicializa o vetor nD com os números de 1 a 60
    for (int i = 0; i < 60; i++) {
        nD[i] = i + 1;
    }

    float timei = clock(); // Marca o tempo inicial de execução

    // Loop principal para realizar o sorteio até todas as dezenas serem sorteadas
    while (a2 == 0 || b2 == 0 || c2 == 0 || d2 == 0 || e2 == 0 || f2 == 0) {
        // Sorteia um número dentro do range disponível
        n = rand() % nR;
        n2 = nD[n];
        nD[n] = nD[nR - 1];
        nR--;

        // Verifica se o número sorteado é uma das dezenas escolhidas
        if (a == n2) a2 = 1;
        if (b == n2) b2 = 1;
        if (c == n2) c2 = 1;
        if (d == n2) d2 = 1;
        if (e == n2) e2 = 1;
        if (f == n2) f2 = 1;

        // Se todas as dezenas foram sorteadas, imprime o resultado
        if (a2 == 1 && b2 == 1 && c2 == 1 && d2 == 1 && e2 == 1 && f2 == 1) {
            a1++;
            printf("Levou %ld tentativas para sortear as 6 dezenas\n", a1);
            break;
        } else if (nR == 0) {
            // Se o range de sorteio se esgotar, reinicializa para novo sorteio
            for (int i = 0; i < 60; i++) {
                nD[i] = i + 1;
            }
            nR = 60;
            a1++;
        }
    }

    float timef = clock(); // Marca o tempo final de execução
    float time = (timef - timei) / CLOCKS_PER_SEC; // Calcula o tempo de execução em segundos
    printf("Levou %f segundos para sortear as 6 dezenas\n", time); // Imprime o tempo de execução
}

/**
 * @brief Função para realizar sorteio de apenas 1 pote até que as 6 dezenas sejam sorteadas.
 * 
 * Esta função sorteia números aleatórios de apenas 1 pote até que todas as 6 dezenas escolhidas pelo usuário sejam sorteadas.
 * @param a Primeira dezena escolhida pelo usuário.
 * @param b Segunda dezena escolhida pelo usuário.
 * @param c Terceira dezena escolhida pelo usuário.
 * @param d Quarta dezena escolhida pelo usuário.
 * @param e Quinta dezena escolhida pelo usuário.
 * @param f Sexta dezena escolhida pelo usuário.
 * @return void
 */
void pote(int a, int b, int c, int d, int e, int f) {
    short int a1 = 0, b1 = 0, c1 = 0, d1 = 0, e1 = 0, f1 = 0; // Contadores de tentativas para cada dezena
    short int a2 = 0, b2 = 0, c2 = 0, d2 = 0, e2 = 0, f2 = 0; // Flags para indicar se cada dezena foi sorteada
    short int n, n2, nD[60], nR = 60; // Variáveis para o sorteio

    // Inicializa o vetor nD com os números de 1 a 60
    for (int i = 0; i < 60; i++) {
        nD[i] = i + 1;
    }

    // Loop principal para realizar o sorteio até que todas as dezenas sejam sorteadas
    while (nR > 0) {
        // Sorteia um número dentro do range disponível
        n = rand() % nR;
        n2 = nD[n];
        nD[n] = nD[nR - 1];
        nR--;

        // Verifica se o número sorteado é uma das dezenas escolhidas
        if (a2 == 0) {
            if (a != n2) {
                a1++;
            } else {
                a1++;
                a2 = 1;
            }
        }
        if (b2 == 0) {
            if (b != n2 && b2 == 0) {
                b1++;
            } else {
                b1++;
                b2 = 1;
            }
        }
        if (c2 == 0) {
            if (c != n2 && c2 == 0) {
                c1++;
            } else {
                c1++;
                c2 = 1;
            }
        }
        if (d2 == 0) {
            if (d != n2 && d2 == 0) {
                d1++;
            } else {
                d1++;
                d2 = 1;
            }
        }
        if (e2 == 0) {
            if (e != n2 && e2 == 0) {
                e1++;
            } else {
                e1++;
                e2 = 1;
            }
        }
        if (f2 == 0) {
            if (f != n2 && f2 == 0) {
                f1++;
            } else {
                f1++;
                f2 = 1;
            }
        }

        // Se todas as dezenas foram sorteadas, imprime o resultado
        if (a2 == 1 && b2 == 1 && c2 == 1 && d2 == 1 && e2 == 1 && f2 == 1) {
            break;
        }
    }

    // Imprime o número de tentativas para sortear cada dezena individualmente
    printf("Levou %d tentativas para sortear a dezena %d\n", a1, a);
    printf("Levou %d tentativas para sortear a dezena %d\n", b1, b);
    printf("Levou %d tentativas para sortear a dezena %d\n", c1, c);
    printf("Levou %d tentativas para sortear a dezena %d\n", d1, d);
    printf("Levou %d tentativas para sortear a dezena %d\n", e1, e);
    printf("Levou %d tentativas para sortear a dezena %d\n", f1, f);
}

/**
 * @brief Função principal (main).
 * 
 * Função principal que chama a função mega_sena para iniciar o programa.
 * @return 0
 */
int main() {
    mega_sena(); // Chama a função para realizar o sorteio da Mega-Sena
    return 0;
}
