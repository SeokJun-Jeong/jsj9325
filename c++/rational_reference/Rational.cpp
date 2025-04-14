#include "Rational.h"
#include <cassert>

Rational::Rational()
{
    this->number = 0;
    this->denominator = 1;
}


Rational::Rational(int number)
{
    this->number = number;
    this->denominator = 1;
}

Rational::Rational(int number, int denominator)
{
    // assert(den != 0);
    this->number = number;
    this->denominator = denominator;
}


Rational::~Rational()
{
    
}


// void Rational::operator=(Rational R)
// {
//     this->number = R.number;
//     this->denominator = R.denominator;
// }

// void Rational::operator=(const Rational *pR)
// {
//     this->number = pR->number;
//     this->denominator = pR->denominator;
// }

void Rational::operator=(const Rational& rR)
{
    this->number = rR.number;
    this->denominator = rR.denominator;
}

// int Rational::operator==(const Rational& rR)
// {
//     if (this->number == rR.number && this->denominator == rR.denominator)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

bool Rational::operator==(const Rational& rR)
{
    // if (this->number == rR.number && this->denominator == rR.denominator)
    // {
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }
    return(this->number == rR.number && this->denominator == rR.denominator);
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