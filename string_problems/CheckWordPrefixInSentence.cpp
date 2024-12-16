
#include<bits/stdc++.h>
using namespace std;

int isPrefixOfWord(string sentence, string searchWord) {
    // step 1 : use a stringstream to split the sentence into words
    istringstream stream(sentence);
    string word;
    int index = 0;

    // step 2 : loop through each word and check if searchWord is a prefix
    while (stream >> word) {
        // increment the word index (1-based)
        index++;

        // check if the current word starts with the searchWord
        if (word.find(searchWord) == 0) {
            // return the 1-indexed position (i + 1)
            return index;
        }
    }

    // step 3 : if no match is found, return -1
    return -1;
}

int main(){
    // string sentence = "i love eating burger", searchWord = "burg";

    // string sentence = "this problem is an easy problem", searchWord = "pro";

    string sentence = "i am tired", searchWord = "you";
    cout<<isPrefixOfWord(sentence, searchWord)<<endl;
    return 0;
}