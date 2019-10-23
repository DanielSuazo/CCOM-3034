#include "stack.h"

int main() {
  Stack s;
  if (s.empty()) cout << "this boi empty" << endl;
  s.push(1);
  s.push(2);
  s.push(3);
  if (s.empty());
  ElementType n;
  while (n = s.getTop()) {
    cout << n << endl;
  }
  return 0; 
}