#include<iostream>
#include<stack>

using namespace std;

void fuckYouImC(int &x, int &y) {
  x = x ^ y;
  y = x ^ y;
  x = x ^ y;
}

bool isBalanced(const string &st);

int main() {
  while (true) {
    string s;
    cin >> s;
    cout << boolalpha << isBalanced(s) << endl;
  }
}

bool isBalanced(const string &st) {
  if (st.length() % 2 == 1) return false;
  stack<char> s;
  for (auto e : st) {
    if (e == '(' || e == '[' || e == '{') {
      s.push(e);
      } else {
    cout << "ok" << endl;
    if (s.empty()) return false;
    if (e == ')' && s.top() == '(' ||
        e == ']' && s.top() == '[' ||
        e == '}' && s.top() == '{') s.pop();
    else cout << "die" << endl; //return false;
    }
  }
  return s.empty();
}