#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>
// class Complex;          //class선언

class Complex
{
friend std::ostream& operator<<(std::ostream& out, const Complex& rhs);     //class문에 있지만 전역함수이다(friend)

public: 
    // Complex();                    
    // Complex(double re);          
    Complex(double re = 0.0, double im = 0.0);          //default argument vs parameter
    Complex(const Complex& rhs);                        //copy constructor
    ~Complex();                    
    
    // void operator = (Complex c);
    // void operator=(const Complex *pc);   //pointer 사용 사용x
    Complex& operator=(const Complex& rhs);      //referece 사용

    // int operator==(const Complex& rc);          c언어
    bool operator==(const Complex& rhs);          //c++
 
    const Complex operator+(const Complex& rhs);
    const Complex operator-(const Complex& rhs);
    // const Complex operator*(const Complex& rhs);
    // const Complex operator/(const Complex& rhs);
    //-,*,/

    // double real();
    // double imag();
    
    // void real(double re);
    // void imag(double im);



private: //내부 구현(implemetation)
    double re;  
    double im;  
};

#endif