
// Problem link - https://leetcode.com/problems/transform-array-by-parity/description/?envType=problem-list-v2&envId=array

let transformArray = function(nums) {
    // step 1 - iterate on array 
    for(let i=0; i<nums.length; i++){
        // step 2 - modify array's elements as per even-odd parity
        if(nums[i] % 2 === 0){
            // for even-number update it to 0
            nums[i] = 0;
        }else{
            // for odd-number update it to 1
            nums[i] = 1;
        }
    }

    // step 3 - sort the array in non-decreasing order
    nums.sort((a,b) => a - b);

    // step 4 - return the final modified array as result
    return nums;
};

// const nums = [4,3,2,1];

const nums = [1,5,1,4,2]
console.log(transformArray(nums));