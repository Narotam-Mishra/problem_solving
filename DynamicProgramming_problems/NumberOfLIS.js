
// Problem link - https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

// Approach - using DP memoization technique

let findNumberOfLIS = function(nums) {
    let size = nums.length;
    // If array is empty or has only one element, return its length
    if(size <= 1) return size;

    // there will be atleast 1 increasing subsequence for each array elements
    // Length of longest increasing subsequence ending at index i
    let dp = Array(size).fill(1);

    // Count of longest increasing subsequences ending at index i
    let count = Array(size).fill(1);

    // there will be atleast 1 increasing subsequence for each array elements
    let maxLength = 1;

    // using DP technique to calculate LIS lengths in dp and LIS counts in count array
    for(let i=1; i<size; i++){
        for(let prev = 0; prev < i; prev++){
            // If nums[i] is greater than nums[prev], we have a potential increasing subsequence
            if (nums[i] > nums[prev]) {
              // and adding current nums[i] makes a longer subsequence, update lengths and counts
              if (1 + dp[prev] > dp[i]) {
                dp[i] = dp[prev] + 1;
                // inherit count from previous count
                count[i] = count[prev];
              } else if (1 + dp[prev] === dp[i]) {
                // If adding nums[i] maintains the same length, add to existing count
                count[i] += count[prev];
              }
            }
        }
        maxLength = Math.max(maxLength, dp[i]);
    }

    let res = 0;
    // find all indices where LIS's length is equal to maxLength and sum their counts
    for(let i=0; i<size; i++){
        if(dp[i] === maxLength){
            res += count[i];
        }
    }
    return res;
};

// let arr = [1,3,5,4,7];

let arr = [2,2,2,2,2];
let ans = findNumberOfLIS(arr);
console.log(ans);