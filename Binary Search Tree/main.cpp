#include "BST.h"

int main() {
  BST tree1;
  tree1.insert(5);
  tree1.insert(7);
  tree1.insert(3);
  tree1.inOrder(NULL);
}