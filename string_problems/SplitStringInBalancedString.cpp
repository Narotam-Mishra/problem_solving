
// Problem link : https://leetcode.com/problems/split-a-string-in-balanced-strings/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

#include<bits/stdc++.h>
using namespace std;

int balancedStringSplit(string s) {
    // initialize counters for balance and result
        // tracks the current balance of 'L' and 'R'
    int lrCount = 0;

    // counts the maximum number of balanced substrings
    int maxCount = 0;

    // iterate through each character in the string
    for (char ch : s) {
        // update lrCount: +1 for 'L', -1 for 'R'
        if (ch == 'L') {
            lrCount++;
        }
        else {
            lrCount--;
        }

        // if balance is zero, a balanced substring is found
        if (lrCount == 0)
            maxCount++;
    }

    // return the total number of balanced substrings
    return maxCount;
}

int main(){
    // string str = "RLRRLLRLRL";

    // string str = "RLRRRLLRLL";

    string str = "LLLLRRRR";
    cout<<balancedStringSplit(str)<<endl;
    return 0;
}
