
// Problem link - https://leetcode.com/problems/remove-palindromic-subsequences/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

// utility function to check if string is palindrome or not
bool isPalindrome(string str){
    int l = 0, r = str.size() - 1;
    while(l < r){
        if(str[l] != str[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int removePalindromeSub(string s) {
    // step 1 - if input string `s` is palindrome then we can remove it in 1 step
    // otherwise , remove all a's in one step and all b's in another step
    return isPalindrome(s) ? 1 : 2;
}

int main(){
    // string s = "ababa";

    // string s = "abb";

    string s = "baabb";
    cout<<removePalindromeSub(s)<<endl;
    return 0;
}