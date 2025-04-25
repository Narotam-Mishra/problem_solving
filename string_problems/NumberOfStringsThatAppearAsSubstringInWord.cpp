
// Problem link - https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int numOfStrings(vector<string>& patterns, string word) {
    // step 1 - initialize counter
    int count = 0;

    // step 2 - iterate over each pattern
    for (const std::string& w : patterns) {
        // step 3 - check if word contains the pattern
        if (word.find(w) != std::string::npos) {
            count++;
        }
    }

    // step 4 - return count
    return count;
}

int main(){
    // vector<string> patterns = {"a","abc","bc","d"};
    // string word = "abc";

    // vector<string> patterns = {"a","b", "c"};
    // string word = "aaaaabbbbb";

    vector<string> patterns = {"a","a", "a"};
    string word = "ab";
    cout<<numOfStrings(patterns, word)<<endl;
    return 0;
}