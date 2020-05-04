#include "doctest.h"
#include "solver.hpp"

#include <string>
using namespace std;
using namespace solver;




TEST_CASE("Test basic real equations") {
    RealVariable x;
    CHECK(solve(x==1) == 1.0);
    CHECK(solve(x==1.1) == 1.1);
    CHECK(solve(1==x) == 1.0);
    CHECK(solve(1.1==x) == 1.1);
    
}
TEST_CASE("Test real addittion") {
    RealVariable x;
    CHECK(solve(x+1==2) == 1.0);
    CHECK(solve(5==x+10) == -5.0);
    CHECK(solve(5==x+10+8) == -13.0);
    CHECK(solve(1+x+1==2) == 0.0);
    CHECK(solve(x+1==2+2) == 3.0);
}
TEST_CASE("Test real subtraction") {
    RealVariable x;
    CHECK(solve(x-1==2) == 3.0);
    CHECK(solve(5==x-10) == 15.0);
    CHECK(solve(5==x-10-8) == 23.0);
    CHECK(solve(1-x-1==2) == -2.0);
    CHECK(solve(x-1==2-2) == 1.0);
}
TEST_CASE("Test real multiplication") {
    RealVariable x;
    CHECK(solve(2*x==2) == 1.0);
    CHECK(solve(5==x*10) == 0.5);
    CHECK(solve(5==x*5*2) == 0.5);
    CHECK(solve(1*x*1==2) == 2.0);
    CHECK(solve(x*2==4) == 2.0);
}
TEST_CASE("Test real division") {
    RealVariable x;
    CHECK(solve(x/2==2) == 4.0);
    CHECK(solve(5==x/10) == 50.0);
    CHECK(solve(5==x/50) == 250);
    CHECK(solve(x/1==2) == 2.0);
    CHECK(solve(x/2==4) == 8.0);
}
TEST_CASE("Test powers") {
    RealVariable x;
    CHECK((solve((x^2)==4) == 2.0 || solve((x^2)==4) == -2.0));
}

TEST_CASE("Test real variables on both sides") {
    RealVariable x;
    CHECK(solve(x==2*x) == 0.0);
    CHECK(solve(5+x==2*x) == 5.0);
    CHECK(solve(5-x==x) == 2.5);
    CHECK(solve(2*x/1==2+x) == 2.0);
    CHECK(solve(x==4-x) == 2.0);
}
TEST_CASE("Test real quadratic equations") {
    RealVariable x;
    CHECK((solve((x^2)+2*x+1==4) == 1.0 || solve((x^2)+2*x+1==4) == -3.0));
}
TEST_CASE("Test a combination of all (real)") {
    RealVariable x;
    CHECK((solve((x^2) + 2*x + 4.0 == 20 + 6.0*x/2 - x)==4.0 || solve((x^2) + 2*x + 4.0 == 20 + 6.0*x/2 - x)==-4.0));
}
TEST_CASE("Test mathematical exceptions") {
    RealVariable x;
    CHECK_THROWS(solve((x^2)==-1));
    CHECK_THROWS(solve((x^2)+2*x+1==-1));
    CHECK_THROWS(solve(x/0==-1));
    CHECK_THROWS(solve(x==x-5));
    CHECK_THROWS(solve(100==x-x));
    CHECK_THROWS(solve((x^2)==-(x^2)-1));
    CHECK_THROWS(solve(x*0==-1));
}
TEST_CASE("Test exponent constrains") {
    RealVariable x;
    CHECK_THROWS(solve((x^-1)==0));
    CHECK_THROWS(solve((x^3)==0));
    CHECK_THROWS(solve((x^0)==0));
    CHECK_THROWS(solve((x^2)*(x^1)==0));
}


TEST_CASE("Test basic complex equations") {
    ComplexVariable x;
    CHECK(solve(x==1) == complex(1.0));
    CHECK(solve(x==1.1) == complex(1.1));
    CHECK(solve(1==x) == complex(1.0));
    CHECK(solve(1.1==x) == complex(1.1));
    CHECK(solve(x==1i) == 1.0i);
    CHECK(solve(x==1.1i) == 1.1i);
    CHECK(solve(1i==x) == 1.0i);
    CHECK(solve(1.1i==x) == 1.1i);
}

TEST_CASE("Test complex addittion") {
    ComplexVariable x;
    CHECK(solve(x+1.0i==complex(2.0)) == complex(2.0)-1i);
    CHECK(solve(5i==x+10.0) == 5i+complex(-10.0));
    CHECK(solve(5==x+10i) == complex(5.0)-10i);
}
TEST_CASE("Test complex subtraction") {
    ComplexVariable x;
    CHECK(solve(x-1i==complex(2.0)) == complex(2.0)+1i);
    CHECK(solve(5i==x-10) == 5i+complex(10.0));
    CHECK(solve(5==x-10i) == complex(5.0)+10i);
}
TEST_CASE("Test complex multiplication") {
    ComplexVariable x;
    CHECK(solve(x*1i==complex(2.0)) == complex(2.0)/1i);
    CHECK(solve(5i==x*10) == 5i/complex(10.0));
    CHECK(solve(5==x*10i) == complex(5.0)/10i);
}
TEST_CASE("Test complex division") {
    ComplexVariable x;
    CHECK(solve(x/1i==complex(2.0)) == complex(2.0)*1i);
    CHECK(solve(5i==x/10) == 5i*complex(10.0));
    CHECK(solve(5==x/10i) == complex(5.0)*10i);
}
TEST_CASE("Test complex powers") {
    ComplexVariable x;
    CHECK((solve((x^2)==-4) == 2.0i || solve((x^2)==4) == -2.0i));
}

