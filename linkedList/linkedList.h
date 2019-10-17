#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

typedef int ElementType;

class Node {
  public:
    ElementType data;
    Node *next;
    Node(ElementType d = 0, Node *n = NULL): data(d), next(n) {} 
};

class Llist {
  public:
    Node *head, *tail;
    int length;
  public:
    Llist() : head(NULL), tail(NULL), length(0) {}
    void append(ElementType d);
    void prepend(ElementType d);
    void insertAfter(Node *p, ElementType d);
    Node *search(ElementType d) const;
    void display(ostream &out) const;
    int indexOf(ElementType element) const;
    bool hasCycle() const;
    void removeOdds();
    void removeAfter(Node *cur);
};

ostream& operator<< (ostream &out, const Llist& L);