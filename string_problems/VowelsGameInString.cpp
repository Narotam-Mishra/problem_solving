
// Problem link - https://leetcode.com/problems/vowels-game-in-a-string/?envType=daily-question&envId=2025-09-12

#include<bits/stdc++.h>
using namespace std;

bool doesAliceWin(string s) {
    // step 1 - count vowels in input string `s`
    int vowelsCount = 0;
    for(char ch : s){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            vowelsCount++;
        }
    }

    // step 2 - if vowels count is not zero then `Alice` wins, so return true
    // otherwise return false
    return vowelsCount ? true : false;
}

int main(){
    // string s = "leetcoder";

    string s = "bbcd";
    bool res = doesAliceWin(s);
    res ? cout<<"true" : cout<<"false";
    return 0;
}