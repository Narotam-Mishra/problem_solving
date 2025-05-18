
// Problem link - https://leetcode.com/problems/valid-number/

#include<bits/stdc++.h>
using namespace std;

bool isNumber(string s) {
    // step 1 - remove leading and trailing whitespaces from string `s`
    s.erase(0, s.find_first_not_of(" \t\n\r\f\v"));
    s.erase(s.find_last_not_of(" \t\n\r\f\v") + 1);

    // step 2 - determine regular expression to match valid number format
    regex pattern(R"(^[\+\-]?((\d+\.\d*)|(\.\d+)|(\d+))([eE][\+\-]?\d+)?$)");

    // step 3 - test if string matches valid number regular expression
    return regex_match(s, pattern);
}

int main(){
    string s = "0";
    bool res = isNumber(s);
    res ? cout<<"true" : cout<<"false";
    return 0;
}