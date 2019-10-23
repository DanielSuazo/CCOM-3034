#include<iostream>
#include<string>

using namespace std;

string cipher(string s, unsigned int shift) {
  for(int i = 0; i < s.length(); i++) {
    s[i] = tolower(s[i]);
    s[i] -= 97;
    s[i] = (s[i] + shift) % 26;
    s[i] += 97;
  }
  
  return s;
}

int main() {
  string s;
  int shift;
  cin >> s >> shift;
  cout << cipher(s, shift) << endl;
}