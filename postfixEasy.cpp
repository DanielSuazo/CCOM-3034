#include <stack>
#include <iostream>
#include <string>

using namespace std;

int postfixEval(const string &st);

int main() {
  string s;
  
  while (getline(cin, s) && s != "q")
    cout << postfixEval(s) << endl;
}

int postfixEval(const string &st) {
  stack<int> s;
  for (auto e : st) {
      if (e != ' ') {
      if (e != '*' && e != '/' && e != '+' && e != '-') {
        s.push(e - '0');
      } else if (s.size() < 2) {
        cout << "Die" << endl;
        exit(EXIT_FAILURE);
      } else {
        int op2 = s.top(); s.pop();
        int op1 = s.top(); s.pop();

        switch (e) {
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
          default:
          cout << "khe" << endl;
            break;
        }
      }
    }
  }
  return s.top();
}