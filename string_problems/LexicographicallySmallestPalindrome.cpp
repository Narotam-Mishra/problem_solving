
// Problem link - https://leetcode.com/problems/lexicographically-smallest-palindrome/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

string makeSmallestPalindrome(string s) {
    // step 1 - use two pointers approach 
    int i=0, j = s.size() - 1;

    // step 2 - process characters from both ends
    while(i < j){
        if(s[i] != s[j]){
            // step 3 - replace the character that gives the lexicographically smaller result
            char smallerChar = s[i] < s[j] ? s[i] : s[j];
            s[i] = s[j] = smallerChar;
        }
        i++;
        j--;
    }

    // step 4 - return modified string
    return s;
}

int main(){
    // string s = "egcfe";

    // string s = "abcd";

    string s = "seven";
    cout<<makeSmallestPalindrome(s)<<endl;
    return 0;
}