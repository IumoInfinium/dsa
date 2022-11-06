#include <bits/stdc++.h>
using  namespace std;

typedef struct LinkNode{
    int data;
    struct LinkNode* next;
}Node;

Node *newNode;
void createNode(){
    newNode=(Node*)malloc(sizeof(Node));
}

void insert(int data, Node* senti){
    createNode();
    newNode->data=data;
    newNode->next=senti->next;
    senti->next=newNode;
}

void display(Node *senti){
    Node *i=senti->next;
    while(i->next!=senti){
        cout<<i->data<<" ";
        i=i->next;
    }
    cout<<i->data<<endl;
}

int main(){
    Node *s1=(Node*)malloc(sizeof(Node));
    s1->next=NULL;
    Node *s2=(Node*)malloc(sizeof(Node));
    s2->next=s2;
    insert(1,s1);
    insert(2,s1);
    insert(3,s1);

    insert(10,s2);
    insert(20,s2);
    insert(30,s2);

    display(s1);
    display(s2);
    return 0;
} 