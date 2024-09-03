
// Problem link : https://leetcode.com/problems/find-the-difference/description/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

char findTheDifference(string s, string t) {
    int res = 0;

    // XOR all characters in both strings
    for(char c : s){
        res ^= c;
    }

    for(char c : t){
        res ^= c;
    }

    // convert the result to a character
    return char(res);
}

int main(){
    // string s = "abcd";
    // string t = "abcde";

    string s = "";
    string t = "y";
    cout<<findTheDifference(s, t);
    return 0;
}