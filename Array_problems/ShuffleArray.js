
// Problem link - https://leetcode.com/problems/shuffle-the-array/

// Approach - 1

let shuffle = function(nums, n) {
    let res = []
    for(let i=0; i<n; i++){
        res.push(nums[n+i]);
        res.push(nums[n+i]);
    }
    return res;
};