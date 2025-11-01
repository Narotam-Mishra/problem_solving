
// Problem link - https://leetcode.com/problems/minimum-operations-to-make-array-equal-to-target/description/

let minimumOperations = function(nums, target) {
    // get size of input array `nums`
    const n = nums.length;

    // store final result in `res`
    let res = 0;

    // step 1 - iterate on nums perform given operations
    let curr = 0, prev = 0;
    for(let i=0; i<n; i++){
        curr = target[i] - nums[i];

        // step 2 - check for sign change
        if((prev > 0 && curr < 0) || (prev < 0 && curr > 0)){
            res += Math.abs(curr);
        }

        // step 3 - check if absolute value of current is greater than previous value
        else if(Math.abs(curr) > Math.abs(prev)){
            res += Math.abs(curr - prev);
        }

        // step 4 - update previous, `prev`
        prev = curr;
    }

    // step 5 - return final result `res`
    return res;
};

// const nums = [3,5,1,2], target = [4,6,2,4];

const nums = [1,3,2], target = [2,1,4];
console.log(minimumOperations(nums, target));