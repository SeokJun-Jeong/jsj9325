#ifndef BOUND_ARRAY_H
#define BOUND_ARRAY_H
#include "safeArray.h"

class BoundArray : public SafeArray
{
private:
    int low_;
    
public:
    BoundArray(int low, int upper);
    // explicit BoundArray(int size = ARRAY::ARRAY_SIZE);
    BoundArray(const BoundArray& rhs);
    virtual ~BoundArray();

    BoundArray& operator=(const BoundArray& rhs); //{/*memberwise copy*/}

    bool operator==(const BoundArray& rhs) const;

    int& operator[](int index);
    const int& operator[](int index) const;

    int upper() const;
    int lower() const;
    
};



#endif