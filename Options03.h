#ifndef Options03_h
#define Options03_h

//inputting and displaying option data
int GetInputData(int& N, double (&K)[2], int NoParams);

//pricing European option
double PriceByCRR(double S0, double U, double D,
                  double R, int N, double K[2],
                  double (*Payoff)(double z, double *K));

//computing call payoff
double CallPayoff(double z, double K[2]);

//computing put payoff
double PutPayoff(double z, double K[2]);

//computing put payoff
double DigitalCallPayoff(double z, double K[2]);

#endif
