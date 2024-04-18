#include "Options03.h"
#include "BinModel01.h"
#include <iostream>
#include <cmath>
#include <optional>
using namespace std;

int GetInputData(int& N, double (&K)[2], int NoParams )
{
    double tmp;
    cout << "Enter steps to expiry N: "; cin >> N;
    for (int i = 0; i < NoParams; i++) {
        cout << "Enter strike price K" << i+1 << ":    "; cin >> K[i];
    }
    return 0;
}

double PriceByCRR(double S0, double U, double D,
                  double R, int N, double K[2],
                  double (*Payoff)(double z, double *K))
{
    double q=RiskNeutProb(U,D,R);
    double Price[N+1];
    for (int i=0; i<=N; i++)
    {
        Price[i] = Payoff(S(S0,U,D,N,i),K);
    }
    for (int n=N-1; n>=0; n--)
    {
       for (int i=0; i<=n; i++)
       {
          Price[i]=(q*Price[i+1]+(1-q)*Price[i])/(1+R);
       }
    }
    return Price[0];
}

double CallPayoff(double z, double K[2])
{
    printf("K1: %f\t z: %f\n", K[0], z);
   if (z>K[0]) return z-K[0];
   return 0.0;
}

double PutPayoff(double z, double K[2])
{
   printf("K1: %f\t z: %f\n", K[0], z);
   if (z<K[0]) return K[0]-z;
   return 0.0;
}

double DigitalCallPayoff(double z, double K[2])
{
    if (z<K[0]) return 1.0;
    return 0.0;
}