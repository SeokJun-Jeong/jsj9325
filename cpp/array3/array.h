// 헤더와 cpp를 합쳐서 만듬 (template<typename T> 를 사용하여 int -> T, class에 붙은 함수를 -><T>로 추가한다)
#ifndef ARRAY_H
#define ARRAY_H


// #define ARRAY_SIZE 100
// extern const int ARRAY_SIZE; //cpp에 const int ARRAY_SIZE불러오기

template <typename T>
class Array
{
private:
    T *pArr_;

protected:
    int size_;
    static const int ARRAY_SIZE; //extern const int ARRAY_SIZE;  public안으로 불러옴 , private로 부르면 외부차단으로 인해 에러 발생


public:
    // extern const int ARRAY_SIZE;  //public안으로 불러옴 , private로 부르면 외부차단으로 인해 에러 발생
    static int getDefaultArraySize();

    // Array(); // Array() {};
    explicit Array(int size = ARRAY_SIZE);  //Array::Array(int size)
    Array(const T *pArr, int size);
    Array(const Array<T>& rhs);     // Array(const Array&) { /*memberwise copy */}
    virtual ~Array();  // ~Array() {};

    Array<T>& operator=(const Array& rhs);   //{/*memberwise copy */ return *this}

    bool operator==(const Array<T>& rhs) const;
    
    virtual T& operator[](int index);
    virtual const T& operator[](int index) const;
    
    // Array<T> *operator&() {return this;}
    // const Array<T> *operator&() const { return this; }

    int size() const;
};




#include <cassert>
// #include "array.h"    같이 참조하므로 삭제
// const int ARRAY_SIZE = 100;

template <typename T>
const int Array<T>::ARRAY_SIZE = 100; 

template <typename T>
int Array<T>::getDefaultArraySize()
{
    return Array<T>::ARRAY_SIZE;
}

template <typename T>
Array<T>::Array(int size)
: pArr_(new T[size]), size_(size)
{
    assert(pArr_);
}

template <typename T>
Array<T>::Array(const T *pArr, int size)
: pArr_(new T[size]), size_(size)
{
    assert(pArr_);
    for (int i = 0; i < size; ++i)
    {
        pArr_[i] = pArr[i];
    }
}

template <typename T>
Array<T>::~Array()
{
    delete [] pArr_;
}


template <typename T>
Array<T>::Array(const Array<T>& rhs)
:pArr_(new T[rhs.size_]),size_(rhs.size_)
{
    assert(pArr_);
    for (int i = 0; i < size_; ++i)
    {
        pArr_[i] = rhs.pArr_[i];
    }
    
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
    if (this != &rhs) //자기자신 치환
    {
        delete [] pArr_;
        pArr_ = new T[rhs.size_];
        assert(pArr_);
        for (int  i = 0; i < rhs.size_; ++i)
        {
            pArr_[i] = rhs.pArr_[i];
        }
            size_ = rhs.size_;
        
    }
    return *this;
}

template <typename T>
bool Array<T>::operator==(const Array<T>& rhs) const
{
    if (size_ != rhs.size_)
    {
        return false;
    }
 
    int i;
    for (i = 0; i < rhs.size_; ++i)
    {
        if (pArr_[i] != rhs.pArr_[i])
        {
            break;
        }
        
    }
    return(i == rhs.size_);
}



template <typename T>
T& Array<T>::operator[](int index)
{
    return pArr_[index];

}

template <typename T>
const T& Array<T>::operator[](int index) const
{
    return pArr_[index];

}

template <typename T>
int Array<T>::size() const
{
    return size_;
}

#endif