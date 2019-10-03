#include "queue.h"

int main() {
  Queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  ElementType n;
  while (n = q.pop()) {
    cout << n << endl;
  }

  return 0; 
}