
// Problem link - https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/?envType=daily-question&envId=2025-11-17

let kLengthApart = function (nums, k) {
    // find size of input array, nums
    let n = nums.length;

    // keep track of last 1 index
    let lastOne = -(k + 1);

    // step 1 - iterate through nums
    for (let i = 0; i < n; i++) {
        // step 2 - check if current element and find gap
        if (nums[i] == 1) {
            // gap of current 1 from last one visited should be atleast k
            if (i - lastOne - 1 < k) {
                return false;
            }

            // step 3 - update last 1 index
            lastOne = i;
        }
    }

    // step 4 - return true, if everything works fine
    return true;
};

// const nums = [1,0,0,0,1,0,0,1], k = 2;

const nums = [1,0,0,1,0,1], k = 2;
console.log(kLengthApart(nums, k));