
// Problem link - https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

bool checkZeroOnes(string s) {
    // step 1 - initialize variables to keep track of the maximum length of contiguous segments of 1s and 0s
    int maxOnes = 0, maxZeros = 0;

    // step 2 - initialize variables to keep track of the current character and its count
    char currChar = s[0];
    int currCount = 1;

    // step 3 - iterate on each chacter of `s` starting from 1st index
    for (int i = 1; i < s.length(); i++) {
        // step 4 - continue counting current segemnt
        if (s[i] == currChar) {
            currCount++;
        }
        else {
            // step 5 - when contiguous segment ends, update max length of 1s and 0s
            if (currChar == '1') {
                maxOnes = max(maxOnes, currCount);
            }
            else {
                maxZeros = max(maxZeros, currCount);
            }

            // step 6 - reset current character and count
            currChar = s[i];
            currCount = 1;
        }
    }

    // step 7 - update last segemnt after loop ends
    if (currChar == '1') {
        maxOnes = max(maxOnes, currCount);
    }
    else {
        maxZeros = max(maxZeros, currCount);
    }

    // step 8 - return true if max length of 1s is greater than max length of 0s
    return maxOnes > maxZeros;
}

int main(){
    // string s = "1101";

    // string s = "111000";

    string s = "110100010";
    bool res = checkZeroOnes(s);
    res ? cout<<"true" : cout<<"false";
    return 0;
}