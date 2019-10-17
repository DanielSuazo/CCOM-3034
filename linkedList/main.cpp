#include "linkedList.h"
#include <iostream>

using namespace std;

int main() {
  Llist L;
  L.append(4);
  L.append(1);
  L.append(3);
  L.append(5);
  L.append(2);
  L.removeOdds();
  cout << L << endl;
}