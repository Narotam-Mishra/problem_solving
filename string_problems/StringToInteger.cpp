
// Problem link - https://leetcode.com/problems/string-to-integer-atoi/

#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    // intialize necessary variables
    int i = 0, n = s.size();
    int sign = 1;
    long res = 0;

    // step 1 - skip whispaces in `s`
    while (i < n && s[i] == ' ') {
        i++;
    }

    // step 2 - handle sign
    if (i < n && (s[i] == '-' || s[i] == '+')) {
        sign = s[i] == '-' ? -1 : 1;
        i++;
    }

    // step 3 - convert numeric character to numeric number
    while (i < n && isdigit(s[i])) {
        int digit = s[i] - '0';

        // step 4 - check for overflow / underflow
        if (res > (INT_MAX - digit) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        res = res * 10 + digit;
        i++;
    }

    // step 5 - return resultant number by applying sign
    return (int)res * sign;
}

int main(){
    // string s = "42";

    // string s = "-042";

    // string s = "1337c0d3";

    // string s = "0-1";

    string s = "words and 987";
    cout<<myAtoi(s)<<endl;
    return 0;
}