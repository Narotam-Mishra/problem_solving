
// Problem link - https://leetcode.com/problems/count-vowel-substrings-of-a-string/?envType=problem-list-v2&envId=hash-table

#include<bits/stdc++.h>
using namespace std;

int countVowelSubstrings(string word) {
    // Map to store the last occurrence index of each vowel
    unordered_map<char, int> obj = { {'a', -1}, {'e', -1}, {'i', -1}, {'o', -1}, {'u', -1} };

    int count = 0; // Counter for valid vowel substrings
    int left = 0; // Left pointer of the window

    for (int i = 0; i <= word.length(); i++) {
        if (i < word.length() && obj.find(word[i]) != obj.end()) {
            // Update the last occurrence index of the current vowel
            obj[word[i]] = i;

            // Find the minimum index among the last occurrences of all vowels
            int minIndex = INT_MAX;
            for (auto& pair : obj) {
                minIndex = min(minIndex, pair.second);
            }

            // If all vowels are present in the current window, count valid substrings
            if (minIndex >= 0 && minIndex >= left) {
                count += (minIndex - left) + 1;
            }
        }
        else {
            // If a non-vowel is encountered, reset the window
            left = i + 1;
        }
    }
    return count;
}

int main(){
    // string word = "aeiouu";

    // string word = "unicornarihan";

    string word = "cuaieuouac";
    cout<<countVowelSubstrings(word)<<endl;
    return 0;
}