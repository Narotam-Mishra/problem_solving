
// Problem link - https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int countPrefixSuffixPairs(vector<string>& words) {
    // step 1 - initialize the count
    int count = 0;

    // step 2 - iterate on each word of words
    for (int i = 0; i < words.size(); i++) {
        // step 3 - iterate on each pair of words
        for (int j = i + 1; j < words.size(); j++) {
            // step 4 - check if prefix and suffix exist
            if (words[j].substr(0, words[i].size()) == words[i] &&
                words[j].substr(words[j].size() - words[i].size()) == words[i]) {
                // increment the counter
                count++;
            }
        }
    }

    // step 5 - return count
    return count;
}

int main(){
    // vector<string> words = {"a","aba","ababa","aa"};

    // vector<string> words = {"pa","papa","ma","mama"};

    vector<string> words = {"abab", "ab"};
    cout<<countPrefixSuffixPairs(words)<<endl;
    return 0;
}
