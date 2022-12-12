// Given a rod of length n and its price per lengths
// Find maximum prices that can the found by cutting the rod in peices

#include <bits/stdc++.h>
using namespace std;

// naive recursion, checks every case -> 2^n
int cut_rod(vector<int>& prices, int n){
    if (n==0) return 0;
    int q = INT_MIN;

    for(int i=1;i<n+1;i++)
        q = max(q, prices[i] + cut_rod(prices, n-i-1));
    
    return q;
}

int memo_cut_rod_aux(vector<int>& prices,int n, vector<int>& memo, vector<int>& sol){
    if( memo[n] != -1) return memo[n];

    if( n == 0) return memo[n] = 0;
    
    int q=INT_MIN;

    // check for all length peices
    for(int i=1; i<n+1 ;i++){
        q = max(q, prices[i-1]+ memo_cut_rod_aux(prices,n-i,memo,sol));
        // int remaining = memo_cut_rod_aux(prices,n-i-1,memo,sol);

        // if( q< prices[i] + remaining){
        //     q = prices[i] + remaining;
        //     sol[n]=i;
        // } 
    }
    return memo[n]=q;
}


// Memo-ed version of using already-solved to solve further
int memo_cut_rod(vector<int>& prices,int n){
    // default value is -1, showing no profit.
    vector<int> memo(n+1,-1);

    // how to divide the rod
    vector<int> solution(n+1);

    int ans = memo_cut_rod_aux(prices,n,memo, solution);
    // int j=n;
    // while(j>0){
    //     cout << solution[j] <<" ";
    //     j -= solution[n];
    // }
    return ans;
}

//Bottom-Up of recursion tree
int bottom_up_cut_rod(vector<int>& prices,int n){
    vector<int> dp(n+1,0);
    vector<int> solution(n);
    dp[0]=0;
    int ans ;
    for(int j= 1; j<n+1; j++){
        ans = INT_MIN;
        for(int i =0; i<j; i++){
            // ans =  max(ans , prices[i] + dp[j-i-1]);
            if(ans < prices[i] + dp[j-i-1]){
                ans = prices[i] + dp[j-i-1];
                solution[j]=i;
            }
        dp[j] = ans; 
        }
    }
    // int j=n;
    // while(j>0){
    //     cout << solution[j] <<" ";
    //     j-= solution[n];
    // }
    return dp[n];
}




int solve(int idx, int sum_of_idx, int target, int price[], vector <vector<int>>&memo, vector<int>&ds){

    if(idx>=target) return INT_MIN;
    
    if(memo[idx][sum_of_idx]!=-1) return memo[idx][sum_of_idx];
    
    int take=INT_MIN, not_take=INT_MIN;

    if(sum_of_idx+idx<=target){
        ds.push_back(price[idx]);
        take=solve(idx, sum_of_idx+idx+1, target, price, memo, ds)+price[idx];
        ds.pop_back();
    }
    not_take=solve(idx+1, sum_of_idx, target, price, memo, ds)+0;

    return memo[idx][sum_of_idx]=max(take, not_take);
}
int cutRod(int price[], int n) {
    //code here
    vector <vector<int>> memo(n, vector<int>(n+1,-1));
    vector<int>ds;
    return solve(0,0,n,price, memo,ds);
}





int main(){
    // Rod - length
    int n = 8;
    vector<int> prices = {1,5,8,9,10,17,17,20};


    // Takes expotential time, 2^n
    cout << "Maximum/Optimal profit :";
    cout << cut_rod(prices,n) << endl;


    // Memoized version
    cout << "Maximum/Optimal profit using memo :";
    cout << memo_cut_rod(prices,n) << endl;

    // Bottom-UP version
    cout << "Maximum/Optimal profit using bottom-up :";
    cout << bottom_up_cut_rod(prices,n) << endl;
    return 0;
}