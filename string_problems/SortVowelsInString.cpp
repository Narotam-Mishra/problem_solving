
// Problem link - https://leetcode.com/problems/sort-vowels-in-a-string/description/?envType=daily-question&envId=2025-09-11

#include<bits/stdc++.h>
using namespace std;

// helper function to check if character is vowel or not
bool isVowel(char ch){
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

string sortVowels(string s) {
    // step 1 - count frequency of each vowel in input string `s`
    unordered_map<char, int> vowelMap;
    for(char &ch : s){
        if(isVowel(ch)){
            vowelMap[ch]++;
        }
    }

    // step 2 - define vowels in ASCII sorted order
    string vowels = "AEIOUaeiou";

    // pointer to track current position in sorted vowels string
    int j = 0;

    // step 3 - replace vowels in input string `s` with help of sorted vowels
    for(int i=0; i<s.length(); i++){
        if(isVowel(s[i])){
            // find next available vowel in sorted order
            while(vowelMap[vowels[j]] == 0){
                // skip vowels that are not present in input string
                j++;
            }

            // replace current vowel with the smallest available vowel
            s[i] = vowels[j];

            // decrese used vowel count in `vowelMap`
            vowelMap[vowels[j]]--;
        }
    }

    // step 4 - return modified string `s`
    return s;
}

int main(){
    // string s = "lEetcOde";

    string s = "lYmpH";
    cout<<sortVowels(s);
    return 0;
}

