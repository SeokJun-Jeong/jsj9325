#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
class Rational
{
    friend std::ostream& operator<<(std::ostream & out, const Rational& rhs);


public: //인터페이스
    Rational(int number = 0.0, int denominator = 0.0);  //construct
    Rational(const Rational& rhs);
    // ~Rational();                            //destructor
    

    Rational& operator+=(const Rational& rhs);

 
    bool operator==(const Rational& rhs);
    bool operator!=(const Rational& rhs);

    const Rational operator+(const Rational& rhs);
    const Rational operator-(const Rational& rhs);


    Rational& operator++();
    Rational operator++(int );

private: //내부 구현(implemetation)
    int number_;
    int denominator_;
};

#endif