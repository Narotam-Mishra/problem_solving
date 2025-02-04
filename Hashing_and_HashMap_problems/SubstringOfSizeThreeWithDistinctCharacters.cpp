
#include<bits/stdc++.h>
using namespace std;

int countGoodSubstrings(string s) {
    // edge case:
    if(s.size() < 3) return 0;
    
    // step 1 - initialize variable `count` to tack good substrings
    int count = 0;

    // step 2 - iterate through the string,
    for (int i = 0; i < s.length() - 2; i++) {
        // extracting substrings of length 3
        // and check all three characters are unique
        if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2]) {
            // increment count if above condition met
            count++;
        }
    }

    // step 3 - return the counter `count`
    return count;
}

int main(){
    string s = "xyzzaz";

    // string s = "aababcabc";
    cout<<countGoodSubstrings(s)<<endl;
    return 0;
}