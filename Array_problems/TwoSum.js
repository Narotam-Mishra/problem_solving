
// Problem link - https://leetcode.com/problems/two-sum/description/

// Approach - 1 (Brute Force)

let twoSum = function(nums, target) {
    const res = [];

    for(let i=0; i<=nums.length-2; i++){
        for(let j=i+1; j<=nums.length; j++){
            if(nums[i] + nums[j] === target){
                res.push(i);
                res.push(j);
            }
        }
    }
    return res;
};

// Approach - 2

let twoSum1 = function(nums, target) {

    for(let i=0; i<=nums.length-2; i++){
        for(let j=i+1; j<=nums.length; j++){
            if(nums[i] + nums[j] === target){
                return [i,j];
            }
        }
    }
    return res;
};