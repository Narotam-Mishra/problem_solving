
// Problem link : https://leetcode.com/problems/longest-common-prefix/description/

#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    // corner case: if the array is empty, return ""
    if (strs.empty()) return "";

    // start with the first string as the prefix
    string prefix = strs[0];

    // iterate on the string array
    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {
            // shorten the prefix until it's a prefix of strs[i]
            prefix = prefix.substr(0, prefix.length() - 1);
        }

        // if prefix becomes empty, return ""
        if (prefix.empty()) return "";
    }
    return prefix;
}


int main(){
    vector<string> strs = {"flower","flow","flight"};
    cout<<longestCommonPrefix(strs);
    return 0;
}