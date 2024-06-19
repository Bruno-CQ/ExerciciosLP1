/**
 * @file main.c
 * @brief Programa para calcular média e estado dos alunos em suas matérias.
 *
 * Este programa solicita ao usuário a quantidade de matérias, notas e faltas de cada matéria,
 * calcula a média ponderada de cada uma, e determina se o aluno está aprovado, reprovado ou 
 * se precisa fazer a prova final. Leva em consideração também o número de faltas para reprovação.
 *
 * @author Bruno Costa Queiroz
 * @date 2024
 */

#include <stdio.h>

/**
 * @brief Função para calcular a necessidade e resultado da prova final.
 *
 * Esta função calcula se o aluno precisa fazer a prova final e, se necessário, 
 * verifica se a nota da prova final é suficiente para aprovação.
 *
 * @param media A média das notas da matéria.
 * @param necessario A nota necessária na prova final para aprovação.
 * @return Um inteiro indicando o resultado:
 *         - 3: Aprovado na prova final.
 *         - 4: Reprovado na prova final.
 */
int final(float media, float necessario);

/**
 * @brief Função principal que executa o programa de avaliação acadêmica.
 *
 * Esta função solicita ao usuário a quantidade de matérias, créditos, faltas, notas e pesos das provas,
 * calcula a média ponderada de cada matéria, verifica as condições de aprovação/reprovação e exibe
 * o resultado para cada matéria.
 *
 * @return 0 se o programa executou com sucesso.
 */
int avaliacao1(void) {
  int qtd_materias, creditos, faltas, aulas;
  float nota, peso, p_faltas;

  /// Solicita a quantidade de matérias
  printf("Informe a quantidade de matérias: ");
  scanf("%d", &qtd_materias);

  while (qtd_materias <= 0) {
    printf("Valor inválido. Informe novamente: ");
    scanf("%d", &qtd_materias);
  }

  int estado[qtd_materias];
  float media[qtd_materias], necessario[qtd_materias];

  for (int i = 0; i < qtd_materias; i++) {
    float acumulado = 0, peso_total = 0;

    /// Solicita a quantidade de créditos da matéria
    printf("Informe a quantidade de créditos da %dª matéria: ", i + 1);
    scanf("%d", &creditos);

    while (creditos < 2 || creditos > 10) {
      printf("Valor inválido. Informe novamente: ");
      scanf("%d", &creditos);
    }

    aulas = creditos * 15 * 60 / 50;

    /// Solicita o número de faltas
    printf("Informe o número de faltas da %dª matéria: ", i + 1);
    scanf("%d", &faltas);

    while (faltas < 0) {
      printf("Valor inválido. Informe novamente: ");
      scanf("%d", &faltas);
    }

    p_faltas = (faltas / (float)aulas) * 100;

    /// Solicita as notas e pesos das provas
    for (int j = 0; j < creditos; j++) {
      printf("Informe o peso da %dª nota: ", j + 1);
      scanf("%f", &peso);

      while (peso <= 0) {
        printf("Valor inválido. Informe novamente: ");
        scanf("%f", &peso);
      }

      printf("Informe a %dª nota: ", j + 1);
      scanf("%f", &nota);

      while (nota < 0) {
        printf("Valor inválido. Informe novamente: ");
        scanf("%f", &nota);
      }

      acumulado += (nota * peso);
      peso_total += peso;
    }

    media[i] = acumulado / peso_total + 0.01;

    if (media[i] >= 7) {
      estado[i] = 1;
    } else {
      printf("Não aprovado sem prova final na %dª matéria\n", i + 1);
      necessario[i] = (5 - media[i] * 0.6) / 0.4;
      if (necessario[i] > 10) {
        estado[i] = 2;
      } else {
        if (necessario[i] < 5) {
          necessario[i] = 5;
        }
        estado[i] = final(media[i], necessario[i]);
      }
    }

    if (p_faltas > 25) {
      estado[i] = 0;
    }
  }

  /// Exibe o estado final de cada matéria
  for (int k = 0; k < qtd_materias; k++) {
    switch (estado[k]) {
    case 0:
      printf("Reprovado por falta na %dª matéria.\nA média das notas foi de: %.1f\n", k + 1, media[k]);
      break;
    case 1:
      printf("Aprovado sem prova final na %dª matéria.\nA média das notas foi de: %.1f\n", k + 1, media[k]);
      break;
    case 2:
      printf("Reprovado sem direito a prova final na %dª matéria.\nA média das notas foi de: %.1f\n", k + 1, media[k]);
      break;
    case 3:
      printf("Aprovado por prova final na %dª matéria.\nA média das notas foi de: %.1f e era necessário tirar %.1f para passar na prova final\n", k + 1, media[k], necessario[k]);
      break;
    case 4:
      printf("Reprovado na prova final na %dª matéria.\nA média das notas foi de: %.1f e era necessário tirar %.1f para passar na prova final\n", k + 1, media[k], necessario[k]);
      break;
    }
  }

  return 0;
}

int final(float media, float necessario) {
  float nota_final;

  printf("Digite a nota da prova final: ");
  scanf("%f", &nota_final);

  while (nota_final < 0) {
    printf("Valor inválido. Informe novamente: ");
    scanf("%f", &nota_final);
  }

  if (nota_final >= necessario) {
    return 3;
  } else {
    return 4;
  }
}
