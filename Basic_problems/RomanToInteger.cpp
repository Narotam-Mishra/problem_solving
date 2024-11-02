
// Problem link : https://leetcode.com/problems/roman-to-integer/description/

#include<bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> romanMap = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
    };

    int res = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        // check if the current numeral is less than the next one
        if (i < s.length() - 1 && romanMap[s[i]] < romanMap[s[i + 1]]) {
            // subtract the current numeral's value
            res -= romanMap[s[i]];
        }
        else {
            // add the current numeral's value
            res += romanMap[s[i]];
        }
    }
    return res;
}

int main(){
    // string str = "III";

    // string str = "LVIII";

    string str = "MCMXCIV";

    cout<<romanToInt(str);
    return 0;
}