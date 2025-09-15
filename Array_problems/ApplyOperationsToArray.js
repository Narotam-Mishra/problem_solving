
// Problem link - https://leetcode.com/problems/apply-operations-to-an-array/description/?envType=problem-list-v2&envId=array

let applyOperations = function(nums) {
    // find size of `nums` size
    const n = nums.length;

    // step 1 - iterate on input array and perform operations
    for(let i=0; i<n-1; i++){
        if(nums[i] === nums[i+1]){
            nums[i] *= 2
            nums[i+1] = 0;
        }
    }

    // step 2 - move zeros to end
    let k = 0;
    for(let i=0; i<n; i++){
        if(nums[i] !== 0){
            let temp = nums[i];
            nums[i] = nums[k];
            nums[k] = temp;
            k++;
        }
    }

    // step 3 - return resultant array `nums`
    return nums;
};

// const nums = [1,2,2,1,1,0];

const nums = [0,1];
console.log(applyOperations(nums));