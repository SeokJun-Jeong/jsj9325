#ifndef SAFE_ARRRAY_H
#define SAFE_ARRRAY_H

#include "array.h"

template<typename T>
class SafeArray : public Array<T>
{
private:
    //줄게 없음
public:

    explicit SafeArray(int size = Array<T>::ARRAY_SIZE);
    SafeArray(const T *pArr, int size);
    SafeArray(const SafeArray<T>& rhs); //{ /*memberwise copy*/};  소멸자는 컴파일러 제공한거 씀
    // ~SafeArray() {};
    SafeArray<T>& operator=(const SafeArray<T>& ); //{/*memberwise copy*/}

    bool operator==(const SafeArray<T>& rhs) const;

    // SafeArray& operator[](int index);

     virtual T& operator[](int index);
     virtual const T& operator[](int index) const;

    // int size(); // Array:size() is inherit(public);


    // SafeArray *operator&() {return this;}
    // const SafeArray* operator&() const {return this;}

};



#include <cassert>

template<typename T>
SafeArray<T>::SafeArray(int size)
:Array<T>(size)
{

}

template<typename T>
SafeArray<T>::SafeArray(const T *pArr, int size)
: Array<T>(pArr, size)
{

}

template<typename T>
SafeArray<T>::SafeArray(const SafeArray<T>& rhs)
: Array<T>((Array<T>)rhs)  //slicing하여 array관련 내용만 남게 타입캐스팅
{

}

template<typename T>
SafeArray<T>& SafeArray<T>::operator=(const SafeArray<T>& rhs)
{
    if (this != &rhs)
    {
        this->Array<T>::operator=((Array<T>)rhs);
         // safearray 쪽에서 추가된게 있으면 여기에 추가
    }
    
    return *this;
}

template<typename T>
bool SafeArray<T>::operator==(const SafeArray<T>& rhs) const
{
    return this->Array<T>::operator==((Array<T>)rhs);
}

template<typename T>
T& SafeArray<T>::operator[](int index)
{
    assert(index >= 0 && index < this->Array<T>::size_);          //this->Array::size()에서 array::생략하여 표기
    return this->Array<T>::operator[](index);
}

template<typename T>
const T& SafeArray<T>::operator[](int index) const
{
    assert(index >= 0 && index < this->Array<T>::size_); 
    return this->Array<T>::operator[](index);
}

#endif