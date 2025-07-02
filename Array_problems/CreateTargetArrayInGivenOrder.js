
// Problem link - https://leetcode.com/problems/create-target-array-in-the-given-order/description/?envType=problem-list-v2&envId=array

let createTargetArray = function(nums, index) {
    const n = nums.length;
    
    // strore result in target array `target`
    const target = [];

    // step 1 - process each (value, index) pair from left to right
    for(let i=0; i<n; i++){
        // current value to insert
        let value = nums[i];

        // position where to insert
        let idx = index[i];

        // step 2 - insert value at specified index and shift existing elements to the right
        target.splice(idx, 0, value);
    }

    // step 3 - return target array `target`
    return target;
};

// const nums = [0,1,2,3,4], index = [0,1,2,2,1];

// const nums = [1,2,3,4,0], index = [0,1,2,3,0];

const nums = [1], index = [0];
console.log(createTargetArray(nums, index));