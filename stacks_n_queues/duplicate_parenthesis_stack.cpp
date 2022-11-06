#include <bits/stdc++.h>
using namespace std;

bool duplicateParenthesis(string &s){
    // "(((a+b))+(c))"  <--- contains duplicate parenthesis
    // "((a+b)+c)"      <--- no duplicate paranthesis
    stack <char> st;
    for(char &c : s){
        if(c != ')') st.push(c);
        else{
            if(st.top()=='(') return true;
            
            while(st.top()!='(') st.pop();
            st.pop();
        }
    }
    return false;
}

int main(){
    string s = "(((a+b))+(c))";
    if(duplicateParenthesis(s)) cout << "Given string contains duplicate parenthesis!\n";
    else cout << "No duplicate parenthesis found\n";
    return 0;
}