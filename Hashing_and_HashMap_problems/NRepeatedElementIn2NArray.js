
// Problem link : https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/?envType=problem-list-v2&envId=hash-table

let repeatedNTimes = function(nums) {
    // step 1 - create map to store frequency of each number from nums
    const map = {};
    
    // step 2 - add frequency and parallely check the frequency
    for(let num of nums){
        map[num] = (map[num] || 0) + 1;
        // all numbers are unique except one number
        if(map[num] > 1){
            // return that one unique number
            return num;
        }
    }
    return -1;
};

// const nums = [1,2,3,3];

// const nums = [2,1,2,5,3,2];

const nums = [5,1,5,2,5,3,5,4];
console.log(repeatedNTimes(nums));
