
// Problem link - https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int minOperations(string s) {
    // step 1 - initialize counts for two patterns, '010101..' & '10101010..'
    int countAPattern = 0;
    int countBPattern = 0;

    // step 2 - iterate on each character of binary string
    for (int i = 0; i < s.length(); i++) {
        // step 3 - find expected character for both patterns
        char expectedA = i % 2 == 0 ? '0' : '1';
        char expectedB = i % 2 == 0 ? '1' : '0';

        // step 4 - count mismatch for pattern A
        if (s[i] != expectedA) {
            countAPattern++;
        }

        // count mismatch for pattern B
        if (s[i] != expectedB) {
            countBPattern++;
        }
    }

    // step 5 - return the minimum operations needed to convert to either pattern
    return min(countAPattern, countBPattern);
}

int main(){
    // string s = "0100";

    // string s = "1111";

    string s = "10";
    cout<<minOperations(s)<<endl;
    return 0;
}