
// Problem link : https://leetcode.com/problems/count-the-number-of-consistent-strings/description/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

int countConsistentStrings(string allowed, vector<string>& words) {
    // convert 'allowed' string into a Set for efficient lookup of allowed characters
    unordered_set<char> allowedSet(allowed.begin(), allowed.end());

    int consistentCount = 0;

    // iterate over each word in the 'words' array
    for(string word : words){
        bool isConsistent = true;
        // check each character in the word
        for(char ch : word){
            if(allowedSet.find(ch) == allowedSet.end()){
                // if character is not allowed, mark the word as inconsistent
                isConsistent = false;
                break;
            }
        }

        // if the word is consistent, increment the counter
        if(isConsistent){
            consistentCount++;
        }
    }
    return consistentCount;
}

int main(){
    // string allowed = "ab";
    // vector<string> words = {"ad","bd","aaab","baa","badab"};

    string allowed = "abc";
    vector<string> words = {"a","b","c","ab","ac","bc","abc"};
    cout<<countConsistentStrings(allowed, words);
    return 0;
}