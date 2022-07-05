#include "stack.h"
#include <iostream>

ArrayStack::~ArrayStack()
{
    delete[] container_;
    container_ = nullptr;
}

bool ArrayStack::Push(int data)
{
    if (top_next_ == capacity_)
    {
        throw "Push Error: stack is full";
    }

    container_[top_next_] = data;
    ++top_next_;
    std::cout << "in push ..." << std::endl;
    return true;
}

int ArrayStack::Pop()
{
    if (top_next_ == 0)
    {
        throw "Pop Error: stack is empty";
    }

    int data = container_[top_next_ - 1];
    --top_next_;
    return data;
}

void ArrayStack::Traverse()
{
    for (auto i = 0; i < top_next_; i++)
    {
        std::cout << container_[i] << " ";
    }
    std::cout << std::endl;
}

std::size_t ArrayStack::top_next()
{
    return top_next_;
}

std::size_t ArrayStack::capacity()
{
    return capacity_;
}