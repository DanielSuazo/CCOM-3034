#include<cstdio>
#include<iostream>
#include<ctime>
#include<stack>

using namespace std;

int sumOfDigits(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

bool divisibleByNine(int n) {
  if (n == 9) return true;
  else if (n < 9) return false;
  else return divisibleByNine(sumOfDigits(n));
}

int main(){
  int n;
  while (cin >> n)
  cout << boolalpha << divisibleByNine(n) << endl;
}