#include "Stack.hpp"

Stack::Stack()
{
}

void Stack::push(int payload)
{
    this->addFront(payload);
}

int Stack::pop()
{
    return this->removeFront();
}

int Stack::peek()
{
    return this->getAtIndex(0);
}