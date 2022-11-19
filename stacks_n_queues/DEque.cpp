#include <bits/stdc++.h>
using namespace std;
// Code to implement doubly circular queue

#define MAX 5
int front=-1;
int rear=-1;

void front_enqueue(int arr[],int data){
    if(front == -1 && rear == -1){
        front++;
        rear++;
        arr[rear]=data;
    } 
    else{
        if(front>0){
            front--;
            arr[front]=data;
        }
        else{
            cout << "Cannot front enqueue!\n";
        }
    }
    return;
}


void back_enqueue(int arr[],int data){
    if(front == -1 && rear == -1){
        front++;
        rear++;
        arr[rear]=data;
    }
    else{
        if(rear<MAX-1){
            rear++;
            arr[rear]=data;
        }
        else cout <<"Cannot back enqueue!\n";
    }
    return;
}


void front_dequeue(int arr[]){
    if(front == -1 && rear == -1) cout << "Underflow\n";
    else if(front == rear){
        front=-1;
        rear=-1;
    }
    else front++;
    return;
}

void back_dequeue(int arr[]){
    if(front == -1 && rear == -1) cout << "Underflow\n";
    else if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        rear--;
    }
    return;
}
int main(){
    int arr[MAX];
    back_enqueue(arr,100);
    back_enqueue(arr,200);
    back_enqueue(arr,200);
    back_enqueue(arr,200);
    back_enqueue(arr,300);
    cout << front << "-a- " << rear<< endl;
    front_enqueue(arr,1000);
    cout << front << "-a- " << rear<< endl;
    back_dequeue(arr);
    cout << front << "-b-" << rear<< endl;
    front_dequeue(arr);
    front_dequeue(arr);
    cout << front << "-c-" << rear<< endl;
    front_enqueue(arr,200);
    cout << front << "-d-" << rear<< endl;
    back_dequeue(arr);
    cout << front << "-e-" << rear<< endl;
    back_dequeue(arr);
    cout << front << "-f-" << rear<< endl;
    return 0;
}
