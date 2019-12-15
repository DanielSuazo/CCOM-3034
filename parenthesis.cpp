#include <stack>
#include <iostream>
using namespace std;


bool isBalancedMulti(const string &st){
  stack<char> s;
  for(auto c: st){

    if(c=='[' || c=='(' || c=='{')
      s.push(c);
    if ((c==']' || c==')' || c=='}') && s.empty())
      return false;

    if (!s.empty()) {
      char k = s.top();
    
      if( (k=='[' && c==']') || (k=='(' && c==')') || (k=='{' && c=='}'))
        s.pop();
    }
  }
  return s.empty();
}

int main() {
  cout << boolalpha << isBalancedMulti("(){[]]}") << endl;
}