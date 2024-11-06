
// Problem link : https://leetcode.com/problems/valid-palindrome/description/

#include<bits/stdc++.h>
using namespace std;

string stringConversion(string& str) {
    string res;
    for (char ch : str) {
        if (isalnum(ch)) {
            res += tolower(ch);
        }
    }
    return res;
}

bool isPalindrome(string s) {
    // remove all non-alphanumeric characters from string
    string str = stringConversion(s);

    // now reverse the string
    int l = 0, r = str.size() - 1;
    while (l < r) {
        if (str[l] != str[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main(){
    // string str = "A man, a plan, a canal: Panama";

    string str = "race a car";
    bool res = isPalindrome(str);
    res ? cout<<"true" : cout<<"false";
    return 0;
}