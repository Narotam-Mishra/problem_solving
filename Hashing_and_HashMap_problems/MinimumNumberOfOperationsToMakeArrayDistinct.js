
// Problem link : https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/description/?envType=problem-list-v2&envId=hash-table

let minimumOperations1 = function(nums) {
    // step 1 - initialize all variables
    let minOp = 0;
    let i = 0;
    const seen = new Set();

    // step 2 - iterate over all elements
    while(i < nums.length){
        // add elements until a duplicate is found
        if(!seen.has(nums[i])){
            seen.add(nums[i]);
            i++;
        }else{
            // if duplicate found, remove 3 elements from start
            nums.splice(0, Math.min(3, nums.length));
            seen.clear();
            i = 0;
            minOp++;
        }
    }

    // step 3 - return minimum operation needed
    return minOp;
};

let minimumOperations = function(nums) {
    // step 1: create a boolean array to track seen numbers (assuming range [0, 100])
    let bucket = new Array(101).fill(false);

    // step 2: traverse the array from right to left
    for (let i = nums.length - 1; i >= 0; i--) {
        // if a duplicate is found, calculate the number of operations
        if (bucket[nums[i]]) {
            return Math.ceil((i + 1) / 3); // Equivalent to (i + 3) / 3
        }
        // mark number as seen
        bucket[nums[i]] = true;
    }

    // step 3: if no duplicates, return 0
    return 0;
};

// const nums = [1,2,3,4,2,3,3,5,7];

const nums = [4,5,6,4,4];

// const nums = [6,7,8,9];
console.log(minimumOperations(nums));
