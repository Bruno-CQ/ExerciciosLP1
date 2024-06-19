/**
 * @file cadastro.c
 * @brief Função de cadastro de pessoa.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Função para realizar o cadastro de uma pessoa.
 *
 * Esta função solicita ao usuário que insira o nome, sobrenome e idade de uma pessoa,
 * armazenando essas informações em uma estrutura do tipo pessoa e, em seguida, exibe
 * as informações cadastradas.
 *
 * @return 0 se o cadastro for concluído com sucesso.
 */
int cadastro() {
  /**
   * @brief Estrutura que representa uma pessoa.
   */
  struct pessoa {
    char nome[50]; /**< Nome da pessoa */
    char sobrenome[50]; /**< Sobrenome da pessoa */
    int idade; /**< Idade da pessoa */
  };

  struct pessoa myPessoa;
  printf("\n---------- Cadastro ----------\n");
  printf("Nome......:  ");
  fgets(myPessoa.nome, 50, stdin);
  myPessoa.nome[strcspn(myPessoa.nome, "\n")] = 0;
  printf("Sobrenome.:  ");
  fgets(myPessoa.sobrenome, 50, stdin);
  myPessoa.sobrenome[strcspn(myPessoa.sobrenome, "\n")] = 0;
  printf("Idade.....:  ");
  scanf("%d", &myPessoa.idade);
  printf("\n---------- Show Cadastro ----------\n");
  printf("Nome..: %s %s\n", myPessoa.nome, myPessoa.sobrenome);
  printf("Idade.: %d\n", myPessoa.idade);

  return 0;
}
