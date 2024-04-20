// DefInt.h
#ifndef DEFINT_H
#define DEFINT_H

class DefInt {
  private:
    // Bounds
    double a, b;
  public:
    virtual double f(double z)=0;
    // Constructor
    DefInt(double a_, double b_) : a(a_), b(b_) {}
    // Define integral by Trapezoid and Simpson's Rule (even only) respectively  
    double ByTrapezoid(int N);
    double BySimpson(int N);
};

class DefIntFunc : public DefInt 
{
  public:
    DefIntFunc(double a_, double b_): DefInt(a_, b_) {}
    double f(double x) {return x*x*x-x*x+1;}
};

#endif