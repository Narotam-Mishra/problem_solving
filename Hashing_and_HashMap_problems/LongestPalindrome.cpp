
#include<bits/stdc++.h>
using namespace std;

int longestPalindrome(string s) {
    // step 1: count the frequency of each character,
    unordered_map<char, int> charCount;

    for (char ch : s) {
        charCount[ch]++;
    }

    int longestPalindromeLength = 0;
    bool hasOdd = false;

    // step 2: calculate contributions to the palindrome
    for (const auto& entry : charCount) {
        int count = entry.second;
        if (count % 2 == 0) {
            // if even, all characters can contribute to the palindrome
            longestPalindromeLength += count;
        }
        else {
            // if odd, use the largest even part and flag that an odd exists
            longestPalindromeLength += count - 1;
            hasOdd = true;
        }
    }

    // step 3: add 1 if there's an odd character to be the center
    if (hasOdd) {
        longestPalindromeLength += 1;
    }

    // return longest palindrome length 'longestPalindromeLength'
    return longestPalindromeLength;
}

int main(){
    // string str = "abccccdd";

    string str = "a";
    cout<<longestPalindrome(str)<<endl;
    return 0;
}