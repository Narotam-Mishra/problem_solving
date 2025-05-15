
#include<bits/stdc++.h>
using namespace std;

bool checkString(string s) {
    // step 1 - set flag to tack if we have seen `b`
    bool seenB = false;

    // step 2 - iterate on each character of `s`
    for (char ch : s) {
        // step 3 - mark true for every `b` that we have seen
        if (ch == 'b') {
            seenB = true;
        }
        else if (ch == 'a') {
            // step 4 - if we see an `a` after `b` then return false immediately
            if (seenB) {
                return false;
            }
        }
    }

    // step 5 - return true as all characters follow the rule: 'a's before 'b's
    return true;
}

int main(){
    // string s = "aaabbb";

    // string s = "abab";

    string s = "bbb";
    bool res = checkString(s);
    res ? cout<<"true" : cout<<"false";
    return 0;
}