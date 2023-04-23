#include <bits/stdc++.h>

using namespace std;
typedef struct BinaryTreeNode{
		struct BinaryTreeNode* left;
		struct BinaryTreeNode* right;
		int val;

		BinaryTreeNode(int x){
				val = x;
				left= NULL;
				right = NULL;
		}
} TreeNode;
vector<int> morris_traversal(TreeNode* root){
		vector<int> inorder;

		TreeNode* curr = root;

		while(curr != NULL){
				if(curr->left == NULL){
						inorder.push_back(curr->val);
						curr = curr->right;
				}
				else{
						TreeNode* prev = curr->left;
						while(prev->right != NULL && prev->right != curr)
								prev = prev->right;

						if(prev->right == NULL){
								prev->right = curr;
								curr = curr->left;
						}
						else {
								prev->right= NULL;
								inorder.push_back(curr->val);
								curr= curr->right;
						}
				}
		}
		return inorder;
}
int main(){
		TreeNode* root = new TreeNode(15);
		root->left = new TreeNode(10);
		root->right = new TreeNode(35);
		root->left->left = new TreeNode(5);
		root->left->right = new TreeNode(12);
		root->left->right->right = new TreeNode(14);

		vector<int> inorder;

		inorder =  morris_traversal(root);

		for(int i : inorder) cout <<  i << " ";
		cout << "\n";

		return 0;
}
