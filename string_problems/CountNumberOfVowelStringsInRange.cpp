
// Problem link - https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int vowelStrings(vector<string>& words, int left, int right) {
    // step 1 - initialize counter
    int count = 0;

    // step 2 - create a set of vowels
    unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u'};

    // step 3 - iterate through the specified range
    for(int i=left; i<=right; i++){
        string word = words[i];
        char first = word[0];
        char last = word[word.size() - 1];

        // step 4 - check if both first and last characters are vowels
        if(vowelSet.count(first) && vowelSet.count(last)){
            count++;
        }
    }

    // step 5 - return the count
    return count;
}

int main(){
    // vector<string> words = {"are", "amy", "u"};
    // int left = 0, right = 2;

    vector<string> words = {"hey","aeo","mu","ooo","artro"};
    int left = 1, right = 4;
    cout<<vowelStrings(words, left, right)<<endl;
    return 0;
}