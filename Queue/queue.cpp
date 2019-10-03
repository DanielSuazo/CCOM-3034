#include "queue.h"


void Queue::push(ElementType e) {
  Node *n = new Node(e, head, NULL);
  head = n;
  if (head->next) n->next->prev = n;
  // in case of empty list the tail = head = n
  if (!tail) tail = n;
}


ElementType Queue::pop() {
  if (!tail) {
    return NULL;
    cout << "Error: cannot pop an empty queue." << endl;
  }
  ElementType final = tail->data;
  if (tail != head) {
    tail = tail->prev;
    delete tail->next;
    tail->next = NULL;
  } else {
    delete tail;
    tail = NULL;
  }
  
  return final;
}