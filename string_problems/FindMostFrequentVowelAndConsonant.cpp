
// Problem link - https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int maxFreqSum(string s) {
    // step 1 - use frquency array to store frquency of each character in `s`
    vector<int> frq(26, 0);

    // step 2 - iterate on each character of `s` and store its frquency
    for (char ch : s) {
        frq[ch - 'a']++;
    }

    // step 3 - find maximum vowel and consonants frquency
    int maxFrqV = 0, maxFrqC = 0;
    for (int i = 0; i < 26; i++) {
        if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20) {
            maxFrqV = max(maxFrqV, frq[i]);
        }
        else {
            maxFrqC = max(maxFrqC, frq[i]);
        }
    }

    // step 4 - return sum of maximum vowel and consonant frequency
    return maxFrqC + maxFrqV;
}

int main(){
    // string s = "successes";

    string s = "aeiaeia";
    cout<<maxFreqSum(s)<<endl;
    return 0;
}