#include "Solver03.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Bond
{
    private:
        double F;
        vector<double> T;
        vector<double> C;
        int N = C.size();
    public:
        Bond(double F_, vector<double>& T_, vector<double>& C_) {F=F_; T=T_; C=C_;}
        double Value(double y) {
            double tot = 0;
            for (int index = 0; index < C.size(); index++) {
                tot += C[index] * exp(-y * T[index]);
            }
            tot += F * exp(-y * T.back());
            return tot;
        }
};

int main () {
    double F = 100.0;
    vector<double> T = {1.0, 2.0, 3.0};
    vector<double> C = {1.2, 1.2, 1.2};
    Bond MyBond(F, T, C);
    double trgt = 98.56;
    double tol = 0.0001;

    cout << "F = " << F << endl;
    cout << "T = " << T.back() << endl;
    cout << "coupons: " << endl;
    for (int n=0; n<C.size(); n++)
    cout << "C" << n << " = " << C[n] << " " <<endl;
    cout << "tenors: " << endl;
    for (int n=0; n<T.size(); n++)
    cout << "T" << n << " = " << T[n] << " " <<endl;
    cout << "P = " << trgt << endl << endl;

    double lEnd = 0.0;
    double rEnd = 1.0;
    cout << "Root of Bond bisect: "
    << SolveByBisect(MyBond,trgt,lEnd,rEnd,tol)
    << endl;

    return 0;
}