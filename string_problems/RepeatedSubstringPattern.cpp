
// Problem link : https://leetcode.com/problems/repeated-substring-pattern/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

#include<bits/stdc++.h>
using namespace std;

bool repeatedSubstringPattern(string s) {
    // handle edge case:
    if (s.empty()) {
        return false;
    }

    // step 1 : concatenate the string with itself
    string conStr = s + s;

    // step 2 : remove the first and last characters of the concatenated string
    string modStr = conStr.substr(1, conStr.size() - 2);

    // step 3 : check if the original string is a substring of the modified concatenated string
    return modStr.find(s) != string::npos;
}

int main(){
    // string str = "abab";

    // string str = "aba";

    string str = "abcabcabcabc";
    bool res = repeatedSubstringPattern(str);
    res ? cout<<"true" : cout<<"false"<<endl;
    return 0;
}