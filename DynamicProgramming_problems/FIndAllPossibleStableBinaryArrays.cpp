
// Problem link - https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/description/?envType=daily-question&envId=2026-03-09

#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int memo[201][201][2];

int solveRec(int zeroLeft, int oneLeft, bool lastWasOne, int limit) {
    // base case:
    if (zeroLeft == 0 && oneLeft == 0) {
        return 1;
    }

    if (memo[oneLeft][zeroLeft][lastWasOne] != -1) {
        return memo[oneLeft][zeroLeft][lastWasOne];
    }

    int res = 0;
    if (lastWasOne) {
        // explore zeros
        for (int len = 1; len <= min(limit, zeroLeft); len++) {
            res = (res + solveRec(zeroLeft - len, oneLeft, false, limit)) % mod;
        }
    }    
else {
        // explore ones
        for (int len = 1; len <= min(limit, oneLeft); len++) {
            res = (res + solveRec(zeroLeft, oneLeft - len, true, limit)) % mod;
        }
    }

    return memo[oneLeft][zeroLeft][lastWasOne] = res;
}

int numberOfStableArrays(int zero, int one, int limit) {
    memset(memo, -1, sizeof(memo));
    int startWithOne = solveRec(zero, one, false, limit);
    int startWithZero = solveRec(zero, one, true, limit);

    return int(startWithOne + startWithZero) % mod;
}

int main() {
    int zero = 1, one = 1, limit = 2;
    cout << numberOfStableArrays(zero, one, limit);
    return 0;
}

