#include "stack.h"


void Stack::push(ElementType e) {
  Node *n = new Node(e, top);
  top = n;
}


int Stack::getTop() const {
  if (!top) { // make sure stack isnt empty
    cout << "Error: empty stack." << endl;
    return 0;
  } else return top->data;
}

void Stack::pop() {
  if (top) { // make sure stack isnt empty
    Node* n = top;
    top = top->next;
    delete n;
  } else {
    cout << "Error: empty stack." << endl;
  }
}

bool Stack::empty() const {
  return !top;
}