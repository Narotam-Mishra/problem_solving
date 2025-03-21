
// Problem link - https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

// utility method to check if string is palindromic or not
bool isPalindromicString(string str){
    int s = 0, e = str.size() - 1;
    while(s < e){
        if(str[s] != str[e]){
            return false;
        }
        s++;
        e--;
    }
    return true; 
}

string firstPalindrome(vector<string>& words) {
    // step 1 - iterate on each word 
    for(string word : words){
        // step 2 - check if it is palindromic string or not
        if(isPalindromicString(word)){
            // step 3 - return word immediately if it is palindromic
            return word;
        }
    }
    // step 4 - otherwise return empty string
    return "";
}

int main(){
    // vector<string> words = {"abc","car","ada","racecar","cool"};

    // vector<string> words = {"notapalindrome","racecar"};

    vector<string> words = {"def","ghi"};
    cout<<firstPalindrome(words)<<endl;
    return 0;
}