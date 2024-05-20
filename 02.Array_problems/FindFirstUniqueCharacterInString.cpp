
// Problem link - https://leetcode.com/problems/first-unique-character-in-a-string/description/

#include<bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    // Using unordered_map as frequency map
    unordered_map<char, int> charMap;

    // Iterate over the string to build the frequency map
    for(int i=0; i<s.length(); i++){
        char c = s[i];
        charMap[c]++;
    }

    // Check the character which has frequency 1 and return its index
    for(int i=0; i<s.length(); i++){
        char c = s[i];
        if(charMap[c] == 1){
            return i;
        }
    }

    // If there is no unique character, return -1
    return -1;
}

int main(){
    string str = "leetcode";
    cout<<firstUniqChar(str)<<endl;
    return 0;
}