
#include<bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s) {
    istringstream ss(s);
    vector<string> words;
    string word;

    // split the string `s` into words
    while (ss >> word) {
        words.push_back(word);
    }

    // corner case: if pattern length and words length don't match, immediately
    // return false
    if (pattern.length() != words.size())
        return false;

    // maps to keep track of pattern to word and word to pattern mappings
    unordered_map<char, string> patternToWord;
    unordered_map<string, char> wordToPattern;

    // iterate through each letter in the pattern and corresponding word in words
    for (int i = 0; i < pattern.length(); i++) {
        char letter = pattern[i];
        string word = words[i];

        // check if the letter in the pattern already maps to a different word
        if (patternToWord.count(letter)) {
            if (patternToWord[letter] != word) {
                // conflict: letter is mapped to a different word
                return false;
            }
        }
        else {
            // map the letter to the current word
            patternToWord[letter] = word;
        }

        // check if the word is already mapped to a different letter in the pattern
        if (wordToPattern.count(word)) {
            if (wordToPattern[word] != letter) {
                // conflict: word is mapped to a different letter
                return false;
            }
        }
        else {
            // map the word to the current letter
            wordToPattern[word] = letter;
        }
    }
    // if all mappings are consistent, return true
    return true;
}

int main(){
    // string pattern = "abba";
    // string s = "dog cat cat dog";

    // string pattern = "abba";
    // string s = "dog cat cat fish";

    string pattern = "abba";
    string s = "dog constructor constructor dog";
    bool res = wordPattern(pattern, s);
    res ? cout<<"true" : cout<<"false";
    return 0;
}