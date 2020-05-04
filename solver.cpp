#include "solver.hpp"

using namespace solver;
using namespace std;


RealVariable solver::operator*(const RealVariable& rv1, const RealVariable& rv2){
    //check that maximum exponent is not reached
    if((rv1.coef1_ !=0 && rv2.coef2_ !=0) || (rv1.coef2_ !=0 && rv2.coef1_!=0) 
    || (rv1.coef2_ !=0 && rv2.coef2_!=0) ){
        throw runtime_error("* error: you cannot have a variable with exponent > 2:");
    }
    RealVariable x = RealVariable(rv1.coef0_*rv2.coef0_,
    rv1.coef1_*rv2.coef0_ + rv2.coef1_*rv1.coef0_,  rv1.coef2_*rv2.coef0_ + rv1.coef1_*rv2.coef1_ + rv2.coef2_*rv1.coef0_);
    #ifdef DEBUG
    cout<<"DEBUG: "<<rv1.to_str()<<" * "<<rv2.to_str()<< " gave "<<x.to_str()<<endl;
    #endif
    return x;
    }
    
RealVariable solver::operator*(const RealVariable& rv, double d){
    RealVariable x = RealVariable(d, 0, 0);
    return rv*x;
}
RealVariable solver::operator*(double d, const RealVariable& rv){
    return rv*d;
}
RealVariable solver::operator*(const RealVariable& rv, int d){
    return rv*(double)d;
}
RealVariable solver::operator*(int d, const RealVariable& rv){
    return rv*(double)d;
}

RealVariable solver::operator-(const RealVariable& rv1, const RealVariable& rv2){
    RealVariable x = RealVariable(rv1.coef0_-rv2.coef0_, rv1.coef1_-rv2.coef1_, rv1.coef2_-rv2.coef2_);
    #ifdef DEBUG
    cout<<"DEBUG: "<<rv1.to_str()<<" - "<<rv2.to_str()<< " gave "<<x.to_str()<<endl;
    #endif
    return x;
}
RealVariable solver::operator-(const RealVariable& rv, double d){
    RealVariable x = RealVariable(d, 0, 0);
    return rv-x;
}
RealVariable solver::operator-(double d, const RealVariable& rv){
    RealVariable x = RealVariable(d, 0, 0);
    return x-rv;
}
RealVariable solver::operator-(const RealVariable& rv, int d){
    return rv - (double)d;
}
RealVariable solver::operator-(int d, const RealVariable& rv){
    return (double)d - rv;
}

RealVariable solver::operator+(const RealVariable& rv1, const RealVariable& rv2){
    RealVariable x = RealVariable(rv1.coef0_+rv2.coef0_, rv1.coef1_+rv2.coef1_, rv1.coef2_+rv2.coef2_);
    #ifdef DEBUG
    cout<<"DEBUG: "<<rv1.to_str()<<" + "<<rv2.to_str()<< " gave "<<x.to_str()<<endl;
    #endif
    return x;
}
RealVariable solver::operator+(const RealVariable& rv, double d){
    RealVariable x = RealVariable(d, 0, 0);
    return rv+x;
}
RealVariable solver::operator+(double d, const RealVariable& rv){
    RealVariable x = RealVariable(d, 0, 0);
    return rv+x;
}
RealVariable solver::operator+(const RealVariable& rv, int d){
    return rv+(double)d;
}
RealVariable solver::operator+(int d, const RealVariable& rv){
    return rv+(double)d;
}

RealVariable solver::operator^(const RealVariable& rv, int d){
    if(d < 1 || (rv.coef2_ != 0 && d > 1)|| (rv.coef1_ != 0 && d > 2)|| d > 3){
        throw runtime_error("^ error: you cannot have a variable with exponent not equal to 0, 1 or 2");
    }
    if(d == 0){
        RealVariable x = RealVariable(0,0,0);
        return x;
    }
    else if(d == 1){
        RealVariable x = RealVariable(rv);
        return x;
    }
    else if(d == 2){
    RealVariable x = RealVariable(pow(rv.coef0_,2), 2*rv.coef0_*rv.coef1_, pow(rv.coef1_,2));
    return x;
    }
    else{
        throw runtime_error("^ something seemingly impossible happened");
    }
}
RealVariable solver::operator/(const RealVariable& rv1, const RealVariable& rv2){
    if(rv2.coef0_ == 0 && rv2.coef1_ == 0 && rv2.coef2_ == 0){
         throw runtime_error("/ error: you are trying to devide by zero!");
    }
    RealVariable x;
    // we have 3 cases: rv1 is ax^2, bx or c
    // c
    if(rv2.coef2_ == 0 && rv2.coef1_ == 0){
        x = RealVariable(rv1.coef0_/rv2.coef0_, rv1.coef1_/rv2.coef0_, rv1.coef2_/rv2.coef0_);
    }
    //bx
    else if(rv2.coef2_ == 0 && rv2.coef0_ == 0){
        if(rv1.coef0_ != 0){
            throw runtime_error("/ error: a division operation creates a variable with an unsupported exponent!");
        }
        x = RealVariable(rv1.coef1_/rv2.coef1_, rv1.coef2_/rv1.coef1_,0);
    }
    // ax^2
    else if(rv2.coef2_ == 0 && rv2.coef0_ == 0){
        if(rv1.coef0_ != 0 || rv1.coef1_ != 0){
            throw runtime_error("/ error: a division operation creates a variable with an unsupported exponent!");
        }
        x = RealVariable(rv1.coef2_/rv2.coef2_,0 ,0);
    }
    else{
        throw runtime_error("/ error: we do not support polynomial division!");
    }
    #ifdef DEBUG
    cout<<"DEBUG: "<<rv1.to_str()<<" / "<<rv2.to_str()<< " gave "<<x.to_str()<<endl;
    #endif
    return x;
}

