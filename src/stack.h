#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>

class ArrayStack
{
public:
    ArrayStack() = default;
    ArrayStack(std::size_t capacity) : capacity_(capacity)
    {
        container_ = new int[capacity_];
    };

    virtual ~ArrayStack();

    virtual bool Push(int data);

    virtual int Pop();

    virtual void Traverse();

    virtual std::size_t top_next();

    virtual std::size_t capacity();

private:
    int *container_ = nullptr;
    std::size_t top_next_ = 0;
    std::size_t capacity_ = 0;
};

#endif // !_STACK_H_