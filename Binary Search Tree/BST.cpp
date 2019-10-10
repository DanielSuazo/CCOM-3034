#include "BST.h"

Node *BST::insert(ElementType x, Node* t) {
  if(t == NULL) {
    t = new Node;
    t->data = x;
    t->left = t->right = NULL;
  }
  else if(x < t->data)
    t->left = insert(x, t->left);
  else if(x > t->data)
    t->right = insert(x, t->right);
return t;
}

void BST::inOrder(Node* t) const {
  if(t == NULL){

    return;
  }
  inOrder(t->left);
  cout << t->data << " ";
  inOrder(t->right);
}

void BST::display() const {
  inOrder(root);
  cout << endl;
}

void BST::insert(ElementType e) {
  root = insert(e, root);
}