RealVariable solver::operator/(const RealVariable& rv, double d){
    RealVariable x = RealVariable(d, 0 , 0);
    return rv/x;
 }
RealVariable solver::operator/(const RealVariable& rv, int d){
    return rv/(double)d;
}

RealVariable solver::operator==(const RealVariable& rv1, const RealVariable& rv2){
    
    #ifdef DEBUG
    cout<<"DEBUG solving:"<<rv1.to_str()<<" == "<<rv2.to_str()<<endl;
    #endif
    // transfer RHS to LHS to create the equation ax^2+bx+c
    RealVariable eq = RealVariable(rv1.coef0_-rv2.coef0_, rv1.coef1_ - rv2.coef1_, rv1.coef2_ - rv2.coef2_);

    if(eq.coef2_ != 0){
        double inside_square_root = pow(eq.coef1_,2)-4*eq.coef2_*eq.coef0_;
        if(inside_square_root >= 0){
            double sol = (-eq.coef1_+sqrt(inside_square_root))/(2*eq.coef2_);
            return RealVariable(sol, 0, 0);
        }
        else{
            throw runtime_error("This equation has no real solution!");
        }
    }
    else if(eq.coef1_ != 0){
        double sol = -eq.coef0_/eq.coef1_;
        RealVariable x = RealVariable(sol, 0, 0);
        return x;
    }
    else if (eq.coef0_ == 0){
        return RealVariable(INT64_MAX,0,0);
    }
    else{
        throw runtime_error("This equation has no solution!");
    }


}

RealVariable solver::operator==(const RealVariable& rv, double d){
    RealVariable x = RealVariable(d, 0, 0);
    return rv==x;
}
RealVariable solver::operator==(double d, const RealVariable& rv){
    return rv==d;
}
RealVariable solver::operator==(const RealVariable& rv, int d){
    return rv==(double)d;
    }
RealVariable solver::operator==(int d, const RealVariable& rv){
    return rv==(double)d;
    }

    // COMPLEX VARIABLE

ComplexVariable solver::operator*(const ComplexVariable& rv1, const ComplexVariable& rv2){
    //check that maximum exponent is not reached
    if((rv1.coef1_ !=0i && rv2.coef2_ !=0i) || (rv1.coef2_ !=0i && rv2.coef1_!=0i) 
    || (rv1.coef2_ !=0i && rv2.coef2_!=0i) ){
        throw runtime_error("* error: you cannot have a variable with exponent > 2:");
    }
    ComplexVariable x = ComplexVariable(rv1.coef0_*rv2.coef0_,
    rv1.coef1_*rv2.coef0_ + rv2.coef1_*rv1.coef0_,  rv1.coef2_*rv2.coef0_ + rv1.coef1_*rv2.coef1_ + rv2.coef2_*rv1.coef0_);
    #ifdef DEBUG
    cout<<"DEBUG: "<<rv1.to_str()<<" * "<<rv2.to_str()<< " gave "<<x.to_str()<<endl;
    #endif
    return x;
    }
    
ComplexVariable solver::operator*(const ComplexVariable& rv, double d){
    ComplexVariable x = ComplexVariable(d, 0, 0);
    return rv*x;
}
ComplexVariable solver::operator*(double d, const ComplexVariable& rv){
    return rv*d;
}
ComplexVariable solver::operator*(const ComplexVariable& rv, int d){
    return rv*(double)d;
}
ComplexVariable solver::operator*(int d, const ComplexVariable& rv){
    return rv*(double)d;
}
ComplexVariable solver::operator*(const ComplexVariable& rv, complex<double> d){
    ComplexVariable x = ComplexVariable(d, 0, 0);
    return rv*x;
}
ComplexVariable solver::operator*(complex<double> d, const ComplexVariable& rv){
    return rv*d;
}
ComplexVariable solver::operator*(const ComplexVariable& rv, complex<int> d){
    complex<double> dn = complex((double)d.real(), (double)d.imag());
    return rv*dn;
}
ComplexVariable solver::operator*(complex<int> d, const ComplexVariable& rv){
    return rv*d;
}

