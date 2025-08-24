
// Problem link - https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/?envType=daily-question&envId=2025-08-24

let longestSubarray = function(nums) {
    // using sliding window appraoch
    const n = nums.length;

    // left pointer of window
    let left = 0;

    // store count zeros in current window
    let zeroCount = 0;

    // store maximum length `maxLen` found so far
    let maxLen = 0;

    // step 1 - expand the window from left to right
    for(let right = 0; right<n; right++){
        // step 2 - count zeros in current window
        if(nums[right] === 0){
            zeroCount++;
        }

        // step 3 - if we have more than 1 zero than shrink the window from left
        while(zeroCount > 1){
            if(nums[left] === 0){
                zeroCount--;
            }
            left++;
        }

        // step 4 - update maximum length `maxLen` founs so far
        // subtract 1 because we must delete exactly one element
        maxLen = Math.max(maxLen, right - left + 1 - 1);
    }

    // step 5 - return maximum length of non-empty subarray containing only 1
    return maxLen;
};

// const nums = [1,1,0,1];

// const nums = [0,1,1,1,0,1,1,0,1];

const nums = [1,1,1];
console.log(longestSubarray(nums));