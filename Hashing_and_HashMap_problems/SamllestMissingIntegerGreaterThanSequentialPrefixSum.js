
// Problem link : https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/description/?envType=problem-list-v2&envId=hash-table

let missingInteger = function(nums) {
    // step 1 - initialize the sum of the longest sequential prefix
    let prefixSum = nums[0];

    // initialize the expected next value in the sequential prefix
    let expectedSum = nums[0] + 1;
    
    // step 2 - traverse through the array to find the longest sequential prefix
    for(let i=1; i<nums.length; i++) {
        // if the current number is the expected sequential number
        if(nums[i] === expectedSum) {
            // add to the prefix sum
            prefixSum += nums[i];
            
            // move to the next expected sequential number
            expectedSum++;
        }else{
            // break if sequence is broken
            break;
        }
    }

    // step 3 - find the smallest missing number >= prefixSum
    let x = prefixSum;
    const numSet = new Set(nums);

    // check for the smallest missing value
    while(numSet.has(x)){
        // keep checking until we find a missing number
        x++;
    }

    // step 4 - return the smallest missing number
    return x;
};

// const nums = [1, 2, 3, 2, 5];

const nums = [3,4,5,1,12,14,13];
console.log(missingInteger(nums)); 
