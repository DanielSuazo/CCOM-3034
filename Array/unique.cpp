#include <iostream>

using namespace std;

bool unique(int A[], int length) {
  for (int i = 0; i < length - 1; i++) {
    for (int j = i + 1; j < length; j++) {
      if (A[i] == A[j]) return false;
    }
  }
  return true;
}

int main() {
  int A[] = {1, 2, 3, 4, 5};
  int B[] = {5, 2, 3, 4, 5};
  cout << boolalpha << unique(A, 5) << endl;
  cout << boolalpha << unique(B, 5) << endl;


  return 0;
}