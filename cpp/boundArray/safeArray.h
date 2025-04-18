#ifndef SAFE_ARRRAY_H
#define SAFE_ARRRAY_H

#include "array.h"

class SafeArray : public Array
{
private:
    //줄게 없음
public:

    explicit SafeArray(int size = Array::getDefaultArraySize());
    SafeArray(const int *pArr, int size);
    SafeArray(const SafeArray& rhs); //{ /*memberwise copy*/};  소멸자는 컴파일러 제공한거 씀
    // ~SafeArray() {};
    SafeArray& operator=(const SafeArray& rhs); //{/*memberwise copy*/}

    bool operator==(const SafeArray& rhs) const;

    // SafeArray& operator[](int index);

     virtual int& operator[](int index);
     virtual const int& operator[](int index) const;

    // int size(); // Array:size() is inherit(public);


    // SafeArray *operator&() {return this;}
    // const SafeArray* operator&() const {return this;}

};



#endif