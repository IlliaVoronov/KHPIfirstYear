#include <stdio.h>
#include <math.h>
#include "header.h"


double findB(double x, double y, double z, double *B)
{
  double answerB;
  answerB = cbrt(exp(x - (1/sin(z))));
  *B = answerB;
  return 2;
}

