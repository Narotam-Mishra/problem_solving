
// Problem link - https://leetcode.com/problems/weighted-word-mapping/description/?envType=daily-question&envId=2026-06-13

#include<bits/stdc++.h>
using namespace std;

string mapWordWeights(vector<string>& words, vector<int>& weights) {
    // result string to collect mapped characters for each word
    string res = "";

    // step 1 - process each word independently
    for (string word : words) {
        // step 2 - compute total weight of current word by summing per-letter weights
        int sum = 0;
        for (int i = 0; i < (int)word.size(); i++) {
            // step 3 - map character 'a'..'z' to index 0..25 and add corresponding weight
            sum += weights[word[i] - 'a'];
        }

        // step 4 - reduce the sum modulo 26 to keep within alphabet range
        int sumMod = sum % 26;

        // step 5 - determine mapped character index:
        // idx = 26 - sumMod - 1 converts sumMod to 0-based index from 'a'.
        int idx = 26 - sumMod - 1;

        // step 6 - convert index back to a lowercase letter
        char ch = 'a' + idx;

        // step 7 - append mapped character for this word
        res += ch;
    }

    // step 8 - return the concatenation of mapped characters for all words
    return res;
}

int main(){
    // vector<string> words = {"abcd", "def", "xyz"};
    // vector<int> weights = {5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2};

    // vector<string> words = {"a", "b", "c"};
    // vector<int> weights = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

    vector<string> words = {"abcd"};
    vector<int> weights = {7,5,3,4,3,5,4,9,4,2,2,7,10,2,5,10,6,1,2,2,4,1,3,4,4,5};
    cout<<mapWordWeights(words, weights);
    return 0;
}