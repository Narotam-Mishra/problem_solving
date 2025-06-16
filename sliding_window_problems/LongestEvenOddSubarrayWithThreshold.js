
// Problem link - https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/description/?envType=problem-list-v2&envId=sliding-window

let longestAlternatingSubarray = function(nums, threshold) {
    // store maximum length of alternating subarray in `maxLen`
    let maxLen = 0;
    const n = nums.length;

    // step 1 - iterate through each potential starting position
    for(let l=0; l<n; l++){
        // step 2 - check if current position can be a valid start
        if(nums[l] % 2 !== 0 || nums[l] > threshold){
            // skip starting position
            continue;
        }

        // step 3 - found a valid starting position
        let r = l;

        // step 4 - extend the subarray while conditions are met
        while(r < n){
            // step 5 - check condition 3: current element must be <= threshold
            if(nums[r] > threshold) break;

            // step 6 - check condition 2: alternating parity, except first element
            if(r > l && nums[r] % 2 === nums[r-1] % 2){
                break;
            }

            // step 7 - all conditions satisfied, move to next position
            r++;
        }

        // step 8 - calculate and update maximum length
        maxLen = Math.max(maxLen, r - l);
    }

    // step 9 - return maximum subarray length `maxLen`
    return maxLen;
};

const nums = [3,2,5,4], threshold = 5;

// const nums = [1,2], threshold = 2;

// const nums = [2,3,4,5], threshold = 4;
console.log(longestAlternatingSubarray(nums, threshold));
