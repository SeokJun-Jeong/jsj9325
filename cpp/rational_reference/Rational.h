#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
    
    public: //인터페이스
    Rational(int number, int denominator);  //construct
    Rational(int number);
    Rational();
    ~Rational();                            //destructor
    
    // void operator=(Rational R);
    // void operator=(const Rational *pR);
    void operator=(const Rational& rR);

    // int operator==(const Rational& rR);
    bool operator==(const Rational& rR);
    
    int getNumber();
    int getDenominator();
    
    void setNumber(int number);
    void setDenominator(int denominator);


    private: //내부 구현(implemetation)
    int number;
    int denominator;
};

#endif