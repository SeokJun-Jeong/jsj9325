#include <iostream>
#include "string.h"

int main()
{
    String s1 = "just the way you are";         
    String s2 = s1;         //String s1&s2("just the way you are");
    String s3;

    s3 = s1;
    if (s1 == s3)
    {
        std::cout << "s1 and s3 are equal" << std::endl;
    }
    else
    {
        std::cout << "s1 and s3 are not equal" << std::endl;    
    }
    
    String s4 = " -imagine dragons";
    s4 = s1 + s4;


    std::cout << "s1: " << s1.c_str() << ", " << s1.size() << std::endl;
    std::cout << "s2: " << s2 << ", " << s2.size() << std::endl;
    std::cout << "s3: " << s3 << ", " << s3.size() << std::endl;
    std::cout << "s4: " << s4 << ", " << s4.size() << std::endl;

    return 0;
}