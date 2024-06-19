/**
 * @file main.c
 * @brief Programa para cálculo do IMC e análise com base na idade e sexo.
 *
 * Este programa calcula o Índice de Massa Corporal (IMC) com base no peso e altura fornecidos pelo usuário.
 * Além disso, realiza uma análise do IMC considerando a idade e o sexo do usuário.
 * A análise inclui a categorização do IMC em diferentes faixas de acordo com a idade e sexo.
 *
 * @author Bruno Costa Queiroz
 * @date Data da última modificação: 2024-05-12
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Função principal para cálculo do IMC e análise.
 *
 * Esta função recebe a idade do usuário como argumento via linha de comando.
 * Em seguida, solicita o peso e altura do usuário e calcula o IMC.
 * Baseado no IMC calculado e na idade (e sexo, se menor que 20 anos), imprime uma mensagem categorizando o IMC.
 *
 * @param argc Número de argumentos passados para o programa.
 * @param argv Vetor de strings que contém os argumentos passados para o programa.
 * @return Retorna 0 se o programa for executado com sucesso.
 */
int imc(int argc, char *argv[]);

/**
 * @brief Calcula o Índice de Massa Corporal (IMC) com base no peso e altura fornecidos.
 *
 * @param peso Peso do usuário em quilogramas.
 * @param altura Altura do usuário em metros.
 * @return Retorna o valor do IMC calculado.
 */
float imcC(float peso, float altura);

/**
 * @brief Realiza a análise do IMC baseado na idade e categoriza em faixas específicas.
 *
 * Esta função imprime uma mensagem com base no IMC calculado e na idade do usuário.
 * Se a idade for menor que 20 anos, solicita também o sexo do usuário para categorização adicional.
 *
 * @param idade Idade do usuário fornecida como argumento.
 * @param imc Valor do IMC calculado.
 * @return Retorna 0 se a análise for concluída com sucesso.
 */
int resultado(int idade, float imc);

/**
 * @brief Função principal que inicia o programa de cálculo do IMC.
 *
 * Esta função verifica se o número correto de argumentos foi fornecido.
 * Se nenhum argumento for fornecido, ela imprime uma mensagem de erro.
 *
 * @param argc Número de argumentos passados para o programa.
 * @param argv Vetor de strings que contém os argumentos passados para o programa.
 * @return Retorna 0 se o programa for executado com sucesso.
 */
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Número inválido de argumentos.\n");
    printf("Uso: %s <idade>\n", argv[0]);
    return 1;
  }

  imc(argc, argv);

  return 0;
}

/**
 * @brief Calcula o Índice de Massa Corporal (IMC) com base no peso e altura fornecidos.
 *
 * Fórmula: IMC = peso / altura^2
 *
 * @param peso Peso do usuário em quilogramas.
 * @param altura Altura do usuário em metros.
 * @return Retorna o valor do IMC calculado.
 */
float imcC(float peso, float altura) {
  return peso / pow(altura, 2);
}

/**
 * @brief Realiza a análise do IMC baseado na idade e categoriza em faixas específicas.
 *
 * Esta função imprime uma mensagem com base no IMC calculado e na idade do usuário.
 * Se a idade for menor que 20 anos, solicita também o sexo do usuário para categorização adicional.
 *
 * @param idade Idade do usuário fornecida como argumento.
 * @param imc Valor do IMC calculado.
 * @return Retorna 0 se a análise for concluída com sucesso.
 */
