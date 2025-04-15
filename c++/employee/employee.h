#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "string.h"

class Employee
{
private:
    int id;
    String name;
    Employee *pManager;

    //is not used.
    Employee(const Employee& rhs);
    Employee& operator=(const Employee& rhs);
public:
    Employee(int id, String name, Employee *pManager);
    //~Employee() {};   

    //Employee() {}  <- 명시가 되어 있기 때문에 생성 x 
    //Employee(const Employee& rhs) {memberwise copy}; <-생성 x
    // Employee operator=(const Employee& rhs) {memberwise copy return this;}       <-생성 x

    //Employee* operator&() {return this};
    // const Employee* operator&() const {return this;}

    int getId();            //get
    String getName();
    Employee *getManager();

    bool isManager();

};





#endif