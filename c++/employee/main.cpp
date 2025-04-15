#include <iostream>
#include "employee.h"

int main()
{
    Employee e1(1, "Jeong Seok Jun", NULL);
    Employee e2(2, "Park Hae Jun", &e1);
    Employee e3(3, "Park Jae Young", &e2);
    Employee e4(4, "Park Au Jin", &e3);
    Employee e5(5,"Park Young Jae", &e4);

    
    // Employee e6 = e1;

    // e1 = e2;

    std::cout << "id : " << e1.getId() << " " << e1.getName << std::endl;
    std::cout << "id : " << e2.getId() << " " << e2.getName << std::endl;

    return 0;
}