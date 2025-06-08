
// Problem link - https://leetcode.com/problems/permutation-in-string/

#include<bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
    // edge case: if s1 is longer than s2, no permutation can exist
    if(s1.size() > s2.size()){
        return false;
    }

    // step 1 - using fixed size frequency arrays to count frquencies
    vector<int> pCount(26, 0);
    vector<int> windowCount(26, 0);

    // step 2 - count `s1` pattern frquencies
    for (char ch : s1) {
        pCount[ch - 'a']++;
    }

    // step 3 - calculate window size
    int windowSize = s1.size();

    // step 4 - initialize first window
    for (int i = 0; i < windowSize; i++) {
        windowCount[s2[i] - 'a']++;
    }

    // step 5 - check first window and return true if it matched
    if (pCount == windowCount) {
        return true;
    }

    // step 6 - slide through each the window
    for (int i = windowSize; i < s2.length(); i++) {
        // add character's frequency to window
        windowCount[s2[i] - 'a']++;

        // remove character's frequency from window
        windowCount[s2[i - windowSize] - 'a']--;

        // check current window and return true if it matched
        if (pCount == windowCount) {
            return true;
        }
    }

    // step 8 - return false as sliding through window is completed
    return false;
}

int main(){
    // string s1 = "ab", s2 = "eidbaooo";

    string s1 = "ab", s2 = "eidboaoo";
    bool res = checkInclusion(s1, s2);
    res ? cout<<"true" : cout<<"false";
    return 0;
}