
// problem link - https://leetcode.com/problems/transformed-array/?envType=daily-question&envId=2026-02-05

let constructTransformedArray = function (nums) {
    const n = nums.length;

    // store final result in `res`
    const res = new Array(n);

    // step 1 - iterate on each num of nums
    for (let i = 0; i < n; i++) {
        // step 2 - check if it is positive value
        if (nums[i] > 0) {
            // then move right
            let newIndex = (i + nums[i]) % n;
            res[i] = nums[newIndex];
        }

        // step 3 - check if it is negative value
        else if (nums[i] < 0) {
            // move left
            let steps = Math.abs(nums[i]);
            let newIndex = ((i - steps) % n + n) % n;
            res[i] = nums[newIndex];
        }

        // step 4 - check if value is zero
        else {
            // then stay at same index
            res[i] = nums[i];
        }
    }

    // step 5 - return final result, `res`
    return res;
};

// const nums = [3,-2,1,1];

const nums = [-1,4,-1];
console.log(constructTransformedArray(nums));