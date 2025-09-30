
// Problem link - https://leetcode.com/problems/find-triangular-sum-of-an-array/description/?envType=daily-question&envId=2025-09-30

let triangularSum = function(nums) {
    // find size of input array `nums`
    let n = nums.length;

    // step 1 - iterate till we have only one element left in array `nums`
    while(n > 1){
        // step 2 - process each adjacent pairs of nums array
        for(let i=0; i<n-1; i++){
            // step 3 - sdd current element with next element and take mod 10
            // store result back in position i 
            nums[i] = (nums[i] + nums[i+1]) % 10;
        }

        // step 4 - reduce the effective length of our array
        n--;
    }

    // step 5 - return the single remaining element
    return nums[0];
};

// const nums = [1,2,3,4,5];

const nums = [5];
console.log(triangularSum(nums));