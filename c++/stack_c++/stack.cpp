#include "stack.h"
//#include <stdio.h> malloc 사용 x > new, delete사용
#include <stdlib.h>
#include <assert.h>

void Stack::initStack(int size)    //Stack::을 붙여 구조체 활용
{
	// this->pArr = (int *)malloc(sizeof(int) *size);
    this->pArr = new int[size];
	assert(this->pArr /*!= NULL*/);	   //NULL = 0
	
	this->size = size;
    this->tos = 0;
}

void Stack::cleanupStack()
{
	// free(this->pArr);
    delete [] this->pArr;
}

void Stack::push(int data)
{
    // When full
    //if (this->tos == STACKSIZE) 대신
	// if(this->tos == this->size)
    // {
    //     fprintf(stderr, "Stack is full.\n");
    //     exit(1); // 프로그램 비정상 종료
    // }
	assert(this->tos != this->size);
	//this->array[this->tos] = data; 대신
	this->pArr[this->tos] = data;   // = *(this->pArr + this->tos) = data;
	++this->tos;
}

int Stack::pop()
{
    // When empty
    // if (this->tos == 0)
    // {
    //     fprintf(stderr, "Stack is empty\n");
    //     exit(2);
    // }
    assert(this->tos != 0);


	
	--this->tos;
	//return this->array[this->tos];
	return this->pArr[this->tos];
}