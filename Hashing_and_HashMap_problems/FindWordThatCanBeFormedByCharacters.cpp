
// Problem link : https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

#include<bits/stdc++.h>
using namespace std;

int countCharacters(vector<string>& words, string chars) {
    // step 1 : create a frequency map for `chars`
    unordered_map<char, int> charCount;
    for (char ch : chars) {
        charCount[ch]++;
    }

    // to store the sum of lengths of "good" strings
    int totalLengthofGoodStr = 0;

    // step 2 : iterate through each word in `words`
    for (string word : words) {
        // create a frequency map for the current word
        unordered_map<char, int> wordCount;
        for (char ch : word) {
            wordCount[ch]++;
        }

        // step 3 : check if the word can be formed using `chars`
        bool canBeFormed = true;
        for (char ch : word) {
            if (charCount.find(ch) == charCount.end() || wordCount[ch] > charCount[ch]) {
                // not enough characters available in `chars`
                canBeFormed = false;
                break;
            }
        }

        // step 4 : if the word is "good," add its length to `totalLengthofGoodStr`
        if (canBeFormed) {
            totalLengthofGoodStr += word.length();
        }
    }
    return totalLengthofGoodStr;
}

int main(){
    // vector<string> words = {"cat","bt","hat","tree"};
    // string chars = "atach";

    vector<string> words = {"hello","world","leetcode"};
    string chars = "welldonehoneyr";
    cout<<countCharacters(words, chars)<<endl;
    return 0;
}