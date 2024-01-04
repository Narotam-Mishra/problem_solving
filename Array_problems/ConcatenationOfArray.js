
// Problem link - https://leetcode.com/problems/concatenation-of-array/

// Approach - 1 (Brute Force)

let getConcatenation = function(nums) {
    let res = [];
    for(let i=0; i<nums.length; i++){
        res.push(nums[i]);
    }
    for(let i=0; i<nums.length; i++){
        res.push(nums[i]);
    }
    return res;
};

// Approach - 2 (One liner)

let getConcatenation1 = function(nums) {
    // spread the nums twice
    return [...nums, ...nums];
};