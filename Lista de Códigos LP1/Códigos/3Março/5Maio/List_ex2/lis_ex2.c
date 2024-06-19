/**
 * @file main.c
 * @brief Programa para escolher e executar diferentes exercícios de acordo com a escolha do usuário.
 *
 * Este programa permite ao usuário escolher entre diferentes exercícios numerados e executar o exercício escolhido
 * passando os argumentos necessários (se houver) através de argc e argv.
 * Os exercícios disponíveis são:
 * 1. Valores: Manipulação de valores numéricos.
 * 2. Temperatura: Conversão de temperatura.
 * 3. MDC: Cálculo do Máximo Divisor Comum.
 * 4. IMC: Cálculo do Índice de Massa Corporal.
 * 6. Dado: Simulação de lançamento de dado.
 * 7. Voltar: Retorno ao menu principal.
 *
 * @author Bruno Costa Queiroz
 * @date Data da última modificação: 2024-06-18
 */

#include <stdio.h>

/**
 * @brief Função para listar e executar exercícios conforme a escolha do usuário.
 *
 * Esta função exibe um menu de exercícios numerados e solicita ao usuário que escolha um exercício.
 * Com base na escolha, chama a função correspondente ao exercício selecionado, passando argc e argv como necessário.
 *
 * @param argc Número de argumentos passados para o programa.
 * @param argv Vetor de strings que contém os argumentos passados para o programa.
 */
void list_ex2(int argc, char *argv[]) {
  int escolha;
  printf("Escolha o exercício:\n"
         "1 - Valores (Usa argc [1 num])\n"
         "2 - Temperatura (Usa argc [1 num])\n"
         "3 - MDC (Usa argc [1 num])\n"
         "4 - IMC (Usa argc [1 num])\n"
         "6 - Dado (Usa argc [1 num])\n"
         "7 - Voltar\n");
  scanf("%d", &escolha);

  switch (escolha) {
    case 1:
      valores(argc, argv);
      break;
    case 2:
      temperatura(argc, argv);
      break;
    case 3:
      mdc(argc, argv);
      break;
    case 4:
      imc(argc, argv);
      break;
    case 6:
      dado(argc, argv);
      break;
    case 7:
      main(argc, argv);
      break;
    default:
      printf("Escolha inválida");
  }
}

// Protótipos das funções que serão chamadas pelo menu
void valores( argc, char *argv[]);
void temperatura(int argc, char *argv[]);
void mdc(int argc, char *argv[]);
void imc(int argc, char *argv[]);
void dado(int argc, char *argv[]);

/**
 * @brief Função principal que inicia a execução do programa.
 *
 * Chama a função list_ex2 para exibir o menu de exercícios e executar o exercício escolhido pelo usuário.
 *
 * @param argc Número de argumentos passados para o programa.
 * @param argv Vetor de strings que contém os argumentos passados para o programa.
 * @return Retorna 0 indicando que o programa foi executado com sucesso.
 */
int main(int argc, char *argv[]) {
  list_ex2(argc, argv);
  return 0;
}
