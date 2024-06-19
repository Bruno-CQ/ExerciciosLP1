/**
 * @file main.c
 * @brief Programa principal para execução de diferentes funções de acordo com a escolha do usuário.
 *
 * Este programa oferece ao usuário a opção de escolher entre várias funções diferentes,
 * cada uma realizando uma tarefa específica. A escolha é feita através de um número inteiro
 * digitado pelo usuário.
 *
 * @author Bruno Costa Queiroz
 * @date 2024
 */

#include <stdio.h>

/**
 * @brief Função principal que permite ao usuário escolher qual função executar.
 *
 * A função exibe um menu de opções para o usuário, onde cada opção corresponde a uma função específica.
 * Depois que o usuário faz sua escolha, a função correspondente é chamada para execução.
 *
 * @param argc Número de argumentos da linha de comando.
 * @param argv Vetor de argumentos da linha de comando.
 * @return 0 se o programa executou com sucesso.
 */
int main(int argc, char *argv[]) {
  int escolha;

  // Exibição do menu de opções
  printf("Escolha a função:\n");
  printf("1 - Hello World\n");
  printf("2 - Quatro Operações Básicas\n");
  printf("3 - Torre de Hanói\n");
  printf("4 - Teste do If\n");
  printf("5 - Lista de Exercicios 1\n");
  printf("6 - IRRF\n");
  printf("7 - Mega-Sena\n");
  printf("8 - Geometria Plana\n");
  printf("9 - Calcular Pi com Monte Carlo\n");
  printf("10 - Potenciação\n");
  printf("11 - Tempo de Loop (PA de razão 1)\n");
  printf("12 - Tempo de Loop (PA de Números Primos)\n");
  printf("13 - Dia da Semana (Usa argc [1 num])\n");
  printf("14 - Números (Usa argc [3 num])\n");
  printf("15 - Cálculo de Notas\n");
  printf("16 - Array\n");
  printf("17 - Array: Tamanho, Soma e Média (Usa argc [1 num])\n");
  printf("18 - Arrays Multidimensionais\n");
  printf("19 - Strings\n");
  printf("20 - Ordenador Alfabético\n");
  printf("21 - Teste de Biblioteca\n");
  printf("22 - Lista de Exercícios 2\n");
  printf("23 - Avaliação 2\n");

  // Leitura da escolha do usuário
  scanf("%d", &escolha);

  // Execução da função correspondente à escolha do usuário
  switch (escolha) {
    case 1:
      hello();
      break;
    case 2:
      q_opr1();
      break;
    case 3:
      hanoi();
      break;
    case 4:
      if_test();
      break;
    case 5:
      list_ex1();
      break;
    case 6:
      irrf();
      break;
    case 7:
      mega_sena();
      break;
    case 8:
      geo_plana();
      break;
    case 9:
      calc_pi();
      break;
    case 10:
      potencia();
      break;
    case 11:
      loop_time(1);
      break;
    case 12:
      loop_time(2);
      break;
    case 13:
      dia_sem(argc, argv);
      break;
    case 14:
      numeros(argc, argv);
      break;
    case 15:
      avaliacao1();
      break;
    case 16:
      array1();
      break;
    case 17:
      array2(argc, argv);
      break;
    case 18:
      array3();
      break;
    case 19:
      string();
      break;
    case 20:
      ordenador();
      break;
    case 21:
      biblioteca(argc, argv);
      break;
    case 22:
      list_ex2(argc, argv);
      break;
    case 23:
      avaliacao2();
      break;
    default:
      printf("Escolha inválida\n");
  }

  return 0;
}
