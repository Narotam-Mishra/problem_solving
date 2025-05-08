
// Problem link - https://leetcode.com/problems/increasing-decreasing-string/description/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

string sortString(string s) {
    // step 1 - store frquency of each character in `freq`
    vector<int> freq(26, 0);

    // step 2 - count frequencies
    for (char ch : s) {
        freq[ch - 'a']++;
    }

    // step 3 - store result in `result`
    string result;
    int totalLength = s.length();

    // step 4 - perform algorithm steps
    while (result.length() < totalLength) {
        // follow step 1 to 3 -  Increasing pass: 'a' to 'z'
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                result += (char)(i + 'a');
                freq[i]--;
            }
        }

        // follow step 4 to 6 - Decreasing pass: 'z' to 'a'
        for (int i = 25; i >= 0; --i) {
            if (freq[i] > 0) {
                result += (char)(i + 'a');
                freq[i]--;
            }
        }
    }

    // step 5 - return `result`
    return result;
}

int main(){
    // string s = "aaaabbbbcccc";

    string s = "rat";
    cout<<sortString(s)<<endl;
    return 0;
}
