#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

int postfixEval(const string &st);
void split(const string& str, vector<string>& cont, char delim = ' ');

int main() {
  string s;
  
  while (getline(cin, s) && s != "q")
    cout << postfixEval(s) << endl;
}

int postfixEval(const string &st) {
  vector<string> str;
  split(st, str, ' ');
  stack<int> s;
  for (auto e : str) {
    if (e[0] != '*' && e[0] != '/' && e[0] != '+' && e[0] != '-') {
      s.push(stoi(e));
    } else {
      int op1 = s.top(); s.pop();
      int op2 = s.top(); s.pop();
      switch(e[0]) {
        case '*':
          s.push(op1 * op2);
          break;
        case '/':
          s.push(op1 / op2);
          break;
        case '+':
          s.push(op1 + op2);
          break;
        case '-':
          s.push(op1 - op2);
          break;
      }
    }
  }
  return s.top();
}

void split(const string& str, vector<string>& cont, char delim) {
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) {
        cont.push_back(token);
    }
}