
// Problem link - https://leetcode.com/problems/longest-palindromic-subsequence/

// Approach - using Recursion

#include<bits/stdc++.h>
using namespace std;

int findLPS_Recursion(string str, int i, int j){
    // Base case if bothe indices i and j are equal return 1
    if (i == j) return 1;

    // if ith index surpass jth index that means no pallindromic string is possible
    // return 0
    if (i > j) return 0;

    // if terminal characters are equal , add their contribution
    // and recursively call the function on remaning characters
    if (str[i] == str[j]){
        return 2 + findLPS_Recursion(str, i + 1, j - 1);
    }
    else{
        // otherwise recursively call the function on remaning characters
        return max(findLPS_Recursion(str, i + 1, j), findLPS_Recursion(str, i, j - 1));
    }
}

int longestPalindromeSubseq(string s) {
    return findLPS_Recursion(s, 0, s.size()-1);
}

int main(){
    string str = "bbbab";
    cout<<longestPalindromeSubseq(str)<<endl;
    return 0;
}