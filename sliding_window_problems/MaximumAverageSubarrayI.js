
// Problem link - https://leetcode.com/problems/maximum-average-subarray-i/description/?envType=problem-list-v2&envId=sliding-window

let findMaxAverage = function(nums, k) {
    // edge case: if array length is less than k
    let n = nums.length;
    if(n < k){
        return nums.reduce((sum, num) => sum + num, 0) / n;
    }

    // step 1 - calculate sum of first k-elements of array
    let currSum = 0;
    for(let i=0; i<k; i++){
        currSum += nums[i];
    }

    // step 2 - initialize maximum sum `maxSum`
    let maxSum = currSum;

    // step 3 - slide the window through rest of array
    // start from index k and go till end
    for(let i=k; i<n; i++){
        // slide window: remove leftmost element, add rightmost element
        currSum = currSum - nums[i-k] + nums[i];

        // step 4 - update maximum sum if current sum is larger
        maxSum = Math.max(maxSum, currSum);
    }

    // step 5 - return maximum average (sum divided by k)
    return maxSum / k;
};

// const nums = [1,12,-5,-6,50,3], k = 4;

const nums = [5], k = 1;
console.log(findMaxAverage(nums, k));
