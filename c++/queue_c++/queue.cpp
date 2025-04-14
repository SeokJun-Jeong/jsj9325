#include <cstdio>
#include <cstdlib>
#include "queue.h"
#include <cassert>

Queue::Queue(int size)   //초기화
{
    this->pArr = new int[size];
    assert(this->pArr);
    this->size = size;
    
    this->front =this->rear= 0;
}

Queue::~Queue()
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