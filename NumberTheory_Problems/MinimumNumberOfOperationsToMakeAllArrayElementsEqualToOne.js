
// Problem link - https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description/?envType=daily-question&envId=2025-11-12

/**
 * @param {number[]} nums
 * @return {number}
 */
let minOperations = function (nums) {
    function gcd(a, b) {
        if (b === 0) return a;
        return gcd(b, a % b);
    }

    const n = nums.length;

    // step 1 - count 1's
    let c1 = 0;
    for (let num of nums) {
        if (num == 1) c1++;
    }

    if (c1 > 0) {
        return n - c1;
    }

    // step 2 - no 1 present, find shortest subarray with gcd = 1
    let minLen = n + 1;

    // iterate over all subarrays
    for (let i = 0; i < n; i++) {
            let currGcd = nums[i];

        if (currGcd == 1) {
            // only one element needed, shortest length = 1
            minLen = 1;
            break;
        }

        for (let j = i + 1; j < n; j++) {
            currGcd = gcd(currGcd, nums[j]);
            if (currGcd == 1) {
                    let len = j - i + 1;
                if (len < minLen) {
                    minLen = len;
                }
                break;
            }
        }
    }

    // step 3 - if no subarray found with gcd = 1, return -1
    if (minLen == n + 1) return -1;

    // step 4 - calculate operations
    // operations to get one 1 = (min_length - 1)
    // operations to propagate 1 to rest of array = (n - 1)
    return (minLen - 1) + (n - 1);
};

// const nums = [2,6,3,4];

const nums = [2,10,6,14];
console.log(minOperations(nums));