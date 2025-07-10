
// Problem link - https://leetcode.com/problems/maximum-product-difference-between-two-pairs/description/?envType=problem-list-v2&envId=array

// Brute Force Approach
let maxProductDifference1 = function(nums) {
    // get length of `nums` array
    const n = nums.length;

    // step 1 - sort `nums` array in ascending order
    nums.sort((a,b) => a - b);

    // step 2 - get first two minimum numbers from `nums`
    const minNum1 = nums[0];
    const minNum2 = nums[1];

    // step 3 - get first two maximum numbers from `nums`
    const maxNum1 = nums[n-1];
    const maxNum2 = nums[n-2];

    // step 4 - find and return maximum product difference `maxProdDiff`
    const maxProdDiff = (maxNum1 * maxNum2) - (minNum1 * minNum2);
    return maxProdDiff;
};

// Efficient Approach
let maxProductDifference = function(nums) {
    // find maximum and minimum numbers
    let maxNum1 = -Infinity, maxNum2 = -Infinity;
    let minNum1 = Infinity, minNum2 = Infinity;

    // step 1 - find the two largest and two smallest numbers in one pass
    for(let num of nums){
        // update largest numbers
        if(num > maxNum1){
            maxNum2 = maxNum1;
            maxNum1 = num;
        }else if(num > maxNum2){
            maxNum2 = num;
        }

        // update smallest numbers
        if(num < minNum1){
            minNum2 = minNum1;
            minNum1 = num;
        }else if(num < minNum2){
            minNum2 = num;
        }
    }

    // step 2: calculate and return the maximum product difference
    return (maxNum1 * maxNum2) - (minNum1 * minNum2);
};

// const nums = [5,6,2,7,4];

const nums = [4,2,5,9,7,4,8];
console.log(maxProductDifference(nums));