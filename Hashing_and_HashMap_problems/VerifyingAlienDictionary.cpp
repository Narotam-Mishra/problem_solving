
#include<bits/stdc++.h>
using namespace std;

bool isAlienSorted(vector<string>& words, string order) {
    // step 1 - create a map to store letter to index mapping from alien alphabet
    unordered_map<char, int> orderMap;
    for (int i = 0; i < order.size(); i++) {
        orderMap[order[i]] = i;
    }

    // step 2 - compare adjacent words
    for (int i = 0; i < words.size() - 1; i++) {
        string word1 = words[i];
        string word2 = words[i + 1];

        // get length of shorter word
        int minLength = min(word1.length(), word2.length());
        bool isDifferent = false;

        // compare the two words character by character
        for (int j = 0; j < minLength; j++) {
            int weight1 = orderMap[word1[j]];
            int weight2 = orderMap[word2[j]];

            // if characters are different
            if (weight1 != weight2) {
                // if current character in word1 has higher weight,
                // then words are not sorted
                if (weight1 > weight2) {
                    return false;
                }

                // mark that we found a difference and break
                isDifferent = true;
                break;
            }
        }

        // if no difference found in common prefix and word1 is longer,
        // then words are not sorted (e.g., "apple" vs "app")
        if (!isDifferent && word1.length() > word2.length()) {
            return false;
        }
    }

    // step 3 - if all pairs are in order, return true
    return true;
}

int main(){
    // vector<string> words = {"hello","leetcode"};
    // string order = "hlabcdefgijkmnopqrstuvwxyz";

    // vector<string> words = {"word","world","row"};
    // string order = "worldabcefghijkmnpqstuvxyz";

    vector<string> words = {"apple","app"};
    string order = "abcdefghijklmnopqrstuvwxyz";
    bool res = isAlienSorted(words, order);
    res ? cout<<"true" : cout<<"false";
    return 0;
}