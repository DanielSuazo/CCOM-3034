#include "BST.h"

Node *BST::insert(ElementType e = 0, Node* n = NULL) {
  Node* temp = root;
  if (!root) {
    root = new Node(e);
  } else if (e > temp->data) {
    temp->right = insert(e, temp->right);
  } else if (e < temp->data) {
    temp->left = insert(e, temp->left);
  }
  return temp;
}

void BST::inOrder(Node* t) const {
  if(t == NULL)
    return;
  inOrder(t->left);
  cout << t->data << " ";
  inOrder(t->right);
}