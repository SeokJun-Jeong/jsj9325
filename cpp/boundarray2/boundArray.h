#ifndef BOUND_ARRAY_H
#define BOUND_ARRAY_H
#include "safearray.h"

template <typename T>
class BoundArray : public SafeArray
{
private:
    int low_;
    
public:
    explicit BoundArray(int size = Array<T>);   //cnrk
    // explicit BoundArray(int size = ARRAY::ARRAY_SIZE);
    BoundArray(const BoundArray<T>& rhs);
    virtual ~BoundArray();

    BoundArray& operator=(const BoundArray<T>& rhs); //{/*memberwise copy*/}

    bool operator==(const BoundArray<T>& rhs) const;

    int& operator[](int index);
    const int& operator[](int index) const;

    int upper() const;
    int lower() const;
    
};


#include "boundArray.h"
#include "safearray.h"

template <typename T>
BoundArray<T>::BoundArray(int size)
:SafeArray<T>(size)
{

}
template <typename T>
BoundArray<T>::BoundArray(int low, int upper)
:SafeArray<T>(upper - low), low_(low)
{

}
// BoundArray::BoundArray(int size = ARRAY::ARRAY_SIZE)
// {

// }
template <typename T>
BoundArray<T>::BoundArray(const BoundArray<T>& rhs)
:SafeArray<T>((SafeArray<T>)rhs), low_(rhs.low_)
{

}
template <typename T>
BoundArray::~BoundArray()
{

}

template <typename T>
BoundArray& BoundArray<T>::operator=(const BoundArray<T>& rhs)
{
    if (this != &rhs)
    {
        this->SafeArray<T>::operator=((SafeArray)rhs);
        low_ = rhs.low_;
    }
    return this;   
}

template <typename T>
bool BoundArray<T>::operator==(const BoundArray<T>& rhs) const
{
    return low_ = rhs.low_ && this->SafeArray<T>::operator==((SafeArray<T>)rhs);
}

template <typename T>
int& BoundArray<T>::operator[](int index)
{
    return this->SafeArray<T>::operator[](index - low_);
}
template <typename T>
const int& BoundArray::operator[](int index) const
{
    return this->SafeArray<T>::operator[](index - low_);
}
template <typename T>
int BoundArray<T>::upper() const
{
    return low_ + this->Array<T>::size_;
}
template <typename T>
int BoundArray::lower() const
{
    return low_;
}

#endif