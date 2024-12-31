
#include<bits/stdc++.h>
using namespace std;

vector<string> uncommonFromSentences(string s1, string s2) {
    // step 1 - split the sentences into words and combine them
    string combined = s1 + " " + s2;
    istringstream iss(combined);
    vector<string> words;
    string word;
    while(iss >> word){
        words.push_back(word);
    }

    // step 2 - create a frequency map to count occurrences of each word
    unordered_map<string, int> wordMap;
    for(const string& word : words){
        wordMap[word]++;
    }

    // step 3 - find uncommon words (words with a frequency of exactly 1)
    vector<string> res;
    for(const auto& entry : wordMap){
        if(entry.second == 1){
            res.push_back(entry.first);
        }
    }

    // step 4 - Return the result array `res`
    return res;
}

void printVector(vector<string>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout<<vec[i];
        if (i < vec.size() - 1) {
            cout<<",";
        }
    }
    cout<< "]" <<endl;
}

int main(){
    // string s1 = "this apple is sweet", s2 = "this apple is sour";

    string s1 = "apple apple", s2 = "banana";
    vector<string> res = uncommonFromSentences(s1, s2);
    printVector(res);
    return 0;
}