#include <bits/stdc++.h>
using namespace std;

// Fibonacci using dynmaic programming


// naive approach - go through all possible paths
int fibo(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibo(n-1) + fibo(n-2);
}


// memo based approach
int memo_fibo(int n,vector<int>& memo){
    if(memo[n] != -1) return memo[n];
    if(n==0) return 0;
    if(n==1) return 1;
    memo[n] = memo_fibo(n-1,memo) + memo_fibo(n-2,memo);
    return memo[n]; 
}

int bottom_up_fibo(int n){
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<n+1;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int fibo2(int n){
    int a = 0;
    int b = 1;
    int c=0;
    for(int i=2;i<n+1; i++){
        c= a+b;
        a=b;
        b=c;
    }
    return c;
}

int main(){
    // 0 1 1 2 3 5 8 13 
    int n = 35;
    cout << "Fibonacci at "<< n <<" : ";
    cout << fibo(n) <<endl;

    vector<int> memo(n+1,-1);
    cout << "Memo Fibonacci at "<< n <<" : ";
    cout << memo_fibo(n,memo) <<endl;
 
    cout << "Bottom Up Fibonacci at "<< n <<" : ";
    cout << bottom_up_fibo(n) <<endl;
    
    cout << "Fibonacci-2 at "<< n <<" : ";
    cout << fibo2(n) <<endl;
    return 0;
}