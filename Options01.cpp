#include "Options01.h"
#include "BinModel01.h"
#include <iostream>
#include <cmath>
using namespace std;

int GetInputData(int& N, double& K)
{
   cout << "Enter steps to expiry N: "; cin >> N;
   cout << "Enter strike price K:    "; cin >> K;
   cout << endl;

   if (!((0 < K) && (0 < N))){
       cout << "Error: K <= 0 or N <= 0\n";
       return 1;
   }
   return 0;
}
int factorial(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    return n * factorial(n-1);
}
double S(int n, int i, double S0, double U, double D) {
    return S0 * pow(1 + U, i) * pow(1 + D, n - i);
}

double PriceByCRR(double S0, double U, double D,
                  double R, int N, double K)
{
    int index;
    double sum;
    double q=RiskNeutProb(U,D,R);
    for (index = 0; index < N + 1; index ++) {
        sum += factorial(N) * pow(q, (double) index) * pow(1 - q, N - index) \
                * std::max(S(N,index, S0, U, D) - K, 0.0)/ (factorial(index) * factorial(N - index));
    }

    return sum / pow(1 + R, N);
}

//double PriceByCRR(double S0, double U, double D,
//                  double R, int N, double K)
//{
//    double q=RiskNeutProb(U,D,R);
//    double Price[N+1];
//    for (int i=0; i<=N; i++)
//    {
//        Price[i]=CallPayoff(S(S0,U,D,N,i),K);
//    }
//    for (int n=N-1; n>=0; n--)
//    {
//        for (int i=0; i<=n; i++)
//        {
//            Price[i]=(q*Price[i+1]+(1-q)*Price[i])/(1+R);
//        }
//    }
//    return Price[0];
//}

double CallPayoff(double z, double K)
{
   if (z>K) return z-K;
   return 0.0;
}
