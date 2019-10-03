#include "linkedList.h"

void Llist::removeDuplicates() {
  Node *curr = head;
  while (curr && curr->next) {
    Node *check = curr->next;
    while (check) {
      if (check->data == curr->data) {
        remove(check);
      }
      check = check->next;
    }
  curr = curr->next;
  }
}

void Llist::remove(Node *currNode) {
  if (!currNode) return;
  Node *sucNode = currNode->next;
  Node *predNode = currNode->prev;

  if (sucNode != NULL) {
  sucNode->prev = predNode;
  }

  if (predNode != NULL) {
  predNode->next = sucNode;
  }

  if (currNode == head) { // Removed head
  head = sucNode;
  }

  if (currNode == tail) { // Removed tail
  tail = predNode;
  }
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
    n->prev = head;
  }
  // otherwise, non empty list...
  else {
    n->prev = tail;
    tail->next = n;
  }
  tail = n;
  length++;
}

void Llist::prepend(ElementType d) {
  Node *n = new Node(d);
  
  // in case of empty list the tail = head = n
  if (length == 0) {
    tail = n;
  } else {
    n->next = head->next;
  }
  n->prev = head;
  head = n;

  length++;
}

void Llist::display(ostream &out) const {
  Node *p = head;
  while(p) {
    out << p->data << " ";
    p = p->next;
  }
}

void Llist::displayBackwards(ostream &out) const {
  Node *p = tail;
  while(p != head) {
    out << p->data << " ";
    p = p->prev;
  }
  out << p->data << " ";
  p = p->prev;
}

void Llist::insertAfter(Node *p, ElementType d) {
  Node *n;
  if (p == NULL) {
    n = new Node(d, NULL, head);
    head = n;
    if (!tail) tail = n;
  }
  else {
    n = new Node (d, p->next, p);
    p->next = n;
    n->prev = p;
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