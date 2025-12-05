
// Problem link - https://leetcode.com/problems/count-partitions-with-even-sum-difference/?envType=daily-question&envId=2025-12-05

let countPartitions = function(nums) {
    let n = nums.length;

    // step 1 - find prefix sum
    const prefixSum = new Array(n).fill(0);
    prefixSum[0] = nums[0];
    for (let i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    // step 2 - count partition
    let c = 0, totalSum = prefixSum[n - 1];
    for (let i = 0; i < n - 1; i++) {
        // find left partition sum
        let leftSum = prefixSum[i];

        // find right parition sum
        let rightSum = totalSum - leftSum;

        // find difference between left and right sum
        let diff = leftSum - rightSum;

        // check if difference, `diff` is even or not
        if (diff % 2 == 0) {
            // increment count
            c++;
        }
    }

    // step 3 - return count, `c`
    return c;
};

// const nums = [10,10,3,7,6];

// const nums = [1,2,2];

const nums = [2,4,6,8];
console.log(countPartitions(nums));