#include <iostream>

using namespace std;

typedef int ElementType;

class Node {
  public:
    ElementType data;
    Node *next;
    Node *prev;
    Node(ElementType d = 0, Node *n = NULL, Node *p = NULL): data(d), next(n), prev(p) {} 
};

class Queue {
  private:
    Node* head, *tail;
  public:
    Queue() {head = NULL; tail = NULL;}
    void push(ElementType e);
    ElementType pop();
};