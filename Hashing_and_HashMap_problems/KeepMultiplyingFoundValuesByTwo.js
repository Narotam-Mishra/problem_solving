
// Problem link - - [2154. Keep Multiplying Found Values by Two](https://leetcode.com/problems/keep-multiplying-found-values-by-two/?envType=daily-question&envId=2025-11-19)

/**
 * @param {number[]} nums
 * @param {number} original
 * @return {number}
 */
let findFinalValue = function (nums, original) {
    // step 1 - store all elements of `nums` in set for better lookup
    const numSet = new Set();
    for (let num of nums) {
        numSet.add(num);
    }

    // step 2 - keep searching `original` till it exists in set
    while (numSet.has(original)) {
        // step 3 - double it each time when it is found
        original = 2 * original;
    }

    // step 4 - return `original` when it is not found
    return original;
};