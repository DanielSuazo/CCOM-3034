#include <stack>
#include <string>
#include <iostream>


void bottomInsert(std::stack<char> &st, char x){ 
  
  if (st.size() == 0) st.push(x); 
  else { 
    char a = st.top(); 
    st.pop(); 
    bottomInsert(st, x); 
    st.push(a); 
  }
}

int main() {
  std::stack<char> s;
  char n;
  s.push('b');
  s.push('c');
  s.push('d');
  std::cin >> n;
  bottomInsert(s, n);
  while(!s.empty()) {
    std::cout << s.top() << " ";
    s.pop();
  }
  std::cout << std::endl;


}