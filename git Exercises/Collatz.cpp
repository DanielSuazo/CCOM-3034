#include<iostream>

using namespace std;

int countCollatz(int n) {
  int counter = 0;
  while (n != 1) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n *= 3;
      n++;
    }
    counter++;
  }
  return counter;
}

int main() {
  int n;
  cin >> n;
  cout << countCollatz(n) << endl;
}