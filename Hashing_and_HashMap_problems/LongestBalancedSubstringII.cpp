
// Problem link - https://leetcode.com/problems/longest-balanced-substring-ii/description/?envType=daily-question&envId=2026-02-13

#include<bits/stdc++.h>
using namespace std;

int longestBalanced1(string s) {
    int n = s.length();
    int maxLen = 0;
    
    for(int i = 0; i < n; i++) {
        int cntA = 0, cntB = 0, cntC = 0;
        for(int j = i; j < n; j++) {
            if(s[j] == 'a') {
                cntA++;
            } else if(s[j] == 'b') {
                cntB++;
            } else {
                cntC++;
            }
            
            bool hasA = cntA > 0, hasB = cntB > 0, hasC = cntC > 0;
            bool balanced = false;

            if (hasA && hasB && hasC)
                balanced = (cntA == cntB && cntB == cntC);
            else if (hasA && hasB && !hasC)
                balanced = (cntA == cntB);
            else if (hasA && hasC && !hasB)
                balanced = (cntA == cntC);
            else if (hasB && hasC && !hasA)
                balanced = (cntB == cntC);
            else
                balanced = true; // only one distinct character
            
            if (balanced)
                maxLen = max(maxLen, j - i + 1);
        }
    }
    
    return maxLen;
}

// helper function to find the longest balanced substring
int solve(string& s, char ch1, char ch2){
    int n = s.length();

    unordered_map<int, int> diffMap;

    int maxLen = 0;
    int cnt1=0, cnt2=0;
    for(int i=0; i<n; i++){
        if(s[i] != ch1 && s[i] != ch2){
            diffMap.clear();
            cnt1 = 0;
            cnt2 = 0;
            continue;
        }

        if(s[i] == ch1){
            cnt1++;
        }
        if(s[i] == ch2){
            cnt2++;
        }

        if(cnt1 == cnt2){
            maxLen = max(maxLen, cnt1+cnt2);
        }

        int diff = cnt1 - cnt2;
        if(diffMap.count(diff)){
            maxLen = max(maxLen, i-diffMap[diff]);
        }else{
            diffMap[diff] = i;
        }
    }
    return maxLen;
}

int longestBalanced(string s) {
    int n = s.length();

    int maxLen = 0;

    // step 1 : Case 1 - balanced substring using only 1 distinct character.
    int cnt = 1;   // for s[0]
    for(int i=1; i<n; i++){
        if(s[i] == s[i-1]){
            // extend current run
            cnt++;
        }else{
            // update maximum length
            maxLen = max(maxLen, cnt);
            // reset count
            cnt = 1;
        }
    }
    // capture last run
    maxLen = max(maxLen, cnt);

    // step 2 : Case 2 - balanced substring using 2 distinct characters.
    maxLen = max(maxLen, solve(s, 'a','b'));
    maxLen = max(maxLen, solve(s, 'a','c'));
    maxLen = max(maxLen, solve(s, 'b','c'));

    // step 3 : Case 3 - balanced substring using all 3 distinct characters.
    int cntA=0, cntB=0, cntC=0;
    unordered_map<string, int> diffMap;
    for(int i=0; i<n; i++){
        if(s[i] == 'a'){
            cntA++;
        }
        if(s[i] == 'b'){
            cntB++;
        }
        if(s[i] == 'c'){
            cntC++;
        }

        // check if all three counts are equal, the entire prefix is balanced
        if(cntA == cntB && cntA == cntC){
            maxLen = max(maxLen, cntA+cntB+cntC);
        }

        // encode the current imbalance state as a composite key
        int diffAB = cntA - cntB;
        int diffAC = cntA - cntC;
        string key = to_string(diffAB) + "_" + to_string(diffAC);
        
        if(diffMap.count(key)){
            maxLen = max(maxLen, i-diffMap[key]);
        }else{
            diffMap[key] = i;
        }
    }

    // step 4 - return length of the longest balanced substring 
    return maxLen;
}

int main(){
    // string s = "abbac";

    // string s = "aabcc";

    string s = "aba";
    cout<<longestBalanced(s);
    return 0;
}