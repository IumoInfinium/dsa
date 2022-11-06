#include <bits/stdc++.h>
using namespace std;

string prefix_to_postfix(string& s){
    stack<string> st;
    int n = s.size();
    for(int i=n-1; i>=0; i--){
        string ans = "";
        if(!isalpha(s[i])){
            ans += s[i];
            st.push(ans);
        }
        else{
            if(!st.empty()){
                ans += st.top(); st.pop();
                ans += st.top(); st.pop();
            }
            ans += s[i];
            st.push(ans);
        }
    }
    string res;
    while(!st.empty())res+=st.top();st.pop();
    return res; 
}

int main(){
    string s = "*-A/BC-/AKL";
    cout  << prefix_to_postfix(s) << endl;
    return 0;
}