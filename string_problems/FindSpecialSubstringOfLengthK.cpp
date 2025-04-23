
// Problem link - https://leetcode.com/problems/find-special-substring-of-length-k/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

bool hasSpecialSubstring(string s, int k) {
    // find string length
    int n = s.length();

    // edge cases:
    if (n < k)
        return false;

    // step 1 - iterate through string in chunks
    for (int i = 0; i <= n - k;) {
        char currChar = s[i];
        int j = i;

        // step 2 - find end of the current run of the same character
        while (j < n && s[j] == currChar) {
            j++;
        }

        // find length of current substring
        int runLength = j - i;

        // step 3 - if we found a run of exactly length k
        if (runLength == k) {
            // check the character before (if exist)
            bool beforeValid = (i == 0) || (s[i - 1] != currChar);

            // check the character after (if exist)
            bool afterValid = (j == n) || (s[j] != currChar);

            if (beforeValid && afterValid) {
                return true;
            }
        }

        // move to next character after this run
        i = j;
    }

    // step 4 - return false if none of the conditions satisfy
    return false;
}

int main(){
    // string s = "aaabaaa";
    // int k = 3;

    string s = "abc";
    int k = 2;
    bool res = hasSpecialSubstring(s, k);
    res ? cout<<"true" : cout<<"false";
    return 0;
}