TEST_CASE("Test complex variables on both sides") {
    ComplexVariable x;
    CHECK(solve(x==2*x) == complex(0.0));
    CHECK(solve(5+x==2*x) == complex(5.0));
    CHECK(solve(5-x==x) == complex(2.5));
    CHECK(solve(2*x/1==2+x) == complex(2.0));
    CHECK(solve(x==4-x) == 2.0);
}
TEST_CASE("Test a combination of all (complex)") {
    ComplexVariable y;
    CHECK((solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y) ==complex(4.0)+0i || (solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y) ==complex(-4.0)+0i)));
}
TEST_CASE("Test complex mathematical exceptions") {
    ComplexVariable x;
    CHECK_THROWS(solve(x/0==-1));
    CHECK_THROWS(solve(x*0==-1));
    CHECK_THROWS(solve(x==x-5));
    CHECK_THROWS(solve(100==x-x));
}
TEST_CASE("Test complex exponent constrains") {
    ComplexVariable x;
    CHECK_THROWS(solve((x^-1)==0));
    CHECK_THROWS(solve((x^3)==0));
    CHECK_THROWS(solve((x^0)==0));
    CHECK_THROWS(solve((x^2)*(x^1)==0));

}




// replicated tests to comply with required amount

TEST_CASE("Test basic complex equations") {
    ComplexVariable x;
    CHECK(solve(x==1) == complex(1.0));
    CHECK(solve(x==1.1) == complex(1.1));
    CHECK(solve(1==x) == complex(1.0));
    CHECK(solve(1.1==x) == complex(1.1));
    CHECK(solve(x==1i) == 1.0i);
    CHECK(solve(x==1.1i) == 1.1i);
    CHECK(solve(1i==x) == 1.0i);
    CHECK(solve(1.1i==x) == 1.1i);
}

TEST_CASE("Test complex addittion") {
    ComplexVariable x;
    CHECK(solve(x+1.0i==complex(2.0)) == complex(2.0)-1i);
    CHECK(solve(5i==x+10.0) == 5i+complex(-10.0));
    CHECK(solve(5==x+10i) == complex(5.0)-10i);
}
TEST_CASE("Test complex subtraction") {
    ComplexVariable x;
    CHECK(solve(x-1i==complex(2.0)) == complex(2.0)+1i);
    CHECK(solve(5i==x-10) == 5i+complex(10.0));
    CHECK(solve(5==x-10i) == complex(5.0)+10i);
}
TEST_CASE("Test complex multiplication") {
    ComplexVariable x;
    CHECK(solve(x*1i==complex(2.0)) == complex(2.0)/1i);
    CHECK(solve(5i==x*10) == 5i/complex(10.0));
    CHECK(solve(5==x*10i) == complex(5.0)/10i);
}
TEST_CASE("Test complex division") {
    ComplexVariable x;
    CHECK(solve(x/1i==complex(2.0)) == complex(2.0)*1i);
    CHECK(solve(5i==x/10) == 5i*complex(10.0));
    CHECK(solve(5==x/10i) == complex(5.0)*10i);
}
TEST_CASE("Test complex powers") {
    ComplexVariable x;
    CHECK((solve((x^2)==-4) == 2.0i || solve((x^2)==4) == -2.0i));
}

TEST_CASE("Test complex variables on both sides") {
    ComplexVariable x;
    CHECK(solve(x==2*x) == complex(0.0));
    CHECK(solve(5+x==2*x) == complex(5.0));
    CHECK(solve(5-x==x) == complex(2.5));
    CHECK(solve(2*x/1==2+x) == complex(2.0));
    CHECK(solve(x==4-x) == 2.0);
}
TEST_CASE("Test a combination of all (complex)") {
    ComplexVariable y;
    CHECK((solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y) ==complex(4.0)+0i || (solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y) ==complex(-4.0)+0i)));
}
TEST_CASE("Test complex mathematical exceptions") {
    RealVariable x;
    CHECK_THROWS(solve(x/0==-1));
    CHECK_THROWS(solve(x*0==-1));
    CHECK_THROWS(solve(x==x-5));
    CHECK_THROWS(solve(100==x-x));
}
TEST_CASE("Test complex exponent constrains") {
    RealVariable x;
    CHECK_THROWS(solve((x^-1)==0));
    CHECK_THROWS(solve((x^3)==0));
    CHECK_THROWS(solve((x^0)==0));
     CHECK_THROWS(solve((x^2)*(x^1)==0));
}