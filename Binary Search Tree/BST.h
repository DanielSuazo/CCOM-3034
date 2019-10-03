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
    int depth = 1;
  public:
    BST();
    void insert(ElementType e, Node* n = NULL);
};