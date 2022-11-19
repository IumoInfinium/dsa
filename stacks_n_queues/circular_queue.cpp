#include <bits/stdc++.h>
using namespace std;
// Code to implement circular queue using arrays

#define MAX 10
int front=-1;
int rear =-1;


void enqueue(int arr[], int data){
    if(front == rear && front == -1){
        front++;
        rear++;
        arr[rear]=data;
    }
    else if((rear+1)%front== front){
        cout << "Overflow\n";
    }
    else if(front>0){
        rear = 0;
        arr[rear]=data;
    }
    else{
        rear++;
        arr[rear]=data;
    }
}

void dequeue(int arr[]){
    if(front == rear && front == -1){
        cout << "Underflow\n";
    }
    else if(front == rear){
        front =-1;
        rear = -1;
    }
    else if(front==MAX-1){
        front=0;
    }
    else{
        front++;
    }
}

int main(){
    int arr[MAX];
    for(int i=0;i<MAX;i++){
        enqueue(arr,i);
    }

    cout << "Before dequeue\n";
    cout << "value of front and rear " << front << ":" << rear <<endl;
    cout <<"\n";

    // dequeue 3 elements from array
    dequeue(arr);
    cout << "After dequeue\n";
    cout << "value of front and rear " << front << ":" << rear <<endl;

    dequeue(arr); dequeue(arr);

    enqueue(arr,100);
    cout <<" enqueuing again\n";
    cout << "value of front and rear " << front << ":" << rear <<endl;

    return 0;
}