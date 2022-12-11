#include <bits/stdc++.h>

using namespace std;

typedef struct Red_Black_TreeNode{
    bool color;
    int key;
    struct Red_Black_TreeNode* left;
    struct Red_Black_TreeNode* right;
    struct Red_Black_TreeNode* parent;
}TreeNode;

typedef struct Red_Black_Tree_Info{
    TreeNode* root;
    TreeNode* nil;
}TreeInfo;

TreeInfo T;


TreeNode* create_node(){
    //Color - 1 for Red Node
    //Color - 0 for Black Node
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->parent=NULL;
    return new_node;
}

void left_rotation(TreeInfo& T, TreeNode* x){
    TreeNode* y = x->right;
    x->right = y->left;

    if(y->left != T.nil)
        y->left->parent = x;
    y->parent = x->parent;

    if(x->parent == T.nil)
        T.root = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    
    y->left =x;
    x->parent = y;
}

void right_rotation(TreeInfo& T, TreeNode* x){
    TreeNode* y = x->left;
    y->left = x->right;

    if( x->right != T.nil)
        x->right->parent = y;
    x->parent = y->parent;

    if(y->parent == T.nil)
        T.root = x;
    else if( y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;
    
    x->right = y;
    y->parent = x;
}
void inorder_traversal(TreeNode* root){
    if(root != T.nil){
    inorder_traversal(root->left);
    // cout << root->key <<":"<<root->color <<"  ";
    inorder_traversal(root->right);
    }
}
void rb_tree_insert_fixup(TreeInfo& T, TreeNode* z){
    // cout << "color of parennt  : "<< z->parent->color;
    while(z->parent->color == 1){
        // insertion forms a line in left-side, 2 edges in a line
        if(z->parent == z->parent->parent->left){
            // uncle to z's parent, or sibling of z
            TreeNode* y = z->parent->parent->right;

            if(y->color == 1){
                z->parent->color = 0;
                y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            }
            else if(z == z->parent->right){
                z = z->parent;
                left_rotation(T, z);
            }
            else{
                z->parent->color = 0;
                z->parent->parent->color = 1;
                right_rotation(T,z->parent->parent);
            }
        }
        else{
            // uncle to z's parent, or sibling of z
            TreeNode* y = z->parent->parent->left;

            if(y->color == 1){
                z->parent->color = 0;
                y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            }
            else if(z == z->parent->left){
                z = z->parent;
                left_rotation(T, z);
            }
            else{
                z->parent->color = 0;
                z->parent->parent->color = 1;
                right_rotation(T,z->parent->parent);
            }
        }
    }
}

TreeNode* rb_tree_insert(TreeInfo& T,int val){
    
    // z-> pointer to new node 
    TreeNode* z = create_node();
    z->key = val;

    // y -> a shiftable pointer... pointer to parent, where a node is inserted
    // x -> pointer to root of the tree
    TreeNode* y = T.nil;
    TreeNode* x = T.root;
    
    // searching where to insert the new node
    cout << " ~~~ " << z->key;    
    while(x != T.nil){
        y = x;
        if(z->key < x->key)
            x = x->left;
        else x= x->right;
    }
    // set the parent-pointer-of-z to y
    z->parent = y;

    if(y == T.nil){// if there is no root, set new node as root
        T.root = z;
    }
    else if(z->key < y->key){
        // new node needs to be in the left subtree of where it should be under.
        y->left = z;
        cout <<" left " <<endl;
    }
    else{
        // new node needs to be in the right subtree of where it should be under.
        y->right = z;
        cout << "right" <<endl;
    }
    // left, right pointers are NIL, and color is red
    z->left = T.nil;
    z->right = T.nil;
    z->color = 1;
    // fix, the RB-tree if there are any property failures, due to insertion
    rb_tree_insert_fixup(T,z);

    inorder_traversal(T.root);
    cout <<" =====\n\n";
    return z;
}


int main(){

    T.nil =  (TreeNode*)malloc(sizeof(TreeNode));
    T.root = (TreeNode*)malloc(sizeof(TreeNode));
    T.nil->color=0;     // black color for NIL node
    T.nil->left = NULL;
    T.nil->right= NULL;
    T.root = T.nil;
    T.root->color = 0;
    // cout << T.root->key;
    rb_tree_insert(T,41);
    // cout << T.root->key <<endl;
    rb_tree_insert(T,38);
    
    rb_tree_insert(T,31);
    
    rb_tree_insert(T,12);
    
    rb_tree_insert(T,19);
    
    rb_tree_insert(T,9);
    

    inorder_traversal(T.root);
    return 0;
}