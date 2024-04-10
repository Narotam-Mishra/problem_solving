
// Problem link - https://leetcode.com/problems/longest-common-subsequence/

// Approach - using Recursion

#include<bits/stdc++.h>
using namespace std;

int findLCSRec(string s1, string s2, int i, int j){
    // Base case: if any of the string has been exhausted then return 0
    if (i == -1 || j == -1) return 0;

    // Recursive case1: if the current character from each string is equal
    // then add current character length and recursively call the function on remaining characters
    if (s1[i] == s2[j]){
        return 1 + findLCSRec(s1, s2, i - 1, j - 1);
    }
    else{
        // Recursive case2: either exclude current character from 1st string or 2nd string
        int l1 = findLCSRec(s1, s2, i - 1, j);
        int l2 = findLCSRec(s1, s2, i, j - 1);
        // and return maximum length
        return max(l1, l2);
    }
}

int longestCommonSubsequence(string text1, string text2) {
    return findLCSRec(text1, text2, text1.length()-1, text2.length()-1);
}

int main(){
    string s1 = "abcde";
    string s2 = "ace" ;
    cout<<longestCommonSubsequence(s1,s2)<<endl;
    return 0;
}