ComplexVariable solver::operator-(const ComplexVariable& rv1, const ComplexVariable& rv2){
    ComplexVariable x = ComplexVariable(rv1.coef0_-rv2.coef0_, rv1.coef1_-rv2.coef1_, rv1.coef2_-rv2.coef2_);
    #ifdef DEBUG
    cout<<"DEBUG: "<<rv1.to_str()<<" - "<<rv2.to_str()<< " gave "<<x.to_str()<<endl;
    #endif
    return x;
}
ComplexVariable solver::operator-(const ComplexVariable& rv, double d){
    ComplexVariable x = ComplexVariable(d, 0, 0);
    return rv-x;
}
ComplexVariable solver::operator-(double d, const ComplexVariable& rv){
    ComplexVariable x = ComplexVariable(d, 0, 0);
    return x-rv;
}
ComplexVariable solver::operator-(const ComplexVariable& rv, int d){
    return rv - (double)d;
}
ComplexVariable solver::operator-(int d, const ComplexVariable& rv){
    return (double)d - rv;
}
ComplexVariable solver::operator-(const ComplexVariable& rv, complex<double> d){
    ComplexVariable x = ComplexVariable(d, 0, 0);
    return rv-x;
}
ComplexVariable solver::operator-(complex<double> d, const ComplexVariable& rv){
    ComplexVariable x = ComplexVariable(d, 0, 0);
    return x-rv;
}
ComplexVariable solver::operator-(const ComplexVariable& rv, complex<int> d){
    complex<double> cd = complex((double)d.real(), (double)d.imag());
    return rv - cd;
}
ComplexVariable solver::operator-(complex<int> d, const ComplexVariable& rv){
    return -d+rv;
}

ComplexVariable solver::operator+(const ComplexVariable& rv1, const ComplexVariable& rv2){
    ComplexVariable x = ComplexVariable(rv1.coef0_+rv2.coef0_, rv1.coef1_+rv2.coef1_, rv1.coef2_+rv2.coef2_);
    #ifdef DEBUG
    cout<<"DEBUG: "<<rv1.to_str()<<" + "<<rv2.to_str()<< " gave "<<x.to_str()<<endl;
    #endif
    return x;
}
ComplexVariable solver::operator+(const ComplexVariable& rv, double d){
    ComplexVariable x = ComplexVariable(d, 0, 0);
    return rv+x;
}
ComplexVariable solver::operator+(double d, const ComplexVariable& rv){
    ComplexVariable x = ComplexVariable(d, 0, 0);
    return rv+x;
}
ComplexVariable solver::operator+(const ComplexVariable& rv, int d){
    return rv+(double)d;
}
ComplexVariable solver::operator+(int d, const ComplexVariable& rv){
    return rv+(double)d;
}
ComplexVariable solver::operator+(const ComplexVariable& rv, complex<double> d){
    ComplexVariable x = ComplexVariable(d, 0, 0);
    return rv+x;
}
ComplexVariable solver::operator+(complex<double> d, const ComplexVariable& rv){
    ComplexVariable x = ComplexVariable(d, 0, 0);
    return rv+x;
}
ComplexVariable solver::operator+(const ComplexVariable& rv, complex<int> d){
    complex<double> cd = complex((double)d.real(), (double)d.imag());
    return rv+cd;
}
ComplexVariable solver::operator+(complex<int> d, const ComplexVariable& rv){
    return rv+d;
}

