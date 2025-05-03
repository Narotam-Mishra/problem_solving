
// Problem link - https://leetcode.com/problems/delete-characters-to-make-fancy-string/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

string makeFancyString(string s) {
    // step 1 - store resultant string in `res` array
    string res = "";

    // step 2 - iterate on input string `s`
    for(int i=0; i<s.size(); i++){
        // calculate of length `len` of result `res` string
        int len = res.size();

        // step 3 - check if last two characters in `res` are same as current character
        if(len >= 2 && res[len-1] == s[i] && res[len-2] == s[i]){
            // skip this character to avoid three consecutive characters
            continue;
        }

        // step 4 - otherwise add character to `res` array
        res += s[i];
    }

    // step 5 - return `res`
    return res;
}

int main(){
    // string s = "leeetcode";

    // string s = "aaabaaaa";

    string s = "aab";
    cout<<makeFancyString(s)<<endl;
    return 0;
}