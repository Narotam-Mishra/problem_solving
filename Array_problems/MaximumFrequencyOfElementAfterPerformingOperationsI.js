
// Problem link - https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/description/?envType=daily-question&envId=2025-10-21

// Using Brute Force Approach (this will give TLE)
let maxFrequency1 = function(nums, k, numOperations) {
    const n = nums.length;

    // step 1 - sort array for efficient range queries
    nums.sort((a,b) => a - b);

    // step 2 - try each unique value and its boundaries as target
    const targets = new Set();
    for (let num of nums) {
        targets.add(num);      
        targets.add(num - k);
        targets.add(num + k);   
    }

    // keep track of maximum possible frequency after operations
    let maxFreq = 0;

    // step 3 - using two-pointers to find range [target-k, target+k]
    for(let target of targets){
        let alreadyAtTarget = 0;
        let inRange = 0;

        for(let num of nums){
            // within range
            if(num < target - k) continue;

            // out of range
            if(num > target + k) break;

            // step 4 - check if current number is already equal to target or not
            if(num === target){
                alreadyAtTarget++;
            }else{
                inRange++;
            }
        }

        // step 5 - find maximum frequency 
        let freq = alreadyAtTarget + Math.min(numOperations, inRange);
        maxFreq = Math.max(freq, maxFreq);
    }

    // step 6 - return maximum possible frequency
    return maxFreq;
};

let maxFrequency = function(nums, k, numOperations) {
    // Step 1: Find the maximum possible value after operations
    // Any element can reach at most (its_value + k)
    const maxSize = Math.max(...nums) + k;
    
    // Step 2: Create frequency array to store count of each value
    // freq[i] = how many elements in nums have value i
    const freq = new Array(maxSize + 1).fill(0);
    
    for (let num of nums) {
        freq[num]++;
    }
    
    // Step 3: Convert frequency array to prefix sum array
    // After this: freq[i] = count of elements with value <= i
    // This allows O(1) range queries: count in [L, R] = freq[R] - freq[L-1]
    for (let i = 1; i <= maxSize; i++) {
        freq[i] += freq[i - 1];
    }
    
    let res = 0;
    
    // Step 4: Try every possible target value from 0 to maxSize
    for (let target = 0; target <= maxSize; target++) {
        // Skip if no element currently has this value
        // freq[target] - freq[target-1] gives count at exactly 'target'
        if (freq[target] === 0) continue;
        
        // Step 5: Define the reachable range for this target
        // Elements in [target-k, target+k] can be modified to reach 'target'
        const left = Math.max(0, target - k);
        const right = Math.min(maxSize, target + k);
        
        // Step 6: Count total elements in the reachable range using prefix sum
        // Elements in range [left, right]
        const totalCount = freq[right] - (left > 0 ? freq[left - 1] : 0);
        
        // Step 7: Count elements already at target (no operation needed)
        const targetCount = freq[target] - (target > 0 ? freq[target - 1] : 0);
        
        // Step 8: Calculate required operations
        // Elements that need modification = totalCount - targetCount
        const reqOperations = totalCount - targetCount;
        
        // Step 9: Calculate achievable frequency
        // We get all elements already at target + modified elements (limited by numOperations)
        const maxFreq = targetCount + Math.min(reqOperations, numOperations);
        
        res = Math.max(res, maxFreq);
    }
    
    return res;
};

// const nums = [1,4,5], k = 1, numOperations = 2;

const nums = [5,11,20,20], k = 5, numOperations = 1;
console.log(maxFrequency(nums, k, numOperations));