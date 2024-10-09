
// Problem link : https://leetcode.com/problems/first-letter-to-appear-twice/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

#include<bits/stdc++.h>
using namespace std;

char repeatedCharacter(string s) {
    // create an unordered_map to store character frequencies
    unordered_map<char, int> hm;

    // traverse each character in the string
    for(char ch : s){
        // increment the count of the character in the map
        hm[ch]++;

        // if the count becomes 2, return the character
        if(hm[ch] == 2){
            return ch;
        }
    }
    return '\0';
}

int main(){
    // string str = "abccbaacz";

    string str = "abcdd";
    cout<<repeatedCharacter(str);
    return 0;
}