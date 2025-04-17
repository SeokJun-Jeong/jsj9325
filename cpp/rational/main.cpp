//Rational number(유리수) 구하기 잘못적음

#include <iostream>
#include "Rational.h"

int main()
{
    Rational r1(3,4);        // 3 / 4
    Rational r2(3);               // 3 / 1
    Rational r3;                  // 0 / 1
    
    // r3.setNumber(r1.getNumber);
    // r3.setDenominator(r1.getDenominator);

    std::cout << "r1 : (" << r1.getNumber() << ", " << r1.getDenominator() << "i)" << std::endl;
    std::cout << "r2 : (" << r2.getNumber() << ", " << r2.getDenominator() << "i)" << std::endl;
    std::cout << "r3 : (" << r3.getNumber() << ", " << r3.getDenominator() << "i)" << std::endl;
    
    return 0;
}