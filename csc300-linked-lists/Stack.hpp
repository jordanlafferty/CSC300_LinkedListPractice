#include "LinkedList.hpp"

class Stack :public LinkedList
{
    public:
        Stack();
        void push(int payload);
        int pop();
        int peek();
};