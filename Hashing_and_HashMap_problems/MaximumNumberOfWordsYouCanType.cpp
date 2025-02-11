
#include<bits/stdc++.h>
using namespace std;

int canBeTypedWords(string text, string brokenLetters) {
    // step 1: change brokenLetters into an unordered_set for quick lookup
    unordered_set<char> brokenSet(brokenLetters.begin(), brokenLetters.end());

    // step 2: split text into words using stringstream
    stringstream ss(text);
    string word;
    int count = 0;

    // step 3: iterate over each word
    while (ss >> word) {
        bool canType = true;

        // step 4: check if the word contains any broken letters
        for (char ch : word) {
            if (brokenSet.count(ch)) {
                canType = false;
                // no need to check further
                break; 
            }
        }

        // step 5: if the word can be typed, increment count
        if (canType) count++;
    }

    // step 6 - return required count
    return count;
}

int main(){
    // string text = "hello world", brokenLetters = "ad";

    // string text = "leet code", brokenLetters = "lt";

    string text = "leet code", brokenLetters = "e";
    cout<<canBeTypedWords(text, brokenLetters)<<endl;
    return 0;
}