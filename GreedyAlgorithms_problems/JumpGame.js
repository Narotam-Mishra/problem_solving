
// Problem link - https://leetcode.com/problems/jump-game/description/

// Approach - 1 (Brute Force)

function canJumpRec(pos, nums){
    // step 1 : base case - if we have reached or passed last index, return true
    if(pos === nums.length - 1) return true;

    // step 2 : recursive case - try all possible jumps from to nums[pos]
    let maxJump = nums[pos];

    // iterate on each jump starting from 1  
    for(let jump=1; jump<=maxJump; jump++){
        if(canJumpRec(pos+jump, nums)){
            // if path leads to success return true
            return true;
        }
    }

    // step 3 - return false if no path worked
    return false;
}

let canJump1 = function(nums) {
    return canJumpRec(0, nums);
};

// Approach 2 - using DP

function canJumpDP(pos, nums, memo){
    // step 1 : base case - if we have reached or passed last index, return true
    if(pos === nums.length - 1) return true;

    // step 2 - if we have already calculated the subproblem then return it
    if(memo[pos] !== null){
        return memo[pos];
    }

    // step 3 : try all possible jumps from to nums[pos] and memoize precomputed one
    let maxJump = nums[pos];

    // iterate on each jump starting from 1  
    for(let jump=1; jump<=maxJump; jump++){
        if(pos + jump < nums.length && canJumpDP(pos+jump, nums, memo)){
            // store result before returning it
            memo[pos] = true;
            // if path leads to success return true
            return true;
        }
    }

    // step 4 - if none of jumps worked, mark it as false
    memo[pos] = false;
    return false;
}

let canJump2 = function(nums) {
    let memo = new Array(nums.length).fill(null);
    return canJumpDP(0, nums, memo);
};

// Approach - 3 (Most Optimal Greedy Approach)

let canJump = function(nums) {
    // step 1 - track the farthest index that we can reach
    let maxReach = 0;

    for(let i=0; i<nums.length; i++){
        // step 2 - if we are struck before reaching this index, return false immediately
        if(i > maxReach) return false;

        // step 3 - updated the farthest index reachable
        maxReach = Math.max(maxReach, i + nums[i]);
    }

    // step 3 - if we made it through the loop, we can reach the end
    return true;
};

// const nums = [2, 3, 1, 1, 4];

const nums = [3, 2, 1, 0, 4];
console.log(canJump(nums));
