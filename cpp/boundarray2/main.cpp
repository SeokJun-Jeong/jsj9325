#include <iostream>
#include "boundArray.h"
// #include "safearray.h"


int main()
{   
    BoundArray<int> arr1(1,11);

    for (int i = arr1.lower(); i != arr1.upper(); ++i)
    {
        arr1[i] = i;
    }
    for (int i = arr1.lower(); i != arr1.upper(); ++i)
    {
        std::cout << i << " : " << arr1[i] << std::endl;
    }
    

    BoundArray<double> arr1(5,11);
    for (int i = arr2.lower(); i != arr2.upper(); ++i)
    {
        arr2[i] = i;
    }
    for (int i = arr2.lower(); i != arr2.upper(); ++i)
    {
        std::cout << i << " : " << arr2[i] << std::endl;
    }
    
}