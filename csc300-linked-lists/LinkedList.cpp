#include "LinkedList.hpp"
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
    this->head = NULL;
    this->tail = NULL;
    this->count = 0;
}

void LinkedList::addFront(int payload)
{
    Node* temp = new Node(payload);
    temp->setNextNode(this->head);
    if(this->head != NULL)
    {
        this->head->setPrevNode(temp);
    }
    this->head = temp;
    if(this->count == 0)
    {
        this->tail = this->head;
    }
    this->count = this->count + 1;
}

int LinkedList::removeFront()
{
    if(this->head == NULL)
    {
        cout << "Can't remove front from an empty list" << endl;
    }
    else
    {
        int valToReturn = this->head->getPayload();
        Node* temp = this->head;
        this->head = this->head->getNextNode();
        temp->setNextNode(NULL);
        delete(temp);
        this->count = this->count - 1;
        
        if(this->head != NULL)
        {
            this->head->setPrevNode(NULL);
        }
        else
        {
            this->tail = NULL; //reset tail to NULL if this list is now empty
        }
        return valToReturn;
        
    }
}

void LinkedList::addEnd(int payload)
{
    if(this->head == NULL)
    {
        this->addFront(payload);
    }
    else
    {
        Node* n = new Node(payload);
        //run to the end of the current List
        Node* currNode = this->head;
        while(currNode->getNextNode() != NULL)
        {
            currNode = currNode->getNextNode();
        }
        //currNode now points to a place where his nextNode is NULL
        currNode->setNextNode(n);
        n->setPrevNode(currNode);
        this->tail = n;
        this->count++;
    }
}

int LinkedList::removeEnd()
{
    //write this for HW
    if(this->head != NULL)
    {
        if(this->head->getNextNode() == NULL)
        {
            //I am looking at a one-list
           return this->removeFront();
        }
        else
        {
            //I am looking at a list with at least 2 elements in it
            Node* currNode = this->tail;
            int temp = currNode->getPayload();
            this->tail = currNode->getPrevNode(); //make new tail the second to last guy
            currNode->getPrevNode()->setNextNode(NULL);
            currNode->setPrevNode(NULL);
            delete(currNode);
            this->count--;
            return temp;
        }
    }
    else
    {
        cout << "Can't remove end from an empty list" << endl;
    }
}

int LinkedList::getCount()
{
    return this->count;
}

int LinkedList::getLast()
{
    //if(!this->tail) this means the same thing as the line below
    if(this->tail == NULL)
    {
        cout << "No Last Element - Empty List" << endl;
    }
    else
    {
        return this->tail->getPayload();
    }
}



void LinkedList:: addAtIndex(int payload, int index)
{
   if(index == 0)
    {
        this->addFront(payload);
    }
    else if(index == this->getCount())
    {
        this->addEnd(payload);
    }
    else if(index < 0 || index > this->getCount())
    {
        cout << "Illegal position!!!" << endl;
    }
    else
    {
        //we are adding somewhere in the middle
        Node* n = new Node(payload);
        Node* currNode = this->head;
        for(int i = 0; i < index-1; i++)
        {
            currNode = currNode->getNextNode();
        }
        
        n->setNextNode(currNode->getNextNode());
        n->setPrevNode(currNode);
        currNode->setNextNode(n);
        n->getNextNode()->setPrevNode(n);
        this->count++;
    }
    
    
}


int LinkedList:: removeAtIndex(int index)
{
    if(index == 0)
    {
        return this->removeFront();
    }
    else if(index == this->getCount()-1)
    {
        return this->removeEnd();
    }
    else if(index < 0 || index >= this->getCount())
    {
        cout << "Illegal position!!!" << endl;
    }
    else
    {
        //we are removing a value in the middle
        Node* currNode = this->head;
        for(int i = 0; i < index; i++)
        {
            currNode = currNode->getNextNode();
        }
        int temp = currNode->getPayload();
        currNode->getPrevNode()->setNextNode(currNode->getNextNode());
        currNode->getNextNode()->setPrevNode(currNode->getPrevNode());
        currNode->setPrevNode(NULL);
        currNode->setNextNode(NULL);
        delete(currNode);
        this->count--;
        return temp;
    }
    
}


int LinkedList :: getAtIndex(int index)
{
   if(index < 0 || index >= this->getCount())
    {
        cout << "Illegal position!!!" << endl;
    }
    else
    {
        Node* currNode = this->head;
        for(int i = 0; i < index; i++)
        {
            currNode = currNode->getNextNode();
        }
        return currNode->getPayload();
    }
}


void LinkedList::display()
{
    if(this->head == NULL)
    {
        cout << "Empty List";
    }
    else
    {
        //traverse the list and ask each node to display itself
        this->head->display();
        /*
        Node* currNode = this->head;
        while(currNode != NULL)
        {
            currNode->display();
            currNode = currNode->getNextNode();
        }
        */
    }
}