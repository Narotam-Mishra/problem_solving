
// Problem link - https://leetcode.com/problems/find-maximum-number-of-string-pairs/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int maximumNumberOfStringPairs(vector<string>& words) {
    // step 1 - use a set to keep track of words we've seen but not yet paired
    unordered_set<string> seen;
    int count = 0;

    // step 2 - iterate through each word of words
    for(string word : words){

        // step 3 - reverse the current word
        string revStr = word;
        reverse(word.begin(), word.end());

        // step 4 - check if the revered word has been seen before
        if(seen.count(revStr)){
            count++;
        }else{
            // step 5 - if no match found, add to set
            seen.insert(word);
        }
    }

    // step 6 - return maximum number of reversed string pairs
    return count;
}

int main(){
    // vector<string> words = {"cd","ac","dc","ca","zz"};

    // vector<string> words = {"ab", "ba", "cc"};

    vector<string> words = {"aa", "ab"};
    cout<<maximumNumberOfStringPairs(words)<<endl;
    return 0;
}