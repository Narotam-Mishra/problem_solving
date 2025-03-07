
// Problem link - https://leetcode.com/problems/first-missing-positive/description/?envType=problem-list-v2&envId=array

// Brute Force Approach
let firstMissingPositive1 = function(nums) {
    // step 1 - start checking missing num from 1
    let missingNum = 1;

    // step 2 - check if current number is in nums
    while(nums.includes(missingNum)){
        // if found, move to next number
        missingNum++;
    }

    // step 3 - return first missing number
    return missingNum;
};

// Approach - 2 (Optimized Approach)
let firstMissingPositive = function(nums) {
    const n = nums.length;

    // step 1 - place each number at its correct position
    for(let i=0; i<n; i++){
        while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] !== nums[i]){
            // swap nums[i] with its correct index
            let correctIndex = nums[i] - 1;
            [nums[i], nums[correctIndex]] = [nums[correctIndex], nums[i]];
        }
    }
    
    // step 2 - find the first missing number
    for(let i=0; i<n; i++){
        if(nums[i] !== i+1){
            return i+1;
        }
    }

    // step 3 - if all numbers 1 to n are present, return n+1
    return n+1;
};

const nums = [1, 2, 0];

// const nums = [3,4,-1,1];

// const nums = [7,8,9,11,12];
console.log(firstMissingPositive(nums));
