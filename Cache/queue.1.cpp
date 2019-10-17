#include "cache.h"



ostream &operator<<(ostream &out, const Cache &q) {
  q.display(out);
  return out;
}

void Cache::push(ElementType e) {
  Node *n = new Node(e, NULL);
  if (tail) tail->next = n;
  else head = n;
  tail = n;
  
}


ElementType Cache::front() {
  if (!head) {
    cout << "Error: empty Cache." << endl;
    return 0;
  }
  
  return head->data;
}

void Cache::pop() {
  if (head){
    Node* n = head;
    head = head->next;
    delete n;
  } else {
    cout << "Error: cannot pop and empty Cache" << endl;
  }
}

void Cache::display(ostream &out) const {
  Node *p = head;
  while(p) {
    out << p->data << endl;
    p = p->next;
  }
  out << endl;
}