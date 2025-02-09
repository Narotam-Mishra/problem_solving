
#include<bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    // edge case: if the lengths of the two strings are different, they cannot be isomorphic
    if (s.length() != t.length()) {
        return false;
    }

    // step 1 - Create a map to store the mapping from s to t
    unordered_map<char, char> charMap;

    // step 2 - create a set to track characters in t that have already been mapped
    unordered_set<char> usedChars;

    // step 3 - iterate through each character of the strings
    for (int i = 0; i < s.length(); i++) {
        char charS = s[i];
        char charT = t[i];

        // if the character in s is already mapped
        if (charMap.find(charS) != charMap.end()) {
            // check if it maps to the corresponding character in t
            if (charMap[charS] != charT) {
                return false;
            }
        } else {
            // if the character in t has already been used, it cannot be mapped again
            if (usedChars.find(charT) != usedChars.end()) {
                return false;
            }
            // add the mapping from s to t
            charMap[charS] = charT;
            // mark the character in t as used
            usedChars.insert(charT);
        }
    }

    // step 4 - if all characters are mapped correctly, the strings are isomorphic
    return true;
}

int main(){
    // string s = "egg", t = "add";

    // string s = "foo", t = "bar";

    string s = "paper", t = "title";
    bool res = isIsomorphic(s, t);
    res ? cout<<"true" : cout<<"false";
    return 0;
}