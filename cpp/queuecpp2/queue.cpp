#include "queue.h"
#include <cassert>

const int Queue::QUEUE_SIZE = 100;

Queue::Queue(int size)
: array_(size),front_(0), rear_(0)
{
    // assert(pArr_);
}

Queue::~Queue()
{
    // delete[] pArr_;
}

bool Queue::empty() const
{
    return front_ == rear_;
}

bool Queue::full() const
{
    return rear_ == array_.size();
}

int Queue::size() const
{
    return array_.size();
}

int Queue::remain() const
{
    return array_.size() - rear_;
}

void Queue::push(int data)
{
    assert(!full());

    array_[rear_] = data;
    ++rear_;
}

int Queue::pop()
{
    assert(!empty());

    int i = front_;
    ++front_;
    return array_[i];

}