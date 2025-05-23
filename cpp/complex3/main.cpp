#include <iostream>
#include "complex.h"

int main()
{
    Complex c1;
    Complex c2 = 3.0;           // = Complex c2(3.0);
    Complex c3(3.0, 4.0);
    Complex c4 = c3;            // = Complex c4(c3);   Complex::Complex(const Complex& rhs) 

    // // c1.real(c3.real());
    // // c1.imag(c3.imag());
    // //c1 = &c3;        x  c1.operator=(&c3);   
    c1 = c3;            //operator=(c1,c3) or c1.operator=(c3)  =   void operator=(const Complex& rc)
    // c1 = c2 = c3;       //daisy-chain

    // // if (c1.real() == c3.real() && c1.imag() == c3.imag())
    if(c1 == c3)        //operator=(c1, c3) or c1.operator=(c3)
    {
        std::cout << "c1 and c3 are equal" << std::endl;
    }
    else
    {
        std::cout << "c1 and c3 are not equal" << std::endl;    
    }

    c4 = c2 + c3;           // c2.operator+(c3) or operator+(c2,c3)   const Complex operator+(const Complex& rhs)
    c1 = c2 - c3;

    
    std::cout << c1 << std::endl;            //(3.0, 4.0i) std::cout.operator<<(c1) X  or operator<<(std::cout, c1) O
    std::cout << c2 << std::endl;
    std::cout << c3 << std::endl;
    std::cout << c4 << std::endl;
    


    // std::cout << "c1 : (" << c1.real() << ", " << c1.imag() << "i)" << std::endl;
    // std::cout << "c2 : (" << c2.real() << ", " << c2.imag() << "i)" << std::endl;
    // std::cout << "c3 : (" << c3.real() << ", " << c3.imag() << "i)" << std::endl;
    return 0;
}