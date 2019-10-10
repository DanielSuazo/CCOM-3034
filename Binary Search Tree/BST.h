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
    void inOrder(Node* t) const;
    Node *insert(ElementType e, Node* n);
  public:
    BST(): root(NULL) {}
    void insert(ElementType e);
    void display() const;
};