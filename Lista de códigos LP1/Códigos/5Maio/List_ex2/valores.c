/**
 * @file main.c
 * @brief Programa para análise de valores numéricos.
 *
 * Este programa realiza diversas análises em torno de um valor numérico fornecido pelo usuário ou via argumento de linha de comando.
 * As análises incluem determinar o tipo do argumento (nulo, numérico ou alfabético), imprimir sequências crescentes, decrescentes e alternadas,
 * identificar números primos e perfeitos até o valor fornecido.
 *
 * @author Bruno Costa Queiroz
 * @date Data da última modificação: 2024-05-12
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Função para realizar diversas análises em torno de um valor numérico.
 *
 * Esta função recebe um argumento via linha de comando (ou diretamente se executado sem argumentos).
 * Ela realiza as seguintes operações:
 * - Determina o tipo do argumento (nulo, numérico ou alfabético).
 * - Imprime sequências crescentes, decrescentes e alternadas até o valor fornecido.
 * - Identifica e imprime números primos e perfeitos até o valor fornecido.
 *
 * @param argc Número de argumentos passados para o programa.
 * @param argv Vetor de strings que contém os argumentos passados para o programa.
 * @return Retorna 0 se o programa for executado com sucesso.
 */
int valores(int argc, char *argv[]);

/**
 * @brief Determina o tipo do argumento fornecido.
 *
 * Esta função verifica se o argumento é nulo, numérico ou alfabético e imprime a respectiva mensagem.
 *
 * @param arg Valor numérico a ser verificado.
 */
void tipoArg(int arg);

/**
 * @brief Imprime uma sequência crescente de números até o valor fornecido.
 *
 * @param arg Valor até o qual a sequência será impressa.
 */
void sequence(int arg);

/**
 * @brief Imprime uma sequência decrescente de números a partir do valor fornecido.
 *
 * @param arg Valor a partir do qual a sequência decrescente será impressa.
 */
void sequenceInv(int arg);

/**
 * @brief Imprime uma sequência alternada de números até o valor fornecido.
 *
 * @param arg Valor até o qual a sequência alternada será impressa.
 */
void altern(int arg);

/**
 * @brief Verifica se um número é primo.
 *
 * @param arg Número a ser verificado.
 * @param var Variável de controle (1 para suprimir a saída padrão de "É primo" ou "Não é primo").
 * @return Retorna 0 se o número for primo, caso contrário retorna 1.
 */
int cPrim(int arg, int var);

/**
 * @brief Imprime uma sequência de números primos até o valor fornecido.
 *
 * @param arg Valor até o qual a sequência de números primos será impressa.
 */
void primC(int arg);

/**
 * @brief Imprime uma sequência de números perfeitos até o valor fornecido.
 *
 * @param arg Valor até o qual a sequência de números perfeitos será impressa.
 */
void perfeitoC(int arg);

/**
 * @brief Verifica se um número é perfeito.
 *
 * Um número perfeito é aquele que é igual à soma de seus divisores próprios (excluindo ele mesmo).
 *
 * @param arg Número a ser verificado.
 * @return Retorna 1 se o número for perfeito, caso contrário retorna 0.
 */
int cPerfeito(int arg);

/**
 * @brief Função principal que inicia a análise dos valores.
 *
 * Esta função chama todas as funções de análise para o valor fornecido via argumento.
 * Se nenhum argumento for fornecido, ela imprime uma mensagem de erro.
 *
 * @param argc Número de argumentos passados para o programa.
 * @param argv Vetor de strings que contém os argumentos passados para o programa.
 * @return Retorna 0 se o programa for executado com sucesso.
 */
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Número inválido de argumentos.\n");
    printf("Uso: %s <valor>\n", argv[0]);
    return 1;
  }

  valores(argc, argv);

  return 0;
}

// Implementações das funções omitidas para economia de espaço.
