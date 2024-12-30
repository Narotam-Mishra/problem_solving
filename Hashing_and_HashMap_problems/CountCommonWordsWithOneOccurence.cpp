
#include<bits/stdc++.h>
using namespace std;

int countWords(vector<string>& words1, vector<string>& words2) {
    // step 1 : initialize hash maps to store the frequency of each word
    unordered_map<string, int> wordMap1;
    unordered_map<string, int> wordMap2;

    // step 2 : count each word frequency in words1
    for(const string& word : words1) {
        wordMap1[word]++;
    }

    // step 3 : count each word frequency in words2
    for(const string& word : words2) {
        wordMap2[word]++;
    }

    // step 4 : Compare counts and count matches
    int count = 0;
    for(const auto& entry : wordMap1) {
        if(entry.second == 1 && wordMap2[entry.first] == 1){
            count++;
        }
    }

    // step 5 : return count
    return count;
}

int main(){
    // vector<string> words1 = {"leetcode","is","amazing","as","is"};
    // vector<string> words2 = {"amazing","leetcode","is"};

    // vector<string> words1 = {"b","bb","bbb"};
    // vector<string> words2 = {"a","aa","aaa"};

    vector<string> words1 = {"a","ab"};
    vector<string> words2 = {"a","a","a","ab"};
    cout<<countWords(words1, words2)<<endl;
    return 0;
}