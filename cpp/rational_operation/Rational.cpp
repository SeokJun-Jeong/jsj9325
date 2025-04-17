#include "Rational.h"
#include <iostream>

std::ostream& operator<<(std::ostream & out, const Rational& rhs)
{
    return out<<"("<<rhs.number_<<","<<rhs.denominator_<<"i)";

}


Rational::Rational(int number, int denominator)
{
    number_ = number;
    denominator_ = denominator;
}

Rational::Rational(const Rational& rhs)
{
    denominator_ = rhs.denominator_;
    number_ = rhs.number_;
}


// Rational::~Rational()
// {
    
// }



Rational& Rational::operator+=(const Rational& rhs)
{
    number_ += rhs.number_;
    denominator_ += rhs.denominator_;

    return *this;
}


bool Rational::operator==(const Rational& rhs)
{

    return(number_ == rhs.number_ && denominator_ == rhs.denominator_);
}

bool Rational::operator!=(const Rational& rhs)
{
    return !operator==(rhs);

}

const Rational Rational::operator+(const Rational& rhs)
{
    Rational result(number_ +  rhs.number_, denominator_ + rhs.denominator_);

    return result;
}


const Rational Rational::operator-(const Rational& rhs)
{
    Rational result(number_ -  rhs.number_, denominator_ - rhs.denominator_);

    return result;
}

Rational& Rational::operator++()
{
    number_+=1.0;

    return *this;
}

Rational Rational::operator++(int )
{
    Rational tmp = *this;
    number_+=1.0;

    return tmp;
}
