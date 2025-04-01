
// Problem link - https://leetcode.com/problems/find-the-encrypted-string/description/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

string getEncryptedString(string s, int k) {
    // step 1 - initialize a `res` string to store result
    string res;

    // find length of input string `s`
    int n = s.size();

    // step 2 - iterate on input string `s`
    for (int i = 0; i < n; i++) {
        // step 3 - find `res`
        res += s[(i + k) % n];
    }

    // step 4 - return `res`
    return res;
}

int main(){
    // string s = "dart";
    // int k = 3;

    string s = "aaa";
    int k = 1;
    cout<<getEncryptedString(s, k)<<endl;
    return 0;
}