
// Problem link - https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/description/?envType=problem-list-v2&envId=array

let minOperations = function(nums, k) {
    // step 1 - calculate total sum of `nums` array
    const totalSum = nums.reduce((sum, num) => sum += num, 0);

    // step 2 - find remainder when divided by `k`
    const remainder = totalSum % k;

    // step 3 - if already divisble, return 0
    if(remainder === 0) return 0;

    // step 4 - check if it is not possible (totalSum >= remainder)
    if(totalSum < remainder){
        return -1;
    }

    // we need exactly 'remainder' operations to make sum divisible by k
    // we just need to reduce the total sum by 'remainder'
    // step 5 - hence return `remainder`
    return remainder;
};

// const nums = [3,9,7], k = 5;

// const nums = [4,1,3], k = 4;

const nums = [3,2], k = 6;
console.log(minOperations(nums, k));