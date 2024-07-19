
// /Problem link - https://leetcode.com/problems/number-of-good-pairs/

let numIdenticalPairs = function(nums) {
    let count = 0;
    for(let i=0; i<nums.length; i++){
        for(let j=i+1; j<nums.length; j++){
            if(i < j && nums[i] === nums[j]) count++;
        }
    }
    return count;
};

// let nums = [1, 2, 3, 1, 1, 3]

// let nums = [1,1,1,1]

let nums = [1,2,3]
console.log(numIdenticalPairs(nums));