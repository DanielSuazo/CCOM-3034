#include "priorityQueue.h"



ostream &operator<<(ostream &out, const Queue &q) {
  q.display(out);
  return out;
}

void Queue::enQueue(ElementType e, int p) {
  Node* tmp = new Node(e, p);
  Node* curr = head;
  if (head) {
    Node* next = head->next;
    while(curr && curr->priority < tmp->priority) {
      
    }
  }
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

void Queue::insert(Node* n, Node* tmp, ElementType e) {
  if (n) tmp->next = n->next;
  n->next = tmp;
}