#include "linkedList.h"


bool Llist::hasCycle() const {
  vector <Node*> links(length + 1, NULL);
  Node *currNode = head;
  for (int i = 0; currNode; i++) {
    links[i] = currNode;
    for (int j = 0; j < i; j++) {
      if (links[j] == links[i]) {
        return true;
      }
    }
    currNode = currNode->next;
  }
  return false;
}

int Llist::indexOf(ElementType element) const {
  Node *curr = head;
  for (int i = 0; curr; i++) {
    if (curr->data == element) {
      return i;
    }
    curr = curr->next;
  }
  return -1;
}
void Llist::append(ElementType d){
  Node *n = new Node(d);

  // in case of empty list
  if (!head) {
    head = n;
  }
  // otherwise, non empty list...
  else {
    tail->next = n;
  }
  tail = n;
  length++;
}

void Llist::prepend(ElementType d) {
  Node *n = new Node(d, head);
  
  head = n;
  // in case of empty list the tail = head = n
  if (length == 0) tail = n;

  length++;
}

void Llist::display(ostream &out) const {
  Node *p = head;
  while(p) {
    out << p->data << " ";
    p = p->next;
  }
}

void Llist::insertAfter(Node *p, ElementType d) {
  Node *n;
  if (p == NULL) {
    n = new Node(d, head);
    head = n;
    if (!tail) tail = n;
  }
  else {
    n = new Node (d, p->next);
    p->next = n;
    if (tail == p) tail = n;
  }
  length++;
}

Node* Llist::search(ElementType d) const {
  Node *p = head;
  while(p) {
    if (p->data == d) return p;
    p = p->next;
  }
  return NULL;
}

ostream& operator<< (ostream &out, const Llist& L) {
  L.display(out);
  return out;
}