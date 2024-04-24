#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  short int a, b, c, d, e, f;
  short int a2 = 0, b2 = 0, c2 = 0, d2 = 0, e2 = 0, f2 = 0;
  short int n, n2, nD[60], nR = 60, con;

  printf("Insira as 6 dezenas a serem sorteadas: ");
  scanf("%hd %hd %hd %hd %hd %hd", &a, &b, &c, &d, &e, &f);

  if (a < 1 || a > 60 || b < 1 || b > 60 || c < 1 || c > 60) {
    printf("As dezenas devem estar entre 1 e 60.\n");
    return 1;
  }

  if (a == b || a == c || a == d || a == e || a == f || b == c || b == d || b == e || b == f || c == d || c == e || c == f || d == e || d == f || e == f) {
    printf("As dezenas não podem ser iguais.\n");
    return 1;
  }

  for (int i = 0; i < 60; i++) {
    nD[i] = i + 1;
  }

  srand(time(NULL));

  printf("Escolha o tipo de sorteio:\n1 - Sortear até ganhar\n2 - Sortear de apenas 1 pote até as 6 dezenas saírem\n");
  scanf("%hd", &con);
  if (con != 1 && con != 2) {
    printf("Opção inválida.\n");
    return 1;
  }

  if (con == 2) {
    short int a1 = 0, b1 = 0, c1 = 0, d1 = 0, e1 = 0, f1 = 0;

    while (nR > 0) {
      n = rand() % nR;
      n2 = nD[n];

      nD[n] = nD[nR - 1];
      nR--;
      if (a2 == 0) {
        if (a != n2) {
          a1++;
        } else {
          a1++;
          a2 = 1;
        }
      }
      if (b2 == 0) {
        if (b != n2 && b2 == 0) {
          b1++;
        } else {
          b1++;
          b2 = 1;
        }
      }
      if (c2 == 0) {
        if (c != n2 && c2 == 0) {
          c1++;
        } else {
          c1++;
          c2 = 1;
        }
      }
      if (d2 == 0) {
        if (d != n2 && d2 == 0) {
          d1++;
        } else {
          d1++;
          d2 = 1;
        }
      }
      if (e2 == 0) {
        if (e != n2 && e2 == 0) {
          e1++;
        } else {
          e1++;
          e2 = 1;
        }
      }
      if (f2 == 0) {
        if (f != n2 && f2 == 0) {
          f1++;
        } else {
          f1++;
          f2 = 1;
        }
      }

      if (a2 == 1 && b2 == 1 && c2 == 1 && d2 == 1 && e2 == 1 && f2 == 1) {
        break;
      }
    }

    printf("Levou %d tentativas para sortear a dezena %d\nLevou %d tentativas "
           "para sortear a dezena %d\nLevou %d tentativas para sortear a "
           "dezena %d\nLevou %d tentativas para sortear a dezena %d\nLevou %d "
           "tentativas para sortear a dezena %d\nLevou %d tentativas para "
           "sortear a dezena %d",
           a1, a, b1, b, c1, c, d1, d, e1, e, f1, f);
    return 0;
  }
  if (con == 1) {
    unsigned long int a1;
    while (a2 == 0 || b2 == 0 || c2 == 0 || d2 == 0 || e2 == 0 || f2 == 0) {
      for (int i = 0; i < 6; i++) {
        n = rand() % nR;
        n2 = nD[n];
        nD[n] = nD[nR - 1];
        nR--;
        if (i == 5) {
          for (int i = 0; i < 60; i++) {
            nD[i] = i + 1;
          }
        }

        if (a == n2)
          a2 = 1;
        if (b == n2)
          b2 = 1;
        if (c == n2)
          c2 = 1;
        if (d == n2)
          d2 = 1;
        if (e == n2)
          e2 = 1;
        if (f == n2)
          f2 = 1;
        
        if (a2 == 1 && b2 == 1 && c2 == 1 && d2 == 1 && e2 == 1 && f2 == 1) {
          a1++;
          printf("Levou %d tentativas para sortear as 6 dezenas", a1);
          break;
        } else if (i == 5) {
          a2 = 0;
          b2 = 0;
          c2 = 0;
          d2 = 0;
          e2 = 0;
          f2 = 0;
          a1++;
          nR = 60;
        }
      }
    }
  }
}