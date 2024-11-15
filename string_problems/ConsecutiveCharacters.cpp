
// Problem link : https://leetcode.com/problems/consecutive-characters/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

#include<bits/stdc++.h>
using namespace std;

int maxPower(string s) {
    // initialize variables
    // start with the first character
    char currChar = s[0];

    // length of the current sequence
    int curPow = 1;

    // at least one character guarantees power 1
    int maxPower = 1;

    // iterate through the string starting from the second character
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == currChar) {
            // continue the sequence
            curPow++;
        }
        else {
            // sequence ends, update maxPower if needed
            maxPower = max(maxPower, curPow);

            // reset for the new character
            currChar = s[i];
            curPow = 1;
        }
    }

    // final comparison to account for the last sequence
    maxPower = max(maxPower, curPow);
    return maxPower;
}

int main(){
    // string str = "leetcode";

    string str = "abbcccddddeeeeedcba";
    cout<<maxPower(str);
    return 0;
}
