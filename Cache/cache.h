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

class Cache {
  private:
    Node *head, *tail;
  public:
    Cache() {head = NULL; tail = NULL;}
    void display(ostream &out) const;
    void push(ElementType e);
    ElementType front();
    void pop();
};

ostream &operator<<(ostream &out, const Cache &q);