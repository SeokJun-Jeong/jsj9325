#include "Rational.h"
#include <cassert>

Rational::Rational(int number, int denominator)
{
    // assert(den != 0);
    this->number = number;
    this->denominator = denominator;
}

Rational::Rational(int number)
{
    this->number = number;
    this->denominator = 1;
}

Rational::Rational()
{
    this->number = 0;
    this->denominator = 1;
}


Rational::~Rational()
{
    
}

int Rational::getNumber()
{
    return this->number;
}

int Rational::getDenominator()
{   
    return this->denominator;
}

void Rational::setNumber(int number)
{
    this->number = number;
}

void Rational::setDenominator(int denominator)
{
    this->denominator = denominator;   
}