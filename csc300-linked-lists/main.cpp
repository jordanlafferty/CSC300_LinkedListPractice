#include "Stack.hpp"
#include <iostream>

using namespace std;

int main()
{
    Stack* s = new Stack();
    s->push(1);
    s->push(2);
    s->push(3);
    s->display();

    return 0;
}
