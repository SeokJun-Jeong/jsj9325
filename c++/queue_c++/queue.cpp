#include <cstdio>
#include <cstdlib>
#include "queue.h"
#include <cassert>

Queue::Queue(int size)   //객체가 생성될때 자동적으로 호출되는 멤버함수
{
    this->pArr = new int[size];
    assert(this->pArr);
    this->size = size;
    
    this->front =this->rear= 0;
}

Queue::~Queue()         //객체가 소멸될때 자동적으로 호출되는 멤버함수
{
    delete [] this->pArr;
}

void Queue::push(int data)
{

    
    assert(this->rear != this->size);


    this->pArr[this->rear] = data;
	++this->rear;
}

int Queue::pop()
{

    assert(this->rear != this->front);

    
    int i = this->front;
	++this->front;
	return this->pArr[i];
}