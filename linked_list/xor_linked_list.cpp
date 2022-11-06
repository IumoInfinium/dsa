#include <bits/stdc++.h>
using namespace std;

typedef struct xor_node{
    int data;
    //XOR-ed prev and next pointers
    struct xor_node* np;
}node;

node *create_node(){
    node *tmp = (node*)malloc(sizeof(node));
    tmp->np = NULL;
    return tmp;
}

node* XOR(node *prev, node *next){
    return (node*)((int)prev ^ (int)next);
}

void insert_node(node **head,node **tail, int data, bool from){
    // double-pointers referencing
    // insertion at starting of the linked list
    // from = 1, insert at starting
    // from = 0, insert at last
    node *new_node = create_node();
    new_node->data = data;

    if(*tail == NULL){
        *head=new_node;
        *tail=new_node;
    }
    if(from){
        new_node->np = XOR(*head,NULL);
        if(from && *head !=NULL){
            node *next = XOR((*head)->np, NULL);
            (*head)->np = XOR(new_node, next);
        }
        *head = new_node;
    }
    else{   
        new_node->np = XOR(*tail,NULL);
        if(!from && *tail!=NULL){
            node *prev = XOR((*tail)->np,NULL);
            (*tail)->np = XOR(prev,new_node);
        }
        *tail=new_node;
    }
    cout << "insertion done!\n" ;
    return;
}

/* 
node* insert_node(node *head,node *tail, int data){
    // by Arzoo
    // updating head and returning it again and again
    node *new_node = create_node();
    new_node->data = data;
    new_node->np=head;
    if(tail == NULL) tail = new_node;
    if(head != NULL){
        node *next = XOR(head->np,NULL);
        head->np=XOR(new_node,next);
    }
    head=new_node;
    return head;
}
 */

void delete_node(node **head,node **tail, bool from){
    if(*head == NULL){
        cout<<"Underflow!\n";
        return;
    }
    if(from){
        node *next = XOR(NULL,(*head)->np);
        if(next == NULL){
            *head=NULL;
            *tail=NULL;
            return;
        }
        free(*head);
        next->np = XOR(*head,next->np);
        *head = next;
    }
    else{
        node *prev=XOR((*tail)->np,NULL);
        if(prev == NULL){
            *tail=NULL;
            *head=NULL;
            return;
        }
        free(*tail);
        prev->np = XOR(*tail,prev->np);
        *tail=prev;
    }
    return;
}

//ARZOO CODE
/*
void traversal(node *head){
    //initialising pointers
    cout<<head->data<<" ";
    node*prev=head;
    node *curr=prev->np;
    cout<<curr->data<<" ";
    node *next;    
    next=XOR(curr->np,prev);
    
    //moving pointers ahead
    while(next!=NULL){
        prev=curr;
        curr=next;
        cout<<curr->data<<" ";
        next=XOR(curr->np,prev);
    }
    return;
}
*/

//YASH CODE
void traversal(node *head,node *tail,bool from){
    // from = 1 <= traverse from front;
    // from = 0 <= traverse from back;
    node *prev = NULL, *next;
    if(from){
        node *curr = head;
        while(curr !=NULL){
            cout << curr->data << " ";
            next = XOR(prev, curr->np);
            prev = curr;
            curr = next;
        }
        cout<<endl;
    }
    else{
        node* curr = tail;
        while(curr !=NULL){
            cout << curr->data << " ";
            next = XOR(prev, curr->np);
            prev = curr;
            curr = next;
        }
        cout<<endl;
    }
}


node* search(node *head,int data){
    node* prev = NULL;
    node* curr = head;
    node* next ;

    while(curr !=NULL && curr->data!=data){
        next = XOR(prev, curr->np);
        prev = curr;
        curr = next;
    }
    return curr;
}

//ARZOO CODE
/*
void delete_mid(node *head, int data){
    node *temp = search(head, data);
    if (temp== NULL)
    {
        cout<<"Element not found to delete."<<endl;
        return;
    }

    node *prev = NULL;
    node *curr = head;
    node *next;

    while (curr != temp)
    {
        next = XOR(prev, curr->np);
        prev = curr;
        curr = next;
    }
    next = XOR(prev, curr->np);
    // cout<<"Current positions: "<< prev->data<<" "<<curr->data<<" "<<next->data<<endl;
    prev->np=XOR(XOR(prev->np,curr),next);
    next->np=XOR(XOR(next->np,curr),prev);
}
*/
// YASH CODE
void delete_mid(node *head,node *tail,int data){
    node* prev = NULL;
    node* curr = head;
    node* next ;

    while(curr !=NULL && curr->data!=data){
        next = XOR(prev, curr->np);
        prev = curr;
        curr = next;
    }
    // prev -> pointer before the number to delete.
    if(curr == NULL){
        cout << "No element found !!\n";
        return;
    }
    next = XOR(prev,curr->np);
    prev->np = XOR(prev->np,XOR(curr,next));
    next->np = XOR(next->np,XOR(prev,curr));
    if(curr == tail) tail = prev;
    free(curr);

    curr = NULL;
    return;
}

void reverse(node* &head, node* &tail){
    node *tmp = head;
    head = tail;
    tail = tmp;
}

int main(){
    vector<int> keys = {100, 200, 300, 400, 500};
    node* head = NULL;
    node* tail = NULL;
    cout << "starting insertion..\n";
    for(int k : keys) insert_node(&head,&tail,k,1);
    
    cout << " Adding another element-10 from back \n";
    insert_node(&head,&tail,10,0);
    // use this for node* type return insert_node
    // for(auto i: keys){
    //     head=insert_node(head,tail, keys[i]);
    // }
    
    cout <<"All values in list..\n";
    traversal(head,tail,1);

    cout << "Delete from first element\n";
    delete_node(&head,&tail,true);

    cout << "\nDelete from last element\n";
    delete_node(&head,&tail,false);

    cout << "Searching 240...";
    node *tmp = search(head,240);
    if(tmp!=NULL) cout<< "Found element \n";
    else cout << "Not found\n";


    cout << "Deleting from middle\n";
    delete_mid(head,tail,200);
    cout <<"After deleting it becomes --> ";
    traversal(head,tail,1);

    cout << "reverse the linked list...\n";
    reverse(head,tail);
    traversal(head,tail,1);
    return 0;
}