#pragma once
#include <iostream>
#include <complex>
using std::string;
using std::complex;

namespace solver{
    class RealVariable{
        private: 
        double coefficient_;
        double power_;
        double added_;

        public:
        RealVariable(): coefficient_(0), power_(0), added_(0){}
        RealVariable(double c, double p, double a): coefficient_(c), power_(p), added_(p){}

        const RealVariable& operator-(){return RealVariable(-coefficient_, power_, added_); }
        
        friend RealVariable& operator*(const RealVariable& rv1, const RealVariable& rv2);
        friend RealVariable& operator*(const RealVariable& rv, double d);
        friend RealVariable& operator*(double d, const RealVariable& rv);
        friend RealVariable& operator*(const RealVariable& rv, int d);
        friend RealVariable& operator*(int d, const RealVariable& rv);

        friend RealVariable& operator-(const RealVariable& rv1, const RealVariable& rv2);
        friend RealVariable& operator-(const RealVariable& rv, double d);
        friend RealVariable& operator-(double d, const RealVariable& rv);
        friend RealVariable& operator-(const RealVariable& rv, int d);
        friend RealVariable& operator-(int d, const RealVariable& rv);
        
        friend RealVariable& operator+(const RealVariable& rv1, const RealVariable& rv2);
        friend RealVariable& operator+(const RealVariable& rv, double d);
        friend RealVariable& operator+(double d, const RealVariable& rv);
        friend RealVariable& operator+(const RealVariable& rv, int d);
        friend RealVariable& operator+(int d, const RealVariable& rv);
        
        friend RealVariable& operator^(const RealVariable& rv, int d);
        friend RealVariable& operator/(const RealVariable& rv, double d);
        friend RealVariable& operator/(const RealVariable& rv, int d);

        friend RealVariable& operator==(const RealVariable& rv1, const RealVariable& rv2);
        friend RealVariable& operator==(const RealVariable& rv, double d);
        friend RealVariable& operator==(double d, const RealVariable& rv);
        friend RealVariable& operator==(const RealVariable& rv, int d);
        friend RealVariable& operator==(int d, const RealVariable& rv);
        
        
        
    };
    class ComplexVariable{
        private: 
        complex<double> coefficient_;
        int power_;
        complex<double> added_;

        public:
        
        ComplexVariable(): coefficient_(0), power_(0), added_(0){}
        ComplexVariable(complex<double> c, double p, complex<double>): coefficient_(c), power_(p), added_(p){}

        const ComplexVariable& operator-(){return ComplexVariable(-coefficient_, power_, added_); }

        friend ComplexVariable& operator*(ComplexVariable& cv1, const ComplexVariable& cv2);
        friend ComplexVariable& operator*(ComplexVariable& cv, double d);
        friend ComplexVariable& operator*(double d, ComplexVariable& cv);
        friend ComplexVariable& operator*(ComplexVariable& cv, int d);
        friend ComplexVariable& operator*(int d, ComplexVariable& cv);
        friend ComplexVariable& operator*(ComplexVariable& cv, complex<int> d);
        friend ComplexVariable& operator*(complex<int> d, ComplexVariable& cv);
        friend ComplexVariable& operator*(ComplexVariable& cv, complex<double> d);
        friend ComplexVariable& operator*(complex<double> d, ComplexVariable& cv);


        friend ComplexVariable& operator-(ComplexVariable& cv1, const ComplexVariable& cv2);
        friend ComplexVariable& operator-(ComplexVariable& cv, double d);
        friend ComplexVariable& operator-(double d, ComplexVariable& cv);
        friend ComplexVariable& operator-(ComplexVariable& cv, int d);
        friend ComplexVariable& operator-(int d, ComplexVariable& cv);
        friend ComplexVariable& operator-(ComplexVariable& cv, complex<int> d);
        friend ComplexVariable& operator-(complex<int> d, ComplexVariable& cv);
        friend ComplexVariable& operator-(ComplexVariable& cv, complex<double> d);
        friend ComplexVariable& operator-(complex<double> d, ComplexVariable& cv);
        
        friend ComplexVariable& operator+(ComplexVariable& cv1, const ComplexVariable& cv2);
        friend ComplexVariable& operator+(ComplexVariable& cv, double d);
        friend ComplexVariable& operator+(double d, ComplexVariable& cv);
        friend ComplexVariable& operator+(ComplexVariable& cv, int d);
        friend ComplexVariable& operator+(int d, ComplexVariable& cv);
        friend ComplexVariable& operator+(ComplexVariable& cv, complex<int> d);
        friend ComplexVariable& operator+(complex<int> d, ComplexVariable& cv);
        friend ComplexVariable& operator+(ComplexVariable& cv, complex<double> d);
        friend ComplexVariable& operator+(complex<double> d, ComplexVariable& cv);
        
        friend ComplexVariable& operator^(ComplexVariable& cv, int d);
        friend ComplexVariable& operator/(ComplexVariable& cv, double d);
        friend ComplexVariable& operator/(ComplexVariable& cv, int d);
        friend ComplexVariable& operator/(ComplexVariable& cv, complex<double> d);
        friend ComplexVariable& operator/(ComplexVariable& cv, complex<int> d);

        friend ComplexVariable& operator==(ComplexVariable& cv1, const ComplexVariable& cv2);
        friend ComplexVariable& operator==(ComplexVariable& cv, double d);
        friend ComplexVariable& operator==(double d, ComplexVariable& cv);
        friend ComplexVariable& operator==(ComplexVariable& cv, int d);
        friend ComplexVariable& operator==(int d, ComplexVariable& cv);
        friend ComplexVariable& operator==(ComplexVariable& cv, complex<int> d);
        friend ComplexVariable& operator==(complex<int> d, ComplexVariable& cv);
        friend ComplexVariable& operator==(ComplexVariable& cv, complex<double> d);
        friend ComplexVariable& operator==(complex<double> d, ComplexVariable& cv);
    };


    double solve(RealVariable x);
    std::complex<double> solve(ComplexVariable x);
};