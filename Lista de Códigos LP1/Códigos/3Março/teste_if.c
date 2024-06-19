/**
 * @file main.c
 * @brief Implementação da função if_test para testes de condicional e conversão de char para int.
 * @date 20/03/2024
 * 
 * Este arquivo contém a implementação da função if_test, que realiza testes de condicional if
 * baseados na forma do código e demonstra a conversão de char para int.
 */

#include <stdio.h>

/**
 * @brief Função para testar condicionais if e conversão de char para int.
 * 
 * Esta função inicializa uma variável char 'a' com o valor 'B', imprime seu valor decimal,
 * e então testa a condição if baseada na comparação de 'a' com 'b'. Em seguida, imprime
 * mensagens dependendo do resultado da condição if.
 * 
 * Além disso, a função imprime uma mensagem adicional longa para demonstração.
 * 
 * @return void
 */
void if_test() {
   char a = 'B';
   printf("Decimal of a = %d\n", a);

   if (a != 'b') {
      printf("Value of a = a is ( %c )\n", a);
   } else {
      printf("Value of a != a is ( %c )\n", a);
   }

   printf("Wenomechainsama Tumajarbisaun Wifenlooof Eselifterbraun Anweculbetugtbaby Aslonskysrblu Yuaksoinocenow Buchyulaidsosun\n");
   return;
}
