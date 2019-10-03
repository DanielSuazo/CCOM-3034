#include <iostream>

using namespace std;

typedef int ElementType;

class Node {
  public:
    ElementType data;
    Node *next;
    Node(ElementType d = 0, Node *n = NULL): data(d), next(n) {} 
};

class Stack {
  private:
    Node* head;
  public:
    Stack() {head = NULL;}
    void push(ElementType e);
    ElementType pop();
};