
// Problem link - https://leetcode.com/problems/substring-matching-pattern/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

bool hasMatch(string s, string p) {
    // step 1 - split the string pattern `p` from '*'
    int index = p.find('*');
    string prefix = p.substr(0, index);
    string suffix = p.substr(index+1);

    // step 2 - find the first occurrence of prefix in s
    int prefixIndex = s.find(prefix);

    // step 3 - if prefix not found then return false right away
    if(prefixIndex == string::npos){
        return false;
    }

    // step 4 - check if suffix exist after prefixIndex
    int suffixIndex = s.find(suffix, prefixIndex + prefix.size());

    // step 5 - suffix must appear after prefix for valid match, otherwise return false
    return suffixIndex != string::npos;
}

int main(){
    // string s = "leetcode", p = "ee*e";

    // string s = "car", p = "c*v";

    string s = "luck", p = "u*";
    bool res = hasMatch(s, p);
    res ? cout<<"true" : cout<<"false";
    return 0;
}