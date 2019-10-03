#include "stack.h"


void Stack::push(ElementType e) {
  Node *n = new Node(e, head);
  head = n;
}


int Stack::pop() {
  if (!head) {
    cout << "Error: cannot pop an empty stack." << endl;
    return 0;
  }
  ElementType final = head->data;
  Node* temp = head;
  head = head->next;
  delete temp;
  
  return final;
}