// Implementation of optimal binary search tree based on the probabilites
#include <bits/stdc++.h>
using namespace std;



void optimal_bst(vector<double>& p, vector<double>& q,int n, vector<vector<int>>& root, vector<vector<double>>& w, vector<vector<double>>& e){
    
    for(int i=1; i<= n+1; i++){
        e[i][i-1] = q[i-1];
        w[i][i-1] = q[i-1];
    }
    for(int len=1; len<= n; len++){
        for(int i=1; i<= n-len+1; i++){
        
            int j = i+len-1;
            e[i][j] = INT_MAX;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            
            for(int r= i; r<=j; r++){
                double tmp = e[i][r-1] + e[r+1][j] + w[i][j];
                if( tmp < e[i][j]){
                    e[i][j] = tmp;
                    root[i][j] = r;
                }
            }
        }
    }
}

void printRoot(vector<vector<int>>& root,int n){
    cout << "Root of each subtree"<< endl;

    for(int i=1;i<=n; i++){
        for(int j=1; j<= n; j++){
            cout << root[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// prints structure of optimal BST
// [i,j] -> left and right subtrees of the root r
void printOptimalBST(vector<vector<int>>& root,int n, int i, int j, int r){
    int rootNode = root[i][j];
    if(rootNode == root[1][n]){
        cout << "k" << rootNode << " is the root " << endl;
        printOptimalBST(root, n, i, rootNode-1, rootNode);
        printOptimalBST(root, n, i, rootNode-1, rootNode);
        return;
    }
    if(j < i-1) return ;
    else if( j == i-1){
        if( j<r)
            cout << "d" << j << " is the left child of " << " k" << r << endl;
        else
            cout << "d" << j << " is the right child of " << " k" << r << endl;
        return;
    }
    else{
        if( rootNode < r)
            cout << "k" << rootNode << " is the left child of " << " k" << r << endl;
        else
            cout << "k" << rootNode << " is the right child of " << " k" << r<< endl; 
    }
    printOptimalBST(root,n, i, rootNode-1, rootNode);
    printOptimalBST(root,n, rootNode+1, j, rootNode);
}

int main(){
    // p(i) -> probability for key(i)
    // q(i) -> probability for dummy key d(i)
    vector<double> p = {-1, 0.04, 0.06, 0.08, 0.02, 0.10, 0.12, 0.14};
    vector<double> q = {0.06, 0.06, 0.06, 0.06, 0.05, 0.05, 0.05, 0.05};
    
    // another example
    // vector<double> p = {-1, 0.15, 0.10, 0.05, 0.10, 0.20};
    // vector<double> q = {0.05, 0.10, 0.05, 0.05, 0.10};
    
    int n = p.size()-1;

    vector<vector<int>> root(n+1,vector<int>(n+1,-1));

    vector<vector<double>> w(n+2,vector<double>(n+2,-1));
    vector<vector<double>> e(n+2,vector<double>(n+2,-1));
    
    optimal_bst(p,q,n, root,w,e);

    printRoot(root,n);

    cout << "Cost is :" << e[1][n] << endl;
    
    cout << "Optimal BST" << endl;

    printOptimalBST(root,n, 1,n, -1);
    return 0;
}