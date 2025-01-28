
// Problem link : https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/description/?envType=problem-list-v2&envId=hash-table

#include<bits/stdc++.h>
using namespace std;

int maximumLengthSubstring(string s) {
    // step 1 - initialize variables
    int maxLen = 0;
    unordered_map<char, int> charMap;
    int start = 0;

    // step 2 - Iterate through each character in the sliding window
    for (int end = 0; end < s.length(); end++) {
        // add current character to our count
        char curChar = s[end];
        charMap[curChar]++;

        // step 3 - while window becomes invalid (any char appears more than twice)
        // shrink window from start
        while (charMap[curChar] > 2) {
            char startChar = s[start];
            charMap[startChar]--;
            start++;
        }

        // step 4 - update maximum length of substring
        maxLen = max(maxLen, end - start + 1);
    }

    // step 5 - return maximum length of substring
    return maxLen;
}

int main(){
    // string s = "bcbbbcba";

    string s = "aaaa";
    cout<<maximumLengthSubstring(s)<<endl;
    return 0;
}