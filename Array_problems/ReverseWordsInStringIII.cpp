
// Problem link : https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    // create a string stream from the string s.
    istringstream iss(s);

    string word;
    string res;

    // process each word individually
    while(iss >> word){
        // reverse each word of sentence
        reverse(word.begin(), word.end());

        // add space between words
        if(!res.empty()){
            res += " ";
        }

        // add reversed word to result
        res += word;
    }
    return res;
}

int main(){
    string s = "Let's take LeetCode contest";
    cout<<reverseWords(s);
    return 0;
}