
// Problem link - https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/

#include<bits/stdc++.h>
using namespace std;

bool checkOnesSegment(string s) {
    // step 1 - return true if "01" is not found in the string
    return s.find("01") == string::npos;
}

int main(){
    // string s = "1001";

    string s = "110";
    bool res = checkOnesSegment(s);
    res ? cout<<"true" : cout<<"false";
    return 0;
}