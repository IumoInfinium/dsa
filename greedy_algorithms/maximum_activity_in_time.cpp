#include <bits/stdc++.h>
using namespace std;

// Find the maximum number of activities to choose such that
// there is no time overlapping among them

int max_activity_dp(vector<int>& s, vector<int>& e, int n){
    vector<vector<int>>
        dp(n+1,vector<int>(n+1,-1)),
        act(n+1,vector<int>(n+1,-1));

    for(int i=0;i< n; i++){
        dp[i][i] = 0;
        dp[i][i+1]=0;
    }
    dp[n][n]=0;

    for(int len = 2; len < n+1; len++){
        for(int i=0; i<n-len+1; i++){
            int j = i+len;
            dp[i][j] = 0;
            int k = j-1;
            while ( e[i] < e[k]){
                if( (e[i] <= s[k]) && (e[k] <= s[j]) && dp[i][k] + dp[k][j] +1 > dp[i][j]){
                    dp[i][j] = dp[i][k] + dp[k][j] +1;
                    act[i][j] = k;
                }
                k--;
            }
        }
    }

    // maximum size of that set is ...
    return dp[0][n+1];
}

int greedy_recursive(vector<int>& s, vector<int>& e, int k ,int n){
    int m = k+1;
    while(m <= n+1 && s[m] < e[k])
        m++;
    
    if(m <= n+1) return 1+greedy_recursive(s,e,m,n);
    else return 0;
}

int greedy_iterative(vector<int>& s, vector<int>& e){
    int n = s.size();
    vector<int> activity_idx;
    int k = 1;
    for(int m = 2; m<=n ; m++){
        if(s[m] >= e[k]){
            activity_idx.push_back(m);
            k = m;
        }
    }
    return activity_idx.size();
}

int main(){
    vector<int> startTime= {1,3,0,5,3,5,6,8,8,2,12};
    vector<int> endTime  = {4,5,6,7,9,9,10,11,12,14,16};
    int n = startTime.size();

    cout << "Maximum activites using dynamic programming ..." ;
    cout << max_activity_dp(startTime,endTime,n) << endl;
    
    cout << "Maximum activites using recursive greedy ..." ;
    cout << greedy_recursive(startTime,endTime,0,n) << endl;

    cout << "Maximum activites using iterative greedy ...";
    cout << greedy_iterative(startTime,endTime) << endl;

    return 0;
}