
// Problem link - https://leetcode.com/problems/maximum-score-after-splitting-a-string/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int maxScore(string s) {
    // step 1 - find count of total ones in `s`
    int totalOnes = 0;
    for (char c : s) {
        if (c == '1') totalOnes++;
    }

     // step 2 - store maximum score in maxScor
    int maxScore = 0;
    int zerosLeft = 0;
    int onesSeen = 0;

    // step 3 - iterate on each character of binary string `s`
    // go upto s.length - 1 to ensure right substring is not empty
    for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i] == '0') {
            zerosLeft++;
        } else {
            onesSeen++;
        }

        // step 4 - calculate maximum score `maxScore` on basis of counts of 1's and 0's
        int score = zerosLeft + (totalOnes - onesSeen);
        maxScore = max(maxScore, score);
    }

    // step 5 - return maximum score `maxScore`
    return maxScore;
}

int main(){
    string s = "011101";
    cout<<maxScore(s)<<endl;
}