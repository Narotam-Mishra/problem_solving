
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
    // step 1 - find the maximum possible value after operations
    const maxSize = Math.max(...nums) + k;
    
    // step 2 - create frequency array to store count of each value
    const freq = new Array(maxSize + 1).fill(0);
    
    for (let num of nums) {
        freq[num]++;
    }
    
    // step 3 - convert frequency array to prefix sum array
    // this allows O(1) range queries: count in [L, R] = freq[R] - freq[L-1]
    for (let i = 1; i <= maxSize; i++) {
        freq[i] += freq[i - 1];
    }
    
    // step 4 - try every possible target value from 0 to maxSize
    let res = 0;
    for (let target = 0; target <= maxSize; target++) {
        // skip if no element currently has this value
        if (freq[target] === 0) continue;
        
        // step 5 - define the reachable range for this target
        const left = Math.max(0, target - k);
        const right = Math.min(maxSize, target + k);
        
        // step 6 - count total elements in the reachable range using prefix sum
        const totalCount = freq[right] - (left > 0 ? freq[left - 1] : 0);
        
        // step 7 - count elements already at target (no operation needed)
        const targetCount = freq[target] - (target > 0 ? freq[target - 1] : 0);
        
        // step 8 - calculate required operations
        const reqOperations = totalCount - targetCount;
        
        // step 9 - calculate achievable frequency
        const maxFreq = targetCount + Math.min(reqOperations, numOperations);
        
        // update result `res`
        res = Math.max(res, maxFreq);
    }

    // step 10 - return final result `res`
    return res;
};

const nums = [1,4,5], k = 1, numOperations = 2;

// const nums = [5,11,20,20], k = 5, numOperations = 1;
console.log(maxFrequency(nums, k, numOperations));