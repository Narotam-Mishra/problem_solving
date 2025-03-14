
// Problem link - https://leetcode.com/problems/truncate-sentence/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

string truncateSentence(string s, int k) {
    // step 1 - split the sentence into words
    stringstream ss(s);
    string word;
    vector<string> words;
    while (ss >> word) {
        words.push_back(word);
    }

    // step 2 - join the first k words with a space
    string truncated;
    for (int i = 0; i < k; i++) {
        if (i > 0) {
            truncated += " ";
        }
        truncated += words[i];
    }

    // step 3 - return truncated string
    return truncated;
}

int main(){
    // string s = "Hello how are you Contestant";
    // int k = 4;

    // string s = "What is the solution to this problem";
    // int k = 4;

    string s = "chopper is not a tanuki";
    int k = 5;
    cout<<truncateSentence(s, k)<<endl;
    return 0;
}