#include <iostream>
#include<stack>

using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int d = 0, Node *n = NULL): data(d), next(n) {} 
};


int main() {
  stack<Node> s;
  Node a(1);
  s.emplace(a);
  cout << s.top().data << endl;
  a.data = 3;
  cout << s.top().data << endl;
}
