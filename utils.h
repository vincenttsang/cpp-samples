#include <iostream>
#include <stdio.h>
#include <stdlib.h>

double fRand(double fMin, double fMax)
{
      double f = (double)rand() / RAND_MAX;
      return fMin + f * (fMax - fMin);
}
