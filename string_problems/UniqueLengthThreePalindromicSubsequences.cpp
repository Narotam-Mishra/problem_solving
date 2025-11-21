
// Problem link - https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/?envType=daily-question&envId=2025-11-21

#include<bits/stdc++.h>
using namespace std;

int countPalindromicSubsequence(string s) {
    int n = s.length();

    // step 1 - find all unique characters in input s
    unordered_set<char> letters;
    for(int i=0; i<n; i++){
        letters.insert(s[i]);
    }

    // store final result in res
    int res = 0;

    // step 2 - find first and last occurrence of each character
    for(char ch : letters){
        int firstIndex = -1;
        int lastIndex = -1;

        for(int i=0; i<n; i++){
            if(s[i] == ch){
                if(firstIndex == -1){
                    firstIndex = i;
                }
                lastIndex = i;
            }
        }

        // step 3 - find all unique characters between first and last occurance
        unordered_set<char> set;
        for(int mid = firstIndex+1; mid<=lastIndex-1; mid++){
            set.insert(s[mid]);
        }
        // calculate result, res
        res += set.size();
    }

    // step 4 - return final result, res
    return res;
}

int main(){
    // string s = "aabca";

    // string s = "adc";

    string s = "bbcbaba";
    cout<<countPalindromicSubsequence(s);
    return 0;
}