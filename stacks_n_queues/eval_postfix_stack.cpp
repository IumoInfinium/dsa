#include <bits/stdc++.h>
using namespace std;

int postfix_evaluate(string &s){
    int ans;
    stack<int> st;
    for(char& c: s){
        if(isdigit(c)) st.push(c-'0');
        else{
            int val1 = st.top(); st.pop();
            int val2 = st.top(); st.pop();
            switch(c){
                case '+' : st.push(val2+val1); break;
                case '-' : st.push(val2-val1); break;
                case '*' : st.push(val2*val1); break;
                case '/' : st.push(val2/val1); break;
            }
        }
    }
    ans = st.top(); st.pop();
    return ans;
}

int main(){
    string s="23-2+";
    cout << postfix_evaluate(s)<<endl;
    return 0;
}