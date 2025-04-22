
// Problem link - https://leetcode.com/problems/replace-all-digits-with-characters/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

string replaceDigits(string s) {
    // step 1 - iterate through each character and perform shift operation
    for(int i=1; i<s.length(); i+=2){
        // get character
        char ch = s[i-1];

        // get digit
        int digit = s[i] - '0';

        // step 2 - perform shift operation 
        s[i] = ch + digit;
    }

    // step 3 - return char array `arr` by convert back to string
    return s;
}

int main(){
    // string s = "a1c1e1";

    string s = "a1b2c3d4e";
    cout<<replaceDigits(s)<<endl;
    return 0;
}