int resultado(int idade, float imc) {
  if (idade >= 20) {
    if (imc < 18.5) {
      printf("Seu IMC é %.2f, baseado na sua idade (%d), você está abaixo do peso\n", imc, idade);
    } else if (imc < 24.9) {
      printf("Seu IMC é %.2f, baseado na sua idade (%d), você está no peso normal\n", imc, idade);
    } else if (imc < 29.9) {
      printf("Seu IMC é %.2f, baseado na sua idade (%d), você está com sobrepeso\n", imc, idade);
    } else if (imc < 34.9) {
      printf("Seu IMC é %.2f, baseado na sua idade (%d), você está com obesidade de grau 1\n", imc, idade);
    } else if (imc < 39.9) {
      printf("Seu IMC é %.2f, baseado na sua idade (%d), você está com obesidade de grau 2\n", imc, idade);
    } else {
      printf("Seu IMC é %.2f, baseado na sua idade (%d), você está com obesidade de grau 3\n", imc, idade);
    }
  } else {
    char sexo;
    float faixa1, faixa2, faixa3;
    printf("Digite seu sexo: (Não confundir com gênero)\nM - Masculino\nF - Feminino\n");
    scanf(" %c", &sexo);
    while (sexo != 'M' && sexo != 'F') {
      printf("Resposta inválida, digite novamente: ");
      scanf(" %c", &sexo);
    }
    if (sexo == 'F') {
      if (idade == 19) {
        faixa1 = 16.87, faixa2 = 25.85, faixa3 = 30.72;
      } else if (idade == 18) {
        faixa1 = 16.71, faixa2 = 25.56, faixa3 = 30.22;
      } else if (idade == 17) {
        faixa1 = 16.59, faixa2 = 25.23, faixa3 = 29.72;
      } else if (idade == 16) {
        faixa1 = 16.37, faixa2 = 24.74, faixa3 = 29.1;
      } else if (idade == 15) {
        faixa1 = 16.01, faixa2 = 24.29, faixa3 = 28.51;
      } else if (idade == 14) {
        faixa1 = 15.67, faixa2 = 23.88, faixa3 = 27.97;
      } else if (idade == 13) {
        faixa1 = 15.36, faixa2 = 23.08, faixa3 = 27.07;
      } else if (idade == 12) {
        faixa1 = 14.98, faixa2 = 22.17, faixa3 = 26.95;
      } else if (idade == 11) {
        faixa1 = 14.6, faixa2 = 21.18, faixa3 = 25.59;
      } else if (idade == 10) {
        faixa1 = 14.23, faixa2 = 20.19, faixa3 = 24.2;
      }
    } else {
      if (idade == 19) {
        faixa1 = 17.8, faixa2 = 26.36, faixa3 = 30.66;
      } else if (idade == 18) {
        faixa1 = 17.54, faixa2 = 25.95, faixa3 = 30.02;
      } else if (idade == 17) {
        faixa1 = 17.31, faixa2 = 25.28, faixa3 = 29.32;
      } else if (idade == 16) {
        faixa1 = 17.01, faixa2 = 24.45, faixa3 = 28.53;
      } else if (idade == 15) {
        faixa1 = 16.59, faixa2 = 23.63, faixa3 = 27.76;
      } else if (idade == 14) {
        faixa1 = 16.18, faixa2 = 22.77, faixa3 = 26.93;
      } else if (idade == 13) {
        faixa1 = 15.73, faixa2 = 21.93, faixa3 = 25.93;
      } else if (idade == 12) {
        faixa1 = 15.24, faixa2 = 21.12, faixa3 = 24.89;
      } else if (idade == 11) {
        faixa1 = 14.83, faixa2 = 20.35, faixa3 = 23.7;
      } else if (idade == 10) {
        faixa1 = 14.42, faixa2 = 19.6, faixa3 = 22.6;
      }
    }
    if (imc < faixa1) {
      printf("Seu IMC é %.2f, baseado na sua idade (%d), você está abaixo do peso\n", imc, idade);
    } else if (imc < faixa2) {
      printf("Seu IMC é %.2f, baseado na sua idade (%d), você está no peso normal\n", imc, idade);
    } else if (imc < faixa3) {
      printf("Seu IMC é %.2f, baseado na sua idade (%d), você está com sobrepeso\n", imc, idade);
    } else {
      printf("Seu IMC é %.2f, baseado na sua idade (%d), você está com obesidade\n", imc, idade);
    }
  }
  return 0;
}

/**
 * @brief Função para cálculo do IMC e análise.
 *
 * Esta função realiza todas as operações necessárias para calcular o IMC e analisar o resultado baseado na idade e sexo.
 * Se o número de argumentos fornecidos for inválido, a função imprime uma mensagem de erro.
 *
 * @param argc Número de argumentos passados para o programa.
 * @param argv Vetor de strings que contém os argumentos passados para o programa.
 * @return Retorna 0 se o programa for executado com sucesso.
 */
int imc(int argc, char *argv[]) {
  float peso, altura, imc;
  int idade;
  printf("Idade -> %s\n", argv[1]);

  if (argc == 2) {
    idade = atoi(argv[1]);
  } else if (argc > 2) {
    printf("Muitos argumentos\n");
    return 1;
  } else {
    printf("Entre com um número.\n");
    return 1;
  }

  if (idade < 6) {
    printf("Idade não disponível\n");
    return 1;
  }

  printf("Digite seu peso (kg): ");
  scanf(" %f", &peso);
  printf("Digite sua altura (m): ");
  scanf(" %f", &altura);

  imc = imcC(peso, altura);
  resultado(idade, imc);

  printf("IMC: %.2f\n", imc);
  return 0;
}
