#include "Node.hpp"

class LinkedList
{
  private:
  Node* head;
  Node*tail;
  int count;
  
  
  public:
  LinkedList();
  void display();
  void addFront(int payload);
  int removeFront();
  void addEnd(int payload);
  int removeEnd();
  int getCount();
  int getLast();
  void addAtIndex(int payload, int index);
  int removeAtIndex(int index);
  int getAtIndex(int index);
};