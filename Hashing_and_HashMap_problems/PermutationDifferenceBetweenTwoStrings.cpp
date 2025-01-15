
#include<bits/stdc++.h>
using namespace std;

int findPermutationDifference(string s, string t) {
    // step 1: initialize variable to store absolute difference
    int absDiff = 0;

    // step 2: iterate over any of the input strings
    for (int i = 0; i < s.length(); i++) {
        // get the character from the first string
        char ch = s[i];

        // get the index of that character in the target string `t`
        int i2 = t.find(ch);

        // step 3: find the sum of absolute differences
        absDiff += abs(i - i2);
    }

    // step 4: return the sum of absolute differences
    return absDiff;
}

int main(){
    // string s = "abc", t = "bac";

    string s = "abcde", t = "edbac";
    cout<<findPermutationDifference(s, t)<<endl;
    return 0;
}