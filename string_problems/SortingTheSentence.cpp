
// Problem link : https://leetcode.com/problems/sorting-the-sentence/description/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

string sortSentence(string s) {
    // step 1 - split the string into words
    vector<string> words;
    string word;
    for(char ch : s){
        if(ch == ' '){
            words.push_back(word);
            word.clear();
        }else{
            word += ch;
        }
    }
    // add the last word
    words.push_back(word);

    // create a vector to store words with their positions
    vector<pair<string, int>> wordList;

    // step 2 - find word and its position
    for(string word : words){
        // extract the position from last character of word
        int position = word.back() - '0';

        // extract actual word by removing the last character
        string actualWord = word.substr(0, word.size() - 1);

        // add the word and its position to the list
        wordList.push_back({actualWord, position});
    }

    // step 3 - sort the list based on position
    sort(wordList.begin(), wordList.end(), [](pair<string, int> a, pair<string, int> b){
        return a.second < b.second;
    });

    // step 4 - create the final sentence
    string sortedWords;
    for(const auto& pair : wordList){
        sortedWords += pair.first + " ";
    }

    // step 5 - remove the last space and return the final sentence
    sortedWords.pop_back();
    return sortedWords;
}

int main(){
    // string str = "is2 sentence4 This1 a3";

    string str = "Myself2 Me1 I4 and3";
    cout<<sortSentence(str)<<endl;
    return 0;
}