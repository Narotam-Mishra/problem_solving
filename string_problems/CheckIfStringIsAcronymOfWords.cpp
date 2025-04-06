
// Problem link - https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

bool isAcronym(vector<string>& words, string s) {
    // edge case:
    if(s.size() != words.size()) return false;

    // step 1 - check first characters
    for(int i=0; i<s.size(); i++){
        if(s[i] != words[i][0]){
            return false;
        }
    }

    // step 2 - return true if above condition is satified
    return true;
}

int main(){
    // vector<string> words = {"alice","bob","charlie"};
    // string s = "abc";

    // vector<string> words = {"an","apple"};
    // string s = "a";

    vector<string> words = {"never","gonna","give","up","on","you"};
    string s = "ngguoy";
    bool res = isAcronym(words, s);
    res ? cout<<"true" : cout<<"false";
    return 0;
}