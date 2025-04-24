
// Problem link - https://leetcode.com/problems/minimize-string-length/

#include<bits/stdc++.h>
using namespace std;

int minimizedStringLength(string s) {
    // step 1 - the minimal length is the number of distinct characters
    unordered_set<char> uniqueChars;
    for(char ch : s){
        uniqueChars.insert(ch);
    }
    return uniqueChars.size();
}

int main(){
    // string s = "aaabc";

    // string s = "cbbd";

    string s = "baadccab";
    cout<<minimizedStringLength(s)<<endl;
    return 0;
}