#include "Rational.h"
#include <cassert>
#include <ostream>

std::ostream& operator<<(std::ostream & out, const Rational& rhs)
{
    out<<"("<<rhs.number<<","<<rhs.denominator<<"i)";

    return out;
}


Rational::Rational(int number, int denominator)
{
    this->number = number;
    this->denominator = denominator;
}

Rational::Rational(const Rational& rhs)
{
    this->denominator = rhs.denominator;
    this->number = rhs.number;
}


Rational::~Rational()
{
    
}



Rational& Rational::operator=(const Rational& rhs)
{
    this->number = rhs.number;
    this->denominator = rhs.denominator;

    return *this;
}


bool Rational::operator==(const Rational& rhs)
{

    return(this->number == rhs.number && this->denominator == rhs.denominator);
}

const Rational Rational::operator+(const Rational& rhs)
{
    Rational result(this->number +  rhs.number, this->denominator + rhs.denominator);

    return result;
}


const Rational Rational::operator-(const Rational& rhs)
{
    Rational result(this->number -  rhs.number, this->denominator - rhs.denominator);

    return result;
}

const Rational Rational::operator*(const Rational& rhs)
{
    Rational result(this->number *  rhs.number, this->denominator * rhs.denominator);

    return result;
}

const Rational Rational::operator/(const Rational& rhs)
{
    Rational result(this->number /  rhs.number, this->denominator / rhs.denominator);

    return result;
}
