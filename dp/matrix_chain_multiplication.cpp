#include <bits/stdc++.h>
using namespace std;

// naive solution
int mcm(vector<int>& order,int i,int j){
    if( i == j) return 0;
    int mini = INT_MAX;
    for(int k=i; k<= j-1; k++){
        int ans = mcm(order,i,k) + mcm(order,k+1,j) + order[i-1]*order[k]*order[j];
        mini = min(mini,ans);
    }
    return mini;
}

// memoized version
int mcm2(vector<int>& order, int i,int j, vector<vector<int>>& dp){
    if ( i == j ) return 0;
    if( dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;
    for(int k=i; k<=j-1;k++){
        int ans = mcm2(order,i,k,dp) + mcm2(order,k+1,j,dp) + order[i-1]*order[k]*order[j];
        mini = min(mini, ans);
    }
    return mini;
}

// Tabulation based
int tabulated_mcm(vector<int>& order,int n){
    int m[n][n];
    int i,j,k,l,q;
    for(i= 1;i<n;i++) m[i][i] = 0;
    for(int l=2;l<n;l++){
        for(int i=1;i<n-l+1;i++){
            j = i+l-1;
            m[i][j] = INT_MAX;
            for(int k=i; k<=j-1;k++){
                q = m[i][k] + m[k+1][j] + order[i-1]*order[k]*order[j];
                if(q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n-1];
}
int main(){
    vector<int> order = {5,10,3,12,5,50,6};
    int n = order.size();
    cout << "The minimum number of operations is: ";
    
    // Naive Solution
    // cout << mcm(order,1, n-1) << endl; 

    // Memod Version
    // vector<vector<int>> dp(n, vector<int>(n,-1));
    // cout << mcm2(order,1,n-1,dp) << endl;

    // Tabulated version
    cout << tabulated_mcm(order,n) << endl;
    return 0;
}