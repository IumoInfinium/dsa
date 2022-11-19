#include<bits/stdc++.h>
using namespace std;

void enqueue(stack<int>& st, int data){
    st.push(data);
    return;
}

void dequeue(stack<int>& st){
    stack<int> tmp;
    while(!st.empty()){
        tmp.push(st.top());
        st.pop();
    }
    tmp.pop();
    while(!tmp.empty()){
        st.push(tmp.top());
        tmp.pop();
    }
}
int main(){
    stack<int> st;
    for(int i=0;i<5;i++){
        enqueue(st,i);
    }
    cout << "Size before dequeue " << st.size() <<endl;
    dequeue(st);
    cout << "deleted one element\n";
    cout << "Size after dequeue " << st.size() <<endl;
    return 0;
}