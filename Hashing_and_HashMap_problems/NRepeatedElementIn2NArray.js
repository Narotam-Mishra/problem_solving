
// Problem link : https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/?envType=problem-list-v2&envId=hash-table

let repeatedNTimes1 = function(nums) {
    // step 1 - create map to store frequency of each number from nums
    const map = {};
    
    // step 2 - add frequency and parallely check the frequency
    for(let num of nums){
        map[num] = (map[num] || 0) + 1;
        // all numbers are unique except one number
        if(map[num] > 1){
            // return that one unique number
            return num;
        }
    }
    return -1;
};

let repeatedNTimes = function(nums) {
    // find size of nums
    const n = nums.length;

    // step 1 - start from index 2 because we want to compare
    // nums[i] with nums[i-1] and nums[i-2]
    for (let i = 2; i < n; i++) {
        // case 1 - same element appears consecutively
        if (nums[i] == nums[i - 1]) {
            return nums[i];
        }

        // case 2 - same element appears with one gap
        if (nums[i] == nums[i - 2]) {
            return nums[i];
        }
    }

    // step 2 : Edge case - If not found in the loop, the repeated element
    // must be at the end
    return nums[n-1];
};


const nums = [1,2,3,3];

// const nums = [2,1,2,5,3,2];

// const nums = [5,1,5,2,5,3,5,4];
console.log(repeatedNTimes(nums));
