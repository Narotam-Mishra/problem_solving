
// Problem link - https://leetcode.com/problems/maximum-total-damage-with-spell-casting/description/?envType=daily-question&envId=2025-10-11

let maximumTotalDamage = function(power) {
    // step 1 - count frequency of each power value
    const freqMap = new Map();
    for (const p of power) {
        freqMap.set(p, (freqMap.get(p) || 0) + 1);
    }
    
    // step 2 - extract and sort unique power values
    const nums = Array.from(freqMap.keys()).sort((a, b) => a - b);
    const n = nums.length;
    
    // step 3 - initialize memoization array
    const dp = new Array(n).fill(-1);
    
    // recursive function to find maximum damage
    const solveRec = (i) => {
        // base case: reached end
        if (i >= n) {
            return 0;
        }
        
        // return cached result
        if (dp[i] !== -1) {
            return dp[i];
        }
        
        // option 1: skip current power
        const skipOption = solveRec(i + 1);
        
        // option 2: take current power
        // find next non-conflicting power using binary search
        let left = i + 1;
        let right = n;
        const target = nums[i] + 3;
        
        // binary search for first element >= target
        while (left < right) {
            const mid = Math.floor((left + right) / 2);
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        const takeOption = nums[i] * freqMap.get(nums[i]) + solveRec(left);
        
        // step 4 - store and return maximum
        dp[i] = Math.max(skipOption, takeOption);
        return dp[i];
    };
    
    // step 5 - start recursion from index 0
    return solveRec(0);
};

// const power = [1,1,3,4];

const power = [7,1,6,6];
console.log(maximumTotalDamage(power));