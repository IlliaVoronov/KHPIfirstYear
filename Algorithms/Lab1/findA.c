#include <stdio.h>
#include <math.h>
#include "header.h"


double findA(double x, double y, double z, double *A)
{
  double answerA;
  answerA = pow(2, -x) * sqrt(x + pow(fabs(y), 1.0/4));
  *A = answerA;
  return 1;
}

