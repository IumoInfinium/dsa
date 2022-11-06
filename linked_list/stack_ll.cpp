#include<bits/stdc++.h>
using namespace std;

typedef struct LLNode{
    int data;
    struct LLNode *next;
}Node;

Node* create_node(){
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->next = NULL;
    tmp->data=0;
    return tmp;
}

void push(Node *HEAD,int x){
    Node* tmp = create_node();
    tmp->data = x;
    if(HEAD == NULL){
        HEAD->next = tmp;
    }
    else{
        tmp->next = HEAD->next;
        HEAD->next = tmp;
    }
    return;
}

void pop(Node *HEAD){
    Node *tmp = HEAD->next;
    if(tmp == NULL) return;
    else{
        HEAD->next=tmp->next;
        free(tmp);
        return;
    }
}

int peek(Node *HEAD){
    Node *tmp = HEAD->next;
    
    if(tmp==NULL) return -1;
    cout<<"hi";
    return tmp->data; 
}
int main(){
    int x=0;
    Node *HEAD;
    HEAD = (Node*)malloc(sizeof(Node));
    HEAD->next =NULL;
    // free(HEAD);
    // push(HEAD,10);
    // push(HEAD,20);
    // push(HEAD,30);
    cout <<peek(HEAD) <<"\n";
    // pop(HEAD);
    cout << peek(HEAD) << "\n";
    pop(HEAD);
    cout << peek(HEAD) << "\n";
    pop(HEAD);
    cout <<( ((x=peek(HEAD))==INT_MIN)? "No nodes":to_string(x)) << "\n";
    return 0;
}