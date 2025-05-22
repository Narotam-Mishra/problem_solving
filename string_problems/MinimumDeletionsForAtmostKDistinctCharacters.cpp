
// Problem link - https://leetcode.com/problems/minimum-deletions-for-at-most-k-distinct-characters/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int minDeletion(string s, int k) {
    // step 1 - count frequency of each character
    vector<int> counts(26, 0);
    for (char ch : s) {
        counts[ch - 'a']++;
    }

    // step 2 - sort frequencies in ascending order
    sort(counts.begin(), counts.end());

    // step 3 - count number of distinct characters
    int d = 0;
    for (int i = 0; i < 26; i++) {
        if (counts[i] != 0) {
            d++;
        }
    }

    // step 4 - if already at most k distinct, no deletions needed
    if (d <= k)
        return 0;

    // step 5 - remove the least frequent characters
    int numOfDel = 0;
    int toRemove = d - k;
    for (int i = 0; i < 26 && toRemove > 0; i++) {
        if (counts[i] != 0) {
            numOfDel += counts[i];
            toRemove--;
        }
    }

    // step 6 - return minimum number of deletions
    return numOfDel;
}

int main(){
    // string s = "abc";
    // int k = 2;

    // string s = "aabb";
    // int k = 2;

    string s = "yyyzz";
    int k = 1;
    cout<<minDeletion(s, k)<<endl;
    return 0;
}