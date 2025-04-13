
// Problem link - https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    // step 1 - join all strings from word1 and word2
    string s1, s2;

    for(const string& w : word1){
        s1 += w;
    }

    for(const string& w : word2){
        s2 += w;
    }

    // step 2 - compare the final concatenated strings
    return s1 == s2;
}

int main(){
    // vector<string> word1 = {"ab", "c"};
    // vector<string> word2 = {"a", "bc"};

    // vector<string> word1 = {"a", "cb"};
    // vector<string> word2 = {"ab", "c"};

    vector<string> word1 = {"abc", "d", "defg"};
    vector<string> word2 = {"abcddefg"};
    bool res = arrayStringsAreEqual(word1, word2);
    res ? cout<<"true" : cout<<"false";
    return 0;
}