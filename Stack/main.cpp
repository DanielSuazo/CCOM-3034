#include "stack.h"

int main() {
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  ElementType n;
  while (n = s.pop()) {
    cout << n << endl;
  }

  return 0; 
}