
// Problem link - https://leetcode.com/problems/number-of-zero-filled-subarrays/?envType=daily-question&envId=2025-08-19

let zeroFilledSubarray = function(nums) {
    // store total count and consecutive zeros count
    let totalCount = 0;
    let consecutiveZeros = 0;

    // step 1 - traverse through array
    for(let i=0; i<nums.length; i++){
        // step 2 - count zero
        if(nums[i] === 0){
            // each new zero extends all previous subarrays by 1
            consecutiveZeros++;
            totalCount += consecutiveZeros;
        }else{
            // step 3 - reset when we hit a non-zero
            consecutiveZeros = 0;
        }
    }

    // step 4 - return total count `totalCount`
    return totalCount;
};

// const nums = [1,3,0,0,2,0,0,4];

const nums = [0,0,0,2,0,0];
console.log(zeroFilledSubarray(nums));