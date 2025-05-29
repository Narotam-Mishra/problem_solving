
// Problem link - https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/description/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

// utility function to check for match
bool isMatch(const string &s1, const string &s2, int i){
    return (s1[i] == s2[i] && s1[i+2] == s2[i+2]) || (s1[i] == s2[i+2] && s1[i+2] == s2[i]);
}

bool canBeEqual(string s1, string s2) {
    // edge case:
    if(s1 == s2) return true;

    // step 1 - check for match
    return isMatch(s1, s2, 0) && isMatch(s1, s2, 1);
}

int main(){
    // string s1 = "abcd", s2 = "cdab";

    string s1 = "abcd", s2 = "dacb";
    bool res = canBeEqual(s1, s2);
    res ? cout<<"true" : cout<<"false";
}