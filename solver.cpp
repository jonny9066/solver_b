#include "solver.hpp"

using namespace solver;
using namespace std;

RealVariable& solver::operator*(const RealVariable& rv1, const RealVariable& rv2){RealVariable x; return x;}
RealVariable& solver::operator*(const RealVariable& rv, double d){RealVariable x; return x;}
RealVariable& solver::operator*(double d, const RealVariable& rv){RealVariable x; return x;}
RealVariable& solver::operator*(const RealVariable& rv, int d){RealVariable x; return x;}
RealVariable& solver::operator*(int d, const RealVariable& rv){RealVariable x; return x;}

RealVariable& solver::operator-(const RealVariable& rv1, const RealVariable& rv2){RealVariable x; return x;}
RealVariable& solver::operator-(const RealVariable& rv, double d){RealVariable x; return x;}
RealVariable& solver::operator-(double d, const RealVariable& rv){RealVariable x; return x;}
RealVariable& solver::operator-(const RealVariable& rv, int d){RealVariable x; return x;}
RealVariable& solver::operator-(int d, const RealVariable& rv){RealVariable x; return x;}

RealVariable& solver::operator+(const RealVariable& rv1, const RealVariable& rv2){RealVariable x; return x;}
RealVariable& solver::operator+(const RealVariable& rv, double d){RealVariable x; return x;}
RealVariable& solver::operator+(double d, const RealVariable& rv){RealVariable x; return x;}
RealVariable& solver::operator+(const RealVariable& rv, int d){RealVariable x; return x;}
RealVariable& solver::operator+(int d, const RealVariable& rv){RealVariable x; return x;}

RealVariable& solver::operator^(const RealVariable& rv, int d){RealVariable x; return x;}
RealVariable& solver::operator/(const RealVariable& rv, double d){RealVariable x; return x;}
RealVariable& solver::operator/(const RealVariable& rv, int d){RealVariable x; return x;}

RealVariable& solver::operator==(const RealVariable& rv1, const RealVariable& rv2){RealVariable x; return x;}
RealVariable& solver::operator==(const RealVariable& rv, double d){RealVariable x; return x;}
RealVariable& solver::operator==(double d, const RealVariable& rv){RealVariable x; return x;}
RealVariable& solver::operator==(const RealVariable& rv, int d){RealVariable x; return x;}
RealVariable& solver::operator==(int d, const RealVariable& rv){RealVariable x; return x;}

ComplexVariable& solver::operator*(ComplexVariable& cv1, const ComplexVariable& cv2){ComplexVariable x; return x;}
ComplexVariable& solver::operator*(ComplexVariable& cv, double d){ComplexVariable x; return x;}
ComplexVariable& solver::operator*(double d, ComplexVariable& cv){ComplexVariable x; return x;}
ComplexVariable& solver::operator*(ComplexVariable& cv, int d){ComplexVariable x; return x;}
ComplexVariable& solver::operator*(int d, ComplexVariable& cv){ComplexVariable x; return x;}
ComplexVariable& solver::operator*(ComplexVariable& cv, complex<int> d){ComplexVariable x; return x;}
ComplexVariable& solver::operator*(complex<int> d, ComplexVariable& cv){ComplexVariable x; return x;}
ComplexVariable& solver::operator*(ComplexVariable& cv, complex<double> d){ComplexVariable x; return x;}
ComplexVariable& solver::operator*(complex<double> d, ComplexVariable& cv){ComplexVariable x; return x;}


ComplexVariable& solver::operator-(ComplexVariable& cv1, const ComplexVariable& cv2){ComplexVariable x; return x;}
ComplexVariable& solver::operator-(ComplexVariable& cv, double d){ComplexVariable x; return x;}
ComplexVariable& solver::operator-(double d, ComplexVariable& cv){ComplexVariable x; return x;}
ComplexVariable& solver::operator-(ComplexVariable& cv, int d){ComplexVariable x; return x;}
ComplexVariable& solver::operator-(int d, ComplexVariable& cv){ComplexVariable x; return x;}
ComplexVariable& solver::operator-(ComplexVariable& cv, complex<int> d){ComplexVariable x; return x;}
ComplexVariable& solver::operator-(complex<int> d, ComplexVariable& cv){ComplexVariable x; return x;}
ComplexVariable& solver::operator-(ComplexVariable& cv, complex<double> d){ComplexVariable x; return x;}
ComplexVariable& solver::operator-(complex<double> d, ComplexVariable& cv){ComplexVariable x; return x;}


ComplexVariable& solver::operator+(ComplexVariable& cv1, const ComplexVariable& cv2){ComplexVariable x; return x;}
ComplexVariable& solver::operator+(ComplexVariable& cv, double d){ComplexVariable x; return x;}
ComplexVariable& solver::operator+(double d, ComplexVariable& cv){ComplexVariable x; return x;}
ComplexVariable& solver::operator+(ComplexVariable& cv, int d){ComplexVariable x; return x;}
ComplexVariable& solver::operator+(int d, ComplexVariable& cv){ComplexVariable x; return x;}
ComplexVariable& solver::operator+(ComplexVariable& cv, complex<int> d){ComplexVariable x; return x;}
ComplexVariable& solver::operator+(complex<int> d, ComplexVariable& cv){ComplexVariable x; return x;}
ComplexVariable& solver::operator+(ComplexVariable& cv, complex<double> d){ComplexVariable x; return x;}
ComplexVariable& solver::operator+(complex<double> d, ComplexVariable& cv){ComplexVariable x; return x;}

ComplexVariable& solver::operator^(ComplexVariable& cv, int d){ComplexVariable x; return x;}
ComplexVariable& solver::operator/(ComplexVariable& cv, double d){ComplexVariable x; return x;}
ComplexVariable& solver::operator/(ComplexVariable& cv, int d){ComplexVariable x; return x;}
ComplexVariable& solver::operator/(ComplexVariable& cv, complex<double> d){ComplexVariable x; return x;}
ComplexVariable& solver::operator/(ComplexVariable& cv, complex<int> d){ComplexVariable x; return x;}

ComplexVariable& solver::operator==(ComplexVariable& cv1, const ComplexVariable& cv2){ComplexVariable x; return x;}
ComplexVariable& solver::operator==(ComplexVariable& cv, double d){ComplexVariable x; return x;}
ComplexVariable& solver::operator==(double d, ComplexVariable& cv){ComplexVariable x; return x;}
ComplexVariable& solver::operator==(ComplexVariable& cv, int d){ComplexVariable x; return x;}
ComplexVariable& solver::operator==(int d, ComplexVariable& cv){ComplexVariable x; return x;}
ComplexVariable& solver::operator==(ComplexVariable& cv, complex<int> d){ComplexVariable x; return x;}
ComplexVariable& solver::operator==(complex<int> d, ComplexVariable& cv){ComplexVariable x; return x;}
ComplexVariable& solver::operator==(ComplexVariable& cv, complex<double> d){ComplexVariable x; return x;}
ComplexVariable& solver::operator==(complex<double> d, ComplexVariable& cv){ComplexVariable x; return x;}

double solver::solve(RealVariable x){return 0;}
std::complex<double> solver::solve(ComplexVariable x){return complex(0.0);}