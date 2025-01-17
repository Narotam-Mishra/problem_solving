
// Problem link : https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/?envType=problem-list-v2&envId=hash-table

let findMaxK1 = function(nums) {
    // step 1 - create a Set to store all numbers for quick lookup
    const numSet = new Set(nums);

    // step 2 - initialize a variable to keep track of the largest k
    let largestK = -1;

    // step 3 - iterate through the array
    for(let num of numSet) {
        // check if both num and its negative counterpart -num exist
        if(numSet.has(-num)){
            // update largestK if num is positive and larger than current largestK
            largestK = Math.max(largestK, Math.abs(num));
        }
    }

    // step 4 - return the largest k, or -1 if no such k was found
    return largestK;
};

let findMaxK = function(nums) {
    // step 1 - initialize variables
    let i = 0;
    let val = -1;

    // step 2 - iterate through the array
    while(i <nums.length){
        // step 3 - check for negative counterpart
        if(nums[i] > val && nums.includes(-nums[i])){
            // step 4 - update largest positive integer
            val = nums[i];
        }
        i++;
    }
    // step 5 - return answer
    return val;
};

// const nums = [-1,2,-3,3];

// const nums = [-1,10,6,7,-7,1];

const nums = [-10,8,6,7,-2,-3];
console.log(findMaxK(nums));
