#include "linkedList.h"
#include <iostream>

using namespace std;

int main() {
  Llist L;
  int element, howMany;
  cin >> howMany;
  for (int i = 0; i < howMany; i++) {
    cin >> element;
    L.append(element);
  }
  cout << L << endl;
  L.head->next->next->next = L.head;
  cout << boolalpha << L.hasCycle() << endl;
  
}