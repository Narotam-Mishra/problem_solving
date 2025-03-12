
// Problem link - https://leetcode.com/problems/reverse-prefix-of-word/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

string reversePrefix(string word, char ch) {
    // step 1 - find the first occurrence of ch
    int chIndex = word.find(ch);

    // step 2 - if ch doesn't exist in word, return original word
    if (chIndex == string::npos) return word;

    // step 3 - reverse segment in place
    int left = 0, right = chIndex;
    while (left < right) {
        char temp = word[left];
        word[left] = word[right];
        word[right] = temp;

        left++;
        right--;
    }

    // step 5 - convert back to string and return 
    return word;
}

int main(){
    // string word = "abcdefd";
    // char ch = 'd';

    // string word = "xyxzxe";
    // char ch = 'z';

    string word = "abcd";
    char ch = 'z';
    cout<<reversePrefix(word, ch)<<endl;
    return 0;
}