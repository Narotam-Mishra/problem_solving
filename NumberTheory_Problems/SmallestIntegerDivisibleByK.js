
/**
 * @param {number} k
 * @return {number}
 */
let smallestRepunitDivByK = function (k) {
    // edge case: if k == 1, the smallest number is "1" itself
    if (k == 1) return 1;

    // step 1 - we only need to check up to k lengths due to Pigeonhole Principle
    let remainder = 0;
    for (let len = 1; len <= k; len++) {
        // step 2 - construct the new remainder incrementally
        remainder = (remainder * 10 + 1) % k;

        // step 3 - if remainder is zero, the number of length 'length' divisible by k
        if (remainder == 0) {
            return len;
        }
    }

    // step 4 - if no such number found after k attempts, return -1
    return -1;
};

// const k = 1;

// const k = 2;

const k = 3;
console.log(smallestRepunitDivByK(k));