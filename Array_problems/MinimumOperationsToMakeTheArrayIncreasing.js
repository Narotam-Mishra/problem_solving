
// Problem link - https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/description/?envType=problem-list-v2&envId=array

let minOperations = function(nums) {
    // edge case - array with 0 or 1 element is already strictly increasing
    const n = nums.length;
    if(n <= 1){
        return 0;
    }

    // store minimum number of operations needed to make nums strictly increasing
    let mOperations = 0;

    // step 1 - iterate through array starting from second element
    for(let i=1; i<n; i++){

        // step 2 - check if current element violates strictly increasing property
        if(nums[i] <= nums[i-1]){

            // step 3 - calculate minimum value current element should have
            // to maintain strictly increasing property
            let targetVal = nums[i-1] + 1;

            // step 4 - calculate operations needed to reach target value
            let incrementNeeded = targetVal - nums[i];

            // step 5 - add to total operations
            mOperations += incrementNeeded;

            // step 6 - update current element to target value
            nums[i] = targetVal;
        }
    }

    // step 7 - return minimum operations `mOperations` needed
    return mOperations;
};

// const nums = [1,1,1];

// const nums = [1,5,2,4,1];

const nums = [8];
console.log(minOperations(nums));