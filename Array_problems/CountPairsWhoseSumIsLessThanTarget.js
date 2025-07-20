
// Problem link - https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/description/?envType=problem-list-v2&envId=array

let countPairs = function(nums, target) {
    // store count of pairs in `count`
    let count = 0;

    // step 1 - iterate on each pair of `nums` array
    const n = nums.length;
    for(let i=0; i<n; i++){
        for(let j=i+1; j<n; j++){
            // step 2 - check if `nums[i] + nums[j] < target`
            if(nums[i] + nums[j] < target){
                // increment the counter 
                count++;
            }
        }
    }

    // step 3 - return counter `count`
    return count;
};

// const nums = [-1,1,2,3,1], target = 2;

const nums = [-6,2,5,-2,-7,-1,3], target = -2;
console.log(countPairs(nums, target));