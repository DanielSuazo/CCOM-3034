#include <iostream>

using namespace std;

bool inOrder(int A[], int length) {
  for (int i = 1; i < length; i++) {
    if (A[i] < A[i-1]) return false;
  }
  return true;
}

int main() {
  int A[] = {1, 2, 3, 4, 5};
  int B[] = {5, 2, 3, 4, 5};
  cout << boolalpha << inOrder(A, 5) << endl;
  cout << boolalpha << inOrder(B, 5) << endl;


  return 0;
}