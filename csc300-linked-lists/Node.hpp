class Node
{
  private:
  int payload;
  Node* nextNode;
  Node* prevNode;
  
  public:
  Node(int payload);
  int getPayload();
  Node* getNextNode();
  void setNextNode(Node* n);
  Node* getPrevNode();
  void setPrevNode(Node* n);
  void display();
  
};