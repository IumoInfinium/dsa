#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Code to implement stack using queues

void push(queue<int>& q,int data){
    q.push(data);
}

void pop(queue<int>& q){
    if(q.empty()){
        cout << "Underflow\n";
        return;
    }
    queue<int> tmp;
    while(q.size()!=1){
        tmp.push(q.front());
        q.pop();
    }
    swap(tmp,q);
    return;
}
int peek(queue<int>& q){
    if(q.empty()) return -1;
    return q.back();
}

int main(){
    auto start = high_resolution_clock::now();
    queue<int> q;
    push(q,1);
    push(q, 2);
    push(q, 3);
    push(q, 4);
    push(q, 5);
    cout << peek(q) << "\n";
    pop(q);
    cout << peek(q) << "\n";
    pop(q);
    cout << peek(q) << "\n";
    pop(q);
    cout << peek(q) << "\n";
    pop(q);
    cout << peek(q) << "\n";
    pop(q);
    cout << peek(q) << "\n";
    pop(q);
    cout << peek(q) << "\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\ntime taken - ";
    double d = duration.count()/1000000.0;
    cout << std::setprecision(9)<< d<< endl;
    // printf("%5.f\n",duration.count()); 
    return 0;
}