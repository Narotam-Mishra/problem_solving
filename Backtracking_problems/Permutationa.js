
// Problem link - https://leetcode.com/problems/permutations/description/?envType=problem-list-v2&envId=array

// Approach - Using Backtracking with swapping
let permute = function(nums) {
    // store result in `res` array
    const res = []

    function backtrack(startIndex){
        // base case : if we've placed all elements
        if(startIndex === nums.length){
            // step 1 - make a copy of current state
            res.push([...nums]);
            return;
        }

        // step 2 - try each remaining element at the current position
        for(let i = startIndex; i<nums.length; i++){
            // step 3 - swap current element to the position we're filling
            [nums[startIndex], nums[i]] = [nums[i], nums[startIndex]];

            // step 4 - explore recursively
            backtrack(startIndex+1);

            // step 5 - swap back to restore original state
            [nums[startIndex], nums[i]] = [nums[i], nums[startIndex]];
        }
    }

    // step 6 - initiate recursive call
    backtrack(0);

    // step 7 - return result `res`
    return res;
};

// const nums = [1,2,3];

// const nums = [0,1];

const nums = [1];
console.log(permute(nums));