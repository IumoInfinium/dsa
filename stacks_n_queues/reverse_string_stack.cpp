#include<bits/stdc++.h>
using namespace std;

// program to reverse a string using stack

void reverseString(string& s){
    int n =s.size();
    stack<char> st;
    for(char c: s)
        st.push(c);
    for(int i=0;i<n;i++){
        s[i]= st.top();
        st.pop();
    }
}


int main(){
    string s="need to reverse this!";
    cout << "need to reverse :"<<s <<endl;
    reverseString(s);
    cout << "reversed string :";
    cout <<s <<endl;
    return 0;
}