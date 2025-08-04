
// Problem link - https://leetcode.com/problems/smallest-index-with-equal-value/?envType=problem-list-v2&envId=array

let smallestEqual = function(nums) {
    // step 1 - iterate on `nums` array
    for(let i=0; i<nums.length; i++){
        // step 2 - check the condition, `i mod 10 == nums[i]`
        if(i % 10 === nums[i]){
            // step 3 - return index `i` immdiately
            return i;
        }
    }

    // step 4 - otherwise retun `-1` if given condition doesn't satisfy
    return -1;
};

// const nums = [0,1,2];

// const nums = [4,3,2,1];

const nums = [1,2,3,4,5,6,7,8,9,0];
console.log(smallestEqual(nums));