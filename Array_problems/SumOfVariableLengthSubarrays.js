
// Problem link - https://leetcode.com/problems/sum-of-variable-length-subarrays/description/?envType=problem-list-v2&envId=array

let subarraySum = function(nums) {
    // find size of input array `nums`
    const n = nums.length;
    
    // store final subarray sum in `subArrSum`
    let subArrSum = 0;

    // step 1 - iterate through each index `i`
    for(let i=0; i<n; i++){
        // step 2 - compute start index for the subarray nums[start...i]
        let start = Math.max(0, i-nums[i]);
        
        // step 3 - add up all elements from nums[start] to nums[i]
        for(let j=start; j<=i; j++){
            subArrSum += nums[j];
        }
    }

    // step 4 - return final subarray sum
    return subArrSum;
};

const nums = [2,3,1];

// const nums = [3,1,1,2];
console.log(subarraySum(nums));