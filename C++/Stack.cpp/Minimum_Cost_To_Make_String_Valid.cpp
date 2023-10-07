#include<stack>
#include <iostream>
using namespace std;
int findMinimumCost(string str) {
  //odd case
  if(str.length()%2==1) {
    return -1;
  }
  stack<char>s;
  for(int i=0;i<str.length();i++) {
    char ch=str[i];

    if(ch=='{') {
      s.push(ch);
    } 
    else {
      //ch is closed brace
      if (!s.empty() && s.top() == '{') {
        s.pop();
      }
      else {
        s.push(ch);
      }
    }
  }
  //stack contain invalid expression
  int a=0;
  int b=0;

  while(!s.empty()) {
    if(s.top()=='{') {
      b++;
    }
    else {
      a++;
    }
    s.pop();
  }
  int ans=(a+1)/2 +(b+1)/2;
  return ans;
}

int main() {
    string test="{{{}";
    int min_cost=findMinimumCost(test);
    cout<<min_cost<<endl;

    return 0;
}
