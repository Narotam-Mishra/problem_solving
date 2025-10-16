
// Problem link - https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/?envType=daily-question&envId=2025-10-16

let findSmallestInteger = function(nums, value) {
    // map to store frequency of each remainder when divided by 'value'
    // since adding/subtracting 'value' doesn't change the remainder
    const modMap = new Map();
    
    // step 1 - count frequency of each remainder
    for (const num of nums) {
        // handle negative numbers properly to get positive remainder
        // formula: ((num % value) + value) % value ensures remainder is in [0, value-1]
        const rem = ((num % value) + value) % value;
        modMap.set(rem, (modMap.get(rem) || 0) + 1);
    }
    
    // step 2 - find the maximum MEX by greedily assigning smallest values
    let mex = 0;
    
    // try to form consecutive integers starting from 0
    // for each number 'mex', check if we have an element with remainder (mex % value)
    while ((modMap.get(mex % value) || 0) > 0) {
        // Use one element with this remainder to form 'mex'
        modMap.set(mex % value, modMap.get(mex % value) - 1);
        mex++;
    }
    
    // step 3 - return the first integer we couldn't form (the MEX)
    return mex;
};

// const nums = [1,-10,7,13,6,8], value = 5;

const nums = [1,-10,7,13,6,8], value = 7;
console.log(findSmallestInteger(nums, value));