
// Problem link - https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/description/?envType=daily-question&envId=2026-03-09

let numberOfStableArrays = function(zero, one, limit) {
    const MOD = 1000000007;

    // memo[oneLeft][zeroLeft][lastWasOne]
    const memo = Array.from({ length: one + 1 }, () =>
        Array.from({ length: zero + 1 }, () => Array(2).fill(-1))
    );

    function solveRec(zeroLeft, oneLeft, lastWasOne) {
        // base case
        if (zeroLeft === 0 && oneLeft === 0) {
            return 1;
        }

        if (memo[oneLeft][zeroLeft][lastWasOne] !== -1) {
            return memo[oneLeft][zeroLeft][lastWasOne];
        }

        let res = 0;

        if (lastWasOne === 1) {
            // last was 1 → place zeros
            let maxLen = Math.min(limit, zeroLeft);

            for (let len = 1; len <= maxLen; len++) {
                res += solveRec(zeroLeft - len, oneLeft, 0);
                res %= MOD;
            }

        } else {
            // last was 0 → place ones
            let maxLen = Math.min(limit, oneLeft);

            for (let len = 1; len <= maxLen; len++) {
                res += solveRec(zeroLeft, oneLeft - len, 1);
                res %= MOD;
            }
        }

        memo[oneLeft][zeroLeft][lastWasOne] = res;
        return res;
    }

    let startWithOne = solveRec(zero, one, 0);
    let startWithZero = solveRec(zero, one, 1);

    return (startWithOne + startWithZero) % MOD;
};

// const zero = 1, one = 1, limit = 2;

const zero = 3, one = 3, limit = 2;
console.log(numberOfStableArrays(zero, one, limit));