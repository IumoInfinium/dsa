#include <bits/stdc++.h>
using namespace std;

typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} node;

node *temp, *head;

void createNode()
{
    temp = (node *)malloc(sizeof(node));
    temp->next=NULL;
}

void insertFirst()
{
    createNode();
    cout << "Enter element: ";
    cin >> temp->data;
    if(head==NULL){
        head=temp;
        return;
        // head->next=NULL;
    }
    temp->next = head;
    head = temp;
    
}

void display()
{
    for (node *i = head; i!= NULL; i = i->next)
    {
        cout << i->data << endl;
    }
}

// Recursive approach
node* recur_rev_yash(node *curr, node* prev=NULL){
    if(curr==NULL){
        return prev;    
    }
    else{
        node *next=curr->next;
        curr->next=prev;
        return recur_rev_yash(next,curr);
    }
}


node* recur_rev_arzoo(node* ptr, node* next){
    if(!next) return ptr;
    node* prev = ptr;
    ptr = next;
    next = ptr->next;

    ptr->next = prev;
    return recur_rev_arzoo(ptr,next);
}

void iterative_rev_yash(){
    node *p=NULL,*q=head;
    while(q!=NULL){
        node *r = q->next;
        q->next = p;
        p=q;
        q=r;
    }
    head=p;
}

void iterative_rev_arzoo(){
    node *p,*q=head,*r=head->next;
    do{
        p=q;
        q=r;
        r=q->next;
        q->next=p;
        // q=r;
    }while (r != NULL);
    head->next = NULL;
    head=q; 
}

int main()
{
    // insertFirst();
    // insertFirst();
    // insertFirst();
    // cout<<"before reversing: "<<endl;
    // display();
    // head = recur_rev(head);
    // cout<<"after reversing: "<<endl;
    // display();
    // return 0;


    insertFirst();
    insertFirst();
    insertFirst();
    cout<<"before reversing: "<<endl;
    display();
    head = recur_rev_yash(head);
    cout<<"Yash's list after after reversing: "<<endl;
    display();
    temp= recur_rev_arzoo(head, head->next);
    head->next=NULL;
    head=temp;
    cout<<"Arzoo's list after reversing again: "<<endl;
    display();

    iterative_rev_yash();
    // heda = tmp
    cout<<"Arzoo's list after iterative-reversing again: "<<endl;
    display();

    return 0;
}
