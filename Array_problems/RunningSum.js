
// Problem link - https://leetcode.com/problems/running-sum-of-1d-array/description/

// Approach - 1 

let runningSum = function(nums) {
    let curSum = 0;
    let res = [];
    for(let i=0; i<nums.length; i++){
        curSum += nums[i];
        res.push(curSum);
    }
    return res;
};