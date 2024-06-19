/**
 * @file main.c
 * @brief Programa para manipulação de strings.
 *
 * Este programa permite ao usuário escolher entre duas funções: manipulação de cores e manipulação de frases.
 * A função de manipulação de cores exibe cada caractere de uma cor inserida pelo usuário em uma nova linha.
 * A função de manipulação de frases exibe cada palavra de uma frase inserida pelo usuário em uma nova linha.
 *
 * @author Bruno Costa Queiroz
 * @date Data da última modificação: 2024-06-05
 */

#include <stdio.h>
#define N 32

/**
 * @brief Função principal para escolha entre as funções de manipulação de strings.
 *
 * Esta função exibe um menu para o usuário escolher entre as funções disponíveis: manipulação de cores e manipulação de frases.
 * Dependendo da escolha do usuário, chama a função correspondente.
 *
 * @return Retorna 0 se o programa for executado com sucesso.
 */
int string();

/**
 * @brief Função para manipulação de uma cor.
 *
 * Esta função solicita ao usuário que digite uma cor e exibe cada caractere da cor em uma nova linha.
 *
 * @return Retorna 0 se a operação for concluída com sucesso.
 */
int cor();

/**
 * @brief Função para manipulação de uma frase.
 *
 * Esta função solicita ao usuário que digite uma frase e exibe cada palavra da frase em uma nova linha.
 *
 * @return Retorna 0 se a operação for concluída com sucesso.
 */
int frase();

int main() {
    string();
    return 0;
}

int string() {
  int n;
  printf("Escolha a função:\n1 - Cor\n2 - Frase\n");
  scanf("%d", &n);
  switch (n) {
    case 1:
      cor();
      break;
    case 2:
      frase();
      break;
    default:
      printf("Função não encontrada.\n");
  }
  return 0;
}

int cor() {
  char corl[N];
  int i = 0;

  printf("Digite uma cor: ");
  scanf("%s", corl);
  printf("Cor: %s\n", corl);
  while (corl[i] != '\0')
    printf("%c\n", corl[i++]);

  return 0;
}

int frase() {
  char frase[N];
  int i = 0;
  printf("Digite uma frase: ");
  scanf(" %[^\n]", frase);
  printf("Frase: %s\n", frase);
  while (frase[i] != '\0') {
    if (frase[i] == ' ') {
        printf("\n");
        i++;
    } else {
        printf("%c", frase[i++]);
    }
  }
  return 0;
}
