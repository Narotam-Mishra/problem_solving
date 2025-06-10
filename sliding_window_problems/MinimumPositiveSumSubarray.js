
// Problem link - https://leetcode.com/problems/minimum-positive-sum-subarray/description/?envType=problem-list-v2&envId=sliding-window

let minimumSumSubarray = function(nums, l, r) {
    // store minimum positive sum in `minPositiveSum`
    let n = nums.length;
    let minPositiveSum = Infinity;

    // step 1 - iterate through all possible subarray lengths from l to r
    for(let len=l; len<=r; len++){
        // step 2 - calculate sum of first window of this length
        let windowSum = 0;
        for(let i=0; i<len; i++){
            windowSum += nums[i];
        }

        // check if first window has positive sum
        if(windowSum > 0 && windowSum < minPositiveSum){
            minPositiveSum = windowSum;
        }

        // step 3 - slide window across the array
        for(let start=1; start<=n-len; start++){
            // remove left most element of previous window
            windowSum -= nums[start-1];

            // add the rightmost element of current window
            windowSum += nums[start+len-1];

            // check if first window has positive sum
            if(windowSum > 0 && windowSum < minPositiveSum){
                minPositiveSum = windowSum;
            }
        }

    }

    // step 4 - return -1 if no positive sum found, otherwise return the minimum positive sum
    return minPositiveSum === Infinity ? -1 : minPositiveSum;
};

const nums = [-2, 2, -3, 1], l = 2, r = 3;

// const nums = [3, -2, 1, 4], l = 2, r = 3;

// const nums = [1, 2, 3, 4], l = 2, r = 4;
console.log(minimumSumSubarray(nums, l, r));
