
// Problem link - https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/description/?envType=daily-question&envId=2025-10-22

let maxFrequency = function(nums, k, numOperations) {
    // step 1 - find the maximum possible value after operations
    const maxSize = Math.max(...nums) + k;

    // step 2 - initialize data structures
    // map for difference array - stores boundary changes
    const diff = new Map();
    
    // frequency map to track count of each original value in nums
    const freq = new Map();

    // step 3 - mark reachable ranges for each element
    for(let i = 0; i < nums.length; i++){
        // count frequency of current element (elements already at this value)
        freq.set(nums[i], (freq.get(nums[i]) || 0) + 1);

        // calculate the range [l, r] this element can reach with operations
        const l = Math.max(nums[i] - k, 0);           // left boundary (can't go below 0)
        const r = Math.min(nums[i] + k, maxSize);     // right boundary (bounded by maxSize)

        // use difference array technique for O(1) range update
        diff.set(l, (diff.get(l) || 0) + 1);         // increment at range start
        diff.set(r + 1, (diff.get(r + 1) || 0) - 1); // decrement after range end

        // ensure the current value exists as a key in diff map
        if(!diff.has(nums[i])){
            diff.set(nums[i], 0);
        }
    }

    // step 4 - sort the keys to process in ascending order (like sorted map)
    const sortedTargets = Array.from(diff.keys()).sort((a, b) => a - b);
    
    // process each possible target value using prefix sum on difference array
    let res = 0;      // result - maximum frequency achievable
    let cumSum = 0;   // cumulative sum to convert difference array to actual counts
    
    for(const target of sortedTargets){
        let deltaValue = diff.get(target);  // boundary change at this position
        
        // convert difference value to actual count using prefix sum
        // cumSum holds the count from previous position
        const actualCount = deltaValue + cumSum;
        
        // update the map with actual count
        diff.set(target, actualCount);
        
        // now actualCount represents: total elements that can reach this target
        // get count of elements already at target value (no operation needed)
        const targetFreq = freq.get(target) || 0;

        // calculate how many OTHER elements can reach this target
        // actualCount = total elements that can reach target (including those already there)
        // targetFreq = elements already at target
        // reqOperations = elements that need an operation to reach target
        const reqOperations = actualCount - targetFreq;

        // we can use at most numOperations, so take minimum
        const maxFreq = Math.min(reqOperations, numOperations);

        // total frequency achievable for this target:
        // = elements already at target + elements we modify to reach target
        res = Math.max(res, targetFreq + maxFreq);

        // update cumulative sum for next iteration
        cumSum = actualCount;
    }

    // step 5 - return the maximum frequency found
    return res;
};

// const nums = [1,4,5], k = 1, numOperations = 2;

const nums = [5,11,20,20], k = 5, numOperations = 1;
console.log(maxFrequency(nums, k, numOperations));