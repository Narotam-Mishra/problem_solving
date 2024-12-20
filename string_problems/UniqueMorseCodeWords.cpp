
#include<bits/stdc++.h>
using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {
    // step 1 : define the Morse code lookup table
    vector<string> morseCodeTable = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--", "--.."
    };

    // step 2 : initialize a Set to store unique transformations
    unordered_set<string> tSet;

    // step 3 : iterate through each word in the words array
    for (string word : words) {
        // initialize an empty string to build the Morse code for the word
        string morseWord;

        // convert each letter in the word to its Morse code equivalent
        for (char ch : word) {
            // append the Morse code of the character
            morseWord += morseCodeTable[ch - 'a'];
        }

        // add the transformation to the HashSet
        tSet.insert(morseWord);
    }

    // step 4 : return the size of the Set (number of unique transformations)
    return tSet.size();
}

int main(){
    // vector<string> words = {"gin","zen","gig","msg"};

    vector<string> words = {"a"};
    cout<<uniqueMorseRepresentations(words)<<endl;
    return 0;
}