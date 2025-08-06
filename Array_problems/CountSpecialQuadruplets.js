
// Problem link - https://leetcode.com/problems/count-special-quadruplets/description/?envType=problem-list-v2&envId=array

// Approach - 1 (using Brute Force)
let countQuadruplets1 = function(nums) {
    // get length of `nums` array
    const n = nums.length;

    // step 1 - store quadruplets in `count`
    let count = 0;

    // we'll iterate from left to right on each quadruplet
    // step 2 - this way we can build our frequency map incrementally
    for(let a=0; a<n-3; a++){
        for(let b=a+1; b<n-2; b++){
            for(let c = b+1; c<n-1; c++){
                for(let d = c+1; d<n; d++){
                    // step 3 - check the given condition
                    if(nums[a] + nums[b] + nums[c] === nums[d]){
                        count++;
                    }
                }
            }
        }
    }

    // step 4 - return count of `quadruplets`
    return count;
};

// Approach - 2 (Optimal Approach using Map)
let countQuadruplets = function(nums) {
    // get length of `nums` array
    const n = nums.length;

    // step 1 - store quadruplets in `count`
    let count = 0;

    // step 2 - loop over index `c` from `n-2` to 2 (as we need `a < b < c < d`)
    for(let c=n-2; c>=2; c--){
        // map to store frequency of of sum values from the left part (a, b)
        const map = new Map();
        
        // step 3 - now fix d=c+1 and beyound
        for(let d=c+1; d<n; d++){
            // step 4 - build frequency map for all positions d > c
            map.set(nums[d], (map.get(nums[d]) || 0) + 1);
        }

        // step 5 - iterate on for all valid pairs (a, b) where a < b < c
        for(let a=0; a<c-1; a++){
            for(let b=a+1; b<c; b++){
                // step 6 - find nums[a] + nums[b]
                const targetSum = nums[a] + nums[b] + nums[c];

                // step 7 - if this targetSum exists as nums[d] for some d > c
                if(map.has(targetSum)){
                    // add the number of such pairs (c, d)
                    count += map.get(targetSum);
                }
            }
        }
    }
    
    // step 8 - return count of `quadruplets`
    return count;
};

// const nums = [1,2,3,6];

// const nums = [3,3,6,4,5];

// const nums = [1,1,1,3,5];

const nums = [9,6,8,23,39,23];
console.log(countQuadruplets(nums));