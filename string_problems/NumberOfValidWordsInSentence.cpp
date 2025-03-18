
// Problem link - https://leetcode.com/problems/number-of-valid-words-in-a-sentence/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int countValidWords(string sentence) {
    // step 1 - regular expression to match a valid word
    regex validWordPattern("^[a-z]+(-[a-z]+)?[\\.!,]?$");

    // step 2 - regular expression to match a token that is exactly one punctuation mark
    regex punctuationPattern("^[\\.!,]$");

    // step 3 - use istringstream to tokenize the sentence by whitespace
    istringstream tokenStream(sentence);
    string token;
    int validWordCount = 0;

    // step 4 - process each token from the stream
    while(tokenStream >> token){
        if(regex_match(token, validWordPattern) || regex_match(token, punctuationPattern)){
            validWordCount++;
        }
    }

    // step 5 - return valid word count
    return validWordCount;
}

int main(){
    // string str = "cat and  dog";

    // string sentence = "!this  1-s b8d!";

    string sentence = "alice and  bob are playing stone-game10";
    cout<<countValidWords(sentence)<<endl;
    return 0;
}