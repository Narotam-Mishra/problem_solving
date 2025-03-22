
#include<bits/stdc++.h>
using namespace std;

bool isValid(string word){
    // check all conditions using if else
    if(word.length() < 3) return false;
    bool hasVowel = false, hasConsonant = false;
    
    // iterate on each character of word
    for(int i=0; i<word.length(); i++){
        char ch = word[i];
        if((ch>='a'&& ch<='z') || (ch>='A' && ch<='Z')){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
                hasVowel = true;
            }else{
                hasConsonant = true;
            }
        }else if(ch>='0' && ch<='9'){
            continue;
        }else{
            return false;
        }
    }

    return hasVowel && hasConsonant;
}

bool isValid1(string word){
    // step 1: check if the length is at least 3
    if (word.length() < 3) return false;

    // step 2: ensure only valid characters (letters and digits)
    regex validPattern("^[a-zA-Z0-9]+$");
    if (!regex_match(word, validPattern)) return false;

    // step 3: define vowels and check conditions
    string vowels = "aeiouAEIOU";
    bool hasVowel = false, hasConsonant = false;

    // step 4: iterate through the word to check for vowels and consonants
    for (char ch : word) {
        if (vowels.find(ch) != string::npos) {
            // it's a vowel
            hasVowel = true; 
        } else if (!isdigit(ch)) {
            // if it's not a digit, it's a consonant 
            hasConsonant = true;
        }

        // step 5 - if both conditions are met, return true early
        if (hasVowel && hasConsonant) {
            return true;
        }
    }

    // step 5: return false if either vowels or consonants are missing
    return false;
}

int main(){
    string word = "234Adas";

    // string word = "b3";

    // string word = "a3$e";
    bool res = isValid(word);
    res ? cout<<"true" : cout<<"false";    
    return 0;
}