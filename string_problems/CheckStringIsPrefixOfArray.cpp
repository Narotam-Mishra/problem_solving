
#include<bits/stdc++.h>
using namespace std;

bool isPrefixString(string s, vector<string>& words) {
    // initialize an empty string to build the prefix incrementally
    string prefix = "";

    // step 1 - iterate through the words array
    for (string word : words) {
        // step 2 - add the current word to the prefix
        prefix += word;

        // step 3 - check if the current prefix matches `s`
        if (prefix == s) {
            return true;
        }

        // step 4 - if the prefix length exceeds `s` or diverges from it, return false
        if (prefix.length() > s.length() || s.find(prefix) != 0) {
            return false;
        }
    }

    // step 5 - if we complete the loop and no match is found, return false
    return false;
}

int main(){
    // string s = "iloveleetcode";
    // vector<string> words = {"i","love","leetcode","apples"};

    string s = "iloveleetcode";
    vector<string> words = {"apples", "i","love","leetcode"};
    bool res = isPrefixString(s, words);
    res ? cout<<"true" : cout<<"false"<<endl;
    return 0;
}