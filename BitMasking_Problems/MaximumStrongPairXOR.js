
// Problem link : https://leetcode.com/problems/maximum-strong-pair-xor-i/description/?envType=problem-list-v2&envId=bit-manipulation

let maximumStrongPairXor = function(nums) {
    // intialize `maxXor` to 0 to store result
    let maxXor = 0;

    // iterate on each pairs
    for(let i=0; i<nums.length; i++){
        for(let j=i+1; j<nums.length; j++){
            
            // check strong pair condition
            if(Math.abs(nums[i] - nums[j]) <= Math.min(nums[i], nums[j])){
                // calculate XOR and find maximum XOR value
                maxXor = Math.max(maxXor, nums[i]^nums[j]);
            }
        }
    }
    // return result
    return maxXor;
};

// let nums = [1, 2, 3, 4, 5]

// let nums = [10, 100]

let nums = [5, 6, 25, 30];
console.log(maximumStrongPairXor(nums));
