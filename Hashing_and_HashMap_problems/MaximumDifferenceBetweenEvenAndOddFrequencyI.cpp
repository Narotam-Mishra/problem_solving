
// Problem link - https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/description/?envType=problem-list-v2&envId=hash-table

#include<bits/stdc++.h>
using namespace std;

int maxDifference(string s) {
    // step 1 - create frequency map array and fill it with characters frequencies
    vector<int> freqArr(26, 0);
    for (char ch : s) {
        int charCode = (ch - 'a');
        freqArr[charCode]++;
    }

    // step 2 - find maximum odd frequency from frequency map array
    int maxOddFreq = 0;
    for (int freq : freqArr) {
        if (freq % 2 != 0) {
            maxOddFreq = max(maxOddFreq, freq);
        }
    }

    // step 3 - find minimum even frequency from frequency map array
    int minEvenFreq = INT_MAX;
    for (int freq : freqArr) {
        if (freq > 0 && freq % 2 == 0) {
            minEvenFreq = min(minEvenFreq, freq);
        }
    }

    // step 4 - find and return the maximum difference
    return (maxOddFreq - minEvenFreq);
}

int main(){
    // string s = "aaaaabbc";

    string s = "abcabcab";
    cout<<maxDifference(s)<<endl;
    return 0;
}