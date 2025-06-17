
// Problem link - https://leetcode.com/problems/array-partition/description/?envType=problem-list-v2&envId=array

let arrayPairSum = function(nums) {
    // store maximum sum of minimums in `maxSum`
    let maxSum = 0;

    // step 1 - sort the array to group similar values together
    // this ensures we pair each number with its closest neighbor
    nums.sort((a,b) => a-b);

    // step 2 -iterate of array's number
    // we take elements at even indices (0, 2, 4, ...) because after sorting,
    // these will be the minimum values in each optimal pair
    for(let i=0; i<nums.length; i+=2){
        // step 3 - calculate the sum
        maxSum += nums[i];
    }

    // step 4 - return maximum sum of minimums in `maxSum`
    return maxSum;
};

// const nums = [1,4,3,2];

const nums = [6,2,6,5,1,2];
console.log(arrayPairSum(nums));
