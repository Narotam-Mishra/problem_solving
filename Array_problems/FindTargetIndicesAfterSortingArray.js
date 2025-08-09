
// Problem link - https://leetcode.com/problems/find-target-indices-after-sorting-array/description/?envType=problem-list-v2&envId=array

let targetIndices = function(nums, target) {
    // store result in `res` array
    const res = [];

    // step 1 - sort that array
    nums.sort((a,b) => a - b);

    // step 2 - iterate on each element of array
    for(let i=0; i<nums.length; i++){
        // step 3 - check if current element of array is equal to target
        if(nums[i] === target){
            // store indices in `res`
            res.push(i);
        }
    }

    // step 4 - return `res`
    return res;
};

// const nums = [1,2,5,2,3], target = 2;

// const nums = [1,2,5,2,3], target = 3;

const nums = [1,2,5,2,3], target = 5;
console.log(targetIndices(nums, target));