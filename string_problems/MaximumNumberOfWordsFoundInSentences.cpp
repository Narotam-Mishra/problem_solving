
// Problem link - https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

// utility function to count words in sentence
int countWords(const string& sentence){
    istringstream stream(sentence);
    string word;
    int count = 0;

    while(stream >> word){
        count++;
    }

    return count;
}

int mostWordsFound(vector<string>& sentences) {
    // step 1 - initialize variable to count maximum number of words
    int maxWords = 0;

    // step 2 - iterate on each sentence of `sentences`
    for(string sentence : sentences){
        // step 3 - count number of words in each sentence
        int count = countWords(sentence);

        // step 4 - update maximum number of words
        maxWords = max(maxWords, count);
    }

    // step 5 - return maximum number of words `maxWords`
    return maxWords;
}

int main(){
    // vector<string> sentences = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};

    vector<string> sentences = {"please wait", "continue to fight", "continue to win"};
    cout<<mostWordsFound(sentences)<<endl;
    return 0;
}