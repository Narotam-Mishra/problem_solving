
// Problem link - https://leetcode.com/problems/smallest-integer-divisible-by-k/submissions/1839181527/?envType=daily-question&envId=2025-11-25

#include<bits/stdc++.h>
using namespace std;

int smallestRepunitDivByK(int k) {
    // edge case: if k == 1, the smallest number is "1" itself
    if (k == 1) return 1;

    // step 1 - we only need to check up to k lengths due to Pigeonhole Principle
    int remainder = 0;
    for (int len = 1; len <= k; len++) {
        // step 2 - construct the new remainder incrementally:
        // remainder * 10 shifts digits left, +1 adds the next '1'
        remainder = (remainder * 10 + 1) % k;

        // step 3 - if remainder is zero, the number of length 'length' divisible by k
        if (remainder == 0) {
            return len;
        }
    }

    // step 4 - if no such number found after k attempts, return -1
    return -1;
}

int main() {
    // int k = 1;

    // int k = 2;

    int k = 3;
    cout << smallestRepunitDivByK(k);
    return 0;
}