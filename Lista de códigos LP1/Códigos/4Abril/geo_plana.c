/**
 * @file geometria.c
 * @brief Função para cálculos geométricos básicos com diferentes figuras planas.
 * @date 25/04/2024
 * 
 * Este arquivo contém a implementação da função geo_plana, que permite calcular
 * propriedades geométricas como área, perímetro, distância, etc., para diversas
 * figuras planas. O usuário escolhe a figura desejada e fornece as coordenadas
 * necessárias para realizar os cálculos.
 */

#include <stdio.h>
#include <math.h>

/**
 * @brief Função para realizar cálculos geométricos com diferentes figuras planas.
 * 
 * A função permite calcular propriedades como área, perímetro, distância, etc.,
 * para figuras como reta, triângulo, quadrado, retângulo, losango, trapézio, hexágono
 * e círculo. O usuário escolhe a figura desejada e fornece as coordenadas necessárias
 * para realizar os cálculos.
 * 
 * @return void
 */
void geo_plana() {
    float ax, ay, bx, by, cx, cy, dx, dy, ex, ey, fx, fy; // Coordenadas dos pontos
    float compr, area, perim, ang1, ang2, ang3, cat1, cat2, hipo, lad3, lad4, lad5, lad6; // Variáveis para resultados
    short int fig; // Variável para armazenar a escolha da figura

    // Menu de seleção da figura geométrica
    printf("Escolha a figura geométrica:\n");
    printf("1 - Reta\n");
    printf("2 - Triângulo\n");
    printf("3 - Quadrado\n");
    printf("4 - Retângulo\n");
    printf("5 - Losango\n");
    printf("6 - Trapézio\n");
    printf("7 - Hexágono\n");
    printf("8 - Círculo\n");
    scanf("%hd", &fig);

    // Validação da escolha da figura
    while (fig < 1 || fig > 8) {
        printf("Figura inválida, digite novamente: ");
        scanf("%hd", &fig);
    }

    // Processamento de acordo com a figura escolhida
    switch (fig) {
        case 1:
            printf("Digite as coordenadas do ponto A:\n");
            scanf("%f %f", &ax, &ay);
            printf("Digite as coordenadas do ponto B:\n");
            scanf("%f %f", &bx, &by);

            compr = sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
            printf("A distância entre os pontos A e B é: %.2f\n", compr);
            break;

        case 2:
            printf("Digite as coordenadas do ponto A (Vértice da base):\n");
            scanf("%f %f", &ax, &ay);
            printf("Digite as coordenadas do ponto B (Vértice da base):\n");
            scanf("%f %f", &bx, &by);
            printf("Digite as coordenadas do ponto C (Vértice do topo):\n");
            scanf("%f %f", &cx, &cy);

            cat1 = sqrt(pow(cx - ax, 2) + pow(cy - ay, 2));
            cat2 = sqrt(pow(cx - bx, 2) + pow(cy - by, 2));
            hipo = sqrt(pow(cat1, 2) + pow(cat2, 2));
            perim = cat1 + cat2 + hipo;
            area = (cat1 * cat2) / 2;
            printf("Os catetos são: %.2f e %.2f\n", cat1, cat2);
            printf("A hipotenusa é: %.2f\n", hipo);
            printf("O perímetro é: %.2f\n", perim);
            printf("A área é: %.2f\n", area);
            break;

        case 3:
            printf("Digite as coordenadas do ponto A (Qualquer vértice):\n");
            scanf("%f %f", &ax, &ay);
            printf("Digite as coordenadas do ponto B (Vértice adjacente):\n");
            scanf("%f %f", &bx, &by);

            cat1 = sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
            perim = cat1 * 4;
            area = cat1 * cat1;
            hipo = cat1 * sqrt(2);
            printf("Os lados são: %.2f\n", cat1);
            printf("O perímetro é: %.2f\n", perim);
            printf("A área é: %.2f\n", area);
            printf("A diagonal é: %.2f\n", hipo);
            break;

        case 4:
            printf("Digite as coordenadas do ponto A (Qualquer vértice):\n");
            scanf("%f %f", &ax, &ay);
            printf("Digite as coordenadas do ponto B (Vértice oposto ao A):\n");
            scanf("%f %f", &bx, &by);
            printf("Digite as coordenadas do ponto C (Vértice adjacente ao A):\n");
            scanf("%f %f", &cx, &cy);

            cat1 = sqrt(pow(ax - cx, 2) + pow(ay - cy, 2));
            cat2 = sqrt(pow(bx - cx, 2) + pow(by - cy, 2));
            perim = (cat1 * 2) + (cat2 * 2);
            area = cat1 * cat2;
            hipo = sqrt(pow(cat1, 2) + pow(cat2, 2));
            printf("Os lados são: %.2f e %.2f\n", cat1, cat2);
            printf("O perímetro é: %.2f\n", perim);
            printf("A área é: %.2f\n", area);
            printf("A diagonal é: %.2f\n", hipo);
            break;

        case 5:
            printf("Digite as coordenadas do ponto A (Qualquer vértice):\n");
            scanf("%f %f", &ax, &ay);
            printf("Digite as coordenadas do ponto B (Vértice oposto ao A):\n");
            scanf("%f %f", &bx, &by);
            printf("Digite as coordenadas do ponto C (Outro vértice):\n");
            scanf("%f %f", &cx, &cy);
            printf("Digite as coordenadas do ponto D (Outro vértice):\n");
            scanf("%f %f", &dx, &dy);

            cat1 = sqrt(pow(ax - cx, 2) + pow(ay - cy, 2));
            cat2 = sqrt(pow(bx - cx, 2) + pow(by - cy, 2));
            lad3 = sqrt(pow(ax - dx, 2) + pow(ay - dy, 2));
            lad4 = sqrt(pow(bx - dx, 2) + pow(by - dy, 2));
            hipo = sqrt(pow(cat1, 2) + pow(cat2, 2));
            compr = sqrt(pow(cat1, 2) + pow(lad3, 2));
            perim = cat1 + cat2 + lad3 + lad4;
            area = (cat1 * cat2) / 2;
            printf("Os lados são: %.2f, %.2f, %.2f e %.2f\n", cat1, cat2, lad3, lad4);
            printf("O perímetro é: %.2f\n", perim);
            printf("A área é: %.2f\n", area);
            printf("As diagonais são: %.2f e %.2f\n", compr, hipo);
            break;

        case 6:
            printf("Digite as coordenadas do ponto A:\n");
            scanf("%f %f", &ax, &ay);
            printf("Digite as coordenadas do ponto B:\n");
            scanf("%f %f", &bx, &by);
            printf("Digite as coordenadas do ponto C:\n");
            scanf("%f %f", &cx, &cy);
            printf("Digite as coordenadas do ponto D:\n");
            scanf("%f %f", &dx, &dy);

            cat1 = sqrt(pow(ax - cx, 2) + pow(ay - cy, 2));
            cat2 = sqrt(pow(bx - cx, 2) + pow(by - cy, 2));
            lad3 = sqrt(pow(ax - dx, 2) + pow(ay - dy, 2));
            lad4 = sqrt(pow(bx - dx, 2) + pow(by - dy, 2));
            hipo = sqrt(pow(cat1, 2) + pow(cat2, 2));
            compr = sqrt(pow(cat1, 2) + pow(lad3, 2));
            perim = cat1 + cat2 + lad3 + lad4;
            area = ((cat1 + cat2) * 0.5) * compr;
            printf("Os lados são: %.2f, %.2f, %.2f e %.2f\n", cat1, cat2, lad3, lad4);
            printf("O perímetro é: %.2f\n", perim);
            printf("A área é: %.2f\n", area);
            printf("As diagonais são: %.2f e %.2f\n", compr, hipo);
            break;

        case 7:
            printf("Digite as coordenadas do ponto A e siga no sentido horário ou anti-horário:\n");
            scanf("%f %f", &ax, &ay);
            printf("Digite as coordenadas do ponto B:\n");
            scanf("%f %f", &bx, &by);
            printf("Digite as coordenadas do ponto C:\n");
            scanf("%f %f", &cx, &cy);
            printf("Digite as coordenadas do ponto D:\n");
            scanf("%f %f", &dx, &dy);
            printf("Digite as coordenadas do ponto E:\n");
            scanf("%f %f", &ex, &ey);
            printf("Digite as coordenadas do ponto F:\n");
            scanf("%f %f", &fx, &fy);

            cat1 = sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
            cat2 = sqrt(pow(cx - bx, 2) + pow(cy - by, 2));
            lad3 = sqrt(pow(dx - cx, 2) + pow(dy - cy, 2));
            lad4 = sqrt(pow(ex - dx, 2) + pow(ey - dy, 2));
            lad5 = sqrt(pow(fx - ex, 2) + pow(fy - ey, 2));
            lad6 = sqrt(pow(ax - fx, 2) + pow(ay - fy, 2));
            perim = cat1 + cat2 + lad3 + lad4 + lad5 + lad6;
            area = fabs((ax * by - bx * ay) + (bx * cy - cx * by) + (cx * dy - dx * cy) + (dx * ey - ex * dy) + (ex * fy - fx * ey) + (fx * ay - ax * fy)) / 2;
            printf("Os lados são: %.2f, %.2f, %.2f, %.2f, %.2f e %.2f\n", cat1, cat2, lad3, lad4, lad5, lad6);
            printf("O perímetro é: %.2f\n", perim);
            printf("A área é: %.2f\n", area);
            break;

        case 8:
            printf("Digite as coordenadas do ponto A (Ponto central do círculo):\n");
            scanf("%f %f", &ax, &ay);
            printf("Digite as coordenadas do ponto B (Algum ponto da circunferência):\n");
            scanf("%f %f", &bx, &by);

            compr = sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
            perim = 2 * M_PI * compr;
            area = M_PI * pow(compr, 2);
            printf("O raio é: %.2f\n", compr);
            printf("O perímetro é: %.2f\n", perim);
            printf("A área é: %.2f\n", area);
            break;

        default:
            printf("Opção inválida.\n");
            break;
    }
}
