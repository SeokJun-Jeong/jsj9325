#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public: //인터페이스
    Complex();                      //default constructor(기본생산자)
    Complex(double re);             //convert. constructor(변환생산자)
    Complex(double re, double im);  //construct(생산자)
    ~Complex();
    
    //void operator = (Complex c);
    // void operator=(const Complex *pc);   //pointer 사용 사용x
    void operator=(const Complex& rc);      //referece 사용

    // int operator==(const Complex& rc);          //ex) 4==4 true(int 1), 4==3 false(int0)
    bool operator==(const Complex& rc);
 
    double real();
    double imag();
    
    void real(double re);
    void imag(double im);



private: //내부 구현(implemetation)
    double re;  //real
    double im;  //imaginary
};

#endif