
// Problem link - https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

// utility function to convert a word to its numerical value
int getNumericValue(string s){
    string numStr = "";

    for(char ch : s){
        int digit = ch - 'a';
        numStr += to_string(digit);
    }

    return stoi(numStr);
}

bool isSumEqual(string firstWord, string secondWord, string targetWord) {
    // step 1 - change input strings to corresponding numeric values
    int val1 = getNumericValue(firstWord);
    int val2 = getNumericValue(secondWord);
    int targetVal = getNumericValue(targetWord);

    // step 2 - check sum of numeric values are equal to corresponding numeric value of `targetWord`
    return (val1 + val2) == targetVal;
}

int main(){
    // string firstWord = "acb", secondWord = "cba", targetWord = "cdb";

    // string firstWord = "aaa", secondWord = "a", targetWord = "aab";

    string firstWord = "aaa", secondWord = "a", targetWord = "aaaa";
    bool res = isSumEqual(firstWord, secondWord, targetWord);
    res ? cout<<"true" : cout<<"false";
    return 0;
}