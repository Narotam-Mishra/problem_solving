
// Problem link : https://leetcode.com/problems/count-pairs-of-similar-strings/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

#include<bits/stdc++.h>
using namespace std;

int similarPairs(vector<string>& words) {
    int pairsCnt = 0;
    map<string, int> countMap;

    for(string word : words){
        // normalize the word by converting it to a set of unique characters
        set<char> charSet(word.begin(), word.end());

        // convert the set back to a sorted string
        string sortedWord(charSet.begin(), charSet.end());

        // if this sortedWord has been seen before, increment pairs count
        if(countMap.find(sortedWord) != countMap.end()){
            pairsCnt += countMap[sortedWord];
        }

        // increment or set the count for this normalized form of the word
        countMap[sortedWord] = countMap[sortedWord] + 1;
    }
    // retrun similar pairs count 'pairsCnt'
    return pairsCnt;
}

int main(){
    // vector<string> words = {"aba","aabb","abcd","bac","aabc"};

    vector<string> words = {"aabb","ab","ba"};
    cout<<similarPairs(words);
    return 0;
}