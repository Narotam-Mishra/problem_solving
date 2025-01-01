
// Problem link - https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring1(string s) {
    // step 1 - initialize a Set to store unique characters in the current window
    unordered_set<string> charSet;
    
    // step 2 - initialize two pointers `start` & `end` for the sliding window
    int start = 0;
    // use `maxLength`to keep track of the maximum length of the substring
    int maxLength = 0;

    // step 3 - iterate over the string using `end` pointer
    for(int end = 0; end < s.length(); end++){
        // if the character at 'end' is already in the set, shrink the window
        while(charSet.find(s.substr(end, 1)) != charSet.end()){
            // remove the character at `start` from the set and move `start` forward
            charSet.erase(s.substr(start, 1));
            start++;
        }

        // add the current character at 'end' to the set
        charSet.insert(s.substr(end, 1));
        
        // update maximum length of substring
        maxLength = max(maxLength, end - start + 1);
    }

    // step 4 - return the maximum length found
    return maxLength;
}

int lengthOfLongestSubstring(string s) {
    // step 1 - initialize an unordered_map to store the characters and their most recent indices
    unordered_map<char, int> map;
    
    // step 2 - initialize two pointers `start` & `end` for the sliding window
    int start = 0;
    // use `maxLength`to keep track of the maximum length of the substring
    int maxLength = 0;

    // step 3 - iterate over the string using `end` pointer
    for(int end = 0; end < s.length(); end++){
        char currChar = s[end];

        // if the character is already in the map, move the `start` pointer
        if(map.find(currChar) != map.end()){
            // move the `start` pointer to the right of the previous index of the current character
            start = max(start, map[currChar] + 1);
        }

        // add the current character at 'end' to the set
        map[currChar] = end;
        
        // update maximum length of substring
        maxLength = max(maxLength, end - start + 1);
    }

    // step 4 - return the maximum length found
    return maxLength;
}

int main(){
    // string str = "abcabcbb";

    // string str = "bbbbb";

    string str = "pwwkew";
    cout<<lengthOfLongestSubstring(str)<<endl;
    return 0;
}