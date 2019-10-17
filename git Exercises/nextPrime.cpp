#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int x) {
  if (x == 2) return true;
  if (x % 2 == 0) return false;

  for (int i = 3; i < sqrt(x) + 1; i += 2) {
    if (x % i == 0) return false;
  }
  return true;
}

int nextPrime(int x) {
  int check = x + 1;
  while(true) {
    if (!isPrime(check)) check++;
    else break;
  }
  return check;
}

int main() {
  int n;
  cin >> n;
  cout << "The next prime is: " << nextPrime(n) << endl;
  return 0;
}