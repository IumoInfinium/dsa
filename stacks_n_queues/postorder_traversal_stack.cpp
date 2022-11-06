#include <bits/stdc++.h>
using namespace std;

typedef struct binary_node{
    int key;
    struct binary_node* left;
    struct binary_node* right;

    binary_node(int x){
        key=x;
        left = NULL;
        right = NULL;
    }
}node;


void postOrderTraversal(node* root){
    stack<node*> st1,st2;
    node* curr;
    st1.push(root);
    while(!st1.empty()){
        curr= st1.top();
        st1.pop();
        st2.push(curr);
        if(curr->left !=NULL) st1.push(curr->left);
        if(curr->right!=NULL) st1.push(curr->right);
    }
    while(!st2.empty()){
        cout<<st2.top()->key << " ";
        st2.pop();
    }
}


void postOrderTraversal2(node* root){
    // using 1 stack
    stack<node*> st;
    node* curr=root, *prev=NULL;
    while(curr!=NULL || !st.empty()){
        if(curr != NULL){
            st.push(curr);
            curr=curr->left;
        }
        else{
            curr = st.top();
            if(curr->right == NULL || curr->right == prev){
                cout << curr->key <<" ";
                st.pop();
                prev= curr;
                curr= NULL;
            }
            else curr=curr->right;
        }
    }
    return ;
}


int main(){
    node* root = new node(55);
    root->left = new node(40);
    root->right = new node(60);
    root->left->left = new node(35);
    root->left->right= new node(45);

    root->right->left= new node(57);
    postOrderTraversal(root);
    cout << "\nSAD\n";
    postOrderTraversal2(root);
    return 0;
}