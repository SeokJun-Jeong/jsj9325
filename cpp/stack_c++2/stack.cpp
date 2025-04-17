#include "stack.h"
#include <cassert>


// const int Stack_SIZE = 100;
const int Stack::STACK_SIZE = 100; 

// int Stack::getDefaultStackSize()
// {
//     return Stack::STACK_SIZE;
// }

Stack::Stack(int size)
: pArr_(new int[size]), size_(size), tos_(0)
{
    assert(pArr_);
}

Stack::~Stack()
{
    delete [] pArr_;
}

Stack::Stack(const int *pArr, int size)
: pArr_(new int[size]), size_(size)
{
    assert(pArr_);
    for (int i = 0; i < size; ++i)
    {
        pArr_[i] = pArr[i];
    }
}


Stack::Stack(const Stack& rhs)
:pArr_(new int[rhs.size_]),size_(rhs.size_)
{
    assert(pArr_);
    for (int i = 0; i < size_; ++i)
    {
        pArr_[i] = rhs.pArr_[i];
    }
    
}

// Stack& Stack::operator=(const Stack& rhs)
// {
//     if (this != &rhs) //자기자신 치환
//     {
//         delete [] pArr_;
//         pArr_ = new int[rhs.size_];
//         assert(pArr_);
//         for (int  i = 0; i < rhs.size_; ++i)
//         {
//             pArr_[i] = rhs.pArr_[i];
//         }
//             size_ = rhs.size_;
        
//     }
//     return *this;
// }

// bool Stack::operator==(const Stack& rhs) const
// {
//     if (size_ != rhs.size_)
//     {
//         return false;
//     }
 
//     int i;
//     for (i = 0; i < rhs.size_; ++i)
//     {
//         if (pArr_[i] != rhs.pArr_[i])
//         {
//             break;
//         }
        
//     }
//     return(i == rhs.size_);
// }



// int& Stack::operator[](int index)
// {
//     return pArr_[index];

// }

// const int& Stack::operator[](int index) const
// {
//     return pArr_[index];

// }

int Stack::size() const
{
    return size_;
}

int Stack::remain() const
{
    return size_ - tos_;
}

bool Stack::isEmpty() const
{
    return tos_ == 0;
}

bool Stack::isFull() const
{
    return tos_ == size_;
}

void Stack::push(int data)
{

	assert(!this->isFull());
	//this->array[this->tos] = data; 대신
	pArr_[tos_] = data;   // = *(this->pArr + this->tos) = data;
	++tos_;
}

int Stack::pop()
{

    assert(!this->isEmpty);

    --tos_;
	//return this->array[this->tos];
	return pArr_[tos_];
}