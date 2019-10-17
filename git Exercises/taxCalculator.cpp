#include<iostream>

using namespace std;

void calculateTax(int x, int taxRate) {
  float tax = x * taxRate * .01;
  cout << "Tax = $" << tax << endl;
  cout << "Total = $" << tax + x << endl;
}

int main() {
  int n, tax;
  cin >> n >> tax;
  calculateTax(n, tax);
}