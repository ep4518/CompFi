#include "BinModel01.h"
#include "Options03.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double S0,U,D,R;

   if (GetInputData(&S0,&U,&D,&R)==1) return 1;

   double K[2];   //strike price
   int N;      //steps to expiry

   cout << "Enter call option data:" << endl;
   GetInputData(N,K,1);
   double call = PriceByCRR(S0,U,D,R,N,K,CallPayoff);
   cout << "European call option price = "
        << call << endl << endl;

   cout << "Enter put option data:" << endl;
   GetInputData(N,K,1);
   double put = PriceByCRR(S0,U,D,R,N,K,PutPayoff);
   cout << "European put option price =  "
        << put << endl << endl;

// When Strike is the same
    cout << "Put-Call Parity = 1:" << endl;
    if (round((call - put) / (S0 - K[0] * exp(-R))) == 1.0) cout << "True\n";
    else cout << "False\n";

   cout << "Enter digital call option data:" << endl;
   GetInputData(N,K,2);
   cout << "European digital call option price =  "
        << PriceByCRR(S0,U,D,R,N,K,DigitalCallPayoff)
        << endl << endl;
   return 0;
}
