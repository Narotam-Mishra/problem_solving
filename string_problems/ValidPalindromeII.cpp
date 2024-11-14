
#include<bits/stdc++.h>
using namespace std;

bool checkPalindromeInRange(string str, int left, int right) {
    while (left < right) {
        // mismatch found
        if (str[left] != str[right]) return false;
        left++;
        right--;
    }
    // No mismatches, it's a palindrome
    return true;
}

bool validPalindrome(string s) {
    // using two pointers approach
    int l = 0, r = s.length() - 1;

    // move pointers towards each other
    while (l < r) {
        if (s[l] != s[r]) {
            // if mismatch found, try skipping either the left or right character
            return checkPalindromeInRange(s, l + 1, r) || checkPalindromeInRange(s, l, r - 1);
        }
        l++;
        r--;
    }
    // if no mismatches, or it's already a palindrome
    return true;
}

int main(){
    // string str = "abca";

    // string str = "aba";

    string str = "abc";
    bool res = validPalindrome(str);
    res ? cout<<"true" : cout<<"false";
    return 0;
}