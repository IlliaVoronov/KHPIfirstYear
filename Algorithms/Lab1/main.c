#include <stdio.h>
#include <math.h>
#include "header.h"

void input(double *a, double *b, double *c);
double findA(double x, double y, double z, double *A);
double findB(double x, double y, double z, double *B);


int main(void)
{
  double x, y, z, A, B;
  input(&x, &y, &z);
  printf("x, y and z: %lf, %lf, %lf.\n", x, y, z);
  findA(x, y, z, &A);
  findB(x, y, z, &B);

  printf("A = %lf\n", A);
  printf("B = %lf\n", B);

  return 0;
}

