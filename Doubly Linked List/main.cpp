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

  // cin >> element;
  L.removeDuplicates();
  cout << L << endl;
  L.displayBackwards(cout);
  cout << endl;
  
}