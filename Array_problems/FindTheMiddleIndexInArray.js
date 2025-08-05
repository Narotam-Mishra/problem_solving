
// Problem link - https://leetcode.com/problems/find-the-middle-index-in-array/description/?envType=problem-list-v2&envId=array

let findMiddleIndex = function(nums) {
    // find size of `nums` array
    const n = nums.length;

    // step 1 - find totalSum of `nums`
    let totalSum = 0;
    for(let num of nums){
        totalSum += num;
    }

    // using formula, totalSum = leftSum + rightSum + nums[i]
    // so, rightSum = totalSum - leftSum - nums[i];

    // step 2 - iterate through array to find middle index
    // store left sum in `leftSum`
    let leftSum = 0;
    for(let i=0; i<n; i++){
        // step 3 - calculate rightSum using above formula
        let rightSum = totalSum - leftSum - nums[i];

        // step 4 - check if leftSum equals rightSum
        if(leftSum === rightSum){
            // return middle index `i` immediately
            return i;
        }

        // step 5 - calculate leftSum
        leftSum += nums[i];
    }

    // step 6 - no valid middle index found, so return -1
    return -1
};

// const nums = [2,3,-1,8,4];

// const nums = [1,-1,4];

const nums = [2,5];
console.log(findMiddleIndex(nums));