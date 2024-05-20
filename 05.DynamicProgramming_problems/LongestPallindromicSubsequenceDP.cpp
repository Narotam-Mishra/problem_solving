
// Problem link - https://leetcode.com/problems/longest-palindromic-subsequence/description/

// Approach - using Top Down DP

#include<bits/stdc++.h>
using namespace std;

int findLPS_TopDownDP(string str, int i, int j, vector<vector<int>>& dp){
    // Base case if bothe indices i and j are equal return 1
    if (i == j) return 1;

    // if ith index surpass jth index that means no pallindromic string is possible
    // return 0
    if (i > j) return 0;

    // if dp[i][j] is already computed then return dp[i][j]
    if(dp[i][j] != -1) return dp[i][j];

    // if terminal characters are equal , add their contribution
    // and recursively call the function on remaning characters
    if (str[i] == str[j]){
        return dp[i][j] = 2 + findLPS_TopDownDP(str, i + 1, j - 1, dp);
    }
    else{
        // otherwise recursively call the function on remaning characters
        return dp[i][j] = max(findLPS_TopDownDP(str, i + 1, j, dp), findLPS_TopDownDP(str, i, j - 1, dp));
    }
}

int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return findLPS_TopDownDP(s, 0, s.size()-1, dp);
}

int main(){
    string str = "bbbab";
    cout<<longestPalindromeSubseq(str)<<endl;
    return 0;
}