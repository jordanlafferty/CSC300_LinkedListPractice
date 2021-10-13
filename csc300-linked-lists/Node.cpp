#include "Node.hpp"
#include <iostream>

using namespace std;

Node::Node(int payload)
{
    this->payload = payload;
    this->nextNode = NULL;
    this->prevNode = NULL;
}

int Node::getPayload()
{
    return this->payload;
}

Node* Node::getNextNode()
{
    return this->nextNode;
}

void Node::setNextNode(Node* n)
{
    this->nextNode = n;
}

Node* Node::getPrevNode()
{
    return this->prevNode;
}
  
void Node::setPrevNode(Node* n)
{
    this->prevNode = n;
}
  
void Node::display()
{
    cout << this->payload << " -> ";
    if(this->nextNode != NULL)
    {
        this->nextNode->display();
    }
    else
    {
        cout << "NULL" << endl;
    }
}