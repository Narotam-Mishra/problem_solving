
// Problem link - https://leetcode.com/problems/longest-palindromic-subsequence/description/

#include<bits/stdc++.h>
using namespace std;

int findLCSBottomUpDPUtility(string s1, string s2){
    int dpArr[1005][1005];
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

int longestPalindromeSubseq(string s) {
    string s1 = s;
    reverse(s1.begin(), s1.end());
    return findLCSBottomUpDPUtility(s,s1);
}

int main(){
    string str = "bbbab";
    cout<<longestPalindromeSubseq(str)<<endl;
}