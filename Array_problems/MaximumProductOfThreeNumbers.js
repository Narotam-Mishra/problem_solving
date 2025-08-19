
// Problem link - https://leetcode.com/problems/maximum-product-of-three-numbers/description/?envType=problem-list-v2&envId=array

/*
Two possible scenarios for maximum product:
1. Three largest positive numbers: nums[n-1] * nums[n-2] * nums[n-3]
2. Two smallest negative numbers * largest positive: nums[0] * nums[1] * nums[n-1]
(since negative * negative = positive, and we want the largest positive result)
*/
    

let maximumProduct = function(nums) {
    const n = nums.length;

    // step1 - sort `nums` array 
    nums.sort((a, b) => b - a);

    // step 2 - calculate maximum product of three maximum positive numbers 
    const prod1 = nums[0] * nums[1] * nums[2];

    // step 3 - calculate maximum product of two smallest negative numbers and a largest positive number
    const prod2 = nums[n-1] * nums[n-2] * nums[0];

    // step 4 - return the maximum product
    return Math.max(prod1, prod2);
}; 

// const nums = [1,2,3];

// const nums = [1,2,3,4];

// const nums = [-1,-2,-3];

const nums = [-100,-98,-1,2,3,4];
console.log(maximumProduct(nums));