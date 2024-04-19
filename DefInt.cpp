//DefInt.cpp
#include "DefInt.h"
#include <iostream> 

double DefInt::ByTrapezoid(int N) {
     double h = (b - a) / N;
     double cumsum = 0;
     double x;
     int index;

     for (index = 0; index < N + 1; index++) {
          x = a + index * h;
          if (index == 0 || index == N) {
               cumsum += h / 2 * f(x);
          }
          else cumsum += h * f(x);
     }
     return cumsum;
}

double DefInt::BySimpson(int N) {
     if (N % 2 != 0) {
          std::cerr << "Simpson's rule requires an even number of subintervals." << std::endl;
          return 0;
     }
     double h = (b - a) / N;
     double x;
     int index;
     double cumsum = 0;

     for (index = 0; index < N + 1; index++) {
          x = a + index * h;
          if (index == 0 || index == N) cumsum += f(x);
          else if (index % 2 != 0) cumsum+= 4 * f(x);
          else cumsum += f(x);
     }
     return h / 3 * cumsum;
}