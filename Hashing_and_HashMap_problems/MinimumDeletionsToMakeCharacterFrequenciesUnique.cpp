
// Problem link - https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

#include<bits/stdc++.h>
using namespace std;

int minDeletions(string s) {
    // step 1 - count frquency of each character of `s`
    vector<int> frqMap(26, 0);
    for(char ch : s){
        frqMap[ch - 'a']++;
    }

    // step 2 - use set to store used frequencies to ensure uniqueness
    unordered_set<int> usedFrequencies;
    int deletionCount = 0;

    // step 3 - iterate on each frquency values
    for(int frq : frqMap){
        // step 4 - reduce frequency until it's unique (or zero)
        while(frq > 0 && usedFrequencies.count(frq)){
            frq--;
            deletionCount++;
        }

        // step 5 - if `frq > 0`, add it to the set of used frquencies
        if(frq > 0){
            usedFrequencies.insert(frq);
        }
    }

    // step 6 - return minimum deletion needed to make good string
    return deletionCount;
}

int main(){
    // string s = "aab";

    // string s = "aaabbbcc";

    string s = "ceabaacb";
    cout<<minDeletions(s);
    return 0;
}