#include <bits/stdc++.h>

using namespace std;

typedef struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} TreeNode;

TreeNode *root;

TreeNode *create_node(){
    TreeNode *tmp = (TreeNode *)malloc(sizeof(TreeNode));
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}


TreeNode* bst_insert(int val){
    TreeNode *new_node = create_node();

    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;

    if (root == NULL){
        root = new_node;

        return root;
    }
    TreeNode *q, *p = root;
    while (p != NULL){
        if (p->data > new_node->data){
            q = p;
            p = p->left;
        }
        else{
            q = p;
            p = p->right;
        }
    }
    if (q->data > new_node->data)
        q->left = new_node;
    else{
        q->right = new_node;
    }
    return new_node;
}

bool bst_search(TreeNode *root, int key){
    if (!root)
        return false;
    TreeNode *p = root;

    while (p != NULL){
        if (p->data == key)
            return true;
        else if (p->data > key)
            p = p->left;
        else
            p = p->right;
    }
    return false;
}

void preorder_traversal(TreeNode *root){
    if (root != NULL){
        cout << root->data << " ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}
void inorder_traversal(TreeNode *root){
    if (root != NULL){
        inorder_traversal(root->left);
        cout << root->data << " ";
        inorder_traversal(root->right);
    }
}
void postorder_traversal(TreeNode *root){
    if (root != NULL){
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout << root->data << " ";
    }
}

TreeNode* minimum_tree(TreeNode *root){
    while(root->left != NULL)
        root = root->left;
    return root;
}
TreeNode* recursive_minimum_tree(TreeNode* root){
    if(root->left != NULL) return recursive_minimum_tree(root->left);
    else return root;
}

TreeNode* maximum_tree(TreeNode *root){
    while(root->right != NULL)
        root = root->right;
    return root;
}
TreeNode* recursive_maximum_tree(TreeNode* root){
    if(root->right != NULL) return recursive_maximum_tree(root->right);
    else return root;
}
TreeNode* successor_tree(TreeNode* root,TreeNode* x){
    if(x->right != NULL)
        return minimum_tree(x->right);
    
    TreeNode *succ = NULL;
    while(root != NULL){
        if(x->data < root->data){
            succ = root;
            root = root->left;
        }
        else if (x->data > root->data)
            root=root->right;
        else
            break;
    }
    return succ;   
}

TreeNode* predecessor_tree(TreeNode* root, TreeNode* x){
    if(x->left != NULL)
        return maximum_tree(x->left);
    
    TreeNode* pre = NULL;
    while(root != NULL){
        if(x->data > root->data){
            pre = root;
            root = root->left;
        }
        else if(x->data < root->data)
            root = root->right;
        else
            break;
    }
    return pre;
}
int main(){
    TreeNode *tmp_p,*tmp_q;
    tmp_q=bst_insert( 55);
    bst_insert(30);
    bst_insert(65);
    tmp_p = bst_insert(10);
    bst_insert(40);
    bst_insert(90);

    cout << "Search for 57 :" << bst_search(root, 57) << endl;
    cout << "Search for 90 :" << bst_search(root, 90) << endl;

    cout << "\nPreOrder traversal : ";
    preorder_traversal(root);
    
    cout << "\nInOrder traversal :";
    inorder_traversal(root);

    cout << "\nPostOrder traversal :";
    postorder_traversal(root);

    TreeNode* node;
    // node = minimum_tree(root);
    node = recursive_minimum_tree(root);
    cout << "\nMinimum value in tree : " << node->data << endl;
    
    // node = maximum_tree(root);
    node = recursive_maximum_tree(root);
    cout << "Maximum value in tree : " << node->data << endl;

    node = successor_tree(root,tmp_p);
    cout << "Successor of 10 :"<< node->data <<endl;
    
    node = predecessor_tree(root,tmp_q);
    cout << "Predecessor of 55 :"<< node->data <<endl;
    return 0;
}
    