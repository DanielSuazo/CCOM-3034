#include "priorityQueue.h"

int main() {
  Queue q;
  string n;
  while (getline(cin, n) && (n != "quit" || n != "Quit")) {
    if (n == "remove") q.deQueue();
    else if (n == "print") cout << q;
    else q.enQueue(n);
    cout << "To-Do List: \n" << q;
  }

  return 0; 
}