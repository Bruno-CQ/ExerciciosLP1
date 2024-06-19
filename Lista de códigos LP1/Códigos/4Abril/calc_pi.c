/**
 * @file main.c
 * @brief Implementação para estimar o valor de pi usando o método de Monte Carlo.
 * @date 30/04/2024
 * 
 * Este arquivo contém a implementação da função calc_pi, que utiliza o método de Monte Carlo
 * para estimar o valor de pi (π). A função gera um grande número de amostras aleatórias dentro
 * de um quadrado unitário e conta quantas dessas amostras caem dentro de um círculo de raio 1
 * inscrito no quadrado. O valor de pi é então estimado usando a relação entre a área do círculo
 * e a área do quadrado.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float randomF();
float estim_pi(int n);

/**
 * @brief Função principal para estimar o valor de pi usando o método de Monte Carlo.
 * 
 * A função calcula uma estimativa do valor de pi utilizando o método de Monte Carlo.
 * Ela gera um grande número de amostras aleatórias dentro de um quadrado unitário e
 * determina quantas dessas amostras estão dentro de um círculo de raio 1 inscrito no
 * quadrado. O valor de pi é estimado pela relação entre o número de pontos dentro do
 * círculo e o total de pontos gerados.
 * 
 * @return void
 */
void calc_pi() {
    unsigned int num_sample = 1000000; // Número de amostras (pontos aleatórios) a serem gerados
    srand(time(NULL)); // Inicialização do gerador de números aleatórios

    // Estimar o valor de pi
    float pi = estim_pi(num_sample);

    // Imprimir o valor estimado de pi
    printf("Estimated value of pi: %f\n", pi);
}

/**
 * @brief Função que gera um número aleatório de ponto flutuante entre 0 e 1.
 * 
 * @return float Número aleatório entre 0 e 1.
 */
float randomF() {
    return (float)rand() / RAND_MAX;
}

/**
 * @brief Função que estima o valor de pi usando o método de Monte Carlo.
 * 
 * @param num_samples Número de amostras (pontos aleatórios) a serem gerados.
 * @return float Valor estimado de pi.
 */
float estim_pi(int num_samples) {
    int num_inside = 0; // Contador para pontos dentro do círculo

    // Gerar num_samples amostras aleatórias e contar quantas estão dentro do círculo
    for (int i = 0; i < num_samples; i++) {
        float x = randomF();
        float y = randomF();

        // Calcular a distância do ponto (x, y) até a origem (0, 0)
        float dist = sqrt(x * x + y * y);

        // Verificar se o ponto está dentro do círculo de raio 1
        if (dist <= 1) {
            num_inside++;
        }
    }

    // Estimar o valor de pi usando a relação entre a área do círculo e a área do quadrado
    return 4.0 * num_inside / num_samples;
}
