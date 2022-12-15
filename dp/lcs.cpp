// Implementation of LCS(Longest Common Subsequence)
// using dynamic programming 
#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2, vector<vector<int>>& s) {
    int m = text1.size();
    int n = text2.size();
    
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
                s[i][j]=0;
            }
            else if(text1[i-1] == text2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                s[i][j]=1;
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                s[i][j]=-1;
            }
        }
    }
    return dp[m][n];
}
void printlcs(string& x, int i,int j, vector<vector<int>>& s){
    if( i== 0 || j == 0) return;
    if(s[i][j] == 0){
        printlcs(x,i-1,j-1,s);
        cout << x[i];
    }
    else if (s[i][j] == 1) printlcs(x,i-1,j,s);
    else printlcs(x,i,j-1,s);
}
int main(){
    string text1 = "abcde";
    string text2 = "ace";
    
    cout << "Length of LCS : ";
    
    int m = text1.size();
    int n = text2.size();
    
    vector<vector<int>> s(m+1,vector<int>(n+1,-1));
    
    cout << longestCommonSubsequence("abcde","ace",s) <<endl;

    printlcs(text1,0,0,s);
    return 0;
}