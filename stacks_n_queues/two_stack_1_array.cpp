#include <bits/stdc++.h>
#define MAX 10
using namespace std;

// implementing 2 stacks in one-array
int arr[MAX];
int top1=-1;
int top2=MAX;

bool push(int x,int stackname){
    if(stackname == 1){
        // if stack 1
        if(top1 == -1 && top2!= 0){
            top1++;
            arr[top1]=x;
            return true;
        }
        else if(top1+1 == top2) return false;
        else{
            top1++;
            arr[top1]=x;
            return true;
        }
    }
    else if(stackname == 2){
        // if stack 2
        if(top2 == MAX && top1 != MAX-1){
            top2--;
            arr[top2]=x;
            return true;
        }
        else if(top2-1 == top1) return false;
        else{
            top2--;
            arr[top2]=x;
            return true;
        }
    }
    else{
        // Invalid stack name
        return false;
    }
    return false;
}

bool pop(int stackname){
    if(stackname == 1){
        if(top1 != -1){
            top1--;
            return true;
        }
        return false;
    }
    else if(stackname == 2){
        if(top2 != MAX+1){
            top2++;
            return true;
        }
        return false;
    }
    return false;
}

int peek(int stackname){
    if(stackname ==1 ) return top1;
    else if(stackname == 2) return top2;
    return INT_MIN;
}

int main(){
    int c,choice,x,stackname;
    c=1;
    while(c){
        cout <<" \n1. push(x, stackname)\n";
        cout <<" 2. pop(stackname)\n";
        cout <<" 3. peek(stackname)\n";
        cout <<" 3. print\n";
        cout <<" 0. Exit\n";
        cout << "Enter choice :";
        cin >> choice;
        switch(choice){
            case 0:
                exit(0);
                break;
            case 1: 
                cout << "enter element and push into stack number";
                cin >>x >> stackname;
                cout << "operation ="<<push(x,stackname) <<"\n\n"; 
                break;
            case 2:
                cout << "pop from stack number\n";
                cin >> stackname;
                cout << "operation =" << pop(stackname) <<"\n\n";
                break;

            case 3:
                cout << "peek in (1/2):";
                cin >> stackname;
                cout <<"top at:" <<peek(stackname) <<"\n\n"; 
                break;
            case 4:
                cout << "printing array";
                for(int i=0; i< MAX;i++){
                    cout << arr[i] << " ";
                }  
                cout << "\n\n";
                break;
            default:
                cout << "invalid choice\n";
                break;
        }

    }
    return 0;
}