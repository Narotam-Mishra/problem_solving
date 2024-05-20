
// Problem link - https://leetcode.com/problems/longest-common-subsequence/

// Approach - using Top Down DP

#include<bits/stdc++.h>
using namespace std;

// Define the DP array globally
int dp[1005][1005];

int findLCSTopDownDP(string s1, string s2, int i, int j) {
    // Base case: if any of the string has been exhausted then return 0
    if (i == -1 || j == -1) return 0;

    // if dp[i][j] is already calculated then return dp[i][j]
    if (dp[i][j] != -1) return dp[i][j];

    // Recursive case1: if the current character from each string is equal
    // then add current character length and recursively call the function on remaining characters
    if (s1[i] == s2[j]) {
        return dp[i][j] = 1 + findLCSTopDownDP(s1, s2, i - 1, j - 1);
    } else {
        // Recursive case2: either exclude current character from 1st string or 2nd string
        int l1 = findLCSTopDownDP(s1, s2, i - 1, j);
        int l2 = findLCSTopDownDP(s1, s2, i, j - 1);
        // and return maximum length
        return dp[i][j] = max(l1, l2);
    }
}

int longestCommonSubsequence1(string text1, string text2) {
    // Initialize dp array with -1
    memset(dp, -1, sizeof(dp));
    return findLCSTopDownDP(text1, text2, text1.length() - 1, text2.length() - 1);
}

// Memoization hashmap
unordered_map<string, int> dpMemo; 

int findLCSTopDownDPMap(string s1, string s2){
    // Base case: if any of the strings is empty, return 0
    if(s1.empty() || s2.empty()) return 0;

    // Check if the result is already memoized
    string key = s1 + "|" + s2;
    if(dpMemo.find(key) != dpMemo.end()) return dpMemo[key];

    // If the last characters of both strings match
    if(s1.back() == s2.back()){
        return dpMemo[key] = 1 + findLCSTopDownDPMap(s1.substr(0, s1.length()-1), s2.substr(0, s2.length()-1));
    }else{
        // Recurrence for two cases:
        // 1. Remove the last character of s1 and keep s2 unchanged
        int l1 = findLCSTopDownDPMap(s1.substr(0, s1.length()-1), s2);
        // 2. Remove the last character of s2 and keep s1 unchanged
        int l2 = findLCSTopDownDPMap(s1, s2.substr(0, s2.length()-1));
        // Return the maximum of both cases
        return max(l1,l2);
    }
}

int longestCommonSubsequence2(string text1, string text2) {
    return findLCSTopDownDPMap(text1, text2);
}

int dpArr[1005][1005];

int findLCSBottomUpDP(string s1, string s2){
    for(int i=1; i<=s1.length(); i++){
        for(int j=1; j<=s2.length(); j++){
            if(i == 0 || j == 0) dpArr[i][j] = 0;
            else{
                if(s1[i-1] == s2[j-1]){
                    dpArr[i][j] = 1 + dpArr[i-1][j-1];
                }else{
                    dpArr[i][j] = max(dpArr[i-1][j], dpArr[i][j-1]);
                }
            }
        }
    }
    return dpArr[s1.length()][s2.length()];
}

int longestCommonSubsequence(string text1, string text2) {
    return findLCSBottomUpDP(text1, text2);
}

int main() {
    string s1 = "abcde";
    string s2 = "ace";

    // string s1 = "abc";
    // string s2 = "abc";

    // string s1 = "abc";
    // string s2 = "def";
    cout << longestCommonSubsequence(s1, s2) << endl;
    return 0;
}