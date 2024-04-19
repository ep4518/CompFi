// DefInt.h
#ifndef DEFINT_H
#define DEFINT_H

class DefInt {
     private:
        // Bounds
          double a, b;
        // ptr to function
          double (*f)(double);
     public:
        // Constructor
          DefInt(double a, double b, double (*FuncPtr)(double)) : a(a), b(b), f(FuncPtr) {}
        // Def integral by Trapezoid and Simpson's Rule (even only) respectively  
          double ByTrapezoid(int N);
          double BySimpson(int N);
};

#endif