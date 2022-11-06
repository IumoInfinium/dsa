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


void preOrderTraversal(node* root){
    stack<node*> st;
    node* curr = root;
    while(curr !=NULL || !st.empty()){
        while(curr != NULL){
            cout << curr->key << " ";
            st.push(curr);
            curr=curr->left;
        }
        curr =st.top();
        st.pop();
        curr = curr->right;
    }
    return;
}



int main(){
    node* root = new node(55);
    root->left = new node(40);
    root->right = new node(60);
    root->left->left = new node(35);
    root->left->right= new node(45);

    root->right->left= new node(57);
    preOrderTraversal(root);
    return 0;
}