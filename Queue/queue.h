#include <iostream>
#include <string>

using namespace std;

typedef string ElementType;

class Node {
  public:
    ElementType data;
    Node *next;
    Node(ElementType d = 0, Node *n = NULL): data(d), next(n) {} 
};

class Queue {
  private:
    Node *head, *tail;
  public:
    Queue() {head = NULL; tail = NULL;}
    void display(ostream &out) const;
    void enQueue(ElementType e);
    ElementType deQueue();
};

ostream &operator<<(ostream &out, const Queue &q);