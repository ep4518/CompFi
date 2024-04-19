#include "BinModel02.h"
#include "Options05.h"
#include "DefInt.h"
#include <iostream>
#include <cmath>
using namespace std;


double f(double x){return x*x*x-x*x+1;}

int main()
{
   BinModel Model;

   double a = 1.0;
   double b = 2.0;
   DefInt MyInt(a,b,f);
   int N = 10;

   cout << "By Trapezoidal Estimation: \n" << MyInt.ByTrapezoid(N) << endl;
   cout << "By Simpson Estimation: \n" << MyInt.BySimpson(N) << endl;

   if (Model.GetInputData()==1) return 1;

   Call Option1;
   Option1.GetInputData();
   cout << "European call option price = "
        << Option1.PriceByCRR(Model,Option1.GetK())
        << endl << endl;

   Put Option2;
   Option2.GetInputData();
   cout << "European put option price = "
        << Option2.PriceByCRR(Model,Option2.GetK())
        << endl << endl;

   return 0;
}
