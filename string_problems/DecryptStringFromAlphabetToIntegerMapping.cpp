
// Problem link - https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

string freqAlphabets(string s) {
    // step 1 - start from the last character
    int i = s.length() - 1;
    string result;

    // step 2 - iterate `s` from reverse
    while (i >= 0) {
        if (s[i] == '#') {
            // step 3 - decode two-digit number (10# to 26#)
            int num = stoi(s.substr(i - 2, 2));

            // convert to letter
            result.push_back(char(96 + num));

            // move back 3 places
            i -= 3;
        }
        else {
            // step 4 - decode single-digit number (1 to 9)
            // convert character to number
            int num = s[i] - '0';

            // start from the last character
            result.push_back(char(96 + num));

            //move back 1 place
            i -= 1;
        }
    }

    // step 5 - reverse the result to get correct order
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    // string s = "10#11#12";

    string s = "1326#";
    cout<<freqAlphabets(s)<<endl;
    return 0;
}