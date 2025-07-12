
// Problem link - https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/?envType=problem-list-v2&envId=array

let countPairs = function(nums, k) {
    // store count of required pairs in `count`
    let count = 0;
    
    // step 1 - iterate on each pairs of nums array
    const n = nums.length;
    for(let i=0; i<n; i++){
        for(let j=i+1; j<n; j++){
            // step 2 - check if nums[i] == nums[j] and (i * j) is divisible by k
            if(nums[i] === nums[j] && (i * j) % k === 0){
                // increment count 
                count++;
            }
        }
    }

    // step 3 - return the number of such pairs
    return count;
};

// const nums = [3,1,2,2,2,1,3], k = 2;

const nums = [1,2,3,4], k = 1;
console.log(countPairs(nums, k));