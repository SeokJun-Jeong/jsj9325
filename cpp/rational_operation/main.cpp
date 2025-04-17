//Rational number(유리수) 구하기 잘못적음

#include <iostream>
#include "Rational.h"

int main()
{
    Rational r1;                            // 0 / -4
    Rational r2 = 3; //Rational r2(3);      // 3 / 1
    Rational r3(3,4);                       // 0 / 1
    Rational r4 = r3;                       //Rational::Rational(const Rational& rhs)  


    r1 = r3;

    r1 == r3;
    r1 != r3;

    r1 = r2 + r3;
    r1 = r2 - r3;
    r1 += r2 += r3;

    ++r1;
    r1++;


    // if (c1.real() == c3.real() && c1.imag() == c3.imag())
    if(r1 == r3)        //operator==(c1, c3) or c1.operator==(c3)
    {
        std::cout << "r1 and r3 are equal" << std::endl;
    }
    else
    {
        std::cout << "r1 and r3 are not equal" << std::endl;    
    }

   
    // r1 = r2 / r3;
    std::cout << r1 << std::endl; 
    std::cout << r2 << std::endl; 
    std::cout << r3 << std::endl; 
    std::cout << r4 << std::endl; 


    return 0;
}