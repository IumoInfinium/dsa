#include<bits/stdc++.h>
using namespace std;

// program to reverse a stack with recursion
// adds stack value temporarily to call stack and pushs back to main stack after doing
// given work

void insert_at_bottom(stack<int>& st,int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }

    int top = st.top();
    st.pop();
    insert_at_bottom(st,ele);
    st.push(top);
}

void reverseStack(stack<int>& st){
    if(st.empty()) return;

    int top = st.top();
    st.pop();
    reverseStack(st);

    insert_at_bottom(st,top);
}

int main(){
    stack<int> st;
    int x;
    cout << "\ninsert stack values :\n";
    for(int i=0;i<10; i++){
        cout << i <<" th value :";
        cin >> x;
        st.push(x);
    }
    reverseStack(st);
    while(!st.empty()){
        cout << st.top() <<" ";
        st.pop();
    }
    cout <<"\n";
    return 0;
}