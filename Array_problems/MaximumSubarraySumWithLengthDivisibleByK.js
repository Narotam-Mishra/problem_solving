
// Problem link - https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/description/?envType=daily-question&envId=2025-11-27

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
let maxSubarraySum = function(nums, k) {
    const n = nums.length;
    const INF = Number.MAX_SAFE_INTEGER;
    
    // minPref[r] stores the minimum prefix sum encountered at any position 
    const minPref = new Array(k).fill(INF);

    // running prefix sum: sum of elements from start to current position
    let pref = 0;  
    let ans = Number.MIN_SAFE_INTEGER;
    
    minPref[0] = 0;
    
    // step 1 - iterate through each position in the array (1-indexed for clarity)
    for (let j = 1; j <= n; j++) {
        // update prefix sum: P[j] = P[j-1] + nums[j-1]
        pref += nums[j - 1];
        
        // step 2 - calculate remainder class of current position
        const rem = j % k;
        
        // step 3 - check If we've seen a position with same remainder before
        if (minPref[rem] !== INF) {
            // subarray sum = current_prefix - smallest_previous_prefix_with_same_remainder
            ans = Math.max(ans, pref - minPref[rem]);
        }
        
        // step 4 - Update minimum prefix sum for this remainder class
        minPref[rem] = Math.min(minPref[rem], pref);
    }

    // step 5 - return final result, `res`
    return ans;
}

// test case
// const nums = [1, 2], k = 1;

// const nums = [-1,-2,-3,-4,-5], k = 4;

const nums = [-5,1,2,-3,4], k = 2;
console.log(maxSubarraySum(nums, k));  