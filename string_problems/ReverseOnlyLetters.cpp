
// Problem link : https://leetcode.com/problems/reverse-only-letters/?envType=problem-list-v2&envId=string&difficulty=EASY&status=TO_DO%2CATTEMPTED

#include<bits/stdc++.h>
using namespace std;

string reverseOnlyLetters(string s) {
    // initialize pointers
    int l = 0, r = s.size() - 1;

    // process the characters until the two pointers meet
    while (l < r) {
        // move left pointer to the next letter
        while (l < r && !isalpha(s[l])) {
            l++;
        }

        // move right pointer to the next letter
        while (l < r && !isalpha(s[r])) {
            r--;
        }

        // swap letters at left and right pointers
        if (l < r) {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
    return s;
}

int main(){
    // string str = "ab-cd";

    // string str = "a-bC-dEf-ghIj";

    string str = "Test1ng-Leet=code-Q!";
    cout<<reverseOnlyLetters(str);
    return 0;    
}