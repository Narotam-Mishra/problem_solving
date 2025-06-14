
// Problem link - https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/?envType=problem-list-v2&envId=sliding-window

let minimumDifference = function(nums, k) {
    // store minimum possible difference in `minDiff`
    let minDiff = Infinity;
    
    // step 1 - edge case : if k is 1, difference is always 0
    if(k === 1) return 0;

    // step 2 - sort the array so that close values are next to each other
    nums.sort((a, b) => a - b);

    // step 3 - iterate on array elements in window of size-k
    for(let i=0; i<=nums.length - k; i++){
        // take the current window of size k over the sorted array
        const windowMin = nums[i];
        const windowMax = nums[i+k-1];

        // step 4 - find difference and update minimum difference
        const diff = windowMax - windowMin;
        minDiff = Math.min(minDiff, diff);
    }

    // step 5 - return the smallest difference found
    return minDiff;
};

// const nums = [90], k = 1;

const nums = [9,4,1,7], k = 2;
console.log(minimumDifference(nums, k));
