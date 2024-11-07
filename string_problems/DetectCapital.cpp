
#include<bits/stdc++.h>
using namespace std;

string toUpper(const string& s){
    string upperStr = s;
    for(char &ch : upperStr){
        ch = toupper(ch);
    }
    return upperStr;
}

string toLower(const string& s){
    string lowerStr = s;
    for(char &ch : lowerStr){
        ch = tolower(ch);
    }
    return lowerStr;
}

bool detectCapitalUse(string word) {
    // check for 1st condition : if all letters are uppercase
    if(word == toUpper(word)) return true;

    // check for 2nd condition : if all letters are lowercase
    if(word == toLower(word)) return true;

    // check for 3rd condition : if only the first letter is uppercase and the rest are lowercase
    if(isupper(word[0]) && word.substr(1) == toLower(word.substr(1))){
        return true;
    }

    // if none of three conditions are true then return false
    return false;
}

int main(){
    // string word = "USA";

    // string word = "leetcode";

    string word = "FlaG";
    bool res = detectCapitalUse(word);
    res ? cout<<"true" : cout<<"false";
    return 0;
}