#pragma once
#include <iostream>
#include <complex>
#include <cmath>
#define DEBUG

using std::string;
using std::complex;

static complex<double> czero = complex(0.0,0.0);

namespace solver{
    class RealVariable{
        private: 
        double coef0_;
        double coef1_;
        double coef2_;

        public:
        RealVariable(): coef0_(0), coef1_(1), coef2_(0){}
        RealVariable(double c0, double c1, double c2): coef0_(c0), coef1_(c1), coef2_(c2){
        }
        RealVariable(const RealVariable& rv): coef0_(rv.coef0_), coef1_(rv.coef1_), coef2_(rv.coef2_){}
        RealVariable& set_c0(double c0){
            coef0_ = c0;
            return *this;
        }
        RealVariable& set_c1(double c1){
            coef1_ = c1;
            return *this;
        }
        RealVariable& set_c2(double c2){
            coef2_ = c2;
            return *this;
        }
        double get_sol(){return coef0_; }

        const RealVariable operator-(){return RealVariable(-this->coef0_, -this->coef1_,-this->coef2_); }
        
        friend RealVariable operator*(const RealVariable& rv1, const RealVariable& rv2);
        friend RealVariable operator*(const RealVariable& rv, double d);
        friend RealVariable operator*(double d, const RealVariable& rv);
        friend RealVariable operator*(const RealVariable& rv, int d);
        friend RealVariable operator*(int d, const RealVariable& rv);

        friend RealVariable operator-(const RealVariable& rv1, const RealVariable& rv2);
        friend RealVariable operator-(const RealVariable& rv, double d);
        friend RealVariable operator-(double d, const RealVariable& rv);
        friend RealVariable operator-(const RealVariable& rv, int d);
        friend RealVariable operator-(int d, const RealVariable& rv);
        
        friend RealVariable operator+(const RealVariable& rv1, const RealVariable& rv2);
        friend RealVariable operator+(const RealVariable& rv, double d);
        friend RealVariable operator+(double d, const RealVariable& rv);
        friend RealVariable operator+(const RealVariable& rv, int d);
        friend RealVariable operator+(int d, const RealVariable& rv);
        
        friend RealVariable operator^(const RealVariable& rv, int d);

        friend RealVariable operator/(const RealVariable& rv1, const RealVariable& rv2);
        friend RealVariable operator/(const RealVariable& rv, double d);
        friend RealVariable operator/(const RealVariable& rv, int d);

        friend RealVariable operator==(const RealVariable& rv1, const RealVariable& rv2);
        friend RealVariable operator==(const RealVariable& rv, double d);
        friend RealVariable operator==(double d, const RealVariable& rv);
        friend RealVariable operator==(const RealVariable& rv, int d);
        friend RealVariable operator==(int d, const RealVariable& rv);
        
        #ifdef DEBUG
        string to_str() const{
            string text = "(";
            if(coef2_!=0){
                text+=std::to_string((int)coef2_)+"x^2";
            }
            else{
                text+="0";
            }
            text+=" , ";
            if(coef1_!=0){
                text+=std::to_string((int)coef1_)+"x";
            }
            else{
                text+="0";
            }
            text+=" , ";
            if(coef0_!=0){
                text+= std::to_string((int)coef0_);
            }
            else{
                text+="0";
            }
            text+=+")";
            return text;
        }
        #endif
        
    };
    
    class ComplexVariable{
        private: 
        complex<double> coef0_;
        complex<double> coef1_;
        complex<double> coef2_;


        public:
        ComplexVariable(): coef0_(0), coef1_(1), coef2_(0){}
        ComplexVariable(complex<double> c0, complex<double> c1, complex<double> c2): coef0_(c0), coef1_(c1), coef2_(c2){
        }
        ComplexVariable(const ComplexVariable& rv): coef0_(rv.coef0_), coef1_(rv.coef1_), coef2_(rv.coef2_){}

        ComplexVariable& set_c0(complex<double> c0){
            coef0_ = c0;
            return *this;
        }
        ComplexVariable& set_c1(complex<double> c1){
            coef1_ = c1;
            return *this;
        }
        ComplexVariable& set_c2(complex<double> c2){
            coef2_ = c2;
            return *this;
        }
        complex<double> get_sol(){return coef0_; }

        const ComplexVariable operator-(){return ComplexVariable(-this->coef0_, -this->coef1_,-this->coef2_); }
        
