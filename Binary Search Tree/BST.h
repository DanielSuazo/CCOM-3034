#include <iostream>

using namespace std;

typedef int ElementType;

struct Node {
  Node* left;
  Node* right;
  ElementType data;
  Node(ElementType d = 0, Node* l = NULL, Node* r = NULL): left(l), right(r), data(d) {}
};

class BST {
  private:
    Node* root;
  public:
    BST(): root(NULL) {}
    Node* insert(ElementType e, Node* n = NULL);
    void inOrder(Node* t) const;
};