
// Problem link : https://leetcode.com/problems/is-subsequence/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

#include<bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t) {
    // pointer for source string 's'
    int i = 0;

    // pointer for target string 't'
    int j = 0;

    // traverse through string 't'
    while (j < t.size()) {
        // if characters match, move the pointer i for s
        if (i < s.length() && s[i] == t[j]) {
            i++;
        }

        // move the pointer j for t in each iteration
        j++;
    }
    // if we finished the loop and haven't matched all characters in s
    return i == s.length();
}

int main(){
    // string s = "abc", t = "ahbgdc";
    string s = "axc", t = "ahbgdc";
    bool res = isSubsequence(s, t);
    res ? cout<<"true" : cout<<"false";
    return 0;
}