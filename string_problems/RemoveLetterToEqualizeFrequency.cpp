
// Problem link - https://leetcode.com/problems/remove-letter-to-equalize-frequency/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

bool equalFrequency(string word) {
    // step 1 - store frequency of each character in frequency array `frq`
    vector<int> frq(26, 0);
    for (char ch : word) {
        frq[ch - 'a']++;
    }

    // step 2 - try removing each frequency once
    for (int i = 0; i < 26; i++) {
        // skip 0-frequency
        if (frq[i] == 0) {
            continue;
        }

        // step 3 - remove frequency once
        frq[i]--;

        // step 4 - collect non-zero frequency once
        unordered_set<int> frqSet;
        for (int f : frq) {
            if (f > 0) {
                frqSet.insert(f);
            }
        }

        // step 5 - check if all frquencies are same, then return true immediately
        if (frqSet.size() == 1)
            return true;

        // step 6 - restore original frquency
        frq[i]++;
    }

    // step 7 - return false if conditions not met
    return false;
}

int main(){
    // string word = "abcc";

    string word = "aacc";
    bool res = equalFrequency(word);
    res ? cout<<"true" : cout<<"false";
    return 0;
}