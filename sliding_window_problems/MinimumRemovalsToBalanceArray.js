
// Problem link - https://leetcode.com/problems/minimum-removals-to-balance-array/?envType=daily-question&envId=2026-02-06

let minRemoval = function(nums, k) {
    const n = nums.length;

    // step 1 - sort `nums` array
    nums.sort((a,b) => a - b);

    // using sliding withow with two-poleters
    let i=0, j=0;
    let maxNum = nums[0], minNum = nums[0];

    // keep track of maximum balanced subarray
    // initially there will be atleast 1 balance subarray
    let len = 1;

    // step 2 - move throught he window
    while(j < n){
        // keep track of maximum and minimum number
        minNum = nums[i];
        maxNum = nums[j];

        // step 3 - check balance subarray condition
        while(i < j && maxNum > k * minNum){
            i++;
            minNum = nums[i];
        }

        // step 4 - updated balanced subarry length
        len = Math.max(len, j-i+1);

        // move to next window
        j++;
    }

    // step 5 - return minimum number of elements to remove
    return n - len;
};

// const nums = [2,1,5], k = 2;

// const nums = [1,6,2,9], k = 3;

const nums = [4,6], k = 2;
console.log(minRemoval(nums, k));