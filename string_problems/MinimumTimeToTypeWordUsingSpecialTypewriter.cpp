
// Problem link - https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int minTimeToType(string word) {
    // step 1 - store minimum time in `minTime`
    int minTime = 0;

    // pointer start from character `a`
    char currChar = 'a';

    // step 2 - iterate on each character of word
    for (int i = 0; i < word.size(); i++) {
        // get current character as target character
        char targetChar = word[i];

        // step 3 - calculate absolute difference between current and target character
        int diff = abs(targetChar - currChar);

        // step 4 - calculate minimum time
        // since typwriter is circular so it can be either clockwise or anti-clockwise
        int moveTime = min(diff, 26 - diff);

        // step 5 - add 1 second to type each character
        minTime += moveTime + 1;

        // step 6 - update current chacter
        currChar = targetChar;
    }

    // step 7 - return minimum time to type out the word
    return minTime;
}

int main(){
    // string word = "abc";

    // string word = "bza";

    string word = "zjpc";
    cout<<minTimeToType(word)<<endl;
    return 0;
}