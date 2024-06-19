/**
 * @file main.c
 * @brief Implementação da função list_ex1 para apresentar um menu de escolha de exercícios.
 * @date 20/03/2024
 * 
 * Este arquivo contém a implementação da função list_ex1, que exibe um menu para o usuário escolher
 * entre diversos exercícios disponíveis. Cada escolha chama uma função correspondente para executar
 * o exercício selecionado.
 */

#include <stdio.h>

/**
 * @brief Função para apresentar um menu de escolha de exercícios e chamar a função correspondente.
 * 
 * Esta função exibe um menu com opções numeradas de exercícios. O usuário pode escolher uma opção,
 * e a função chama outra função correspondente ao exercício escolhido.
 * 
 * As opções disponíveis incluem tipos de dados, operações matemáticas básicas, conversor, intervalos
 * de tipos numéricos, impressão de números de 1 a 6, progressão aritmética, desenho de linhas e quadrados.
 * 
 * @return void
 */
void list_ex1() {
  int escolha;
  printf("Escolha o exercício:\n1 - Tipos de dados\n2 - Quatro operações básicas\n3 - Conversor\n4 - Intervalo de Short Int\n5 - Intervalo de Int\n6 - De 1 a 6\n7 - Progressão Aritmética\n8 - Linha\n9 - Quadrado\n10 - Voltar\n");
  scanf("%d", &escolha);

  switch (escolha) {
    case 1:
      tipos_dados();
      break;
    case 2:
      q_opr2();
      break;
    case 3:
      conversor();
      break;
    case 4:
      intervalos(1);
      break;
    case 5:
      intervalos(2);
      break;
    case 6:
      um_6();
      break;
    case 7:
      prog_arit();
      break;
    case 8:
      formas(1);
      break;
    case 9:
      formas(2);
      break;
    case 10:
      main();
      break;
    default:
      printf("Escolha inválida");
  }
  return;
}
