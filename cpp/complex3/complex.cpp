#include "complex.h"

std::ostream& operator<<(std::ostream& out, const Complex& rhs)
{
    out<<"("<<rhs.re<<","<<rhs.im<<"i)";

    return out;
}

Complex::Complex(double re, double im)             //default사용
{
    this->re=re;
    this->im=im;
}

Complex::~Complex()
{

}

Complex::Complex(const Complex& rhs)                //c4
{
    this->re = rhs.re;
    this->im = rhs.im;
}

Complex& Complex::operator=(const Complex& rhs)
{
    this->re = rhs.re;
    this->im = rhs.im;

    return *this;
}


bool Complex::operator==(const Complex& rhs)
{
    // if (this->re == rhs.re && this->im == rhs.im)
    // {
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }
    return (this->re == rhs.re && this->im == rhs.im);   //위 if문을 return값에 나타낸것
}


const Complex Complex::operator+(const Complex& rhs)
{
    Complex result(this->re + rhs.re, this->im + rhs.im);

    return result;
}

const Complex Complex::operator-(const Complex& rhs)
{
    Complex result(this->re - rhs.re, this->im - rhs.im);

    return result;

}
    