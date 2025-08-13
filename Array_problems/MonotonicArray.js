
// Problem link - https://leetcode.com/problems/monotonic-array/description/?envType=problem-list-v2&envId=array

let isMonotonic = function(nums) {
    // base case: arrays with 1 element is always monotonic
    if(nums.length === 1) return true;

    // step 1 - track if we have seen increasing and decreasing trend in `nums` array
    let hasIncreasing = false;
    let hasDecresing = false;

    // step 2 - iterate on `nums` array
    for(let i=0; i<nums.length-1; i++){
        // step 3 - compare current element with next element
        if(nums[i] < nums[i+1]){
            hasIncreasing = true;
        }else if(nums[i] > nums[i+1]){
            hasDecresing = true;
        }

        // step 4 - early termination : if both trends exist, array is not monotonic
        if(hasIncreasing && hasDecresing){
            return false;
        }
    }

    // step 5 - array is monotonic if we haven't seen both increasing and decreasing, so return true
    return true;
};

// const nums = [1,2,2,3];

// const nums = [6,5,4,4];

const nums = [1,3,2];
console.log(isMonotonic(nums));