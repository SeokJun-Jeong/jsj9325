//Rational number(유리수) 구하기 잘못적음

#include <iostream>
#include "Rational.h"

int main()
{
    Rational r1;                         // 3 / 4
    Rational r2 = 3; //Rational r2(3);    // 3 / 1
    Rational r3(3,4);                    // 0 / 1
    
    r1 = r3;

    // if (c1.real() == c3.real() && c1.imag() == c3.imag())
    if(r1 == r3)        //operator==(c1, c3) or c1.operator==(c3)
    {
        std::cout << "r1 and r3 are equal" << std::endl;
    }
    else
    {
        std::cout << "r1 and r3 are not equal" << std::endl;    
    }

    std::cout << "r1 : (" << r1.getNumber() << ", " << r1.getDenominator() << "i)" << std::endl;
    std::cout << "r2 : (" << r2.getNumber() << ", " << r2.getDenominator() << "i)" << std::endl;
    std::cout << "r3 : (" << r3.getNumber() << ", " << r3.getDenominator() << "i)" << std::endl;
    
    return 0;
}