
// Problem link - https://leetcode.com/problems/make-the-string-great/description/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

bool formsBadPair(char ch1, char ch2) {
    // check if they are the same letter (case-insensitive)
    bool sameLetterDifferentCase = tolower(ch1) == tolower(ch2);

    // check if they have different cases (original characters are different)
    bool differentCase = ch1 != ch2;

    // above both conditions must be true for a bad pair
    return sameLetterDifferentCase && differentCase;
}

string makeGood(string s) {
    // step 1 - use string as stack for efficiency in C++
    string stack;

    // step 2 - process each character in the string
    for (char currentChar : s) {
        // step 3 - if stack is empty, just add current character
        if (stack.empty()) {
            stack.push_back(currentChar);
            continue;
        }

        // get the last character from stack
        char lastChar = stack.back();

        // step 4 - check if current char and last char form a bad pair
        if (formsBadPair(lastChar, currentChar)) {
            // remove the bad pair by popping from stack
            // (current char is not added, last char is removed)
            stack.pop_back();
        }
        else {
            // no bad pair, add current character to stack
            stack.push_back(currentChar);
        }
    }

    // step 5 - return the final resultant string `stack` 
    return stack;
}

int main(){
    // string s = "leEeetcode";

    // string s = "abBAcC";

    string s = "s";
    cout<<makeGood(s)<<endl;
    return 0;
}