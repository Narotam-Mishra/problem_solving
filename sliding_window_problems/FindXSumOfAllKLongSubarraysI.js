
// Problem link - https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/description/?envType=daily-question&envId=2025-11-04

let findXSum = function(nums, k, x) {
    const n = nums.length;
    const ans = [];

    // helper function to calculate x-sum for a given subarray
    function calculateXSum(s, e){
        // step 1 - count frequency of each element in current window
        const frq = new Map();

        for(let i=s; i<=e; i++){
            frq.set(nums[i], (frq.get(nums[i]) || 0) + 1);
        }

        // step 2 - convert frequency map to array of [value, frequency] pairs
        const pairs = Array.from(frq.entries());

        // edge : if distinct pairs < x, return sum of all elements
        if(pairs.length < x){
            let sum = 0;
            for(let i=s; i<=e; i++){
                sum += nums[i];
            }
            return sum;
        }
        
        // step 3 - sort pairs by frequency (desc), then by value (desc)
        pairs.sort((a, b) => {
            const [val1, f1] = a;
            const [val2, f2] = b;

            // first priority: higher frequency
            if(f1 !== f2){
                return f2 - f1;
            }

            // second priority: higher value (tiebreaker)
            return val2 - val1;
        })

        // step 4 - calculate x-sum from top x elements
        let xSum = 0;
        for(let i=0; i<x; i++){
            const [val, freq] = pairs[i];
            xSum += val * freq;
        }

        return xSum;
    }

    // step 5 - process each k-length subarray using sliding window
    for(let i=0; i<=n-k; i++){
        const sumX = calculateXSum(i, i+k-1);
        ans.push(sumX);
    }

    // step 6 - return final answer `ans`
    return ans;
};

// const nums = [1,1,2,2,3,4,2,3], k = 6, x = 2;

const nums = [3,8,7,8,7,5], k = 2, x = 2;
console.log(findXSum(nums, k, x));