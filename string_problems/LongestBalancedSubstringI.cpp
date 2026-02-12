
// Problem link - https://leetcode.com/problems/longest-balanced-substring-i/description/?envType=daily-question&envId=2026-02-12

#include<bits/stdc++.h>
using namespace std;

// utility function to balanced substring
bool isBalancedString(vector<int>& frq){
    int commonFrq = 0;
    for(int i=0; i<26; i++){
        if(frq[i] == 0) continue;

        if(commonFrq == 0){
            commonFrq = frq[i];
        }else if(frq[i] != commonFrq){
            return false;
        }
    }
    return true;
}

int longestBalanced(string s) {
    int n = s.length();

    // keep track of length of the longest balanced substring
    int maxLen = 0;

    // step 1 - iterate on each character of string
    for(int i=0; i<n; i++){
        // store frequency
        vector<int> frq(26,0);

        // step 2 - iterate on each substring
        for(int j=i; j<n; j++){
            frq[s[j] - 'a']++;

            // step 3 - check if substring is balanced or not
            if(isBalancedString(frq)){
                // step 4 - update maximum length of balanced substring
                maxLen = max(maxLen, j-i+1);
            }
        }
    }

    // step 5 - return longest balanced substring
    return maxLen;
}

int main(){
    // string s = "abbac";

    // string s = "zzabccy";

    string s = "aba";
    cout<<longestBalanced(s);
    return 0;
}