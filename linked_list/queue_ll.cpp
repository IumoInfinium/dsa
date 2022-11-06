#include<bits/stdc++.h>
using namespace std;

typedef struct LLNode{
    int data;
    struct LLNode *next;
}Node;

typedef struct Sentinel{
    int data;
    Node *prev;
    Node *next;
}Senti;

Node* create_node(){
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->next = NULL;
    tmp->data=0;
    return tmp;
}

void enqueue(Senti *S,int data){
    Node* tmp = create_node();
    tmp->data = data;
    if(S->next == NULL){
        S->next = tmp;
        S->prev = tmp;
    }
    else{
        S->prev->next = tmp;
        S->prev=tmp;
    }
    return;
}

void dequeue(Senti *S){
    if(S->next == NULL) return;
    Node* tmp = S->next;
    S->next = tmp->next;
    free(tmp);
    tmp = NULL;
}

int peek(Senti *S){
    if(S == nullptr) return INT_MIN;
    return S->next->data;
}
int main(){

    int x=0;
    Senti *S;
    S= (Senti*)malloc(sizeof(Senti));
    S->next =NULL;
    S->prev=NULL;
    // free(HEAD);
    
    enqueue(S,10);
    cout << peek(S) << "\n";
    
    enqueue(S,20);
    dequeue(S);

    cout << peek(S) << "\n";
    enqueue(S,30);
    cout <<peek(S) <<"\n";
    
    dequeue(S);
    cout << peek(S) << "\n";
    dequeue(S);
    cout <<( ((x=peek(S))==INT_MIN)? "No nodes":to_string(x)) << "\n";
    return 0;
}