#include <bits/stdc++.h>
using namespace std;

// program to sort a stack using recursion

void sortedInsert(stack<int>& st, int ele){
    if(st.empty() || ele > st.top()){
        st.push(ele);
    }
    else{
        int top = st.top();
        st.pop();
        sortedInsert(st, ele);
        st.push(top);
    }
}

void sortStack(stack<int>& st){
    if(!st.empty()){
        int top = st.top();
        st.pop();
        sortStack(st);
        sortedInsert(st, top);
    }
}

int main(){
    stack<int> st;
    int x;
    cout << "\ninsert stack values :";
    for(int i=0;i<10; i++){
        cin >> x;
        st.push(x);
    }
    cout << "\n\nnow sorted stack is :";
    sortStack(st);
    while(!st.empty()){
        cout << st.top() <<" ";
        st.pop();
    }
    cout <<"\n";
    return 0;

}