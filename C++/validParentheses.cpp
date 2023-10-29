#include <bits/stdc++.h>
using namespace std;

bool matching(char a, char b){
    return ((a=='[' && b ==']') || (a=='(' && b==')') || (a=='{' && b=='}'));
}
bool solution(string st){
    stack<int>s;
    for(int i=0;st[i] !='\0';i++){
        if(st[i]=='[' || st[i]=='(' || st[i] == '{') s.push(st[i]);
        else{
            if(s.empty()==true) return false;
            else if(matching(s.top(),st[i])==false) return false;
            else 
            s.pop();
        }
    }
        return (s.empty()==true);
}
int main()
{
    string str;
    cin >> str;
    if(solution(str)) cout<<"True"<<endl;
    else cout << "False" << endl;
    return 0;
}