
// Problem link : https://leetcode.com/problems/reverse-vowels-of-a-string/description/?envType=study-plan-v2&envId=leetcode-75

#include<bits/stdc++.h>
using namespace std;

string reverseVowels(string s) {
    string vowels = "aeiouAEIOU";
    int left = 0, right = s.size() - 1;

    while(left < right){
        // move left pointer until it finds a vowel
        while(left < right && vowels.find(s[left]) == string::npos){
            left++;
        }

        // move right pointer until it finds a vowel
        while(left < right && vowels.find(s[right]) == string::npos){
            right--;
        }

        // swap vowels
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return s;
}

int main(){
    // string str = "hello";

    string str = "leetcode";
    cout<<reverseVowels(str);
    return 0;
}