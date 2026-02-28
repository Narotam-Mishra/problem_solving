
// Problem link - https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/?envType=daily-question&envId=2026-02-28

let concatenatedBinary = function(n) {
    const mod = 1_000_000_007n;
    let res = 0n;

    // step 1 - iterate on each number from 1 to n
    for (let num = 1n; num <= BigInt(n); num++) {
        // step 2 - find number of bits
        let bits = Math.floor(Math.log2(Number(num))) + 1;

        // step 3 - calculate result
        res = ((res << BigInt(bits)) % mod + num) % mod;
    }

    // step 4 - return final result, `res`
    return Number(res);
};

// const n = 12;

const n = 1;
console.log(concatenatedBinary(n));