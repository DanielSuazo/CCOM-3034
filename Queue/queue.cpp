#include "queue.h"



ostream &operator<<(ostream &out, const Queue &q) {
  q.display(out);
  return out;
}

void Queue::enQueue(ElementType e) {
  Node *n = new Node(e, NULL);
  if (tail) tail->next = n;
  else head = n;
  tail = n;
  
}


ElementType Queue::deQueue() {
  if (!head) {
    cout << "Error: cannot deQueue an empty queue." << endl;
    return 0;
  }
  ElementType final = head->data;
  Node* temp = head;
  head = head->next;
  delete temp;
  
  return final;
}

void Queue::display(ostream &out) const {
  Node *p = head;
  while(p) {
    out << p->data << endl;
    p = p->next;
  }
  out << endl;
}