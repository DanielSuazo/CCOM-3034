#include "BST.h"

void BST::insert(ElementType e, Node* n = NULL) {
  Node* n = new Node(e);
  Node* temp = root;
  if (!root) {
    root = n;
  } else if (e > temp->data) {
    insert(e, )
  }
}