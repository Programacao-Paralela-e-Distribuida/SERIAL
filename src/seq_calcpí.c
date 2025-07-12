#include <stdio.h>
const long num_passos = 10000000000;

int main(int argc, char *argv[]) {  /* seq_calcpi.c  */
double passo = 1.0 / (double) num_passos;
double soma=0.0;
  for (long int i = 0; i < num_passos; i++) {
      double x = (i + 0.5) * passo;
      soma += 4.0 / (1.0 + x * x);
  }
  double pi = soma * passo;
  printf("Valor de Pi calculado: %2.15f \n", pi);
  return 0;
}
