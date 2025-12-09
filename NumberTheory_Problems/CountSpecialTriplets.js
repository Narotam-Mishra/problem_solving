
// problem link - https://leetcode.com/problems/count-special-triplets/?envType=daily-question&envId=2025-12-09

let specialTriplets = function(nums) {
    const MOD = 1e9+7;

    // left: frequency of values to the left of current j
    // right: frequency of values to the right of current j
    const left = new Map();
    const right = new Map();

    // step 1 - initialize right with counts of the whole array
    for (const num of nums) {
        right.set(num, (right.get(num) || 0) + 1);
    }

    // store final result, `res`
    let res = 0;

    // step 2 - iterate each element as middle index j
    for (const num of nums) {
        // step 3 - exclude current num from right side (it becomes the middle j)
        right.set(num, (right.get(num) || 0) - 1);

        // step 4 - target value that must appear on both sides: 2 * nums[j]
        const target = num * 2;

        // step 5 - count occurrences of target on left and right
        const leftCount = left.get(target) || 0;
        const rightCount = right.get(target) || 0;

        // step 6 - triplets contributed by this j = leftCount * rightCount
        res = (res + (leftCount * rightCount) % MOD) % MOD;

        // step 7 - include current num into the left side for subsequent j's
        left.set(num, (left.get(num) || 0) + 1);
    }

    // step 8 - return final result, `res`
    return res;
};

const nums = [6,3,6];
console.log(specialTriplets(nums));