
// Problem link - https://leetcode.com/problems/make-sum-divisible-by-p/?envType=daily-question&envId=2025-11-30

let minSubarray = function(nums, p) {
    // step 1 - find sum of all elements
    let sum = 0;
    for (let num of nums) {
        sum = (sum + num) % p;
    }

    let target = sum % p;

    // if already divisible
    if (target === 0) return 0;

    // step 2 - store prefix sums
    let mp = new Map();
    mp.set(0, -1);

    let curr = 0;
    let n = nums.length;
    let res = n;

    // step 3 - find remainVal using map
    for (let j = 0; j < n; j++) {
        curr = (curr + nums[j]) % p;
        let remainVal = (curr - target + p) % p;

        if (mp.has(remainVal)) {
            res = Math.min(res, j - mp.get(remainVal));
        }

        mp.set(curr, j);
    }

    return res === n ? -1 : res;
};

const nums = [3,1,4,2], p = 6;

// const nums = [6,3,5,2], p = 9;

// const nums = [1,2,3], p = 3;
console.log(minSubarray(nums, p));