ComplexVariable solver::operator^(const ComplexVariable& rv, int d){
    if(d < 1 || (rv.coef2_ != czero && d > 1)|| (rv.coef1_ != czero && d > 2)|| d > 3){
        throw runtime_error("^ error: you cannot have a variable with exponent not equal to 0, 1 or 2");
    }
    if(d == 0){
        ComplexVariable x = ComplexVariable(0,0,0);
        return x;
    }
    else if(d == 1){
        ComplexVariable x = ComplexVariable(rv);
        return x;
    }
    else if(d == 2){
    ComplexVariable x = ComplexVariable(rv.coef0_*rv.coef0_, 2.0*rv.coef0_*rv.coef1_, rv.coef1_*rv.coef1_);
    return x;
    }
    else{
        throw runtime_error("^ something seemingly impossible happened");
    }
}
ComplexVariable solver::operator/(const ComplexVariable& rv1, const ComplexVariable& rv2){
    if(rv2.coef0_ == czero && rv2.coef1_ == czero && rv2.coef2_ == czero){
         throw runtime_error("/ error: you are trying to devide by zero!");
    }
    ComplexVariable x;
    // we have 3 cases: rv1 is ax^2, bx or c
    // c
    if(rv2.coef2_ == czero && rv2.coef1_ == czero){
        x = ComplexVariable(rv1.coef0_/rv2.coef0_, rv1.coef1_/rv2.coef0_, rv1.coef2_/rv2.coef0_);
    }
    //bx
    else if(rv2.coef2_ == czero && rv2.coef0_ == czero){
        if(rv1.coef0_ != czero){
            throw runtime_error("/ error: a division operation creates a variable with an unsupported exponent!");
        }
        x = ComplexVariable(rv1.coef1_/rv2.coef1_, rv1.coef2_/rv1.coef1_,0);
    }
    // ax^2
    else if(rv2.coef2_ == czero && rv2.coef0_ == czero){
        if(rv1.coef0_ != czero || rv1.coef1_ != czero){
            throw runtime_error("/ error: a division operation creates a variable with an unsupported exponent!");
        }
        x = ComplexVariable(rv1.coef2_/rv2.coef2_,0 ,0);
    }
    else{
        throw runtime_error("/ error: we do not support polynomial division!");
    }
    #ifdef DEBUG
    cout<<"DEBUG: "<<rv1.to_str()<<" / "<<rv2.to_str()<< " gave "<<x.to_str()<<endl;
    #endif
    return x;
}

ComplexVariable solver::operator/(const ComplexVariable& rv, double d){
    ComplexVariable x = ComplexVariable(d, 0 , 0);
    return rv/x;
 }
ComplexVariable solver::operator/(const ComplexVariable& rv, int d){
    return rv/(double)d;
}

ComplexVariable solver::operator/(const ComplexVariable& rv, complex<double> d){
    ComplexVariable x = ComplexVariable(d, 0 , 0);
    return rv/x;
 }
ComplexVariable solver::operator/(const ComplexVariable& rv, complex<int> d){
    complex<double> cd = complex((double)d.real(), (double)d.imag());
    return rv/cd;
}


ComplexVariable solver::operator==(const ComplexVariable& rv1, const ComplexVariable& rv2){
    
    #ifdef DEBUG
    cout<<"DEBUG solving:"<<rv1.to_str()<<" == "<<rv2.to_str()<<endl;
    #endif
    // transfer RHS to LHS to create the equation ax^2+bx+c
    ComplexVariable eq = ComplexVariable(rv1.coef0_-rv2.coef0_, rv1.coef1_ - rv2.coef1_, rv1.coef2_ - rv2.coef2_);

    if(eq.coef2_ != czero){
        complex<double> inside_square_root = (eq.coef1_*eq.coef1_)-4.0*eq.coef2_*eq.coef0_;
        complex<double> sol = (-eq.coef1_+sqrt(inside_square_root))/(2.0*eq.coef2_);
        return ComplexVariable(sol, 0, 0);
    }
    else if(eq.coef1_ != czero){
        complex<double> sol = -eq.coef0_/eq.coef1_;
        ComplexVariable x = ComplexVariable(sol, 0, 0);
        return x;
    }
    else if (eq.coef0_ == czero){
        return ComplexVariable(INT64_MAX,0,0);
    }
    else{
        throw runtime_error("This equation has no solution!");
    }


}

ComplexVariable solver::operator==(const ComplexVariable& rv, double d){
    ComplexVariable x = ComplexVariable(d, 0, 0);
    return rv==x;
}
ComplexVariable solver::operator==(double d, const ComplexVariable& rv){
    return rv==d;
}
ComplexVariable solver::operator==(const ComplexVariable& rv, int d){
    return rv==(double)d;
    }
ComplexVariable solver::operator==(int d, const ComplexVariable& rv){
    return rv==(double)d;
    }

ComplexVariable solver::operator==(const ComplexVariable& rv, complex<double> d){
    ComplexVariable x = ComplexVariable(d, 0, 0);
    return rv==x;
}
ComplexVariable solver::operator==(complex<double> d, const ComplexVariable& rv){
    return rv==d;
}
ComplexVariable solver::operator==(const ComplexVariable& rv, complex<int> d){
    complex<double> cd = complex((double)d.real(), (double)d.imag());
    return rv==cd;
    }
ComplexVariable solver::operator==(complex<int> d, const ComplexVariable& rv){
    return rv==d;
    }

double solver::solve(RealVariable x){return x.get_sol();}
std::complex<double> solver::solve(ComplexVariable x){return x.get_sol();}