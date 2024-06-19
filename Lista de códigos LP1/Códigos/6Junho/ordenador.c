/**
 * @file ordenador.c
 * @brief Funções para ordenação e manipulação de nomes.
 *
 * Este programa solicita ao usuário uma quantidade de nomes, os armazena, ordena-os
 * alfabeticamente, e exibe várias informações sobre os nomes inseridos.
 *
 * @author Bruno Costa Queiroz
 * @date 2024
 */

#include <stdio.h>
#include <string.h>
#include <locale.h>

/**
 * @brief Função principal que executa a ordenação e manipulação de nomes.
 *
 * Esta função solicita ao usuário uma quantidade de nomes, armazena-os, ordena-os
 * em ordem alfabética, e exibe diversas informações sobre os nomes inseridos,
 * incluindo o primeiro nome, último nome, nome(s) do meio e ordem inversa.
 *
 * @return 0 se o programa executou com sucesso.
 */
int ordenador() {
  setlocale(LC_ALL, ""); // Permite o uso de caracteres acentuados

  unsigned int q; // Quantidade de nomes
  printf("Informe a quantidade de nomes: ");
  scanf("%d", &q);

  // Validação da quantidade de nomes
  while (q <= 0) {
    printf("Quantidade de nomes inválida, tente novamente.\nInforme a quantidade de nomes: ");
    scanf("%d", &q);
  }

  char nome[q][64]; // Matriz para armazenar os nomes
  char ordem[64]; // Variável auxiliar para ordenação

  // Leitura dos nomes digitados pelo usuário
  for(int i = 0; i < q; i++) {
    printf("Digite o nome: ");
    scanf(" %[^\n]", nome[i]);
    getchar(); // Limpa o buffer do teclado
  }

  // Exibição da ordem digitada dos nomes
  printf("Ordem digitada:\n");
  for(int i = 0; i < q; i++) {
    printf("%s\n", nome[i]);
  }

  // Ordenação dos nomes em ordem alfabética
  for(int i = 0; i < q; i++) {
    for(int j = i + 1; j < q; j++) {
      if(strcoll(nome[i], nome[j]) > 0) {
        strcpy(ordem, nome[i]);
        strcpy(nome[i], nome[j]);
        strcpy(nome[j], ordem);
      }
    }
  }

  // Exibição da ordem alfabética dos nomes
  printf("Ordem alfabética:\n");
  for(int i = 0; i < q; i++) {
    printf("%s\n", nome[i]);
  }

  // Exibição do primeiro e último nome
  printf("Primeiro nome: %s\nÚltimo nome: %s\n", nome[0], nome[q-1]);

  // Exibição do(s) nome(s) do meio
  if(q == 1) {
    printf("Nome do meio: %s\n", nome[0]);
  } else if(q % 2 == 0) {
    printf("Nomes do meio: %s e %s\n", nome[q/2 - 1], nome[q/2]);
  } else {
    printf("Nome do meio: %s\n", nome[q/2]);
  }

  // Exibição dos nomes em ordem inversa
  printf("Nomes em ordem inversa:\n");
  for(int i = q-1; i >= 0; i--) {
    printf("%s\n", nome[i]);
  }

  return 0;
}
