
#include<bits/stdc++.h>
using namespace std;

bool isSubstringPresent(string s) {
    // step 1: reverse the string
    string reversed = string(s.rbegin(), s.rend());

    // step 2: check if any substring of length 2 exists in the reversed string
    for (int i = 0; i < s.length() - 1; i++) {
        string sub = s.substr(i, 2);
        if (reversed.find(sub) != string::npos) {
            // return true if substring found
            return true;
        }
    }

    // step 3: return false if no substring found
    return false;
}

int main(){
    // string s = "leetcode";

    // string s = "abcba";

    string s = "abcd";
    bool res = isSubstringPresent(s);
    res ? cout<<"true" : cout<<"false";
    return 0;
}