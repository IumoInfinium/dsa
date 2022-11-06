#include <bits/stdc++.h>
using namespace std;

typedef struct link_node{
    int key;
    struct link_node *next;
}Node;

Node *create_node(){
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->next = NULL;
    return tmp;
}

void insert_node(Node *senti,int ele){
    Node *new_node = create_node();
    new_node->key = ele; 
    if(senti ->next == senti) new_node->next = senti;
    else new_node->next = senti->next;
    senti->next=new_node;
}

void display(Node *senti){
    Node *tmp = senti->next;
    while(tmp != senti){
        cout << tmp->key <<" ";
        tmp=tmp->next;
    }
    cout << "\n";
}


void reverse(Node* senti){
    if(senti->next == senti) return;
    Node *p = senti;
    Node *q = senti ->next;
    while(q!= senti){
        Node *r = q->next;
        q->next = p;
        p=q;
        q=r;
    }
    senti->next = p;
}

int main(){
    Node *Sentinel = create_node();
    Sentinel->next = Sentinel;

    insert_node(Sentinel,100);
    insert_node(Sentinel,200);
    insert_node(Sentinel,300);
    display(Sentinel);
    reverse(Sentinel);
    display(Sentinel);
    return 0;
}