#include <bits/stdc++.h>
using namespace std;

typedef struct LinkedListNode{
    int key;
    struct LinkedListNode *next;
}Node;


Node* create_node(){
    Node *tmp;
    tmp = (Node*) malloc(sizeof(Node));
    tmp->next = NULL;
    return tmp;
}


// insert at first position
void insert_node(Node *senti,int ele){
    Node *new_node = create_node();
    new_node->key = ele; 
    new_node->next = senti->next;
    senti->next=new_node;
}

Node* search(Node *senti,int ele){
    Node *tmp = senti;
    if(tmp->next == senti){
        cout << "phew\n";
        return NULL;
    }
    while(tmp->next!= senti && tmp->next->key != ele){
        tmp=tmp->next;
    }
    if(tmp->next == senti){
        cout <<"Element not found " <<ele << "\n";
        return NULL;
    }
    cout << "Element found " << tmp->next->key << "\n";
    return tmp;
}

void delete_node(Node *senti,int ele){
    Node *prev = search(senti,ele);
    if(!prev) return;
    Node *tmp = prev->next;
    prev->next = tmp->next;
    free(tmp);
    tmp=NULL;
}

void display(Node *senti){
    Node *tmp = senti->next;
    while(tmp != senti){
        cout << tmp->key <<" ";
        tmp=tmp->next;
    }
    cout << "\n";
}

int main(){
    // Sentinel / HEAD node
    Node *senti;
    senti = (Node*) malloc(sizeof(Node));
    senti->next = senti;
    
    insert_node(senti,100);
    insert_node(senti,200);
    insert_node(senti,300);
    insert_node(senti,400);

    cout << "part-1 \n";
    search(senti, 400);
    display(senti);

    cout << "part-2 \n";
    delete_node(senti,200);

    cout << "part-3 \n";
    search(senti,200);
    display(senti);
    return 0;
}