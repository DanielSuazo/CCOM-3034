#include <iostream>
#include <string>

using namespace std;

typedef string ElementType;

class Node {
  public:
    int priority;
    ElementType data;
    Node *next;
    Node(ElementType d = 0, int p = 0, Node *n = NULL): data(d), next(n), priority(p) {} 
};

class Queue {
  private:
    Node *head, *tail;
  public:
    Queue() {head = NULL; tail = NULL;}
    void display(ostream &out) const;
    void enQueue(ElementType e, int p);
    ElementType deQueue();
    void insert(Node* n, Node* tmp, ElementType e);
};

ostream &operator<<(ostream &out, const Queue &q);