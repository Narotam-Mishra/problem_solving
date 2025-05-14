
// Problem link - https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

bool checkAlmostEquivalent(string word1, string word2) {
    // step 1 - using frequency array `frq`
    vector<int> frq(26, 0);

    // step 2 - count frequency of characters in word1
    for (char ch : word1) {
        frq[ch - 'a']++;
    }

    // step 3 - subtract frequency for characters in word2
    for (char ch : word2) {
        frq[ch - 'a']--;
    }

    // step 4 - check if absolute difference is more than 3
    for (int i = 0; i < 26; i++) {
        if (abs(frq[i]) > 3) {
            return false;
        }
    }

    // step 5 - return true if all diffs are within 3
    return true;
}

int main(){
    // string word1 = "aaaa", word2 = "bccb";

    // string word1 = "abcdeef", word2 = "abaaacc";

    string word1 = "cccddabba", word2 = "babababab";
    bool res = checkAlmostEquivalent(word1, word2);
    res ? cout<<"true" : cout<<"false";
    return 0;
}