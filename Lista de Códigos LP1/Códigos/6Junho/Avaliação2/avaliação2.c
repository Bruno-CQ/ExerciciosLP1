/**
 * @file avaliacao2.c
 * @brief Função de avaliação com seleção de opções.
 */

#include <stdio.h>

/**
 * @brief Função que apresenta um menu de opções e executa a função correspondente à escolha do usuário.
 *
 * Esta função exibe um menu com várias opções numeradas e solicita ao usuário que escolha uma delas.
 * Dependendo da escolha do usuário, a função executa a função correspondente ou retorna ao programa principal.
 * Se o usuário escolher uma opção inválida, exibe uma mensagem informando isso.
 */
int avaliacao2() {
  int escolha;
  printf("Escolha uma opção:\n1 - Array Int\n2 - Array Float\n3 - Array Bidimensional\n6 - Palavras Cruzadas\n7 - Voltar\n");
  scanf("%d", &escolha);
  switch(escolha) {
    case 1:
      array4(); // Chama a função array4() para tratar a opção 1
      break;
    case 2:
      array5(); // Chama a função array5() para tratar a opção 2
      break;
    case 7:
      main();   // Retorna ao programa principal se escolher a opção 7
      break;
    default:
      printf("Opção inválida\n"); // Exibe mensagem se a escolha não estiver entre 1, 2 ou 7
  }
}
