
// Problem link - https://leetcode.com/problems/maximize-the-number-of-partitions-after-operations/?envType=daily-question&envId=2025-10-17

#include<bits/stdc++.h>
using namespace std;

// memoization map: stores computed results for (index, uniqueChars bitmask, canChange flag)
unordered_map<long long, int> memo;

string str;
int K;

int solveRec(long long i, long long uniqueChars, bool canChange) {
    // create unique key combining: index (bits 27+), uniqueChars bitmask (bits 1-26), canChange flag (bit 0)
    long long key = ((i << 27) | (uniqueChars << 1) | canChange);

    // return cached result if already computed
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    // base case: reached end of string, no more partitions possible
    if (i >= str.length()) {
        return 0;
    }

    // get character index (0-25 for 'a'-'z')
    int charIndex = str[i] - 'a';

    // add current character to the bitmask (set corresponding bit)
    int newUniqueChars = uniqueChars | (1 << charIndex);

    // count number of distinct characters using popcount (counts set bits)
    int uniqueCharsCount = __builtin_popcount(newUniqueChars);

    int res;
    // tf adding current character exceeds K distinct characters
    if (uniqueCharsCount > K) {
        // start a new partition: increment count and reset bitmask to only current character
        res = 1 + solveRec(i + 1, 1 << charIndex, canChange);
    }
    else {
        // continue current partition: keep the updated bitmask
        res = solveRec(i + 1, newUniqueChars, canChange);
    }

    // if we still have the option to change one character
    if (canChange) {
        // try changing current character to each of 26 possible letters
        for (int newCharId = 0; newCharId < 26; newCharId++) {
            // calculate new bitmask with the changed character
            int newCharSet = uniqueChars | (1 << newCharId);
            int newUniqueCharCount = __builtin_popcount(newCharSet);

            // if changing causes partition split
            if (newUniqueCharCount > K) {
                // start new partition with changed character, mark canChange as false
                res = max(res, 1 + solveRec(i + 1, 1 << newCharId, false));
            }
            else {
                // continue partition with changed character, mark canChange as false
                res = max(res, solveRec(i + 1, newCharSet, false));
            }
        }
    }

    // cache and return the result
    return memo[key] = res;
}

int maxPartitionsAfterOperations(string s, int k) {
    str = s;
    K = k;

    // start with empty bitmask (0), canChange = true
    // add 1 because we count partition boundaries, need to add final partition
    return solveRec(0, 0, true) + 1;
}

int main(){
    string s = "accca";
    int k = 2;

    // string s = "aabaab";
    // int k = 3;

    // string s = "xxyz";
    // int k = 1;
    cout<<maxPartitionsAfterOperations(s, k);
    return 0;
}