#include "BinModel02.h"
#include "BSModel32.h"
#include "Options09.h"
#include <iostream>
using namespace std;

int GetInputData(double& S0, double& r, double& sigma, double& h);

int main() {
   double S0=100.0;
   double r=0.05;
   double sigma=0.2;
   double T=1.0/12.0;
   double K=100.0;
   int N=100;
   cout << "S0 =    " << S0 << endl;
   cout << "r  =    " << r << endl;
   cout << "sigma = " << sigma << endl;
   cout << "T =     " << T << endl;
   cout << "K =     " << K << endl;
   cout << "N =     " << N << endl;
   cout << endl;
   double h = T / N;
   BSModel BSModel(S0, r, sigma); 
   BinModel BModel = BSModel.ApproxBinModel(h);
   BinLattice<double> PriceTree;
   BinLattice<bool> StoppingTree;
//    cout << "This is R: " << BModel.GetR() << endl;
   Put Option(N,K);
   Option.PriceBySnell(BModel,PriceTree,StoppingTree);
   cout << "American Price By Snell: " << PriceTree.GetNode(0,0) << endl;
   
   return 0;
}

int GetInputData(double& S0, double& r, double& sigma) {
    cout << "Input S0: "; cin >> S0;
    cout << "Input r: "; cin >> r;
    cout << "Input sigma: "; cin >> sigma;

    return 0;
}