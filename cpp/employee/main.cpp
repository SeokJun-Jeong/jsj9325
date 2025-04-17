//고치기 노트작성하기
#include <iostream>
#include "employee.h"

void printEmployee(Employee *p)
{
    std::cout << "id: " << p->getId() << "name : "<< p->getName() << " | ";
    std::cout <<((p->getManager() )? "" : p->getManager()->getName()) <<std::endl;
}
int main()
{
    // Employee e1(1, "Jeong Seok Jun", NULL);
    // Employee e2(2, "Park Hae Jun", &e1);
    // Employee e3(3, "Park Jae Young", &e2);
    // Employee e4(4, "Park Au Jin", &e3);
    // Employee e5(5,"Park Young Jae", &e4);

    // Employee e6 = e1;
    // e1 = e2;

    // Employee Employees[10]; //default construct가 없기에 생성이 x
    Employee* pEmployees[10];    //pointer를 사용하여 정의
    pEmployees[0] = new Employee(1, "Jeong Seok Jun", NULL);
    pEmployees[1] = new Employee(2, "Park Hae Jun", pEmployees[0]);
    pEmployees[2] = new Employee(3, "Park Jae Young", pEmployees[0]);
    pEmployees[3] = new Employee(4, "Park Au Jin", pEmployees[0]);
    pEmployees[4] = new Employee(5, "Park Young Jae", pEmployees[3]);
    

    for (int i = 0; i < 5; ++i)
    {
        printEmployee(pEmployees[i]);
    }
    

    for (int i = 0; i < 5; ++i)
    {
        delete pEmployees[i];
    }
    


    // std::cout << "id : " << e1.getId() << " " << e1.getName << std::endl;
    // std::cout << "id : " << e2.getId() << " " << e2.getName << std::endl;

    return 0;
}