        friend ComplexVariable operator*(const ComplexVariable& rv1, const ComplexVariable& rv2);
        friend ComplexVariable operator*(const ComplexVariable& rv, double d);
        friend ComplexVariable operator*(double d, const ComplexVariable& rv);
        friend ComplexVariable operator*(const ComplexVariable& rv, int d);
        friend ComplexVariable operator*(int d, const ComplexVariable& rv);
        friend ComplexVariable operator*(const ComplexVariable& rv, complex<double> d);
        friend ComplexVariable operator*(complex<double> d, const ComplexVariable& rv);
        friend ComplexVariable operator*(const ComplexVariable& rv, complex<int> d);
        friend ComplexVariable operator*(complex<int> d, const ComplexVariable& rv);

        friend ComplexVariable operator-(const ComplexVariable& rv1, const ComplexVariable& rv2);
        friend ComplexVariable operator-(const ComplexVariable& rv, double d);
        friend ComplexVariable operator-(double d, const ComplexVariable& rv);
        friend ComplexVariable operator-(const ComplexVariable& rv, int d);
        friend ComplexVariable operator-(int d, const ComplexVariable& rv);
        friend ComplexVariable operator-(const ComplexVariable& rv, complex<double> d);
        friend ComplexVariable operator-(complex<double> d, const ComplexVariable& rv);
        friend ComplexVariable operator-(const ComplexVariable& rv, complex<int> d);
        friend ComplexVariable operator-(complex<int> d, const ComplexVariable& rv);
        
        friend ComplexVariable operator+(const ComplexVariable& rv1, const ComplexVariable& rv2);
        friend ComplexVariable operator+(const ComplexVariable& rv, double d);
        friend ComplexVariable operator+(double d, const ComplexVariable& rv);
        friend ComplexVariable operator+(const ComplexVariable& rv, int d);
        friend ComplexVariable operator+(int d, const ComplexVariable& rv);
        friend ComplexVariable operator+(const ComplexVariable& rv, complex<double> d);
        friend ComplexVariable operator+(complex<double> d, const ComplexVariable& rv);
        friend ComplexVariable operator+(const ComplexVariable& rv, complex<int> d);
        friend ComplexVariable operator+(complex<int> d, const ComplexVariable& rv);
        
        friend ComplexVariable operator^(const ComplexVariable& rv, int d);

        friend ComplexVariable operator/(const ComplexVariable& rv1, const ComplexVariable& rv2);
        friend ComplexVariable operator/(const ComplexVariable& rv, double d);
        friend ComplexVariable operator/(const ComplexVariable& rv, int d);
        friend ComplexVariable operator/(const ComplexVariable& rv, complex<double> d);
        friend ComplexVariable operator/(const ComplexVariable& rv, complex<int> d);

        friend ComplexVariable operator==(const ComplexVariable& rv1, const ComplexVariable& rv2);
        friend ComplexVariable operator==(const ComplexVariable& rv, double d);
        friend ComplexVariable operator==(double d, const ComplexVariable& rv);
        friend ComplexVariable operator==(const ComplexVariable& rv, int d);
        friend ComplexVariable operator==(int d, const ComplexVariable& rv);
        friend ComplexVariable operator==(const ComplexVariable& rv, complex<double> d);
        friend ComplexVariable operator==(complex<double> d, const ComplexVariable& rv);
        friend ComplexVariable operator==(const ComplexVariable& rv, complex<int> d);
        friend ComplexVariable operator==(complex<int> d, const ComplexVariable& rv);
        
        #ifdef DEBUG
        string to_str() const{
            string text = "(";
            if(coef2_!=czero){
                text+="("+std::to_string(coef2_.real()) +" + "+std::to_string(coef2_.real())+"i)x^2";
            }
            else{
                text+="0";
            }
            text+=" , ";
            if(coef1_!=czero){
                text+="("+std::to_string(coef1_.real()) +" + "+std::to_string(coef1_.real())+"i)x";
            }
            else{
                text+="0";
            }
            text+=" , ";
            if(coef0_!=czero){
                text+="("+std::to_string(coef1_.real()) +" + "+std::to_string(coef1_.real())+"i)";
            }
            else{
                text+="0";
            }
            text+=+")";
            return text;
        }
        #endif
    };

    double solve(RealVariable x);

    std::complex<double> solve(ComplexVariable x);

    
};

