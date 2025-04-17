#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
private: //내부 구현(implemetation)
    int number;
    int denominator;

public: //인터페이스
    Rational(int number, int denominator);  //construct
    Rational(int number);
    Rational();
    ~Rational();                            //destructor

    int getNumber();
    int getDenominator();

    void setNumber(int number);
    void setDenominator(int denominator);
};

#endif