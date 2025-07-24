
// Problem link - https://leetcode.com/problems/special-array-i/description/?envType=problem-list-v2&envId=array

let isArraySpecial = function(nums) {
    const n = nums.length;
    // check edge case
    if(n === 1) return true;

    // step 1 - iterate on each adjacent pairs
    for(let i=1; i<n; i++){
        // step 2 - if adjacent pair is not odd and even then return false immediately
        if(((nums[i-1] & 1) === 1) && ((nums[i] & 1) === 1) || ((nums[i-1] & 1) === 0) && ((nums[i] & 1) === 0)){
            return false;
        }
    }

    // step 3 - otherwise return true
    return true;
};

// const nums = [1];

// const nums = [2,1,4];

// const nums = [4,3,1,6];

const nums = [2,10]
console.log(isArraySpecial(nums));