/**
 * @file main.c
 * @brief Implementação da função conversor para converter um número inteiro em diferentes formatos.
 * @date 26/03/2024
 * 
 * Este arquivo contém a implementação da função conversor, que recebe um número inteiro positivo
 * e o converte em decimal, octal, hexadecimal e caractere imprimível, se possível.
 */

#include <stdio.h>

/**
 * @brief Função para converter um número inteiro em diferentes formatos.
 * 
 * Esta função solicita ao usuário um número inteiro positivo, verifica sua faixa e converte-o em
 * decimal, octal, hexadecimal e caractere imprimível, se possível. Se o número for menor que 32,
 * o caractere correspondente não imprimível será substituído por 32. Se for maior que 126, será
 * convertido para o intervalo de 0 a 127.
 * 
 * @return void
 */
void conversor() {
  int tea;

  printf("Digite um número inteiro positivo: ");
  scanf("%d", &tea);

  tea = (tea < 0) ? -tea : tea;

  if (tea >= 32 && tea <= 126) {
    printf("%d correspondente a: \n%d em decimal\n%o em octal\n%x em hexadecimal\n%c em caractere\n", tea, tea, tea, tea, tea);
  } else if (tea < 32) {
    tea = 32;
    printf("O número digitado é menor que 32, e como é um caractere não imprimível, será substituído por 32\n%d em decimal\n%o em octal\n%x em hexadecimal\n%c em caractere\n", tea, tea, tea, tea);
  } else {
    tea = tea % 128;
    printf("O número digitado é maior que 126, então será convertido:\n%d em decimal\n%o em octal\n%x em hexadecimal\n%c em caractere\n", tea, tea, tea, tea);
  }
  return;
}
